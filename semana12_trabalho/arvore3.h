#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAM_STRING 100
//strcpy(r->pergunta,novaPergunta);

typedef struct arvore Arvore;

struct arvore{
	char pergunta[TAM_STRING];
	struct arvore* esquerda;
	struct arvore* direita;
};

Arvore* cria_arvore(char novaPergunta[TAM_STRING]){
	Arvore* nova = (Arvore*) malloc(sizeof(Arvore));
	strcpy(nova->pergunta,novaPergunta);
	nova->esquerda = NULL;
	nova->direita = NULL;
	return nova;
}

Arvore* insere(Arvore* r,char novaPergunta[TAM_STRING]){
	if(r == NULL){
		
		r = (Arvore*) malloc(sizeof(Arvore));
		strcpy(r->pergunta,novaPergunta);
		r->esquerda = NULL;
		r->direita = NULL;
		
	}else if(strcmp(novaPergunta,r->pergunta) < 0)
		r->esquerda = insere(r->esquerda,novaPergunta);	
	else
		r->direita = insere(r->direita,novaPergunta);
		
	return r;
	
}


void imprime (Arvore* r){
	
	if (r != NULL) {
		
		imprime(r->esquerda);
		printf("%s \n",r->pergunta);
		imprime(r->direita);	
	}
	
}

void libera(Arvore* r){
	if(r != NULL){
		libera(r->esquerda);
		libera(r->direita);
		free(r);
	}	
}


