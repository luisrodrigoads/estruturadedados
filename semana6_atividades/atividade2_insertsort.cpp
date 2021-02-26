#include<stdio.h>
#include<stdlib.h>

typedef struct lista Lista;

struct lista{
	int numero;
	struct lista * proximo;
};

Lista * insere_lista_ordenada(Lista * l,int valor){
	
	Lista* anterior = NULL; 
	Lista* p = l;
	
	while (p != NULL && p->numero < valor){//localiza posição de inserção
		anterior = p;
		p = p->proximo;
	}
	
	//cria novo elemento
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->numero = valor;
	
	//encadeia elemento
	if(anterior == NULL){//insere no início da lista
		novo->proximo = l;
		l = novo;
	}
	else{//insere no meio da lista
		novo->proximo = anterior->proximo;
		anterior->proximo = novo;	
	}
		
	return l;
}

void imprime_lista(Lista * l){
	printf("imprime lista\n");
	Lista * pl;
	for(pl = l; pl != NULL;pl = pl->proximo){
		printf("%d\n",pl->numero);	
	}
	
}

void limpa_lista(Lista ** pl){
	printf("limpando lista\n");
	while(*pl != NULL){
		Lista * t = (*pl)->proximo;
		*pl = NULL;
		free(*pl);
		*pl = t;
	}
}

main(){
	
	Lista * lista_numeros = NULL;
	int valor=1;
	
	while(valor != 0){
		printf("\nPara Sair digite 0\n------------------");
		printf("\nDigite um valor: ");
		scanf("%d",&valor);
		if(valor != 0)
			lista_numeros = insere_lista_ordenada(lista_numeros,valor);
			
	}
	
	if(lista_numeros != NULL)
		imprime_lista(lista_numeros);
	else
		printf("nenhum valor inserido na lista\n");
		
	limpa_lista(&lista_numeros);
	
	system("pause");
}
