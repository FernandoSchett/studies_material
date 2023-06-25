/*
EQUIPE:
Fernando Antonio Marques Schettini
Joao Marcelo Miranda
Joao Vitor Mendes Pinto do Santos
Gabriel Claudino
OBS: O codigo nao usa nenhuma teoria de arvores.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define TRUE 1
typedef struct{
char info;
int pos;
int marcador;
}tp_ram;
void insertionSort(char arr[], int n){
int i, key, j, k;
for (i = 1; i < n; i++)
{
key = arr[i];
j = i - 1;
while (j >= 0 && arr[j] > key)
{
arr[j + 1] = arr[j];
j = j - 1;
}
arr[j + 1] = key;
}
}
void insertionSortRam(tp_ram arr[], int n){
int i, key, j, k,keypos;
for (i = 1; i < n; i++)
{
key = arr[i].info;
keypos = arr[i].pos;
j = i - 1;
while (j >= 0 && arr[j].info > key)
{
arr[j + 1].info = arr[j].info;
arr[j + 1].pos = arr[j].pos;
j = j - 1;
}
arr[j + 1].info = key;
arr[j + 1].pos = keypos;
}
}
void print_ram(tp_ram arr[]){
int i;
for(i = 0; i<3; i++){
printf("%c", arr[i].info);
}printf("\n");
}
void troca(tp_ram arr[], int TAM){
tp_ram aux = arr[0];
arr[0] = arr[TAM];
arr[TAM] = aux;
}
int main(void){
= 0;
FILE *arq, *fitas[4], *aux, *frasefinal;
int trocas, i = 0, j, k = 0, tam = 0, valor = 0, lolo=0, arquivos =0, h=0,atu
tp_ram memoria[3];
arq = fopen("frase.txt", "r");
fitas[0] = fopen("fita1.txt", "w+");
fitas[1] = fopen("fita2.txt", "w+");
fitas[2] = fopen("fita3.txt", "w+");
fitas[3] = fopen("fita4.txt", "w+");
//OUTOUT ESPERADO (SOMENTE PARA CONSULTA RÁPIDA):
char fraseEsperada[30];
fgets(fraseEsperada, sizeof(fraseEsperada),arq);
insertionSort(fraseEsperada, strlen(fraseEsperada));
printf("Output esperado: %s\n", fraseEsperada);
rewind(arq);
//OUTOUT ESPERADO FINALIZADO.
while(i != 3){
memoria[i].info = fgetc(arq);
memoria[i].pos = 0;
memoria[i].marcador = 0;
if(memoria[i].info == -1){
memoria[i].info = 126;
tam--;
memoria[i].marcador = 1;
}
i++;
tam++;
}
j = 0;
while(TRUE){
if(memoria[0].info == 126 && memoria[1].info == 126 && memoria[2].info
== 126){
printf("Arquivo finalizado\n");
break;
}
////
printf("Memoria RAM:");
print_ram(memoria);
printf("Tamanho: %d\n",tam);
insertionSortRam(memoria, tam);
printf("Memoria RAM Ordenada:");
print_ram(memoria);
system("pause");
////fputc(memoria[0].info, fitas[atu]);
printf("Este e o caracter colacado na fita: %c\n", memoria[0].info);
valor = memoria[0].info;
memoria[0].info = fgetc(arq); //LENDO O PROXIMO CARACTER
if(memoria[0].info == -1){
memoria[0].info = 126;
//printf("TAMANHO -- 1\n");
tam--;
memoria[0].marcador = 1;
troca(memoria, tam);
}
printf("Este e o caracter retirado na fita: %c\n",memoria[0].info);
if(memoria[0].info < valor){
memoria[0].marcador = 1;
//MARCANDO POR SER UM CARACT. MENOR
printf("Caracter Marcado: %c\n",memoria[0].info );
//printf("TAMANHO -- 2\n");
tam--;
troca(memoria, tam);
}
printf("tamanho denovo: %d\n", tam);
if(tam == 0){
tam = 3;
for(i = 0; i< tam; i++){
if(memoria[i].info != 126){
memoria[i].marcador = 0;
}else{
tam--;
//printf("sexo\n");
troca(memoria, tam);
}
}
//printf("este eh atu: %d\n", atu);
fputc('~', fitas[atu]);
}
j++;
//printf("CHGEUEI AQUI PORRA: %d\n", j);
atu++;
if(atu == 3){
atu = 0;
}
}
system("cls");
memoria[0].info = 0;
i = 0;
while(i != 4){
rewind(fitas[i]);
i++;
}
//system("cls");
k = 3;
tam = 0;
arquivos = j;
printf("Quantidade de blocos fomardos: %d\n", j);
trocas = 1;
while(1){if(arquivos < 0 && (j == 8 || j == 7) && trocas == 1){
printf("Fitas trocadas.\n");
rewind(fitas[k]);
fclose(fitas[1]);
fitas[1] = fopen("fita2.txt", "w+");
aux = fitas[k];
fitas[k] = fitas[1];
fitas[1] = aux;
trocas = 0;
}
while(tam!=3){
memoria[tam].info = fgetc(fitas[tam]);
printf("Este e o caracter retirado na fita1: %c\
n",memoria[tam].info);
memoria[tam].pos = tam;
memoria[tam].marcador = 0;
if(memoria[tam].info == -1){
memoria[tam].marcador = 1;
memoria[tam].info = '~';
}
tam++;
}
///
printf("Memoria RAM:");
print_ram(memoria);
printf("Tamanho: %d\n",tam);
insertionSortRam(memoria, tam);
printf("Memoria RAM Ordenada:");
print_ram(memoria);
printf("Tamanho: %d\n",tam);
system("pause");
///
if(memoria[0].marcador == 1 && memoria[1].marcador == 1 &&
memoria[2].marcador == 1 ){
if(j % 3 == 0 && j != 3){
fclose(fitas[0]);
fitas[0] = fopen("fita1.txt", "w+");
fclose(fitas[1]);
fitas[1] = fopen("fita2.txt", "w+");
fclose(fitas[2]);
fitas[2] = fopen("fita3.txt", "w+");
rewind(fitas[k]);
while(true){
memoria[0].info = fgetc(fitas[k]);
if(memoria[0].info == -1){
break;
}
fputc(memoria[0].info, fitas[h]);
if(memoria[0].info == '~'){
h++;
}
}
fclose(fitas[k]);
fitas[k] = fopen("fita4.txt", "w+");
arquivos = 3;
tam = 0;rewind(fitas[0]);
rewind(fitas[1]);
rewind(fitas[2]);
j = 3;
}else{
break;
}
}else{
fputc(memoria[0].info, fitas[k]);
printf("Este e o caracter colacado na fita: %c\
n",memoria[0].info);
memoria[0].info = fgetc(fitas[memoria[0].pos]);
printf("Este e o caracter retirado na fita: %c\
n",memoria[0].info);
if(memoria[0].info == '~' && memoria[1].info == '~' &&
memoria[2].info == '~'){
printf("Bloco finalizado\n");
arquivos = arquivos - 3;
fputc('~', fitas[k]);
tam = 0;
printf("Arquivos: %d ggggggggggggggggggggggggggggggg\n",
arquivos);
if(arquivos == 1 || arquivos == 2){
printf("Fitas trocadas.\n");
rewind(fitas[k]);
fclose(fitas[2]);
fitas[2] = fopen("fita3.txt", "w+");
aux = fitas[k];
fitas[k] = fitas[2];
fitas[2] = aux;
}
}
}
}
printf("Output esperado: %s\n", fraseEsperada);
printf("Fita foda: %d", k);
rewind(fitas[k]);
frasefinal = fopen("frasefinal.txt", "w+");
while(true){
memoria[0].info = fgetc(fitas[k]);
if(memoria[0].info == '~' ){
break;
}
fputc(memoria[0].info, frasefinal);
}
i = 0;
while(i != 4){
fclose(fitas[i]);
i++;
}
fclose(arq);
fclose(frasefinal);
return 0;
}
