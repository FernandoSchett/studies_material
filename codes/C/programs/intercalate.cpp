#include <stdio.h>
#include "listase.h"

void intercala(tp_listase **lista1, tp_listase **lista2){
	//se um dos ponteiros for nulo, o resultado é a outra lista integralmente
	if (*lista1 == NULL)
        *lista1 = *lista2;
	if (*lista2 == NULL)
		*lista2 = *lista1;	
	
	//inicializa os ponteiros atu e next para ambas as listas
	tp_listase *atu1, *atu2, *next1, *next2;
	int lista_foco, primeiro = 1;
	atu1 = *lista1;
	atu2 = *lista2;
	next1 = atu1->prox;
	next2 = atu2->prox;
	
	while (1) {
		if (primeiro) {
			if (atu1->info <= atu2->info) {
				*lista2 = atu1;	
				lista_foco = 1;		
			}
			else {
				*lista1 = atu2;	
				lista_foco = 2;
			}
			primeiro = 0;
		} else {
			if (lista_foco == 1){
				if (next1->info > atu2->info){
					atu1->prox = atu2;
					lista_foco = 2;	
				 } 
				atu1 = next1;
				if (next1 != NULL)
					next1= next1->prox;				
			}else {
				if (next2->info > atu1->info){
					atu2->prox = atu1;
					lista_foco = 1;
					}
				atu2 = next2;
				if (next2 != NULL)
					next2= next2->prox;						
				}				
			} // fim do else mais externo
			
		if (lista_foco ==1 && next1==NULL) {
			atu1->prox=atu2;
			break;
		} else {
			if (lista_foco==2 && next2==NULL){
				atu2->prox=atu1;
				break;
			}

		} 
		    		
	}	
	
}

int main() {
	tp_listase *lista1, *lista2;
	
	lista1 = lista2 = inicializa_listase();
	
	insere_listase_no_fim(&lista1, 10);
	insere_listase_no_fim(&lista1, 15);
	insere_listase_no_fim(&lista1, 60);
	insere_listase_no_fim(&lista1, 65);
	insere_listase_no_fim(&lista1, 70);
	insere_listase_no_fim(&lista2, 4);
	insere_listase_no_fim(&lista2, 20);
	insere_listase_no_fim(&lista2, 30);	
	insere_listase_no_fim(&lista2, 80);	
	insere_listase_no_fim(&lista2, 90);	
		
	printf("Lista1:\n");	
	imprime_listase(lista1);
	printf("\n");
	printf("Lista2:\n");	
	imprime_listase(lista2);
	
	
	intercala(&lista1, &lista2);
	printf("\n\n");

	printf("Lista1:\n");		
	imprime_listase(lista1);
	printf("\n");
	printf("Lista2:\n");	
	imprime_listase(lista2);	
	
	return 0;
}
