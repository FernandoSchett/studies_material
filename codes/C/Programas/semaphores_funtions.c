/*
File:           semaphores_funtions.c
Last changed:   25/06/20 16:05
Purpose:        functions used ate gcc semaphores_win.c code.
Authors:        ?????
Usage: 
	HowToCompile:   gcc semaphores_win.c -o semaphores_win
	HowToExecute:   ./semaphores_win  
*/


#include "semaphoreswindows.h"

// Variaveis globais

extern t_fila * raiz;
extern t_fila * aux;
extern int sequenciaArquivo;
extern int pos;

extern LONG lInsArqTId;
extern LONG lImpArqTId;

extern HANDLE mutex;				// mutex - Sem�foro Bin�rio {0, 1}
extern HANDLE posicoesOcupadas;	// Sem�foros Sincronizadores de eventos
extern HANDLE posicoesLivres;	// Sem�foros Sincronizadores de eventos

/**
    Insere arquivo no spool
*/
void insereArquivo() {
	t_fila * novo;
	while(1) {

        novo = (t_fila *) malloc(sizeof(t_fila));
		novo->prox = NULL;

        DOWN(posicoesLivres);
		LOCK(mutex); //Trava a RC
        Sleep(150);
		geraNomeArquivo(novo->Arquivo);
		aux = raiz;
		if (raiz == NULL)
        {
			raiz = novo;
		}
		else
        {
			while(aux->prox != NULL) {
				aux= (t_fila *) aux->prox;
			}
			aux->prox = novo;
		}
		pos++; 			//incrementa posicoes ocupadas

        printf("\n>>> Inserindo: %s na posicao %d", novo->Arquivo, pos);

        UNLOCK(mutex);  //Libera a RC
        Sleep(1);
		UP(posicoesOcupadas);
	}
}


void imprimeArquivo() {
	while(1) {
		DOWN(posicoesOcupadas);  //Elimina a Espera Ocupada
		LOCK(mutex);   //Trava a RC

		Sleep(200); // Simula o tempo de impress�o
		aux = raiz;
		printf("\n... Imprimindo: %s ", aux->Arquivo);
		raiz = aux->prox;
		free(aux);
		UNLOCK(mutex);  //Libera a RC
		UP(posicoesLivres);
		Sleep(2); // Simula o tempo de impress�o
	}
}


void geraNomeArquivo(char *string) {
    char *tmp;
	char seq[10];

    tmp = string;

	strcpy(tmp, "Arquivo ");
	itoa(sequenciaArquivo++, seq, 10);
	strcat(tmp, seq);
}

/*
Opera��es sobre sem�foros
*/

void DOWN(HANDLE h) {
	WaitForSingleObject(h, INFINITE);
}

void UP(HANDLE h) {
	ReleaseSemaphore(h, 1, NULL);
}

void LOCK(HANDLE h) {
	WaitForSingleObject(h, INFINITE);
}

void UNLOCK(HANDLE h) {
    ReleaseMutex(h);
}


