/*This is a program that will receive a lista of elements, then chossen randomly one of then. Chances are the same for eaach element recieve.
Fernando Schettini (o mais foda) Github:https://github.com/FernandoSchett */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


int sorter(int *possb){
	int random, nrandom, choosen;
	float chance;
	
	srand(time (NULL)); //Generate seed for rand(),based in your pc time.
	printf("possibility: %d\n", *possb);
	random = (rand() % 100); //Generate random number in range 1-100.
	printf("random: %d\n", random);
	chance =  100 /(float)*possb; //chance of getting any number.
	printf("chance: %f \n", chance);
	
	nrandom = 0;
	choosen = 0;
				
	while(nrandom < random){ //Look for the range.
		nrandom = nrandom  + chance;
		//printf("choosen: %d\n", choosen);
		//printf("nrandom: %d\n", nrandom);
		choosen ++; 	
	}
	//printf("choosen: %d\n", choosen);
	return choosen;
}

int main (){
	
	char element[100], celement[100];
	int possibility, choosen,cont;
	printf("Hi! Im the number sorter, how many elements do you wanna sort?\n");
	scanf(" %d", &possibility);
	choosen = sorter(&possibility);
	printf("Type %d elements:\n", possibility);
	cont = 0;
	while(cont != possibility){		//Scan all elements then, stores the choosen one based on integer receive from sorter();
		scanf(" %[^\n]s", element);
		if(cont == choosen){
			strcpy(celement, element);
		}
		cont ++;
	}
	
	printf("Choosen element: %s\n", celement);
	
		
	
	
	
	
	return 0;
}
