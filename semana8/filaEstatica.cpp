#include<stdio.h>
#include<stdlib.h>

typedef struct fila Fila;
Fila* cria (void);
void insere (Fila* f, float v);
float retira (Fila* f);
int vazia (Fila* f);
void libera (Fila* f);

#define N 100

struct fila{
	int ini, fim;
	float vet[N];
};

int incr (int i){
	if(i == N-1)
		return 0;
	else
		return i+1;
}

Fila* cria(void){
	Fila* f = (Fila*) malloc(sizeof(Fila));
	f->ini = f->fim = 0;
	// inicializa fila vazia
	return f;
}

void insere (Fila* f,float v){
	if(incr(f->fim) == f->ini){
		//fila cheia: capacidade esgotada
		printf("Capacidade da fila estourou.\n");
		exit(1);
	}
	/* insere elemento na próxima posicao livre */
	f->vet[f->fim] = v;
	f->fim = incr(f->fim);
}

float retira (Fila* f){
	float v;
	if(vazia(f)){
		printf("Fila vazia.\n");
		exit(1);
	}
	v = f->vet[f->ini];
	f->ini = incr(f->ini);
	return v;
}

int vazia (Fila* f){
	return (f->ini == f->fim);
}

void libera (Fila* f){
	free(f);
}

void imprime (Fila* f){
	int indice = f->ini;
	while(indice < f->fim){
		printf("Imprimindo Fila %f\n",f->vet[indice]);
		indice++;
	}
}

int main(void){
	
	Fila* f = cria();
	insere(f,2);
	insere(f,4);
	insere(f,1);
	insere(f,9);
	imprime(f);
	
	printf("Primeiro elemento: %f\n",retira(f));
	printf("Segundo elemento: %f\n",retira(f));
	printf("Configuracao da fila:\n");
	
	imprime(f);
	libera(f);
	
	system("pause");
}
