// Made by: Fernando Schettini - Github: https://github.com/FernandoSchett
//          Joao Vitor - Github: https://github.com/juauzitor
// Manipulacao de uma carderneta de notas usando fseek e ftell.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

int main(){
	
	setlocale(LC_ALL, "portuguese");
	char registro[100], nome[100],frase[100], nomemaior[100], nomemenor[100];
	FILE *arq;
	int i = 0, r, pos;
	arq = fopen("Notas.txt" , "r+"); // Abre o arquivo
	float nota[4][3], mediaalta = 0, media, mediabaixa = 0;
	
	if(!arq){   //Se o ponteiro eh nulo, houve um problem ao abrir o arquivo.
		printf("Houve um problem ao abrir o arquivo..\n");
		return 0;
	}
		
	printf("Arquivo Atual:\n\n"); //Printa o Arquivo Original	
	
	while(fgets(registro,sizeof(registro), arq)){
		printf("%s",registro);	
	}
	rewind(arq);
	
	//Posiciona ponteiro na formatacao.
	while(i!= 7){
		if(i == 2){
			pos = ftell(arq);
		}
		fgets(registro,sizeof(registro), arq);	
		i++;
	}
	
	printf("\nAnalise dos Alunos:\n\n");
	i = 0;
	
	while(!feof(arq)){
		fscanf(arq," %s", nome);
		printf("Aluno :%s", nome);
		printf("\n");
		
		fscanf(arq, "%f %f %f", &nota[i][0], &nota[i][1], &nota[i][2]);
		
		printf("Nota 1: %.1f\n", nota[i][0]);	
		printf("Nota 2: %.1f\n", nota[i][1]);
		printf("Nota 3: %.1f\n", nota[i][2]);
		
		media = nota[i][0] + nota[i][1] + nota[i][2];
		media = media/3;
		printf("Media: %.1f\n\n", media);
		
		if(i == 0){
			mediabaixa = media;
			strcpy (nomemenor,nome);
		}
		
		if(media > mediaalta){
			mediaalta = media;
			strcpy (nomemaior,nome);
		}
		if(media < mediabaixa){
			mediabaixa = media;
			strcpy (nomemenor,nome);
		}	
		i++;
	}
	printf("Pessoa com a maior media (%.1f): %s\n", mediaalta, nomemaior);
	printf("Pessoa com a menor media (%.1f): %s\n", mediabaixa, nomemenor);
		
	system("pause");
	system("cls");
	
//	fclose(arq);

	rewind(arq);

	//strcpy(frase, "bundao\n");
	//fputs(frase, arq);	

	//printf(" ponteiro: %d\n", arq);
	//fprintf(arq,frase);
	//fputs("palavra chave", arq);
	
	//printf(" %s\n", registro);

	//printf(" %s\n", registro);
	//fgets(registro,sizeof(registro), arq);
	fseek(arq, pos,SEEK_SET);
	sprintf(frase, "O aluno que apresenta o maior desempenho é %s com media igual a %.2f\nO aluno que apresenta o menor desempenho é %s com media igual a %.2f", nomemaior, mediaalta, nomemenor, mediabaixa);
	//printf("%s\n", frase);
	fputs(frase, arq);
	
	
	rewind(arq);
	printf("Novo Arquivo:\n\n"); //Printa o Arquivo modificado
	while(fgets(registro,sizeof(registro), arq)){
		printf("%s",registro);		
	}
	fclose(arq);
	
	return 0;
}
