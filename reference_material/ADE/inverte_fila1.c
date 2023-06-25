#include <stdio.h>
#include "pilha.h"
#include "fila.h"

void inverte_fila(tp_fila *f){
	tp_pilha paux;
	tp_item e;
	inicializa_pilha(&paux);
	while (!fila_vazia(f)){
		remove_fila(f,&e);
		push(&paux, e);
	}
	while (!pilha_vazia(&paux)){
		pop(&paux, &e);
		insere_fila(f,e);
	}	
}
int main(){
	tp_fila fila;
	inicializa_fila(&fila);
	insere_fila(&fila, 1);	
	insere_fila(&fila, 2);	
	insere_fila(&fila, 3);	
	insere_fila(&fila, 4);	
	insere_fila(&fila, 5);	
	insere_fila(&fila, 6);
	imprime_fila(fila);
	inverte_fila(&fila);
	imprime_fila(fila);		
	return 0;
}
