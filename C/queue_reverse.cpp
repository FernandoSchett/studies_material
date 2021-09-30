// Made by: Fernando Schettini Github: https://github.com/FernandoSchett

// This program is gonna receive values, put then in a queue and then print it 
// with the values in their reverse order.
#include <stdio.h>
#include "stack.h"
#include "queue.h"


void reverse_queue(tp_queue *Q1){ //this fucntion is gonna reverse the order of the queue values.
	
	

	
}

int main(){
	int number;
	tp_queue Q1; 
	printf("How many values do you wanna put in the queue?\n");
	scanf(" %d", &number);
	start_queue(&Q1);
	fill_queue(&Q1, &number);
	reverse_queue(&Q1);
	printf("Reversed Queue:\n");
//	print_queue(&Q1);
	return 0;
}
