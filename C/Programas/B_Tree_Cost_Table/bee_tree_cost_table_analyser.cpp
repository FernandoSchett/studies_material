// Made by: Fernando Schettini Github: https://github.com/FernandoSchett

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "ARVB.h"

char* get_data(char *registro){
	int i = 0,j = 0, data_on  = 0;
	char data[100];
		
	while(true){
		//printf("registro: %c\n", registro[i]);
		if(data_on == 1 && registro[i] == '<'){
			data[j] = '\0';
			break;
		}
		if(data_on == 1){
			data[j] = registro[i];
			j++;
		}
		if(registro[i] == '>'){
			//printf("ativado\n");
			data_on = 1;	
		}
		i++;
	}
	//printf("data: %s\n", data);
	return data;
}

void ler_arquivo(FILE **lista_custos, TipoApontador * arvoreB){
	char registro[100], pre_data[100];
	int info = 0;
	float soma = 0 ;
	TipoRegistro aux;

	while(fgets(registro, sizeof(registro), *lista_custos) != NULL){
		if(strstr(registro, "<Cod>")){	
			strcpy(pre_data, get_data(registro));
			aux.Chave.cod = atoi(pre_data);
			//printf("cod = %d\n", aux.cod);
			info++;
		}
		if(strstr(registro, "<Descr>")){
			strcpy(aux.Chave.desc, get_data(registro));
			//printf("desc = %s\n", aux.desc);
			info++;
		}
		if(strstr(registro, "<Custo>")){
			//strcpy(pre_data, get_data(registro));
			//printf("pre_data: %s\n", pre_data);
			aux.Chave.custo = atof(get_data(registro));
			//printf("custo = %.2f\n", aux.Chave.custo);
			info++;
		}
		if(info == 3){
			info = 0;
			soma = soma + aux.Chave.custo; 
			Insere(aux, arvoreB);
			//Pesquisa(&aux, *arvoreB);
			//printf("Inserido: cod: %d, custo: %f, desc: %s", aux.Chave.cod, aux.Chave.custo, aux.Chave.desc);
		}
	}
	//printf("soma: %f\n", soma);
}

int main(){
	//setlocale(LC_ALL, "Portuguese");
	FILE *lista_custos;
	TipoApontador arvoreB;
	int resposta;
	float custo;
	TipoRegistro aux;
	
	Inicializa(&arvoreB);
	lista_custos = fopen("tabela_custo.txt", "r");
	if(lista_custos == NULL){
		printf("Erro ao abrir arquivo.\n");
		return 0;	
	}
	
	ler_arquivo(&lista_custos, &arvoreB);
	rewind(lista_custos);
	
	while(true){
		printf("Oque Gostaria de Fazer?\n");
		printf("1 - Pesquisar por codigo.\n");
		printf("2 - Exibir etapas da obra de forma hierarquizada.\n");
		printf("3 - Exibir custo total da obra.\n");
		printf("Outro - Encerrar Programa.\n");
		scanf(" %d", &resposta);
		switch(resposta){
			case 1:
				printf("Digite o codigo do custo:\n");
				scanf(" %d", &aux.Chave.cod);
				Pesquisa(&aux, arvoreB);
				printf("Custo Referido: Cod: %d\n Custo: %f\n desc: %s\n", aux.Chave.cod, aux.Chave.custo, aux.Chave.desc);
			case 2:
				printf("OverView de sua obra: \n");
				ExibeHierarquizado(arvoreB);
			case 3:
				printf("Soma total do custo da obra:\n");
				SomaCusto(arvoreB, &custo);
				printf("Custo total da obra: %.3f\n", custo);
			default:
				return 0; 
		}
	}
	
	fclose(lista_custos);
	return 0;
}
