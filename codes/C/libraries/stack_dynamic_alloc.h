#include <stdio.h>
#include <stdlib.h>

typedef int tp_item; 

typedef struct tp_no_aux {   
  tp_item info;   
  struct tp_no_aux *prox;   
} tp_no; 


typedef struct {   
  tp_no *topo;   
} tp_pilha;


tp_pilha *inicializa_pilha (){
   tp_pilha *pilha=(tp_pilha*) malloc(sizeof(tp_pilha));   
   pilha->topo = NULL;   
   return pilha;
}  

int pilha_vazia (tp_pilha *pilha){   
 if (pilha->topo == NULL) return 1;
 return 0;
}

tp_no *aloca() {
	tp_no* pt;
	pt=(tp_no*) malloc(sizeof(tp_no));
	return pt;
}

int push (tp_pilha *pilha, tp_item e){   
  tp_no *novo;   
  novo=aloca();
  if (!novo) return 0;

  novo->info = e;  
  if ( pilha_vazia(pilha) ) { //Se for o primeiro elemento da lista
     novo->prox = NULL;   
     }  
  else {
     novo->prox = pilha->topo;   
     }  
  pilha->topo = novo; 
  return 1;   
}        


int pop (tp_pilha *pilha, tp_item *e){   
  tp_no *aux;

  if (pilha_vazia(pilha)) return 0;
  *e=pilha->topo->info;
  aux=pilha->topo;
  pilha->topo=pilha->topo->prox;
  free(aux);
  aux=NULL;
  return 1;   
}        

int top (tp_pilha *pilha, tp_item *e){   
  tp_no *aux;

  if (pilha_vazia(pilha)) return 0;
  *e=pilha->topo->info;
  return 1;   
}        



tp_pilha *destroi_pilha(tp_pilha *pilha) {    
	 tp_no *atu=pilha->topo, *aux;
     tp_item e;
	 while (atu != NULL)
	       {
			aux = atu->prox;
            pop(pilha, &e);  
			atu= aux; 
            }
	pilha->topo = NULL;
	free(pilha);
	return NULL;
}



void imprime_pilha(tp_pilha *pilha) {
     tp_pilha *pilha_aux;
     tp_item e;
     //cria e inicializa uma pilha auxiliar
	 pilha_aux=inicializa_pilha();
     
	 while (!pilha_vazia(pilha))
	       {
            pop(pilha,&e);
            printf("%d ", e);
            push(pilha_aux, e);           
            }
	
	while (!pilha_vazia(pilha_aux))
	       {
            pop(pilha_aux,&e);
            push(pilha, e);           
            }
     pilha_aux = destroi_pilha(pilha_aux);

}



