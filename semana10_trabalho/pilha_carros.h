#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAM_STRING_GRANDE 50
#define TAM_STRING_MEDIO 40
#define TAM_STRING_PEQUENO 20
#define TAM_LINHA_ARQUIVO 130

/*
------ Definição das estruturas de dados -------
*/

typedef struct pilha Carro;
typedef struct listaCarros ListaCarros;

struct pilha{
	ListaCarros * primeiro;
};

struct listaCarros{
	char Modelo[TAM_STRING_MEDIO];
	char NumeroDoChassi[TAM_STRING_GRANDE];
	char Cor[TAM_STRING_PEQUENO];
	struct listaCarros * proximo;
};

/*
------ Funções -------
*/

//verifica se a pilha está vazia
int verificaPilhaVazia(Carro* c){
	return (c->primeiro == NULL);
}

//cria uma pilha
Carro* criaPilha(void){
	Carro* c = (Carro*) malloc(sizeof(Carro));
	c->primeiro = NULL;
	return c;
}

//registra um novo carro no estoque
void insere_na_pilha(Carro* c,char novoModelo[TAM_STRING_MEDIO],char novoNumeroDoChassi[TAM_STRING_GRANDE],char novaCor[TAM_STRING_PEQUENO]){
	ListaCarros *novoCarro = (ListaCarros *) malloc(sizeof(ListaCarros));
	strcpy(novoCarro->Modelo,novoModelo);
	strcpy(novoCarro->NumeroDoChassi,novoNumeroDoChassi);
	strcpy(novoCarro->Cor,novaCor);
	novoCarro->proximo = c->primeiro;
	c->primeiro = novoCarro;
}

//remove um carro do estoque
void retira_da_pilha(Carro* c){
	ListaCarros * l;
	int TAM = TAM_STRING_MEDIO + TAM_STRING_GRANDE + 14;
	char modeloChassi[TAM];
	if(verificaPilhaVazia(c)){
		printf("A pilha está vazia.");
	}else{
		l = c->primeiro;
		strcpy(modeloChassi,l->Modelo);
		strcat(modeloChassi," / ");
		strcat(modeloChassi,l->NumeroDoChassi);
		c->primeiro = l->proximo;
		free(l);
		printf("\nModelo / chassi : %s\n",modeloChassi);
	}
}

//leitura inicial do arquivo dos carros
Carro* leitura_inicial_arquivo_carros(Carro* c){
	
	char modelo[TAM_STRING_MEDIO];
	char numeroDoChassi[TAM_STRING_GRANDE];
	char cor[TAM_STRING_PEQUENO];
	
	char linha[TAM_LINHA_ARQUIVO];
	char * ultimaString;
	FILE *fileCarros;
	
	Carro* pilhaNova;
	pilhaNova = criaPilha();
	c = criaPilha();
	
	if((fileCarros = fopen("carros.txt","r")) != NULL){
		
		while(!feof(fileCarros)){
			
			fgets(linha,TAM_LINHA_ARQUIVO,fileCarros);
			ultimaString = strtok(linha,"|");
			
			int coluna = 0;
			while(ultimaString != NULL){
		
					if(coluna == 0)
						strcpy(modelo,ultimaString);
					else if(coluna == 1)
						strcpy(numeroDoChassi,ultimaString);
					else if(coluna == 2){
						strcpy(cor,ultimaString);
						insere_na_pilha(c,modelo,numeroDoChassi,cor);
					}
						
				ultimaString = strtok(NULL,"|");
				coluna++;
			}
			
		}
		
		if(!verificaPilhaVazia(c)){
		
			while(!verificaPilhaVazia(c)){
				insere_na_pilha(pilhaNova,c->primeiro->Modelo,c->primeiro->NumeroDoChassi,c->primeiro->Cor);
				retira_da_pilha(c);
			}
		
		}
		
		fclose(fileCarros);
	}
	
	if(!verificaPilhaVazia(pilhaNova))
		return pilhaNova;
	else
		return c;
}

//grava a lista de carros atualizada no arquivo
void salva_carros_no_arquivo(Carro* c){
	FILE *fileCarros;
	
	fileCarros = fopen("carros.txt","w+");
	
	ListaCarros * l;
	for(l = c->primeiro; l != NULL; l = l->proximo){
		fprintf(fileCarros,"%s|%s|%s|\n",l->Modelo,l->NumeroDoChassi,l->Cor);
	}
	fclose(fileCarros);
	printf("\nSalvando dados no arquivo carros.txt ...\n");
}





//libera a memória alocada para manipular a lista(pilha) de carros
void libera_pilha(Carro* c){
	ListaCarros * l = c->primeiro;
	while(l != NULL){
		ListaCarros * t = l->proximo;
		free(l);
		l = t;
	}
	free(c);
}

//mostra a lista dos carros em estoque
void imprime_pilha(Carro* c){
	ListaCarros * l;
	printf("\n-----Lista de carros-----\n\n");
	if(c->primeiro == NULL){
		printf("\nNão há veiculos cadastrados.\n\n");
	}else{
		printf("Modelo\t| Numero do chassi\t| Cor\n--------------------------\n");	
		for(l = c->primeiro; l != NULL; l = l->proximo){
			printf("%s | %s | %s\n",l->Modelo,l->NumeroDoChassi,l->Cor);
		}
		printf("\n");
	}
}
