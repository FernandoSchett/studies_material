/*This is a program that will receive a lista of elements, then chossen randomly one of then. Chances are the same for eaach element recieve.
Fernando Schettini (o mais foda) Github:https://github.com/FernandoSchett */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


int sorter(int *possb){
	int random, nrandom, choosen;
	long double	chance;
	
	srand(time (NULL)); //Generate seed for rand(),based in your pc time.
	//printf("%d\n", *possb);
	random = (rand() % 100); //Generate random number in range 1-100.
	//printf("random: %d\n", random);
	chance =  100 / *possb; //chance of getting any number.
	//printf("chance: %lf \n", chance);
	
	
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
	int possibility, choosen;
	printf("Hi! Im the number sorter, how many elements do you wanna sort?\n");
	scanf(" %d", &possibility);
	choosen = sorter(&possibility);
	
	while(possibility > 0){		//Scan all elements then, stores the choosen one based on integer receive from sorter();
		scanf(" %[^n]s", element);
		if(possibility == choosen){
			strcpy(celement, element);
		}
		possibility --;
	}
	
	printf("Choosen element: %s\n", celement);
	
		
	
	
	
	
	return 0;
}
