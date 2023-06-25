// Made by: Fernando Schettini Github: https://github.com/FernandoSchett


// This is a Insertion Sort algorihm, it will receive
// n values , put then in the vector, then use 
// Insertion Sort, and make then ascending order.

#include <stdio.h>

void Insertion_Sorter(int *vector, int *quant){
	int i,j,aux;
	for(i = 1; i < *quant; i++){
		aux = vector[i];
		for(j = i; (j>0) && (aux < vector[j-1]); j--){
			vector[j] = vector[j-1];
		}
		vector[j] = aux;
	}
}

void Print_Vector(int *vector, int *quant){
	int cont;
	cont = 0;
	printf("Vetor:");
	while(cont != *quant){
		printf(" %d", vector[cont]);
		cont++;
	}
}


int main (){
	int number,cont,vector[1000];
	
	printf("Hi,im gonna use Insertion Sort for make YOUR numbers in ascending order :\n");
	printf("How many number do you wanna organize?\n");
	scanf(" %d", &number);
	
	printf("Type the numbers:\n");
	cont = 0;
	while(number != cont){		
		scanf(" %d", &vector[cont]);
		cont++;
	}
	
	Insertion_Sorter(vector, &number);
	Print_Vector(vector, &number);
		
	return 0;
}
 
