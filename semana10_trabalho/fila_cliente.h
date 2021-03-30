#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAM_STRING_GRANDE 50
#define TAM_STRING_MEDIO 40
#define TAM_STRING_PEQUENO 20
#define TAM_LINHA_ARQUIVO 130

typedef struct fila Clientes;
typedef struct elementoDaFila ElementoDaFila;

/*
------ Definição das estruturas de dados -------
*/

struct elementoDaFila{
	char Nome[TAM_STRING_MEDIO];
	char CPF[TAM_STRING_PEQUENO];
	char Telefone[TAM_STRING_PEQUENO];
	struct elementoDaFila* proximo;
};

struct fila{
	ElementoDaFila* inicial;
	ElementoDaFila* final;
};

/*
------ Funções -------
*/

//verifica se a fila está vazia
int verificaFilaVazia(Clientes* cf){
	return (cf->inicial == NULL);
}

//cria a fila
Clientes* criaFila(void){
	Clientes* cf = (Clientes*) malloc(sizeof(Clientes));
	cf->inicial = cf->final = NULL;
	return cf;
}

//função auxiliar para inserir no fim da fila
ElementoDaFila* insere_no_fim(ElementoDaFila* final, char novoNome[TAM_STRING_MEDIO],char novoCPF[TAM_STRING_PEQUENO],char novoTelefone[TAM_STRING_PEQUENO]){
	ElementoDaFila* novoCliente = (ElementoDaFila*) malloc(sizeof(ElementoDaFila));
	strcpy(novoCliente->Nome,novoNome);
	strcpy(novoCliente->CPF,novoCPF);
	strcpy(novoCliente->Telefone,novoTelefone);
	novoCliente->proximo = NULL;
	
	if(final != NULL)
		final->proximo = novoCliente;
			
	return novoCliente;
}

//registra novo cliente
void insere_na_fila(Clientes* cf,char novoNome[TAM_STRING_MEDIO],char novoCPF[TAM_STRING_PEQUENO],char novoTelefone[TAM_STRING_PEQUENO]){
	cf->final = insere_no_fim(cf->final,novoNome,novoCPF,novoTelefone);
	if(cf->inicial == NULL) //verifica se a fila ficou vazia
		cf->inicial = cf->final;
}

//leitura inicial do arquivo dos clientes
Clientes* leitura_inicial_arquivo_clientes(Clientes* cf){
	
	char nome[TAM_STRING_MEDIO];
	char cpf[TAM_STRING_PEQUENO];
	char telefone[TAM_STRING_PEQUENO];
	
	char linha[TAM_LINHA_ARQUIVO];
	char * ultimaString;
	FILE *fileClientes;

	cf = criaFila();
	
	if((fileClientes = fopen("clientes.txt","r")) != NULL){
		while(!feof(fileClientes)){
			
			fgets(linha,TAM_LINHA_ARQUIVO,fileClientes);
			ultimaString = strtok(linha,"|");
			
			int coluna = 0;
			while(ultimaString != NULL){
				
					if(coluna == 0)
						strcpy(nome,ultimaString);
					else if(coluna == 1)
						strcpy(cpf,ultimaString);
					else if(coluna == 2){
						strcpy(telefone,ultimaString);
						insere_na_fila(cf,nome,cpf,telefone);
					}	
					
				ultimaString = strtok(NULL,"|");
				coluna++;
			}
			
		}
		fclose(fileClientes);
	}
	
	return cf;
}

//grava a lista de clientes atualizada no arquivo
void salva_clientes_no_arquivo(Clientes* cf){
	
	FILE *fileClientes;
	
	fileClientes = fopen("clientes.txt","w+");
	
	ElementoDaFila * a;
	for(a = cf->inicial; a != NULL; a = a->proximo){
		fprintf(fileClientes,"%s|%s|%s|\n",a->Nome,a->CPF,a->Telefone);
	}
	fclose(fileClientes);
	printf("\nSalvando dados no arquivo clientes.txt ...\n");
		
}

//funçõa auxiliar para retirar no inicio da fila
ElementoDaFila* retira_no_inicio(ElementoDaFila* inicial){
	ElementoDaFila* elemento = inicial->proximo;
	free(inicial);
	return elemento;
}

//remove um cliente da fila
void retira_da_fila(Clientes* cf){
	
	char nome[TAM_STRING_MEDIO];
	
	if(verificaFilaVazia(cf)){
		printf("Não há clientes cadastrados");
		exit(1);
	}
	strcpy(nome,cf->inicial->Nome);
	cf->inicial = retira_no_inicio(cf->inicial);
	if(cf->inicial == NULL)//verifica se a fila ficou vazia
		cf->final == NULL;
	printf("Cliente: %s",nome);
}



//libera a memória alocada para manipular a fila de clientes
void libera_fila(Clientes* cf){
	ElementoDaFila* a = cf->inicial;
	while(a != NULL){
		ElementoDaFila* b = a->proximo;
		free(a);
		a = b;
	}
	free(cf);
}

//grava num arquivo a lista de clientes ordenada por nome
void gerar_arquivo_ordenado_clientes(Clientes* cf){
	
	FILE *fileClientes;
	
	fileClientes = fopen("clientesOrdenadosPorNome.txt","w+");
	
	ElementoDaFila * a;
	for(a = cf->inicial; a != NULL; a = a->proximo){
		fprintf(fileClientes,"%s|%s|%s|\n",a->Nome,a->CPF,a->Telefone);
	}
	fclose(fileClientes);
	printf("\nGerando arquivo de clientes ordenado ...\n");	
	libera_fila(cf);
}

//organiza a fila de clientes por nome
void organiza_fila(Clientes* cf){
	
	char auxNome[TAM_STRING_MEDIO];
	char auxCpf[TAM_STRING_PEQUENO];
	char auxTelefone[TAM_STRING_PEQUENO];
	
	ElementoDaFila* f;
	Clientes* filaAuxiliar;
	filaAuxiliar = criaFila();
	
	if(cf->inicial != NULL){
		f = cf->inicial;
		while(f != NULL){	
			insere_na_fila(filaAuxiliar,f->Nome,f->CPF,f->Telefone);
			f = f->proximo;
		}	
	}	
	
	if(filaAuxiliar->inicial != NULL){
		
		ElementoDaFila* a;
		ElementoDaFila* b;
		a = filaAuxiliar->inicial;
		b = filaAuxiliar->inicial;
		
		while(b != NULL){
			
			while(a->proximo != NULL){
				if(strcmp(strupr(a->Nome),strupr(a->proximo->Nome)) > 0){
					
					strcpy(auxNome,a->Nome);
					strcpy(a->Nome,a->proximo->Nome);
					strcpy(a->proximo->Nome,auxNome);
					
					strcpy(auxCpf,a->CPF);
					strcpy(a->CPF,a->proximo->CPF);
					strcpy(a->proximo->CPF,auxCpf);
					
					strcpy(auxTelefone,a->Telefone);
					strcpy(a->Telefone,a->proximo->Telefone);
					strcpy(a->proximo->Telefone,auxTelefone);
				}
				
				a = a->proximo;
			}
			
			b = b->proximo;
		}
		
		gerar_arquivo_ordenado_clientes(filaAuxiliar);
	}else{
		printf("\nNão clientes cadastrados para ordenar.\n");
	}
}


//mostra a lista de clientes
void imprime_fila(Clientes* cf){
	ElementoDaFila* a;
	printf("\n-----Fila de clientes-----\n\n");
	if(cf->inicial == NULL){
		printf("Não há clientes cadastrados.\n\n");
	}else{
		printf("Nome\t| CPF\t| Telefone\n--------------------------\n");
		for(a = cf->inicial; a != NULL; a = a->proximo){
			printf("%s | %s | %s\n",a->Nome,a->CPF,a->Telefone);
		}
		printf("\n");	
	}	
}
