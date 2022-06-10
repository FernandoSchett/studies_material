#include "ArvB.h"

int main(int argc, char *argv[]){ 
	TipoRegistro x;
	TipoPagina *D;
	Inicializa(&D);
	printf("Chave: ");
	scanf("%ld%*[^\n]", &x.Chave);
	getchar();
	while (x.Chave != 0) { 
		Insere(x, &D);
	  	Imprime(D); 
		printf("Chave: ");
	  	scanf("%ld%*[^\n]", &x.Chave);
	  	getchar();
	}
	
    printf("Pesquisa-Chave: ");
	scanf("%ld%*[^\n]", &x.Chave);
	Pesquisa(&x, D);
	printf("%ld",x.Chave);
	getchar();
	
	
	
	printf("Chave: ");
	scanf("%ld%*[^\n]", &x.Chave);
	getchar();
	while (x.Chave != 0) { 
		Retira(x.Chave, &D);
	  	Imprime(D);
	  	printf("Chave: ");
	  	scanf("%ld%*[^\n]", &x.Chave);
	  	getchar();
	}
	return 0;
}


void TestaI(TipoApontador p, int pai, short direita){ 
	int i;
	int antecessor = 0;
	if (p == NULL) return;
	if (p->r[0].Chave > pai && direita == FALSE) 
	{ 
		printf("Erro: filho %12ld maior que pai %d\n", p->r[0].Chave, pai);
		return;
	}
	for (i = 0; i < p->n; i++) { 
		if (p->r[i].Chave <= antecessor) { 
			printf("Erro: irmao %ld maior que irmao a esquerda %d\n",
			(long)p->r[i].Chave, antecessor);
			return;
		}
		antecessor = p->r[i].Chave;
	}
	for (i = 0; i < p->n; i++) 
		TestaI(p->p[i], p->r[i].Chave, FALSE);
	TestaI(p->p[p->n], p->r[i].Chave, TRUE);
}

void Testa(TipoApontador p){ 
	int i;
	if (p == NULL) return;
	for (i = 0; i < p->n; i++) 
		TestaI(p->p[i], p->r[i].Chave, FALSE);
	TestaI(p->p[p->n], p->r[i].Chave, TRUE);
}

