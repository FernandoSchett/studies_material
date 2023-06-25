#include <stdio.h>
#include "fila.h"
#include "pilha.h"

void organiza_trem(tp_fila *trem){
    int tam, cont=1;
	tp_item e;
	tp_pilha desvio;
	inicializa_pilha(&desvio);	
	do {
		tam=tamanho_fila(trem);
		for (int i=1;i<=tam;i++){
			remove_fila(trem,&e);
			switch(e){
				case 'A': insere_fila(trem, e);
				          break;
				case 'B': if (cont==1) insere_fila(trem, e);
						  else push(&desvio, e);
						  break;
				case 'C': push(&desvio, e);
				          break;  
			}			
		}
		cont++;
	}
	while (cont<=2);
	
	while (!pilha_vazia(&desvio)){
		pop(&desvio, &e);
		insere_fila(trem, e);
	}

}


int main(){
    tp_fila trem;
	inicializa_fila(&trem);
	insere_fila(&trem, 'A');
	insere_fila(&trem, 'C');
	insere_fila(&trem, 'B');
	insere_fila(&trem, 'B');
	insere_fila(&trem, 'A');
	insere_fila(&trem, 'C');
	imprime_fila(trem);
	organiza_trem(&trem);
	printf("\n");
	imprime_fila(trem);	
	return 0;
}


