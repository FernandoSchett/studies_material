#include <stdio.h>
#include "fila.h"

int main(){
	tp_fila fila;
	inicializa_fila(&fila);
	int i, num;	
	tp_item e;
	for (i=1;i<=15;i++){
		printf("Digite um numero inteiro: ");
		scanf("%d", &num);
		if (num%2==0) {
			if (!insere_fila(&fila, num)) {
				remove_fila(&fila, &e);
				insere_fila(&fila, num);
			}
		} else {
			if (!remove_fila(&fila,&e)){
				printf("Fila vazia");
			}
		}
	}
	imprime_fila(fila);
	return 0;
}
