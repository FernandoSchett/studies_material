// Made by: Fernando Schettini Github: https://github.com/FernandoSchett

// This program is gonna receive values, put then in a queue and then print it 
// with the values in their reverse order.
#include <stdio.h>
#include "stack.h"
#include "queue.h"


void reverse_queue(tp_queue *Q1){ //this fucntion is gonna reverse the order of the queue values.
	tp_item element;
	tp_stack saux;
	start_stack(&saux);
	while(!empty_queue(Q1)){
		queue_remove(Q1, &element);
		push(&saux, element);
	}
	while(!empty_stack(&saux)){
		pop(&saux, &element);
		queue_insert(Q1, element);
	}	
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
	print_queue(Q1);
	return 0;
}
