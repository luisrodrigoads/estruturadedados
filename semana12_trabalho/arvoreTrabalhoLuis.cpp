#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include "arvore.h"
#include "arvore2.h"

#define TAM_STRING 100

Arv* inserePergunta(){
	system("clear || cls");
	fflush(stdin);
	char novaPergunta[TAM_STRING];	
	Arv* nova = (Arv*)malloc(sizeof(Arv));
	
	printf("\n**********Cadastrar nova pergunta**********\n");
	printf("Digite a pergunta: ");
	scanf("%[^\n]",novaPergunta);
	
	nova = cria(novaPergunta,NULL,NULL);
	return nova;
}

Arv* percorre(Arv* a){
	
	fflush(stdin);
	char op;
	if((a != NULL) || op != 's'){
		system("clear || cls");
		printf("\n%s ",a->pergunta);
		printf("Para sim digite [s], para não digite[n]: ");
		printf(" %c",op);
		if(op != 's')
			percorre(a->dir);
	
	}else if(op == 'n'){
		a->dir = inserePergunta();
		percorre(a->dir);
	}else
		return a;
}

main(){
	/* implementação arvore.h
	Arvore* a = cria_arvore("carlos");
	a = insere(a,"luis");
	a = insere(a,"bruno");
	a = insere(a,"andre");*/
	
	//implementação arvore2.h
	/*Arv* a1= cria("d",NULL,NULL); 
	Arv* a2= cria("b",NULL,a1); 
	Arv* a3= cria("e",NULL,NULL); 
	Arv* a4= cria("f",NULL,NULL); 
	Arv* a5= cria("c",a3,a4); 
	Arv* a = cria("a",a2,a5 );*/
	 
	Arv* a = NULL;
	a = inserePergunta();
	//printf("%s",a->pergunta);
	a = percorre(a);
	
	
	//imprime(a);
	
	libera(a);
}
