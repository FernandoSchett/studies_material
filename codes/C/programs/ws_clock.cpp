/*
File:           ws_clock.cpp
Last changed:   25/06/20 16:05
Purpose:        simulator of the WSClock page replacement algorithm in an operating system.
Authors:        Fernando Antonio Marques Schettini
Usage: 
	HowToCompile:   gcc ws_clock.cpp -o ws_clock
	HowToExecute:   ./ws_clock  
*/

#include <stdio.h>
#include <stdlib.h>
#include "ListaSE.h"

void constroiListaCircular(tp_listase *lista){ // Funcao para deixar a lsita circular
    tp_listase *atu;
    atu = lista;
    while(atu->prox != NULL){ //Percorre a lsita ate achar o fim
        atu=atu->prox;
    }
    
    atu->prox = lista; //Seta o funal da lista como inicio
}

void imprimeListaseCircular(tp_listase *lista, int qntPaginas){  //Imprime a lista circular
    tp_listase *atu;
    atu = lista;
    int cont = 0;
    while(cont != qntPaginas){ //Percorre a lista, imprimindo elementos, até acabar, baseado no tamanho dela
        printf("Num pagina: %d, Tempo de carregamento: %lld, Bit de referenciacao: %d\n", atu->numPagina, atu->tempoPagina, atu->bitRef);
        atu=atu->prox;
        cont++;
    }
}

void referencia(tp_listase *lista, int referencia){ //Percorre a lista ate encontrar a pagina de referencia, setando seu bit de referenciacao
    tp_listase *atu;
    atu = lista;
    while(atu->numPagina != referencia){ //Loop percorre ate encontrar o numero da pagina do parametro
        atu = atu->prox; 
    }
    atu->bitRef = 1; //Seta o bit de referenciacao
} 

int carregaPagina(tp_listase **lista, int numPagina, int delta, int tam){
    int tempoAtual;
    int cont = 0;
    struct timeval current_time; //pega o tempo atual
    gettimeofday(&current_time, NULL);
    
    while(cont != tam){ //Para quando percorrer a lista inteira
        if((*lista)->bitRef == 1){ //Checa se o bit de referenciacao e 1, se for seta igual a 0
            (*lista)->bitRef = 0;
            printf("ENTREI");
        }else{ //se nao for, ele verifica a diferenca de tempo e igual a delta
            tempoAtual = ((current_time.tv_sec - inicio.tv_sec));

            if( tempoAtual - ((*lista)->tempoPagina) > delta){ // Caso a condicional seja verdadeira, ele substitui a pagina
                (*lista)->numPagina = numPagina;
                (*lista)->bitRef = 0;
                (*lista)->tempoPagina = tempoAtual;
                return 1; //Encerra a funcao
            }
        }
        (*lista) = (*lista)->prox; //Caso a pagina analisa seja invalida, ele passa para a proxima pagina
        cont++;
    }
    //Subistitui o primeiro depois da rodada inteira, caso nao tenha percorrido a lista inteira e nao tenha encontrado um candidato que satistfaca a condicao de delta e bit de referenciacao
    (*lista)->numPagina = numPagina;
    (*lista)->bitRef = 0;
    (*lista)->tempoPagina = tempoAtual;
    return 1;
}

int main(){
    int numFramesInicial, delta, id = 0, tempoAtual;
    tp_listase *memoria; //Cria a lista simplismente encadeada
    memoria = inicializa_listase(); //Inicializa a lista
    gettimeofday(&inicio, NULL); //Pega o valor do tempo de inicio do programa
    
    printf("Insira o numero de paginas no algoritmo inicial:\n");
    scanf(" %d", &numFramesInicial); //Le a quantidade de paginas que o programa vai ter

    printf("Insira o numero de Delta:\n");
    scanf(" %d", &delta); //Le o valor de delta para o programa
    
    
    while(numFramesInicial != id){
        insere_listase_no_fim(&memoria, id); //Insere elementos na lista
        id++;
    }
    constroiListaCircular(memoria); //Torna a lista simplismente encadeada em uma lista circular
 
    struct timeval current_time; //Variavel para pegar o tempo do programa
    int aux;
    char op;
    while(op != 'F' ){

        printf("\n\nSimulador de Algoritmo WSClock. Oque deseja fazer?\n"); 
        printf("R - Referenciar uma pagina\n");
        printf("S - Carregar uma pagina\n");
        printf("W - Indicar tempo atual\n");
        printf("E - Exibir paginas e seus atributos\n");
        printf("F - Sair do programa\n");
        scanf(" %c", &op); //Le o que o usuário deseja fazer (R/S/W/E/F)
        switch (op){
            case 'R':
                printf("Insira o numero da pagina a ser referenciada: \n");
                scanf(" %d", &aux);
                referencia(memoria, aux); //Setta o bit de referenciacao da pagina para 1
                break;

            case 'S':
                printf("Insira o numero da pagina a carregada: \n");
                scanf(" %d", &aux);
                carregaPagina(&memoria, aux, delta, numFramesInicial); //Carrega uma pagina para a lista circular
                break;
            
            case 'W':
                gettimeofday(&current_time, NULL); //Pega o tempo total do codigo
                tempoAtual = ((current_time.tv_sec - inicio.tv_sec)); //Calcula o tempo atual
                printf("\nTempo atual do programa em Segundos: %d\n", tempoAtual); //Mostra o tempo atual
                break;

            case 'E':
                printf("Imprimindo o relogio...\n");
                imprimeListaseCircular(memoria, numFramesInicial); //Mostra a lista circular
                break;
            
            default:          
                printf("Valor Invalido, tente novamente:\n"); //Usuario inseriu uma opcao invalida
                break;
        }     
    } 
}