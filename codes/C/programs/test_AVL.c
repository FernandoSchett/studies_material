#include <stdio.h>
#include <locale.h>
#include "ArvoreAVL2.h"


int main(){
	/*Demonstração das funções feitas em sala*/
	setlocale(LC_ALL,""); // Define localização para acentuação correta...
	int num, vazia, altura, totNOs, valCons, valRem;
	ArvAVL* raiz = criarAVL();
	vazia = estah_vaziaABB(raiz);
	if(vazia) printf("ÁRVORE AVL VAZIA!\n");
	printf("Digite um valor para inserir na árvore AVL (ou -1 para parar):");
	scanf("%d", &num);
	while(num != -1){
		inserir(raiz, num);
		altura = alturaAVL(raiz);
		printf("\nAltura: %d", altura);
		printf("\nDigite outro valor para inserir na árvore (ou -1 para parar):");
		scanf("%d", &num);
	}	
	vazia = estah_vaziaABB(raiz);
	if(vazia==0) printf("ÁRVORE AVL NAO VAZIA!");
	totNOs = totalNOsABB(raiz);
	printf("\nTotal de Nós: %d", totNOs);
	
	printf("\nDigite um valor para remover da árvore (ou -1 para parar):");
	scanf("%d", &valRem);
	
	while(valRem != -1){
		if(remover(raiz, valRem)){
			printf("\n%d removido da árvore!", valRem);
		}		
		printf("\nDigite outro valor para remover da árvore (ou -1 para parar):");
		scanf("%d", &valRem);
	}

	totNOs = totalNOsABB(raiz);
	printf("\nTotal de Nós: %d", totNOs);
	printf("\n==========================\nPercorrendo a árvore:\n");
	printf("PRE ORDEM (pre fixa):\n");
	contPrint = 0;
	preOrd(raiz);
	printf("\nEM ORDEM (in fixa):\n");
	contPrint = 0;
	emOrd(raiz);
	printf("\nPOS ORDEM (pos fixa):\n");
	contPrint = 0;
	posOrd(raiz);
	return 0;
}

