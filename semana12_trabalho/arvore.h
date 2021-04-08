#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAM_STRING 100

typedef struct arvoreNo ArvoreNo;

struct arvoreNo{
	char pergunta[TAM_STRING];
	struct arvoreNo* esquerda;
	struct arvoreNo* direita;
};

typedef struct arvore Arvore;
struct arvore{
	struct arvore* raiz;
};

ArvoreNo* insereArvoreNo(char novaPergunta[TAM_STRING],ArvoreNo* esq, ArvoreNo* dir){
	ArvoreNo* novo = (ArvoreNo*) malloc(sizeof(ArvoreNo));
	strcpy(novo->pergunta,novaPergunta);
	novo->esquerda = esq;
	novo->direita = dir;
	return novo;
}

Arvore* criaArvore(Arvore* r){
	Arvore* novaArvore = (Arvore*) malloc(sizeof(Arvore));
	novaArvore->raiz = r;
	return novaArvore;
}

//imprime(a->raiz);
void imprimeNo(ArvoreNo* r){
	printf("<");
	if(r != NULL){
		printf("%s",r->pergunta);
		imprimeNo(r->esquerda);
		imprimeNo(r->direita);
	}
	printf(">");
}

void imprimeArvore(Arvore* a){
	imprimeNo(a->raiz); 
}

void liberaNo(ArvoreNo* r){
	if(r != NULL){
		liberaNo(r->esquerda);
		liberaNo(r->direita);
		free(r);
	}
}

void liberaArvore(Arvore* a){
	liberaNo(a->raiz);
	free(a);
}

int procuraNo(ArvoreNo* r,char perguntaNo[TAM_STRING]){
	if(strcmp(perguntaNo,r->pergunta) == 0)
		return 1;
	else if(procuraNo(r->esquerda,perguntaNo))
		return 1;
	else
		return procuraNo(r->direita,perguntaNo);
}

int procuraNaArvore(Arvore* a,char perguntaNo[TAM_STRING]){
	return procuraNo(a->raiz,perguntaNo);
}



