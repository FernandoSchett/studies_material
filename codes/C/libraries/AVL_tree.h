#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct NO* ArvAVL;

struct NO{
   struct NO *esq;
   int info;
   int alt; //altura da sub-árvore (facilita o cálculo do fator de balanceamento!)
   struct NO *dir;
};

ArvAVL* criarAVL();
void preOrd(ArvAVL* raiz);
void emOrd(ArvAVL* raiz);
void posOrd(ArvAVL* raiz);
int inserir(ArvAVL* raiz, int valor);
int remover(ArvAVL* raiz, int valor); // Responsável pela busca do nó a ser removido
struct NO* buscarMenor(struct NO* atual); // Busca o nó mais a esquerda de uma árvore
int consultarValorAVL(ArvAVL* raiz, int valor);
int maior(int x, int y);
int alt_NO(struct NO* no);
int fb_NO(struct NO* no);
void RotacaoLL(ArvAVL* raiz);
void RotacaoRR(ArvAVL* raiz);
void RotacaoRL(ArvAVL* raiz);
void RotacaoLR(ArvAVL* raiz);

int contPrint=0;

ArvAVL* criarAVL(){
	ArvAVL* raiz = (ArvAVL*)malloc(sizeof(ArvAVL));
	if(raiz!=NULL){
		*raiz = NULL;
	}
	return raiz;
}
void preOrd(ArvAVL* raiz){
   if(raiz==NULL) return;
   if(*raiz != NULL){
   	  if(contPrint!=0){
	     printf(" ");	 
	  }
      printf("%d", (*raiz)->info);
      contPrint++;
      preOrd(&((*raiz)->esq));
      preOrd(&((*raiz)->dir));
   }
}

void emOrd(ArvAVL* raiz){
   if(raiz==NULL) return;
   if(*raiz != NULL){
   	  //printf("Contador:%d", contPrint);
      emOrd(&((*raiz)->esq));
   	  if(contPrint!=0){
	     printf(" ");	 
	  }
      printf("%d", (*raiz)->info);
      contPrint++;
      emOrd(&((*raiz)->dir));
   }
}

void posOrd(ArvAVL* raiz){
   if(raiz==NULL) return;
   if(*raiz != NULL){
      posOrd(&((*raiz)->esq));
      posOrd(&((*raiz)->dir));
   	  if(contPrint!=0){
	     printf(" ");	 
	  }
      printf("%d", (*raiz)->info);
      contPrint++;
   }
}


int alturaAVL(ArvAVL* raiz){
	if(raiz == NULL) return 0;
	if(*raiz == NULL) return 0;
	int alt_esq = alturaAVL(&((*raiz)->esq));
	int alt_dir = alturaAVL(&((*raiz)->dir));
	if(alt_esq > alt_dir){
		return alt_esq + 1;
	}else{
		return alt_dir + 1;
	}
}

int totalNOsABB(ArvAVL* raiz){
	if(raiz == NULL) return 0;
	if(*raiz == NULL) return 0;
	int tot_esq = totalNOsABB(&((*raiz)->esq));
	int tot_dir = totalNOsABB(&((*raiz)->dir));
	return (tot_esq + tot_dir + 1);
}

int estah_vaziaABB(ArvAVL* raiz){
	if(raiz==NULL) return 1;
	if(*raiz == NULL) return 1;
	return 0;
}	

int inserir(ArvAVL* raiz, int valor){	
	int res;
	if(*raiz==NULL){
		struct NO* novo;
		novo = (struct NO*)malloc(sizeof(struct NO));
		if(novo==NULL) return 0;
		novo->info = valor;
		novo->alt = 0;
		novo->dir = NULL;
		novo->esq = NULL;
		*raiz = novo;
		return 1;	
	} else {
		struct NO* atual = *raiz;
		if(valor < atual->info){
			if((res=inserir(&(atual->esq), valor))==1){
				if(fb_NO(atual) >= 2){
					if(valor < (*raiz)->esq->info){
						RotacaoLL(raiz);
					}else{
						RotacaoLR(raiz);
					}
				}
			}
		}else{
			if(valor > atual->info){
				if((res=inserir(&(atual->dir), valor))==1){
					if(fb_NO(atual) >= 2){
						if(valor > (*raiz)->dir->info){
							RotacaoRR(raiz);
						}else{
							RotacaoRL(raiz);
						}
					}
				}
			}else{
				return 0; // Valor Duplicado
			}
		}
		atual->alt = maior(alt_NO(atual->esq), alt_NO(atual->dir)) + 1;
		return res;
	} 
}

void liberaNO(struct NO* no){
   if(no==NULL) return;
   liberaNO(no->esq);
   liberaNO(no->dir);
   free(no);
   no = NULL;
}

void liberaABB(ArvAVL* raiz){
   if(raiz==NULL) return;
   liberaNO(*raiz);
   free(raiz);
}

int consultarValorAVL(ArvAVL* raiz, int valor){
	if(raiz == NULL) return 0;
	if(*raiz == NULL) return 0;
	struct NO* atual = *raiz;
	while(atual != NULL){
		if(atual->info == valor){
			return 1;
		}else{
			if(atual->info > valor){
				atual = atual->esq;
			}else{
				atual = atual->dir;
			}
		}
	}
	return 0;
}

int alt_NO(struct NO* no){
   if(no == NULL) return -1;
   else return no->alt;
}

int fb_NO(struct NO* no){
	int esq = alt_NO(no->esq);
	int dir = alt_NO(no->dir);
	return labs(esq - dir);
}

int maior(int x, int y){
	return (x>y)?x:y;
}

void RotacaoLL(ArvAVL* raiz){
   struct NO* no;
   no = (*raiz)->esq;
   (*raiz)->esq = no->dir;
   no->dir = *raiz;
   (*raiz)->alt = maior(alt_NO((*raiz)->esq), alt_NO((*raiz)->dir)) + 1;
   no->alt = maior(alt_NO(no->esq), (*raiz)->alt) + 1;
   *raiz = no;
}

void RotacaoRR(ArvAVL* raiz){
   struct NO* no;
   no = (*raiz)->dir;
   (*raiz)->dir = no->esq;
   no->esq = *raiz;
   (*raiz)->alt = maior(alt_NO((*raiz)->esq), alt_NO((*raiz)->dir)) + 1;
   no->alt = maior(alt_NO(no->dir), (*raiz)->alt) + 1;
   *raiz = no;
}

void RotacaoLR(ArvAVL* raiz){
	RotacaoRR(&(*raiz)->esq);
	RotacaoLL(raiz);
}

void RotacaoRL(ArvAVL* raiz){
	RotacaoLL(&(*raiz)->dir);
	RotacaoRR(raiz);
}

int remover(ArvAVL* raiz, int valor){	
	int res;
	if(*raiz==NULL){ // Valor não encontrado!
		printf("Valor %d nao encontrado na árvore!", valor);
		return 0;	
	} 
	if(valor < (*raiz)->info){
		if((res=remover(&(*raiz)->esq, valor))==1){
			if(fb_NO(*raiz) >= 2){
				if(alt_NO((*raiz)->dir->esq) <= alt_NO((*raiz)->dir->dir)){
					RotacaoRR(raiz);
				}else{
					RotacaoRL(raiz);
				}
			}
		}				
	}else if(valor > (*raiz)->info){
		if((res=remover(&(*raiz)->dir, valor))==1){
			if(fb_NO(*raiz) >= 2){
				if(alt_NO((*raiz)->esq->dir) <= alt_NO((*raiz)->esq->esq)){
					RotacaoLL(raiz);
				}else{
					RotacaoLR(raiz);
				}
			}
		}							
	}else{ // raiz->info == valor...
		if(((*raiz)->esq == NULL) || ((*raiz)->dir == NULL)){ // O Pai tem 1 ou nenhum filho
			struct NO* noVelho = (*raiz);
			if((*raiz)->esq != NULL) *raiz = (*raiz)->esq;
			else *raiz = (*raiz)->dir;
			free(noVelho);
			return 1;
		}else{ // o nó tem 2 filhos: precisamos substituir pelo nó mais a esquerda da subárvore da direita
			struct NO* temp = buscarMenor((*raiz)->dir);
			(*raiz)->info = temp->info;
			remover(&(*raiz)->dir, (*raiz)->info);
			if(fb_NO(*raiz) >= 2){
				if(alt_NO((*raiz)->esq->dir) <= alt_NO((*raiz)->esq->esq)){
					RotacaoLL(raiz);
				}else{
					RotacaoLR(raiz);
				}
			}
			return 1;			
		}
		return res;
	} 
}

struct NO* buscarMenor(struct NO* atual){
	struct NO* no1 = atual;
	struct NO* no2 = atual->esq;
	while(no2 != NULL){
		no1 = no2;
		no2 = no1->esq;
	}
	return no1;
}

