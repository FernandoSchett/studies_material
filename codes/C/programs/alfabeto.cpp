#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "pilha.h"

int valida_alfabeto(char palavra[30]){
	setlocale(LC_ALL, "portuguese");
    int tam, i, achoue=0;
    tp_item e;
	//cria e inicializa uma pilha auxiliar
	tp_pilha pilha;
    inicializa_pilha(&pilha);
    //Captura a quantidade de caracteres da palavra
	tam=strlen(palavra);
	//Verifica a qtde de caracteres é par. 
	//Se sim, aborta a função
	if (tam%2==0) return 0;
	if (palavra[tam/2]!='e') return 0;
	//Captura cada caractere a string e avalia
	for (i=0;i<tam;i++){
		//Verifica se há letras diferentes de a, b e c
		if ( (palavra[i] != 'd') && (palavra[i] != 'f') &&
	     	 (palavra[i] != 'e') ) return 0;
		//Verifica se o caractere é e	  		
		if (palavra[i] == 'e') {
			if (i != tam/2) return 0;  //retorna 0 se encontrar o caracter e fora do meio
			if (!achoue) achoue=1; //verifica se é o 1o caractere c
			else return 0;
		}
		else {
			if (!achoue) push(&pilha, palavra[i]);
			else{
				pop(&pilha, &e);
				if (palavra[i] != e) return 0;
				} // fim do else mais interno
		} //fim do else mais externo
	} // fim do for
	if (!pilha_vazia(&pilha)) return 0;
	return 1;	
}

int main() {
	char palavra[30];
	printf("Digite uma palavra:");
	gets(palavra);
	if (valida_alfabeto(palavra)==1)
	   printf("Palavra pertence ao dicionario");
	else
	   printf("Palavra NÃO pertence ao dicionario");
    return 0;	
}
