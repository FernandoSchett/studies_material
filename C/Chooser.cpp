// Made by: Fernando Schettini Github: https://github.com/FernandoSchett

// This program is gonna receive 15 values, if the number is pair, its gonna be stored at the queue
// if the read number if odd, it will remove the last number stored. If the queue is empty, show a message instead.
#include <stdio.h>
#include "stack.h"
//#include "queue.h"

typedef struct{  // New Queue, MAX elements numbers == 5.
    tp_item item[6];			
    int start, end;				
    int size;					
} tp_data;	

void start_data(tp_dados *f){ 
	
    f -> start = f -> end = 5;
    f -> size = 0;
    
}

int main(){
	tp_item value, cont, element;
	tp_data Q1;
	start_data(&Q1);
	cont = 0;
	while(cont < 5){
		scanf(" %d", value);
		if(value%2 == 0){ //pair, so keep it on the queue.
			if(full_queue(&Q1)){ 
				queue_remove(&Q1, element);
				queue_insert(&Q1,value);
			}else{
				queue_insert(&Q1,value);
			}
		}else{ //odd
			if(empty_queue(&Q1)){
				print("The queue is empty.");
			}
			else{
				queue_remove(&Q1, element);	
			}
		
		}
		cont++;
	}
	
	return 0;
}


