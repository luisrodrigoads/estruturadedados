#include<stdio.h>
#include<stdlib.h>

//definicao do nó
struct no{
	float info;
	struct no* prox;
};

typedef struct no No;

//definicao da fila;
struct fila{
	No* ini;
	No* fim;
};

typedef struct fila Fila;

//verifica se a fila está vazia
int vazia (Fila* f){
	return (f->ini == NULL);
}

//cria a fila
Fila* cria (void){
	Fila* f = (Fila*) malloc(sizeof(Fila));
	f->ini = f->fim = NULL;
	return f;
}

//funcao auxiliar: insere no fim
No* ins_fim(No* fim,float v){
	No* p = (No*) malloc(sizeof(No));
	p->info = v;
	p->prox = NULL;
	if(fim != NULL) //verifica se a lista nao estava vazia
	fim->prox = p;
	return p;
}

//funcao auxiliar: retira no inicio
No* ret_ini(No* ini){
	No* p = ini->prox;
	free(ini);
	return p;
}

//remove da fila - sempre o ultimo
float retira (Fila* f){
	float v;
	if(vazia(f)){
		printf("Fila vazia.\n");
		exit(1);
	}
	v= f->ini->info;
	f->ini = ret_ini(f->ini);
	if(f->ini == NULL) //fila ficou vazia?
		f->fim = NULL;
	return v;
}

void insere (Fila* f,float v){
	f->fim = ins_fim(f->fim,v);
	if(f->ini == NULL) //fila ficou vazia?
	f->ini = f->fim;
}

//libera a fila
void libera (Fila* f){
	No* q = f->ini;
	while(q != NULL){
		No* t = q->prox;
		free(q);
		q = t;
	}
	free(f);
}

//imprime toda a lista
void imprime (Fila* f){
	No* q;
	for(q=f->ini; q!=NULL;q=q->prox){
		printf("%f\n",q->info);
	}
}

int main(void){
	Fila* f = cria();
	
	insere(f,2);
	insere(f,4);
	insere(f,6);
	insere(f,8);
	
	imprime(f);
	
	printf("Retira primeiro elemento: %f\n",retira(f));
	printf("Retira segundo elemento: %f\n",retira(f));
	
	imprime(f);
	
	libera(f);
	
	system("pause");
}
