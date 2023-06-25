#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define NUM_PESSOA 3

typedef struct{
	char nome[50];
	int idade;
}tp_pessoa;

void grava_dados(FILE *arq){
	int i;
	tp_pessoa pessoa[NUM_PESSOA];
	for(i=0; i<NUM_PESSOA;i++){
		printf("Digite o nome da pessoa:\n");
		scanf(" %[^\n]s", pessoa[i].nome);
		printf("Digite a idade da pessoa:\n");	
		scanf(" %d", &pessoa[i].idade);
	}
	fwrite(pessoa,sizeof(tp_pessoa), NUM_PESSOA, arq);	
}

void le_dados(FILE *arq){
	tp_pessoa pessoa;
	printf("Pessoas gravadas no arquivo:\n");
	do{
		fread(&pessoa, sizeof(tp_pessoa), 1, arq);
		if(!feof(arq)){
			printf("Nome: %s\n", pessoa.nome);
			printf("Idade: %d\n", pessoa.idade);	
		}
	}while(!feof(arq));
	
}

int main(){
	setlocale(LC_ALL, "portuguese");
	char nomearq[50];
	FILE *arq;
	
	printf("Digite o nome do arquivo:\n");
	gets(nomearq);
	
	arq = fopen(nomearq, "w+b");
	
	if(arq == NULL){
		printf("Nao foi possivel abrir o arquivo.\n");
		exit(0);
	}
	
	grava_dados(arq);
	rewind(arq);
	le_dados(arq);
	fclose(arq);
	
	return 0;
}
