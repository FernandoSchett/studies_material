// This is a library that works with MAX 99 elements capacity stacks. You can change that at line 8. 
// Made by: Fernando Schettini Github: https://github.com/FernandoSchett

#ifndef STACK_H 
#define STACK_H 



#include <stdio.h> 
#define MAX 100 

typedef int 
    tp_item;

typedef struct{
    int top;  
    tp_item item[MAX];  
} tp_stack;

void start_stack(tp_stack *s){ 
    s -> top = -1;
}

int empty_stack(tp_stack *s){ 
    if (s-> top == -1)
        return 1; 
    return 0; 
}

int full_stack(tp_stack *s){ 
    if (s->top == MAX-1){
        return 1; 
    } else{
        return 0; 
    }
}

int push(tp_stack *s, tp_item e){ 
    if (full_stack(s)==1){
		return 0; 
	}
	s -> top++; 
    s -> item[s->top] = e; 
    return 1; 
}


int pop(tp_stack *s, tp_item *e){  
    if (empty_stack(s)){
		return 0; 
	}
	*e = s-> item[s->top]; 
    s -> top--;
    return 1;
}

int top(tp_stack *p, tp_item *e){ 
    if (empty_stack(s){
		return 0; 
	}
	*e = s-> item[s->top];
    return 1; 
}


void print_stack(tp_stack s){ 
    tp_item e;
    printf("\n");
    while(!empty_stack(&s)){
        pop(&s, &e);
        printf("%d ", e);
    }
}

int stack_high(tp_stack *s){ 
    return s->top+1;
}

void remove_odds(tp_stack *s){  
    tp_pilha saux; 
    start_stack(&saux);
    tp_item e;
    
    while(!empty_stack(s)){
        pop(s, &e);
        if(e%2==0){ 
        	push(&saux,e);
    	}
	} 

    while(!empty_stack(&saux)){ 
        pop(&saux, &e);
        push(s, e);
    } 
} 

void remove_pairs(tp_stack *s){  
    tp_stack saux;
    start_stack(&saux);
    tp_item e;
    
    while(!empty_stack(s)){
        pop(s, &e);
        if(e%2!=0){ 
        	push(&saux,e);
        }
    } 

    while(!empty_stack(&saux)){ 
        pop(&saux, &e);
        push(s, e);
    } 
} 

int same_stack(tp_stack stack1, tp_stack stack2){ 
    tp_item e1, e2;
    if (stack_high(&stack1) != stack_high(&stack2)){
        return 0; 
	}
	while(!empty_stack(&stack1)){
        pop(&stack1, &e1);
        pop(&stack2, &e2);
        if(e1 != e2){ 
            return 0; 
    	}
		}
    return 1; 
}

int stack_stack (tp_stack *stack1, tp_stack *stack2){ 
    tp_item e;
    start_stack(&saux);
    if (stack_high(stack1) + stack_high(stack2) > MAX){
        return 0; 
    }
    while(!empty_stack(stack2)){
        pop(stack2, &e);
        push(&saux,e);
    }
    while(!empty_stack(&saux)){
        pop(&saux, &e);
        push(stack1,e);
    }
    return 1; 
}

#endif  
