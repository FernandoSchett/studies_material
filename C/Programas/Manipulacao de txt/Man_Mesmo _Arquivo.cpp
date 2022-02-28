// Made by: Fernando Schettini - Github: https://github.com/FernandoSchett
//          Joao Vitor - Github: https://github.com/juauzitor
// Manipulacao de uma carderneta de notas usando arquivo auxliar.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <errno.h>


int main(){
	
	setlocale(LC_ALL, "portuguese");
	char registro[100], nome[100],frase[1000], nomemaior[100], nomemenor[100];
	FILE *arq, *aux;
	int i = 0, r, pos;
	arq = fopen("Notas.txt" , "r+"); // Abre o arquivo
	float nota[3], mediaalta = 0, media, mediabaixa = 0;
	
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
		
		fgets(registro,sizeof(registro), arq);	
		i++;
		if(i == 2){
			r = ftell(arq);	
			
		}
		if(i == 3){
			
		
		}
	}
	
	printf("\nAnalise dos Alunos:\n\n");
	i = 0;
	
	while(!feof(arq)){
		fscanf(arq," %s", nome);
		printf("Aluno :%s", nome);
		printf("\n");
		
		fscanf(arq, "%f %f %f", &nota[0], &nota[1], &nota[2]);
		
		printf("Nota 1: %.1f\n", nota[0]);	
		printf("Nota 2: %.1f\n", nota[1]);
		printf("Nota 3: %.1f\n", nota[2]);
		
		media = nota[0] + nota[1] + nota[2];
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
	
	pos = ftell(arq);
	
	printf("Pessoa com a maior media (%.1f): %s\n", mediaalta, nomemaior);
	printf("Pessoa com a menor media (%.1f): %s\n", mediabaixa, nomemenor);
		
	system("pause");
	system("cls");
	
	//fseek(arq, r, SEEK_SET);
	
	//printf("%s\n", frase);
//	fputs(frase, arq);	
//	sprintf(frase, "O aluno que apresenta o menor desempenho é %s com media igual a %.2f\n", nomemenor, mediabaixa);
//	printf("%s\n", frase);
//	fputs(frase, arq);
	sprintf(frase, "O aluno que apresenta o maior desempenho é %s com media igual a %.2f\nO aluno que apresenta o menor desempenho é %s com media igual a %.2f\n", nomemaior, mediaalta,nomemenor,mediabaixa);
	aux = fopen("outro.txt", "w+"); // Abre o arquivo
	
	if(!aux){   //Se o ponteiro eh nulo, houve um problem ao abrir o arquivo.
    	printf("Oh dear, something went wrong with read()! %s\n", strerror(errno));	
	}		

	i = 0;
	rewind(arq);
	while(fgets(registro,sizeof(registro), arq)){
		if(i == 2){
			fputs(frase, aux);
		}else{
			if(i!=3){
				fputs(registro, aux);			
			}
		}
		i++;
	}
	
	rewind(arq);
	rewind(aux);
	while(fgets(registro,sizeof(registro), aux)){
		printf(" %s", registro);
		fputs(registro, arq);
	}
	
	
	strcpy(registro," ");
	
	while(ftell(arq) != pos){
		fputs(registro, arq);
	}
	
	fclose(aux);
	remove("outro.txt");
	fclose(arq);	


	return 0;
}
