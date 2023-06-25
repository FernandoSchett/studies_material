// Made by: Fernando Schettini Github: https://github.com/FernandoSchett
//This is a program made for pallet logistics
// In the end, all pallets have to be on X place
// Z can only have 6T pallets
// Y can only have 4T pallets
// X cant have heavier pallets on top of lighter pallets 
// we only have 9T,6T,4T, pallets

#include <stdio.h>
#include "stack.h"
#include "queue.h"

void finish(tp_stack *x, tp_stack *y, tp_stack *z){
	
	stack_stack( x, y);
	stack_stack( x, z);	
	
}

void pallets (int *w, tp_stack *x, tp_stack *y, tp_stack *z){
	// 9T pallets will be stacked at X.
	// 6T pallets will be stacked at Y.
	// 4T pallets will be stacked at Z.
	
	if(*w == 6){
		push(y, 6);
		printf("1\n");
	}
	if(*w == 4){
		push(z, 4);	
		printf("2\n");
	}
	if (*w == 9){
		push(x, 9);	
		printf("3\n");
	}	
}


int main (){
	int weight;
	tp_stack X, Y, Z;
	
	//Starting the Stacks.
	start_stack(&X);
	start_stack(&Y);
	start_stack(&Z);
	
	printf("Im the pallet operator, please inform the weight:\n");
	printf("Notes:\n- I will only accecpt 4T, 6T and 9T pallets.\n- If you're done, please type 0.");
	
	while(true){
		scanf(" %d", &weight); //storing weight from the user
		if(weight == 0){ // user said to stop.
			finish(&X, &Y, &Z);
			break;	
		}
		if( weight == 6 || weight == 4 || weight == 9){
			pallets(&weight, &X, &Y, &Z);
			printf("Please inform the next pallet weight:\n");
		}else{ // weight was != 6,4,9,0.
			printf("Invalid pallet weight, please type again:\n");
		}
	}
	
	
	printf("Thanks for using the pallet operator. : )\n");
	printf("Here is your pallet Stacks:\n");
	print_stack(X);
	return 0;
}
