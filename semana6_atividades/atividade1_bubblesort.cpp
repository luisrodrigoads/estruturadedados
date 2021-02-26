#include<stdio.h>
#include<stdlib.h>

typedef struct lista Lista;

struct lista{
	int numero;
	struct lista * proximo;
};

int tam = 0;

Lista * insere_lista_fim(Lista * l,int valor){
		
	Lista * novo = (Lista*) malloc(sizeof(Lista));
	novo->numero = valor;
	novo->proximo = NULL;
	
	if(l == NULL)
		return novo;
		
	Lista * p = l;
	while(p->proximo != NULL)
		p = p->proximo;
		
	p->proximo = novo;
	return l; 
}

Lista * leitura_arquivo(Lista * l){
	
	FILE *file;
	int valor;

	if((file = fopen("arquivos_numeros.txt","r")) == NULL){
		printf("Erro ao abrir arquivo.");
	}else{
		while(fscanf(file,"%d",&valor) == 1){ // verifica se o scanf esta lendo um numero
			l = insere_lista_fim(l,valor);			
			tam++;
		}
		fclose(file);
	}
	
	return (l);
}

void imprime_lista(Lista * l){
	printf("imprime lista\n");
	Lista * pl;
	for(pl = l; pl != NULL;pl = pl->proximo){
		printf("%d\n",pl->numero);	
	}
	
}

void organiza_lista(Lista * l){
	printf("organizando lista\n");
	Lista * pl;
	int j=0,aux;

	while(j < tam){
			
		pl = l;
		while(pl->proximo != NULL){
				if(pl->numero > pl->proximo->numero){
					aux = pl->numero;		
					pl->numero = pl->proximo->numero;
					pl->proximo->numero = aux;
				}	
				pl = pl->proximo;			
		}
	
		j++;
	}
	
}

void gravar_arquivo_ordenado(Lista * l){
	
	printf("gravando arquivo com numeros ordenados\n");
	Lista * pl;
	FILE *file;
	
	file = fopen("arquivo_numeros_ordenados.txt","w");
	
	for(pl = l; pl != NULL;pl = pl->proximo){
		fprintf(file,"%d\n",pl->numero);	
	}
	
	fclose(file);
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
	lista_numeros = leitura_arquivo(lista_numeros);
	imprime_lista(lista_numeros);
	organiza_lista(lista_numeros);
	gravar_arquivo_ordenado(lista_numeros);
	imprime_lista(lista_numeros);

	limpa_lista(&lista_numeros);
	
	system("pause");
}
