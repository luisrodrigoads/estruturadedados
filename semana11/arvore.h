#include<stdlib.h>
#include<stdio.h>

typedef struct arv Arvore;

struct arv{
	char info;
	struct arv * prox;
	struct arv * prim;
};

Arvore * arvore_cria(char c){
	Arvore *n = (Arvore *) malloc(sizeof(Arvore));
	n->info = c;
	n->prim = NULL;
	n->prox = NULL;
	return n;
}

void arvore_insere(Arvore * a, Arvore * b){
	b->prox = a->prim;
	a->prim = b;
}

void arvore_imprime(Arvore *a){
	Arvore *p;
	printf("< desce %c\n", a->info);
	for(p = a->prim; p!= NULL; p = p->prox){
		arvore_imprime(p);
	}
	printf("sobe > \n");
}

int arvore_localiza (Arvore *a, char c){
	Arvore *p;
	if(a->info == c)
		return 1;
	else{
		for(p = a->prim; p!= NULL;p = p->prox){
			if(arvore_localiza(p,c))
				return 1;
		}
		return 0;
	}
}

int arvore_altura(Arvore *a){
	int hmax = -1;
	Arvore *p;
	for(p = a->prim; p != NULL; p = p->prox){
		int h = arvore_altura(p);
		if(h > hmax)
			hmax = h;
	}
	return hmax + 1;
}
