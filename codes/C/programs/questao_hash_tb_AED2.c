#include <stdio.h>
#define TAM 10000
#include <math.h>
#include <stdlib.h>
typedef struct{
int ID;
int idade;
char nome[100];
}tp_pet;
typedef tp_pet tp_item;
typedef struct tp_no{
struct tp_no *esq;
tp_item info;
struct tp_no *dir;
} tp_no;
typedef tp_no * tp_arvore;
tp_arvore inicializa_arvore(){
return NULL;
}
int arvore_vazia(tp_arvore raiz)
{
if(raiz==NULL) return 1;
else return 0;
}
tp_no *aloca_no() //aloca e retorna o endereço
{
tp_no *no;
no=(tp_no*)malloc(sizeof(tp_no));
return no;
}
int insere_no(tp_arvore *raiz, tp_item e){
tp_no *pai=NULL, *novo, *p; //*p=ponteiro auxiliar
novo = aloca_no();//cria um novo elemento e coloca o endereço dele no novo
if(!novo) return 0; //não deu para alocar (novo==null)
novo->info = e;
novo->esq = NULL;
novo->dir=NULL;
p = *raiz;
while(p!=NULL)
{//busca a posição onde será inserido o novo nó
pai=p;
if( e.ID < p->info.ID)
p=p->esq;
else
p=p->dir;
}if(pai!=NULL) //Qual ponteiro do pai (esq ou dir) irá apontar para o novo nó
{
if ( e.ID < pai->info.ID)
pai->esq=novo;
else
pai->dir=novo;
}
else
*raiz=novo;
}
return 1;
void pre_ordem(tp_no *p) //imprime os elementos em pre-ordem
{
if(p!=NULL)
{
printf("\n%d\n",p->info);
pre_ordem(p->esq);
pre_ordem(p->dir);
}
}
void em_ordem (tp_no *p) { //imprime os elementos em ordem
if (p != NULL) {
em_ordem (p->esq);
printf("\n%d\n",p->info);
em_ordem (p->dir);
}
}
void pos_ordem (tp_no *p) { //imprime os elementos em pós-ordem
if (p != NULL) {
pos_ordem (p->esq);
pos_ordem (p->dir);
printf("\n%d\n",p->info);
}
}
tp_no* busca_no (tp_no *p, tp_item e) {
while (p != NULL) {
if (e.ID < p->info.ID)
p = p->esq;
else
if (e.ID > p->info.ID)
p = p->dir;
else
return (p);
};
return (NULL);
}
tp_arvore busca_no_rec(tp_arvore p, tp_item e) {
if (p != NULL) {
if (e.ID < p->info.ID)
return busca_no_rec(p->esq, e);
else
if (e.ID > p->info.ID)
return busca_no_rec(p->dir, e);
else}
else
return (p);
return (NULL);
}
int altura_arvore(tp_arvore raiz){
if(raiz == NULL) return 0;
int alt_esq = altura_arvore(raiz->esq);
int alt_dir = altura_arvore(raiz->dir);
if(alt_esq > alt_dir){
return alt_esq + 1;
}else{
return alt_dir + 1;
}
}
int qtde_nos(tp_arvore raiz){
if(raiz == NULL) return 0;
int tot_esq = qtde_nos(raiz->esq);
int tot_dir = qtde_nos(raiz->dir);
return (tot_esq + tot_dir + 1);
}
int remove_no (tp_arvore *raiz, tp_item e ) {
tp_no *p=*raiz,
*ant=NULL,
*sub,
*pai,
*filho;
while (p!=NULL && p->info.ID != e.ID) {
ant=p;
if (e.ID < p->info.ID)
p = p->esq;
else
p = p->dir;
}
if (p==NULL) /* não encontrou */
return 0;
/* nó tem no máximo um filho */
if (p->esq==NULL)
sub=p->dir;
else
if (p->dir==NULL)
sub=p->esq;
else {
/* nó tem dois filhos */
pai=p; sub=p->dir; filho=sub->esq;
while (filho!=NULL) {
pai=sub; sub=filho; filho=sub->esq;
}
/* neste ponto, sub é o sucessor em ordem de p */
if (pai!=p) {
/*p não é o pai de sub e sub==pai->esq */
pai->esq=sub->dir;
/* remove o nó apontado por sub de sua atual
posição e substitui pelo filho direito de rp */
/* sub ocupa o lugar de p */
sub->dir=p->dir;
}}
/*define filho esq de sub para que sub ocupe o lugar de p */
sub->esq=p->esq;
}
/* insere sub na posição ocupada por p */
if (ant==NULL)
*raiz=sub; /* p era raiz */
else
if (p==ant->esq)
ant->esq=sub;
else
ant->dir=sub;
free(p);
return 1;
void destroi_no(tp_no *no){
if(no==NULL) return;
destroi_no(no->esq);
destroi_no(no->dir);
// printf("\n %d ", no->info);
free(no);
no = NULL;
return;
}
void destroi_arvore(tp_arvore *raiz){
if(*raiz==NULL) return;
destroi_no(*raiz);
// free(*raiz);
*raiz=NULL;
}
int hash(int ID_pet){
int ID_hash;
}
ID_hash = (int)(TAM * fmod(0.5, ID_pet));
//printf("Numero hash: %d\n", ID_hash);
return ID_hash;
void insere_hash(tp_pet pet, tp_arvore *tabela){
int ID_hash;
ID_hash = hash(pet.ID);
insere_no(&tabela[ID_hash], pet);
}
int busca_hash(tp_pet *pet, tp_arvore *tabela){
int ID_hash;
tp_no *aux;
ID_hash = hash(pet->ID);
aux = busca_no(tabela[ID_hash], *pet);if(aux != NULL){
*pet = aux->info;
return 1;
}else{
return 0;
}
}
int main(){
int i = 0, ID = 0;
tp_pet aux;
tp_arvore tabela[TAM];
char resposta;
while(i != 00){
tabela[i] = inicializa_arvore();
i++;
}
while(true){
printf("Digite C para cadastrar ou P para pesquisar.\n");
scanf(" %c", &resposta);
if(resposta == 'C'){
printf("Digite os dados do Pet:\n");
printf("Nome:\n");
scanf(" %s", aux.nome);
printf("Idade:\n");
scanf(" %d", &aux.idade);
ID++;
aux.ID = ID;
insere_hash(aux, tabela);
}else{
if(resposta == 'P'){
printf("Digite o ID do Pet:\n");
scanf(" %d", &aux.ID);
if(busca_hash(&aux, tabela)){
printf("Idade: %d\n", aux.idade);
printf("Nome: %s\n", aux.nome);
}else{
printf("Pet nao cadastrado.\n");
}
}
}
}
return 0;
}
