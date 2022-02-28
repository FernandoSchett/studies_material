#ifndef LISTADUPLA_H
#define LISTADUPLA_H
#include <stdio.h>
#include <stdlib.h>

typedef int tp_item;

typedef struct tp_no_aux{
    struct tp_no_aux *ant;
    tp_item info;
    struct tp_no_aux *prox;
}tp_no;

typedef struct{
    tp_no *ini;
    tp_no *fim;
}tp_listad;

tp_listad *inicializa_listad(){
    tp_listad *lista = (tp_listad*) malloc(sizeof(tp_listad));
    lista->ini = NULL;
    lista->fim = NULL;
    return lista;
}
int listaVazia(tp_listad *lista){
    if(lista->ini == NULL)
        return 1;
    return 0;
}

tp_no *alocaNo(){
    tp_no *pt = (tp_no*) malloc(sizeof(tp_no));
    return pt;
}

int insereListaNoFim(tp_listad *lista,tp_item e){
    tp_no *novo = alocaNo();
        if(!novo)
            return 0;
        novo->info = e;
        if(lista->ini == NULL && lista->fim == NULL){
            lista->ini = novo;
            lista->fim = novo;
            novo->ant = NULL;
            novo->prox = NULL;
        }
        else{
            novo->prox = NULL;
            novo->ant = lista->fim;
            lista->fim->prox = novo;
            lista->fim = novo;
        }
    return 1;
}

int insereListaNoIni(tp_listad *lista,tp_item e){
    tp_no *novo = alocaNo();
        if(!novo)
            return 0;
        novo->info = e;
        if(lista->ini == NULL && lista->fim == NULL){
            lista->ini = novo;
            lista->fim = novo;
            novo->ant = NULL;
            novo->prox = NULL;
        }
        else{
            novo->ant = NULL;
            novo->prox = lista->ini;
            lista->ini->ant = novo;
            lista->ini = novo;
        }  
    return 1;
}

void imprimeListad(tp_listad *lista,int ordem){
    tp_no *aux;
        switch (ordem)
        {
        case 1: aux = lista->ini;
                while(aux!=NULL){
                    printf("%d ",aux->info);
                    aux = aux->prox;
                }
            break;
        case 2: aux = lista->fim;
                while(aux!=NULL){
                    printf("%d ",aux->info);
                    aux = aux->ant;
                }
        
        default: printf("Codigo invalido");
            
        }
        printf("\n");
}

int removeNo(tp_listad *lista,tp_item e){
    tp_no *aux;
    aux = lista->ini;
        while(aux!=NULL && aux->info !=e)
            aux = aux->prox;
        if(aux == NULL)
            return 0;
        if(lista->ini == lista->fim)
            lista->ini = lista->fim = NULL;
        else{
            if(lista->ini == aux){
                lista->ini = aux->prox;
                aux->prox->ant = NULL;
            }
            else if(lista->fim == aux){
                lista->fim = aux->ant;
                aux->ant->prox = NULL;
            }
            else{
                aux->prox->ant = atu->ant;
                aux->ant->prox = aux->prox;
            }
        }
        free(aux);
}

tp_listad* apagaListad(tp_listad *lista){
    tp_no *aux;
    aux = list->ini;
        while(aux!=NULL){
            lista->ini = aux->prox;
            free(aux);
            aux = lista->ini;
        }
        free(lista);
        return NULL;
}

#endif