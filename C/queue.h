// Made by: Fernando Schettini Github: https://github.com/FernandoSchett

#ifndef QUEUE_H   
#define QUEUE_H   

#include <stdio.h> 
#define MAX 100 

typedef int tp_item; 

typedef struct{  
    tp_item item[MAX];			
    int start, end;				
    int size;					
} tp_queue;		

void queue_starter(tp_queue *f){ 
	
    f -> start = f -> end = MAX-1;
    f -> size = 0;
    
}

int empty_queue(tp_queue *f){ 
	
    if(f -> start == f-> fim){
		return 1; 
	}
    return 0; 
    
}

int next(int pos){ 
	
    if(pos >= MAX -1){ 
		return 0; 
	}
    return ++pos; 			

}

int full_queue(tp_queue *f){ 
	
    if(next(f -> end) == f -> start){
        return 1;
    }
    return 0;


}

int queue_insert(tp_queue *f, tp_item e){ 
    
	if(full_queue(f)){
		return 0; 
	}
	f -> end = next(f -> end);
    f -> item[f->end] = e;
    f -> size++;
    return 1; 

}

int queue_remove(tp_queue *f, tp_item *e){
	
    if(empty_queue(f)){
		return 0; 
	}	
    f -> start = proximo(f->start);
    *e = f -> item[f->start];
    f -> size--;
    return 1; 
    
}

void queue_printer(tp_queue f){ 

    tp_item e;
    while(!empty_queue(&f)){
        queue_remove(&f, &e);
        printf(" %d", e);
    }
    
}

int queue_size(tp_queue *f){ 
	
    return f -> size;
    
}


#endif 

