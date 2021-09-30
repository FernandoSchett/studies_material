// This is a library that works with MAX 99 elements capacity queues. 
// Made by: Fernando Schettini Github: https://github.com/FernandoSchett
// Queues here  are "FIFO" (First IN, First OUT)

#ifndef QUEUE_H   
#define QUEUE_H   //indicates QUEUE_H library start

#include <stdio.h> //added stdio.h library.
#define MAX 100 // every time "MAX" appears, compilator will read "100".

typedef int tp_item; //Defining a new variable, tp_item. Doing this, you will be able to change tp_item types: int, float....

typedef struct{  //Defining a new variable, tp_queue.
    tp_item item[MAX];			// As a queue, it needs a vector, for storing the variables.
    int start, end;				// It needs 2 integers as well, they indicades where the queue starts and where it ends.
    int size;					// finally, it need a integer that keeps  the queue size.
} tp_queue;		

void queue_starter(tp_queue *f){ // Function that receives a queue then reset start, size and end. 
	
    f -> start = f -> end = MAX-1;
    f -> size = 0;
    
}

int empty_queue(tp_queue *f){ // Function that receive a queue, then verifies if its empty.
	
    if(f -> start == f-> fim){
		return 1; //"1" == Success
	}
    return 0; // "0" == Failure
    
}

int next(int pos){ //Function that receives a integer then returns the next interger. Used for returning next queue elements positions. 
	
    if(pos >= MAX -1){ // It will fall for pos >= 99, cuz an queue element position cannot be at 100th position.
		return 0; //0 = failure
	}
    return ++pos; 			//note: "++pos" != "pos++"

}

int full_queue(tp_queue *f){ //Function that receives a queue and verifies if its full.
	
    if(next(f -> end) == f -> start){
        return 1;
    }
    return 0;

	// 0 = not full.
	// 1 = full.
}

int queue_insert(tp_queue *f, tp_item e){ //Function that receives a queue and a integer
    
	if(full_queue(f)){
		return 0; //failure,you cant add elements from a full queue.
	}
	f -> end = next(f -> end);
    f -> item[f->end] = e;
    f -> size++;
    return 1; //success.

}

int queue_remove(tp_queue *f, tp_item *e){ //Function that receives a queue and a integer, it will remove the queue first element and keep that value with integer "e"
	
    if(empty_queue(f)){
		return 0; //failure,you cant remove elements from a empty queue.
	}	
    f -> start = proximo(f->start);
    *e = f -> item[f->start];
    f -> size--;
    return 1; //success.
    
}

// You need to creat an copy from the orignal queue, to keep it originality.
void queue_printer(tp_queue f){ //Function that receives a queue and print all elements.

    tp_item e;
    while(!empty_queue(&f)){
        queue_remove(&f, &e);
        printf(" %d", e);
    }
    
}

int queue_size(tp_queue *f){ //Function that receives a queue, and return its size.
	
    return f -> size;
    
}


#endif // indicates QUEUE_H library ends

