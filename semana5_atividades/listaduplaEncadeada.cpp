//lista duplamente encadeada;
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct lista{
	int info;
	struct lista* anterior;
	struct lista* proximo;
};

typedef struct lista Lista;

// cria lista
Lista* lista_cria(void){
 	return (NULL);      
}

// inserção no início 
Lista* lista_insere_inicio(Lista* l, int v){
	
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = v;
	novo->proximo = l;
	novo->anterior = NULL;
	//verifica se lista não está vazia
	if(l != NULL)
		l->anterior = novo;
	return novo;
}

// busca um elemento na lista
Lista* lista_busca(Lista* l,int v){
	
	Lista* p;
	for(p=l; p!=NULL; p=p->proximo)
		if(p->info == v)
			return p;
	return NULL; // não achou o elemento
}

// retira um elemento da lista
Lista* lista_retira(Lista* l, int v){
	
	Lista* p = lista_busca(l,v);
	
	if(p == NULL)
		return l; // não achou elemento retorna lista inalterada
		
	// retira elemento do encadeamento
	if(l == p)	// testa se é o primeiro elemento
		l = p->proximo;
	else
		p->anterior->proximo = p->proximo;
			
	if(p->proximo != NULL) // testa se é o ultimo elemento
		p->proximo->anterior = p->anterior;
		
	free(p);
		
	return l;
}

void lista_imprime(Lista* l){
	
	Lista* pl;
	
      for (pl = l; pl != NULL; pl = pl->proximo){
          printf("info: %d\n",pl->info);
      }
}

// libera a lista
void lista_libera(Lista ** pl){
	
      while (*pl != NULL)
      {
           Lista * t = (*pl)->proximo;
           *pl = NULL;
           free(*pl);
           *pl = t;
      }
 }

main(){
	
	printf("inicio do Programa\n");
	
	Lista * l = lista_cria();
	
	l = lista_insere_inicio(l,4);
	l = lista_insere_inicio(l,5);
	l = lista_insere_inicio(l,8);
	l = lista_insere_inicio(l,1);
	l = lista_insere_inicio(l,3);
	
	lista_imprime(l);
	
	Lista * tmp = lista_busca(l,8);
	if(tmp != NULL)
		printf("\n*************\ninfo: %d\n**********\n",tmp->info);
	else
		printf("valor nao localizado\n");
		
	l = lista_retira(l,1);
	
	lista_imprime(l);
	
	lista_libera(&l);	

	
	system("pause");
}
