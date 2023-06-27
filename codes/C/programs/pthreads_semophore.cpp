#include <semaphore.h>
#include <stdio.h>
#include "LIstaSEAlt.h"
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
sem_t db,mutex;
pthread_t tid;
pthread_t thread1,thread2,thread3,thread4,thread5; 
int pos = -1;
tp_listase *arquivo;
int rc=0;
void write_data_base() {
int valorAtual;
valorAtual = rand()%100;
if(valorAtual%2 == 0){
valorAtual = rand()%100;
printf("Valor sendo inserido: %d\n", valorAtual);
pos++; //incrementa posicoes ocupadas
insere_listase_no_fim( &arquivo, valorAtual);
 printf(">>> Inserindo: %d na posicao %d\n\n", valorAtual, pos);
}else{
printf("Deletando...\n\n");
if(listase_vazia(arquivo)){
printf("Lista vazia, nada para deletar\n\n");
}else{
remove_listase_no_fim(&arquivo);
printf("Deletando valor na posicao %d...\n\n", pos);
pos--;
}
}
}
void read_data_base() {
imprime_listase(arquivo);
}
void *reader(void* param){
while(1){
 sem_wait(&mutex);
 rc++;
 
if(rc==1) sem_wait(&db); 
 
sem_post(&mutex);
 printf("%d Esta lendo...\n", rc);
read_data_base();
//Sleep(500);
usleep(300000);
 sem_wait(&mutex);
 rc--;
 if(rc==0) sem_post(&db);
 sem_post(&mutex);
printf("%d Terminou de ler...\n\n",rc+1); 
 
 if(listase_vazia(arquivo)) printf("Lista vazia...\n\n");
}
 return NULL;
}
void *writer(void* param){
while(1){
 sem_wait(&db);
 write_data_base();
 //Sleep(500);
 sem_post(&db);
}
 return NULL;
}
int main(){
srand(time(NULL));
 sem_init(&mutex,0,1); // x
 sem_init(&db,0,1); // y
arquivo = inicializa_listase();
 
pthread_create(&thread1,NULL,reader,NULL);
 pthread_create(&thread2,NULL,reader,NULL);
 pthread_create(&thread3,NULL,reader,NULL);
pthread_create(&thread4,NULL,reader,NULL);
 pthread_create(&thread5,NULL,writer,NULL);
 
 
 pthread_join(thread1,NULL);
 pthread_join(thread2,NULL);
 pthread_join(thread3,NULL);
 pthread_join(thread4,NULL);
pthread_join(thread5,NULL);
}