// This is a library that works with MAX 99 elements capacity stacks. You can change that at line 8. 
// Made by: Fernando Schettini Github: https://github.com/FernandoSchett

#ifndef STACK_H 
#define STACK_H //indicates STACK_H Library start
//note: every .h arquive NEEDS to dont have a maiN fucntion.
#include <stdio.h> //added stdio.h library.
#define MAX 100 // every time "MAX" appears, compilator will read "100".

typedef int //Defining a new variable, tp_item. Doing this, you will be able to change tp_item types: int, float....
    tp_item;
    
    
typedef struct{
    int top;  // As a stack, it needs a  variable that indicates the top
    tp_item item[MAX];  // it needs a vector as well, for storing the variables.
} tp_stack;

void start_stack(tp_stack *s){ // Function that receives a stack then reset the top.
    s -> top = -1;
}

int empty_stack(tp_stack *s){  // Function that receive a stack, then verifies if its empty.
    if (s-> top == -1)
    	return 1; // Empty.
    return 0; // Not Empty.
}
}

int full_stack(tp_stack *s){ // Function that receive a stack, then verifies if its full.
    if (s->top == MAX-1){
        return 1; //Full.
    } else{
        return 0; //Not Full.
    }
}

int push(tp_stack *s, tp_item e){ // Function that receive a stack, and a element. It add the element at the top of the stack.
    if (full_stack(s)==1){
		return 0;  // You cant add and element if the stack is full.
	}
	s -> top++; 
    s -> item[s->top] = e; //Adds "e" at the stack top.
    return 1; // Success
}


int pop(tp_stack *s, tp_item *e){  // Function that receive a stack, and a element. It remove the element from the top, then stores it and "e".
    if (empty_stack(s)){
		return 0; //failure. you cant remove elements from a empty stack
	}
	*e = s-> item[s->top]; //Stores the element at "e"
    s -> top--;
    return 1; //Success
}

int top(tp_stack *s, tp_item *e){  // Function that receive a stack, and a element. It stores the top element at "e"
    if (empty_stack(s)){
		return 0; //Failure, empty stacks doesnt have a top element.
	}
	*e = s-> item[s->top];
    return 1; //Success
}

// You need to creat an copy from the orignal stack, to keep it originality.
void print_stack(tp_stack s){ // Function that receive a stack, then print it.
    tp_item e;
    printf("\n");
    while(!empty_stack(&s)){
        pop(&s, &e);
        printf("%d ", e);
    }
}

int stack_high(tp_stack *s){ // Function that receive a stack, then return its "high", how many elements are there.
    return s->top+1;
}

void remove_odds(tp_stack *s){  // Function that recieve a stack, then Remove all odds numbers from it.
    tp_stack saux; //Creating a new stack.
    start_stack(&saux);
    tp_item e;
    
    while(!empty_stack(s)){
        pop(s, &e);
        if(e%2==0){ // Stores only pair numbers.
        	push(&saux,e);
    	}
	} 

    while(!empty_stack(&saux)){ //Push Stored numbers at the original stack.
        pop(&saux, &e);
        push(s, e);
    } 
} 

void remove_pairs(tp_stack *s){ // Function that recieve a stack, then Remove all adds numbers from it. 
    tp_stack saux;
    start_stack(&saux);
    tp_item e;
    
    while(!empty_stack(s)){
        pop(s, &e);
        if(e%2!=0){ // Stores only odd numbers.
        	push(&saux,e);
        }
    } 

    while(!empty_stack(&saux)){ //Push Stored numbers at the original stack.
        pop(&saux, &e);
        push(s, e);
    } 
} 

int same_stack(tp_stack stack1, tp_stack stack2){ //This function will receive 2 stacks, then it will return "0" or "1", "0" == diff, "1" == equal.
    tp_item e1, e2;
    if (stack_high(&stack1) != stack_high(&stack2)){
        return 0; // they cant be the same stack if their high are diff. 
	}
	while(!empty_stack(&stack1)){
        pop(&stack1, &e1);
        pop(&stack2, &e2);
        if(e1 != e2){ // compare elements
            return 0;  // if the elements in the same position are diff, they are not the same.
    	}
		}
    return 1; 
}

int stack_stack (tp_stack *stack1, tp_stack *stack2){ //This fucntion will receive 2 stacks, then stack the second one at the first.
    tp_item e;
    tp_stack saux;
    start_stack(&saux);
    if (stack_high(stack1) + stack_high(stack2) > MAX){
        return 0;//fail, the new stack cant exceed MAX elements. 
    }
    while(!empty_stack(stack2)){
        pop(stack2, &e);
        push(&saux,e);
    }
    while(!empty_stack(&saux)){
        pop(&saux, &e);
        push(stack1,e);
    }
    return 1; //success.
}

#endif  // indicates STACK_H library ends
