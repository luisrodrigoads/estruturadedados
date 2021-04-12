#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAM_STRING 100
//strcpy(r->pergunta,novaPergunta);
typedef struct arv Arv;

struct arv {
 char pergunta[TAM_STRING];
 struct arv* esq;
 struct arv* dir;
};

Arv* cria(char novaPergunta[TAM_STRING], Arv* sae, Arv* sad){
 Arv* p=(Arv*)malloc(sizeof(Arv));
 strcpy(p->pergunta,novaPergunta);
 p->esq = sae;
 p->dir = sad;
 return p;
}

void imprime (Arv* a){
	printf("<");
	 if (a != NULL){
	 printf("%s \n", a->pergunta); /* mostra raiz */
	 imprime(a->esq); /* mostra sae */
	 imprime(a->dir); /* mostra sad */
	 }
	printf(">");
}

Arv* libera (Arv* a){
	 if (a != NULL){
	 libera(a->esq); /* libera sae */
	 libera(a->dir); /* libera sad */
	 free(a); /* libera raiz */
	 }
	return NULL;
}
