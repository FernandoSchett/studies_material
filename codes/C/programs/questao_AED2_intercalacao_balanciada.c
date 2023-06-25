#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
typedef struct{
char info;
int pos;
}tp_ram;
void insertionSortram(tp_ram arr[], char n){
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
void insertionSortchar(char arr[], char n){
int i, key, j, k;
for (i = 1; i < n; i++)
{
key = arr[i];
j = i - 1;
}
while (j >= 0 && arr[j] > key)
{
arr[j + 1] = arr[j];
arr[j + 1] = arr[j];
j = j - 1;
}
arr[j + 1] = key;
}
int main(){
FILE *arq, *cam1, *cam2, *cam3, *arqfinal, *cam4, *cam5, *cam6, *afinal;
int i,j,k,o,cont, cont4,cont5,cont6,tam,z,primeira_vez,blocos_feitos,
passou,passou2, linha1 = 1,linha2 = 1,linha3 = 1,contador = 0, contadorbrabo = 0;
char frasedesorg[30],fraseorg[30], ram[3],teste[100], registro[100];
tp_ram memoria[3];
cam1 = fopen("fita1.txt", "w+");
cam2 = fopen("fita2.txt", "w+");
cam3 = fopen("fita3.txt", "w+");
cam4 = fopen("fita4.txt", "w+");
cam5 = fopen("fita5.txt", "w+");cam6 = fopen("fita6.txt", "w+");
afinal = fopen("arfinalbrabo.txt", "w+");
arq = fopen("fraseobj.txt", "r+");
fscanf (arq," %[^\n]s", frasedesorg);
printf("Frase do arquivo: %s\n", frasedesorg);
printf("O tamnho da string eh: %d\n", strlen(frasedesorg));
j = 1;
rewind(arq);
while(!feof(arq)){
if(!fgets(ram,sizeof(ram)+1,arq)){
break;
}
printf("Ram atual: %s\n", ram);
insertionSortchar(ram, strlen(ram));
printf("Ram atual org: %s\n", ram);
switch(j){
case 1:
fputs(ram, cam1);
j++;
break;
case 2:
fputs(ram, cam2);
j++;
break;
case 3:
fputs(ram, cam3);
j = 1;
break;
default:
printf("Deu merda na logica.\n");
break;
}
}
rewind(cam1);
rewind(cam2);
rewind(cam3);
printf("Aqui temos 3 caminhos.\n");
fscanf(cam1," %s", registro);
printf("string no cam1: %s\n", registro);
fscanf(cam2," %s", registro);
printf("string no cam2: %s\n", registro);
fscanf(cam3," %s", registro);
printf("string no cam3: %s\n", registro);
system("pause");
system("cls");
blocos_feitos = 0;
rewind(cam1);
rewind(cam2);
rewind(cam3);
//fclose(cam1);
//fclose(cam2);//fclose(cam3);
//cam4 = fopen("fita4.txt", "r");
//cam5 = fopen("fita5.txt", "r");
//cam6 = fopen("fita6.txt", "r");
rewind(cam1);
rewind(cam2);
rewind(cam3);
while(true){
if(!feof(cam1)){
memoria[0].info = fgetc(cam1);
memoria[0].pos = 1;
printf("Letra colocada dentro da ram: %c\n", memoria[0].info);
}else{
cont4 = 3;
}
if(!feof(cam2)){
memoria[1].info = fgetc(cam2);
memoria[1].pos = 2;
printf("Letra colocada dentro da ram: %c\n", memoria[1].info);
}else{
cont5 = 3;
}
if(!feof(cam3)){
memoria[2].info = fgetc(cam3);
memoria[2].pos = 3;
printf("Letra colocada dentro da ram: %c\n", memoria[2].info);
//printf("Final de arquivo: %d\n", feof(cam3));
}else{
//printf("SUPERSALVE\n");
cont6 = 3;
}
tam = 3;
cont = 0;
cont4 = 0;
cont5 = 0;
cont6 = 0;
passou = 0;
passou2 = 0;
while(true){
insertionSortram(memoria, tam);
//printf("blcosos fodas %d\n",blocos_feitos);
if(blocos_feitos == 0){
if(!(memoria[0].info == -1)){
fputc(memoria[0].info, cam4);
printf("Letra colocada no cam4: %c\
n",memoria[0].info);
}
}else{if(blocos_feitos == 1){
if(!(memoria[0].info == -1)){
fputc(memoria[0].info, cam5);
printf("Letra colocada no cam5: %c\
n",memoria[0].info);
}
}else
{
if(blocos_feitos == 2){
if(!(memoria[0].info == -1)){
fputc(memoria[0].info, cam6);
printf("Letra colocada no cam6:
%c\n",memoria[0].info);
}
}
}
}
//printf("blcosos fodas2 %d\n",blocos_feitos);
if(memoria[0].pos == 1){
cont4++;
}
if(memoria[0].pos == 2){
cont5++;
}
if(memoria[0].pos == 3){
cont6++;
}
if(cont4 == 3 && cont5 == 3 && cont6 == 3){
printf("FINAL DO BLOCO.\n");
break;
}else{
if(feof(cam1) && feof(cam2) && feof(cam3)){
printf("FINAL DO PROCESSO.\n");
break;
}
}
if(!(cont4 == 3 || cont5 == 3 || cont6 == 3)){
switch(memoria[0].pos){
case 1:
memoria[0].info = fgetc(cam1);
memoria[0].pos = 1;
break;
case 2:
memoria[0].info = fgetc(cam2);
memoria[0].pos = 2;
break;
case 3:
memoria[0].info = fgetc(cam3);
memoria[0].pos = 3;
break;
}
}else{
//printf("SALVE1\n");
if(cont4 == 3){
cont++;
}if(cont5 == 3){
cont++;
}
if(cont6 == 3){
cont++;
}
if(cont == 1){
//printf("SALVE2\n");
if(passou == 1){
switch(memoria[0].pos){
case 1:
memoria[0].info = fgetc(cam1);
memoria[0].pos = 1;
break;
case 2:
memoria[0].info = fgetc(cam2);
memoria[0].pos = 2;
break;
case 3:
memoria[0].info = fgetc(cam3);
memoria[0].pos = 3;
break;
}
}else{
memoria[0].info = memoria[1].info;
memoria[0].pos = memoria[1].pos;
memoria[1].info = memoria[2].info;
memoria[1].pos = memoria[2].pos;
tam = 2;
passou = 1;
}
}
if(cont == 2){
//printf("SALVE3\n");
if(passou2 == 1){
switch(memoria[0].pos){
case 1:
memoria[0].info = fgetc(cam1);
memoria[0].pos = 1;
break;
case 2:
memoria[0].info = fgetc(cam2);
memoria[0].pos = 2;
break;
case 3:
memoria[0].info = fgetc(cam3);
memoria[0].pos = 3;
break;
}
}else{
memoria[0].info = memoria[1].info;
memoria[0].pos = memoria[1].pos;
tam = 1;
passou2 = 1;
}
}}
//printf("CONTMASTER: %d\n", cont);
cont = 0;
}
blocos_feitos++;
if(feof(cam1) && feof(cam2) && feof(cam3) ){
break;
}
}
/////////////////////////////////////////////////////////////////////////////
///////////////////////////////
system("cls");
rewind(cam4);
rewind(cam5);
rewind(cam6);
tam = 3;
memoria[0].info = fgetc(cam4);
memoria[0].pos = 1;
printf("Letra colocada dentro da ram: %c\n", memoria[0].info);
memoria[1].info = fgetc(cam5);
memoria[1].pos = 2;
if(memoria[1].info == -1){
//memoria[1].info = memoria[0].info;
//linha2 = 0;
tam--;
}
printf("Letra colocada dentro da ram: %c\n", memoria[1].info);
memoria[2].info = fgetc(cam6);
memoria[2].pos = 3;
if(memoria[2].info == -1){
//memoria[2].info = memoria[1].info;
//memoria[1].info = memoria[0].info;
//linha3 = 0;
tam--;
}
printf("Letra colocada dentro da ram: %c\n", memoria[2].info);
printf("tam = %d\n", tam);
cont = 0;
cont4 = 0;
cont5 = 0;
cont6 = 0;
passou = 0;
passou2 = 0;
while(true){
//
printf("CONTS: %d %d %d\n", cont4,cont5,cont6);printf("Esta eh a ram:");
o = 0;
while(o != 3){
printf("%c", memoria[o].info);
o++;
}
printf("\n");
printf("Esta eh a pos dos char :");
o = 0;
while(o != 3){
printf("%d", memoria[o].pos);
o++;
}
printf("\n");
insertionSortram(memoria, tam);
printf("Esta eh a ram ordenada:");
o = 0;
while(o != 3){
printf("%c", memoria[o].info);
o++;
}
printf("\n");
printf("Esta eh a pos dos char ordenados:");
o = 0;
while(o != 3){
printf("%d", memoria[o].pos);
o++;
}
printf("\n");
printf("Este eh tam: %d\n", tam);
if(!(memoria[0].info == -1)){
fputc(memoria[0].info, afinal);
printf("Letra colocada no arcfinal: %c\
n",memoria[0].info);
cont++;
if(cont == strlen(frasedesorg)){
printf("ESSE EH O NUMERO DE CARACTER: %d",cont);
break;
}
}else{
break;
}
printf("esta eh memoria.pos : %d\n", memoria[0].pos);
system("pause");
switch(memoria[0].pos){
case 1:
if(linha1 != 0){memoria[0].info = fgetc(cam4);
memoria[0].pos = 1;
if(memoria[0].info == -1 || feof(cam4)){
printf("ACABOU A SEGUNDA LINHA\n");
linha1 = 0;
tam--;
}
}
break;
case 2:
if(linha2 != 0){
memoria[0].info = fgetc(cam5);
memoria[0].pos = 2;
if(memoria[0].info == -1|| feof(cam5)){
linha2 = 0;
tam--;
}
}
break;
case 3:
if(linha3 != 0|| feof(cam6)){
memoria[0].info = fgetc(cam6);
memoria[0].pos = 3;
if(memoria[0].info == -1){
linha3 = 0;
tam--;
}
}
break;
}
printf("tam = %d\n", tam);
if(tam == 1 && contadorbrabo == 0){
if(strlen(frasedesorg) <= 9){
contadorbrabo = 1;
}else{
printf("Salve2/n");
memoria[0].info = memoria[1].info;
memoria[0].pos = memoria[1].pos;
contadorbrabo = 1;
}
}
if(tam == 2 && contador == 0){
if(!(strlen(frasedesorg) <= 18)){
printf("Salve/n");
memoria[0].info = memoria[1].info;
memoria[0].pos = memoria[1].pos;
memoria[1].info = memoria[2].info;
memoria[1].pos = memoria[2].pos;
contador = 1;
}else{
contador = 1;
}
}
}fclose(arq);
fclose(cam1);
fclose(cam2);
fclose(cam3);
fclose(cam4);
fclose(cam5);
fclose(cam6);
fclose(afinal);
}
return 0;
