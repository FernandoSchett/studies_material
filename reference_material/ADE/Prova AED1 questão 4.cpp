#include <stdio.h>
#include "filai.h"
#include "pilhai.h"

int num, i, continua;
tp_pilha pilhaentra, pilhasai;
tp_fila filaentra, filasai;
tp_item e;

int ehpilha(tp_pilha p1, tp_pilha p2){
	tp_item e1, e2;
	while(!pilha_vazia(&p1) && !pilha_vazia(&p2)){
		pop(&p1, &e1);
		pop(&p2, &e2);
		if(e1!=e2)
			return 0;
	}
	return 1;
}

int ehfila(tp_fila f1, tp_fila f2){
	tp_item e1, e2;
	while(!fila_vazia(&f1) && !fila_vazia(&f2)){
		remove_fila(&f1, &e1);
		remove_fila(&f2, &e2);
		if(e1!=e2)
			return 0;
	}
	return 1;
}

void inverte_pilha(tp_pilha *p){
	tp_fila filaux; tp_item inv;
	inicializa_fila(&filaux);
	while(!pilha_vazia(p)){
		pop(p, &inv);
		insere_fila(&filaux, inv);
	}
	while(!fila_vazia(&filaux)){
		remove_fila(&filaux, &inv);
		push(p, inv);
	}
}

int main(){
	
	do{
	
	i=0;
	inicializa_pilha(&pilhaentra);
	inicializa_pilha(&pilhasai);
	inicializa_fila(&filaentra);
	inicializa_fila(&filasai);
	
	printf("Digite os 5 numeros a serem inseridos:\n");
	do{
		scanf("%d", &num);
		push(&pilhaentra, num);
		insere_fila(&filaentra, num);
		i++;
	}while(i<5);
	printf("Digite os 5 numeros retirados da estrutura:\n");
	for(i=0; i<5; i++){
		scanf("%d", &num);
		push(&pilhasai, num);
		insere_fila(&filasai, num);
	}
	inverte_pilha(&pilhasai);
	//imprime_pilha(pilhasai);
	//imprime_pilha(pilhaentra);
	if(ehpilha(pilhaentra, pilhasai) && !ehfila(filaentra, filasai))
		printf("A estrutura eh uma pilha!!");
	if(ehfila(filaentra, filasai) && !ehpilha(pilhaentra, pilhasai))
		printf("A estrutura eh uma fila!!");
	if(ehfila(filaentra, filasai) && ehpilha(pilhaentra, pilhasai))
		printf("Nao posso determinar a estrutura :(");
	if(!ehpilha(pilhaentra, pilhasai) && !ehfila(filaentra, filasai)) 
		printf("Essa estrutura eh impossivel =O");
	printf("\nDigite 1 para testar outra estrutura.\n");
	scanf("%d", &continua);
}while(continua==1);
	return 0;
}
