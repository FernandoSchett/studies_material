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

int ler(FILE *arq, char nomearq[]){
	char registro[50];
	arq = fopen(nomearq, "r");
	if(!arq){
		return 0;
	}
	while(fgets(registro,sizeof(registro), arq)){
		printf("%s",registro);	
	}
	fclose(arq);
	return 1;	
}


int ler_formatado(FILE *arq, char nomearq[]){
	float nota1, nota2, nota3;
	arq = fopen(nomearq, "r");
	if(!arq){
		return 0;
	}
	while(fscanf(arq, "%f %f %f", &nota1, &nota2, &nota3)){
		printf("Nota 1: %f, Nota 2: %f, Nota 3: %f \n", nota1, nota2, nota3);
	}
	fclose(arq);
	return 1;
}



#endif
