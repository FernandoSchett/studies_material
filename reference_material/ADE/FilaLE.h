#include <stdio.h>
#include <stdlib.h>

typedef int tp_item; 

typedef struct tp_no_aux {   
  tp_item info;   
  struct tp_no_aux *prox;   
} tp_no; 


typedef struct {   
  tp_no *ini, *fim;   
} tp_fila;


tp_fila *inicializa_fila (){
   tp_fila *fila=(tp_fila*) malloc(sizeof(tp_fila));   
   fila->ini=fila->fim = NULL;   
   return fila;
}  

tp_no *aloca() {
	tp_no* pt;
	pt=(tp_no*) malloc(sizeof(tp_no));
	return pt;
}

int fila_vazia (tp_fila *fila){   
 if (fila->ini == NULL) return 1;
 return 0;
}

int insere_fila (tp_fila *fila, tp_item e){   
  tp_no *novo;   
  novo=aloca();
  if (!novo) return 0;

  novo->info = e;  
  novo->prox = NULL;
  if ( fila_vazia(fila) ) { //Se for o primeiro elemento da lista
     fila->ini = novo;
     }  
  else {
     fila->fim->prox = novo; 
     }  
  fila->fim=novo;
  return 1;   
}        

int remove_fila (tp_fila *fila, tp_item *e){   
  tp_no *aux;

  if (fila_vazia(fila)) return 0;
  *e=fila->ini->info;
  aux=fila->ini;  

  if (fila->ini == fila->fim) //Se for o único nó da fila
     fila->ini=fila->fim=NULL;
  else
     fila->ini=fila->ini->prox;
     
  free(aux);
  return 1;   
}        


tp_fila *destroi_fila(tp_fila *fila) {
	 tp_no *atu=fila->ini;
	 tp_item e;
    
	 while (atu!=NULL)
	       {
            remove_fila(fila, &e);
            atu=atu->prox;
            }
     fila->ini=fila->fim=NULL;
	 free(fila);	 
	 return NULL;       
}

void imprime_fila(tp_fila *fila) {
     tp_fila *fila_aux;
     tp_item e;
     //cria e inicializa uma pilha auxiliar
	 fila_aux=inicializa_fila();
     
	 while (!fila_vazia(fila))
	       {
            remove_fila(fila,&e);
			printf("%d ", e);
            insere_fila(fila_aux, e);           
            }

     fila->ini = fila_aux->ini; 
     fila->fim = fila_aux->fim; 
     fila_aux->ini = NULL;
     fila_aux->fim = NULL;
     fila_aux = destroi_fila(fila_aux);
     printf("\n");

}


