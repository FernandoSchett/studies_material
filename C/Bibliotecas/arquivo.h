#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <stdio.h>
#include <string.h>
#include <locale.h>
//while(!feof(arq)){}


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

                                                                // notas.txt
int ler_formatado(FILE *arq, char nomearq[]){                   // 1,0 2,0 3,0
	float nota1, nota2, nota3;                                  // 4,5 9,0 12,0 
	arq = fopen(nomearq, "r");                                  // 5,2 4,6 8,4
	if(!arq){
		return 0;
	}
	while(fscanf(arq, "%f %f %f", &nota1, &nota2, &nota3) != EOF){
		printf("Nota 1: %f, Nota 2: %f, Nota 3: %f \n", nota1, nota2, nota3);
	}
	fclose(arq);
	return 1;
}

int ler_alterar_geral(FILE *arq, char nomearq[]){
	float nota[3][3];
	char registro[20];
	arq = fopen(nomearq, "r+");
	int i = 0;
	
	if(!arq){
		return 0;
	}
	
	while(fscanf(arq, "%f %f %f", &nota[i][0], &nota[i][1], &nota[i][2]) != EOF){
		printf("Aluno: %d \n", i+1);
		printf("Nota 1 atual: %.1f   Insira nova nota:\n", nota[i][0]);
		scanf( " %f", &nota[i][0]);
		printf("Nota 2 atual: %.1f   Insira nova nota:\n", nota[i][1]);
		scanf( " %f", &nota[i][1]);
		printf("Nota 3 atual: %.1f   Insira nova nota:\n", nota[i][2]);
		scanf( " %f", &nota[i][2]);
		i++;
	}
	rewind(arq); //volta pro inicio
	//fseek vai pro byte selecionado
	//ftell: diz qual byte esta
	for(i=0; i<3; i++){ // pode usar fprintf
		sprintf(registro, "%.1f  %.1f  %.1f\n", nota[i][0], nota[i][1], nota[i][2]); //joga na string
		fputs(registro, arq);
	}
}





#endif
