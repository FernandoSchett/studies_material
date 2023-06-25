//Alunos: Fernando Schettini, Bernando Serravale
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LETRAS 26
int a;
char armazem[100];
typedef struct tp_no {
char letra;
struct tp_no* filhos[LETRAS];
int eh_folha;
} tp_no;
int tem_filho(tp_no* raiz){
int i;
for (i = 0; i < LETRAS; i++)
if (raiz->filhos[i]){
return 1;
}
return 0;
}
void AutoComplete(tp_no *completar){
int japrintou = 0;
for (int i = 0; i < 26; i++){
if(completar != NULL){
//printf("caracter no do no %c \n", completar->letra);
if(completar->eh_folha == 1 ){
//if(completar->filhos[i] == NULL){
//
printf("Soussa\n");
//}
if(japrintou == 0){
printf("%s\n", armazem);
japrintou = 1;
}
if(!tem_filho(completar)){
japrintou = 0;
armazem[a] = '\0';
a--;
return;
}
}
//if(completar->filhos[i] == NULL){
//
printf("Soussa\n");
//}
if(!(completar->filhos[i] == NULL)){
armazem[a] = i + 'a';
armazem[a+1] = '\0';
a++;}
AutoComplete(completar->filhos[i]);
//printf("foracomplete\n");
}
}
armazem[a-1] = '\0';
//japrintou = 1;
a--;
return;
}
tp_no* cria_no(char letra) {
tp_no* no = (tp_no*) malloc (sizeof(tp_no));
int i;
if (no != NULL) {
no->eh_folha = 0;
no->letra = letra;
for (i=0; i<LETRAS; i++){
no->filhos[i] = NULL;
}
}
return no;
}
tp_no* insere_no_trie(tp_no* raiz, char* palavra) {
tp_no* no = raiz;
int tam = strlen(palavra);
int i;
//printf("salve1\n");
for (i=0; i < tam; i++) {
//printf("salve2\n");
//palavras est�o em mi n�sculo
int ind = (int) palavra[i] - 'a';
if (no->filhos[ind] == NULL) {
// printf("salve4\n");
no->filhos[ind] = cria_no(palavra[i]);
}
//printf("salve6\n");
no = no->filhos[ind];
}
no->eh_folha = 1;
return raiz;
}
int busca_no_trie(tp_no* raiz, char* palavra){
tp_no* no = raiz;
int tam = strlen(palavra);
int i;
for(i=0; i < tam; i++){
int pos = palavra[i] - 'a';
if (no->filhos[pos] == NULL)
return 0;
no = no->filhos[pos];
//constroi palavra
armazem[a] = palavra[i];
armazem[a+1] = '\0';
a++;}
if (no != NULL){
AutoComplete(no);
}
return 0;
}
int main(){
char resposta;
char palavrinha[100];
int tem;
tp_no *root ;
root = cria_no(NULL);
while(true){
printf("Digite C para cadastrar ou P para pesquisar.\n");
scanf(" %c", &resposta);
printf("Digite a palavra:\n");
scanf(" %s", palavrinha);
}
}
a = 0;
if(resposta == 'C'){
root = insere_no_trie(root, palavrinha);
}else{
if(resposta == 'P'){
busca_no_trie(root, palavrinha);
}
}
return 0;
