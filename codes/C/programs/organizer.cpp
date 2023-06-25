//This program will fill up a queue char. After that, it will analyse if the element is a number, or a letter.
//It will print the new organized queue, with letters first and number after, in reverse order.
// Made by: Fernando Schettini Github: https://github.com/FernandoSchett

#include <stdio.h>
#include "stack-char-version.h"
#include "queue-char-version.h"
#include <ctype.h>

void organizer(tp_queue *q){
	tp_queue letters;
	tp_stack numbers;
	start_queue(&letters);
	start_stack(&numbers);
	print_queue(*q);
	char element;
	//Analyse every element of the queue, in the process it emptys it.
	while(!empty_queue(q)){

		queue_remove(q, &element);
		if(isdigit(element)){ //its a number.
			push(&numbers, element);//stores at a letter queue.	
		}
		if(!isdigit(element)){ //its a letter
			queue_insert(&letters, element); //stores at a number stack.
		}
	}

	
	//Now, we need to put then back, in ther order (letters -> numbers)
	while(!empty_queue(&letters)){
		queue_remove(&letters, &element);
		queue_insert(q, element);
	}
	while(!empty_stack(&numbers)){
		pop(&numbers, &element);
		queue_insert(q, element);
	}
	
}
int main (){
	int value;
	tp_queue queue;
	start_queue(&queue);
	printf("Im the queue, organizer! Please, type the number of elements you wanna put in the queue:");
	scanf(" %d", &value);
	fill_queue(&queue, &value);
	organizer(&queue);
	printf("Heres your new queue:\n");
	print_queue(queue);
	return 0;
}
