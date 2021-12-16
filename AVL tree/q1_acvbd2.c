#include <stdio.h>
#include <stdlib.h>
#define MAX(A,B) ((A>B) ? (A):(B))

struct node {
	int info;
	int altura;
	struct node *esq;
	struct node *dir;
};

int altura (struct node *ptr);
void atualiza_altura (struct node *ptr);
struct node *rotacao_esq(struct node *raiz);
struct node *rotacao_dir(struct node *raiz);
struct node *rotacaodupla_esq(struct node *raiz);
struct node *rotacaodupla_dir(struct node *raiz);
struct node *inserirAVL(int x, struct node *raiz, struct node* rr);
void exibir_preordem (struct node *raiz);
void imprimeAVL_antes (struct node *raiz);
void imprimeAVL_depois (struct node *raiz);
void imprimeAVL (struct node *raiz);

int cont = 0;
int main(){
	struct node *raiz;
	raiz = NULL;
	int x;

	while (scanf("%d", &x) != EOF){
		printf("\n----");
		printf("\nAdicionando %d", x);
		raiz = inserirAVL(x, raiz, raiz);
        if(cont == 1) {
            imprimeAVL_depois(raiz);
        }else{
            imprimeAVL(raiz);
        }
        cont = 0;
	}
	printf("\n----");

	return 0;
}



int altura (struct node *ptr){
	if (ptr == NULL)
		return 0;
	else 
		return ptr->altura;
}

void atualiza_altura (struct node *ptr){
	int alturaesq, alturadir;

	if(ptr != NULL){
		alturadir = altura(ptr->dir);
		alturaesq = altura(ptr->esq);
		ptr->altura = MAX(alturadir, alturaesq) + 1;
	}
}

struct node *rotacao_esq(struct node *raiz)
{
	struct node *aux;

	aux = malloc(sizeof(struct node));
	aux = raiz->dir;
	raiz->dir = aux->esq;
	aux->esq = raiz;
	atualiza_altura(raiz->esq);
	atualiza_altura(raiz);
	return(aux);
}
struct node *rotacao_dir(struct node *raiz)
{
	struct node *aux;

	aux = malloc(sizeof(struct node));
	aux = raiz->esq;
	raiz->esq = aux->dir;
	aux->dir = raiz;
	atualiza_altura(raiz->dir);
	atualiza_altura(raiz);
	return(aux);
}

struct node *rotacaodupla_esq(struct node *raiz)
{
	struct node *resultado;

	resultado = malloc(sizeof(struct node));
	raiz->dir = rotacao_dir(raiz->dir);
	resultado = rotacao_esq(raiz);
	return resultado;
}

struct node *rotacaodupla_dir(struct node *raiz)
{
	struct node *resultado;

	resultado = malloc(sizeof(struct node));
	raiz->esq = rotacao_esq(raiz->esq);
	resultado = rotacao_dir(raiz);
	return resultado;
}

struct node *inserirAVL(int x, struct node *raiz, struct node* rr)
{	
	if (raiz == NULL) {
		struct node *raiz = malloc(sizeof(struct node));
		raiz->info = x;
		raiz->esq = NULL;
		raiz->dir = NULL;
		raiz->altura = 1;
		return raiz;
		
	} else {
		if (x < raiz->info){
			raiz->esq = inserirAVL (x, raiz->esq, rr);
			if(((altura(raiz->esq)) - (altura(raiz->dir))) == 2){
				imprimeAVL_antes(rr);
                struct node*aux = raiz;
				if (x < raiz->esq->info){
					raiz = rotacao_dir(raiz);
                    cont = 1;
				} else {
					raiz = rotacaodupla_dir(raiz);
                    cont = 1;
				}
			}
			

		} else {
			raiz->dir = inserirAVL (x, raiz->dir, rr);
			if(((altura(raiz->dir)) - (altura(raiz->esq))) == 2){
				imprimeAVL_antes(rr);
				if (x >= raiz->dir->info){
					raiz = rotacao_esq(raiz);
                    cont = 1;
				} else {
					raiz = rotacaodupla_esq(raiz);
                    cont = 1;
				}
			}
			
		}
		atualiza_altura(raiz);
	}
	return raiz;
}

void exibir_preordem (struct node *raiz){
	if (raiz != NULL){
		printf(" (");
		printf(" %d ", raiz->info);
		exibir_preordem(raiz->esq);
		exibir_preordem(raiz->dir);
		printf(") ");
	} else
		printf(" () ");

}

void imprimeAVL_antes (struct node *raiz){
	printf("\nAntes de ajustar balanceamento...\n  ");
	exibir_preordem(raiz);
}

void imprimeAVL_depois (struct node *raiz){
	printf("\nDepois de ajustar balanceamento...\n  ");
	exibir_preordem(raiz);
}

void imprimeAVL (struct node *raiz){
	printf("\nContinuou AVL...\n  ");
	exibir_preordem(raiz);
}
