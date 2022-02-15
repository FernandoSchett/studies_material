#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <stdio.h>
#include <string.h>
#include <locale.h>

int gravar(FILE *arq, char nomearq[]){
	char mensagem[50];
	arq=fopen(nomearq, "w");
	if (arq==NULL) return 0;
	printf("Digite mensagem 1 para gravar no arquivo: ");
	fflush(stdin);
	gets(mensagem);
	fprintf(arq,strcat(mensagem,"\n"));
	printf("Digite mensagem 2 para gravar no arquivo: \n");
	gets(mensagem);
	fputs(mensagem,arq);
	fclose(arq);
	return 1;
}

int alterar_no_final(FILE *arq, char nomearq[]){
	char mensagem[50];
	arq=fopen(nomearq,"a");
	if(!arq) return 0;
	printf("Digite mensagem para gravar no arquivo: ");
	gets(mensagem);
	fprintf(arq,"\n%s", mensagem);
	fclose(arq);
	return 1;
}
#endif
