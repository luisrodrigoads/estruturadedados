#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

#define TAM_STRING_GRANDE 50
#define TAM_STRING_MEDIO 40
#define TAM_STRING_PEQUENO 20
#define TAM_LINHA_ARQUIVO 130

//carro pilha
//cliente fila

/*
------ Definição das estruturas de dados -------
*/

typedef struct fila Clientes;
typedef struct elementoDaFila ElementoDaFila;

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
------ Definição das funções -------
*/

//funções relacionadas ao cliente
int verificaFilaVazia(Clientes* cf);
Clientes* criaFila(void);
ElementoDaFila* insere_no_fim(ElementoDaFila* final, char novoNome[TAM_STRING_MEDIO],char novoCPF[TAM_STRING_PEQUENO],char novoTelefone[TAM_STRING_PEQUENO]);
ElementoDaFila* retira_no_inicio(ElementoDaFila* inicial);
void insere_na_fila(Clientes* cf,char novoNome[TAM_STRING_MEDIO],char novoCPF[TAM_STRING_PEQUENO],char novoTelefone[TAM_STRING_PEQUENO]);
void retira_da_fila(Clientes* cf);
void libera_fila(Clientes* cf);
void imprime_fila(Clientes* cf);


//funções relacionados ao carro
int verificaPilhaVazia(Carro* c);
Carro* criaPilha(void);
void insere_na_pilha(Carro* c,char novoModelo[TAM_STRING_MEDIO],char novoNumeroDoChassi[TAM_STRING_GRANDE],char novaCor[TAM_STRING_PEQUENO]);
void retira_da_pilha(Carro* c);
void libera_pilha(Carro* c);
void imprime_pilha(Carro* c);

//funções relacionadas a manipulação de arquivos
Clientes* leitura_inicial_arquivo_clientes(Clientes* cf);
Carro* leitura_inicial_arquivo_carros(Carro* c);
void salva_clientes_no_arquivo(Clientes* cf);
void salva_carros_no_arquivo(Carro* c);

void imprime_menu_principal();
void limpa_tela();

main(){
	
	int opcao;
	
	Clientes* filaDeClientes;// = criaFila();
	Carro* listaDeCarros;// = criaPilha();
	
	filaDeClientes = leitura_inicial_arquivo_clientes(filaDeClientes);
	listaDeCarros = leitura_inicial_arquivo_carros(listaDeCarros);
	
	char nome[TAM_STRING_MEDIO],cpf[TAM_STRING_PEQUENO],telefone[TAM_STRING_PEQUENO];
	char modelo[TAM_STRING_MEDIO],numeroDoChassi[TAM_STRING_GRANDE],cor[TAM_STRING_PEQUENO];
	
	setlocale(LC_ALL,"");
	
	do{
		imprime_menu_principal();
		scanf("%d",&opcao);
		switch(opcao){
			case 1:		//Cadastrar clientes
				limpa_tela();
				fflush(stdin);
				printf("\n----Cadastro de Clientes----\n");
				printf("Digite o nome: ");
				scanf("%[^\n]",nome);
				fflush(stdin);
				printf("\nDigite o CPF: ");
				scanf("%[^\n]",cpf);
				fflush(stdin);
				printf("\nDigite o telefone: ");
				scanf("%[^\n]",telefone);
				
				insere_na_fila(filaDeClientes,nome,cpf,telefone);
				salva_clientes_no_arquivo(filaDeClientes);
				system("pause");
				break;
			case 2:		//Visualizar clientes
				limpa_tela();
				imprime_fila(filaDeClientes);
				system("pause");
				break;
			case 3:		//Cadastrar carro no estoque
				limpa_tela();
				fflush(stdin);
				printf("\n----Cadastro de Carros----\n");
				printf("Digite o modelo: ");
				scanf("%[^\n]",modelo);
				fflush(stdin);
				printf("Digite o numero do chassi: ");
				scanf("%[^\n]",numeroDoChassi);
				fflush(stdin);
				printf("Digite a cor do carro: ");
				scanf("%[^\n]",cor);
				
				insere_na_pilha(listaDeCarros,modelo,numeroDoChassi,cor);
				salva_carros_no_arquivo(listaDeCarros);
				system("pause");
				break;
			case 4:		//Visualizar carros no estoque
				limpa_tela();
				imprime_pilha(listaDeCarros);
				system("pause");
				break;
			case 5:		//Entregar carro/cliente
				limpa_tela();
				//printf("\nO carro do modelo %s foi entregue ao cliente %s\n",retira_da_pilha(listaDeCarros),retira_da_fila(filaDeClientes));
				if((filaDeClientes->inicial == NULL) || (listaDeCarros->primeiro == NULL)){
					printf("\n-----Não foi possível realizar a entrega!-----");
					printf("\nCarro ou cliente não disponíveis\n\n");
				}else{
					printf("\n-----Dados da entrega-----\n\n");
					retira_da_fila(filaDeClientes);
					retira_da_pilha(listaDeCarros);	
				}
				system("pause");
				break;
			case 6:		//Gerar arquivo de clientes ordenado(nome)
				limpa_tela();
				break;
			default:	//Sair
				break;
		}
	}while(opcao != 7);
	
	libera_fila(filaDeClientes);
	libera_pilha(listaDeCarros);
	
}

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
	printf("\nSalvando dados no arquivo clientes.txt ...");
		
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

//funçõa auxiliar para retirar no inicio da fila
ElementoDaFila* retira_no_inicio(ElementoDaFila* inicial){
	ElementoDaFila* elemento = inicial->proximo;
	free(inicial);
	return elemento;
}

//remove elemento da fila de clientes
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

void insere_na_fila(Clientes* cf,char novoNome[TAM_STRING_MEDIO],char novoCPF[TAM_STRING_PEQUENO],char novoTelefone[TAM_STRING_PEQUENO]){
	cf->final = insere_no_fim(cf->final,novoNome,novoCPF,novoTelefone);
	if(cf->inicial == NULL) //verifica se a fila ficou vazia
		cf->inicial = cf->final;
}

void libera_fila(Clientes* cf){
	ElementoDaFila* a = cf->inicial;
	while(a != NULL){
		ElementoDaFila* b = a->proximo;
		free(a);
		a = b;
	}
	free(cf);
}

void imprime_fila(Clientes* cf){
	ElementoDaFila* a;
	printf("\n-----Fila de clientes-----\n\n");
	if(cf->inicial == NULL){
		printf("Não há clientes cadastrados.\n\n");
	}else{
		for(a = cf->inicial; a != NULL; a = a->proximo){
			printf("%s | %s | %s\n",a->Nome,a->CPF,a->Telefone);
		}
		printf("\n");	
	}	
}

int verificaPilhaVazia(Carro* c){
	return (c->primeiro == NULL);
}

Carro* criaPilha(void){
	Carro* c = (Carro*) malloc(sizeof(Carro));
	c->primeiro = NULL;
	return c;
}

Carro* leitura_inicial_arquivo_carros(Carro* c){
	
	char modelo[TAM_STRING_MEDIO];
	char numeroDoChassi[TAM_STRING_GRANDE];
	char cor[TAM_STRING_PEQUENO];
	
	char linha[TAM_LINHA_ARQUIVO];
	char * ultimaString;
	FILE *fileCarros;

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
		fclose(fileCarros);
	}
	
	return c;
}

void salva_carros_no_arquivo(Carro* c){
	FILE *fileCarros;
	
	fileCarros = fopen("carros.txt","w+");
	
	ListaCarros * l;
	for(l = c->primeiro; l != NULL; l = l->proximo){
		fprintf(fileCarros,"%s|%s|%s|\n",l->Modelo,l->NumeroDoChassi,l->Cor);
	}
	fclose(fileCarros);
	printf("\nSalvando dados no arquivo carros.txt ...");
}

void insere_na_pilha(Carro* c,char novoModelo[TAM_STRING_MEDIO],char novoNumeroDoChassi[TAM_STRING_GRANDE],char novaCor[TAM_STRING_PEQUENO]){
	ListaCarros *novoCarro = (ListaCarros *) malloc(sizeof(ListaCarros));
	strcpy(novoCarro->Modelo,novoModelo);
	strcpy(novoCarro->NumeroDoChassi,novoNumeroDoChassi);
	strcpy(novoCarro->Cor,novaCor);
	novoCarro->proximo = c->primeiro;
	c->primeiro = novoCarro;
}

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

void libera_pilha(Carro* c){
	ListaCarros * l = c->primeiro;
	while(l != NULL){
		ListaCarros * t = l->proximo;
		free(l);
		l = t;
	}
	free(c);
}

void imprime_pilha(Carro* c){
	ListaCarros * l;
	if(c->primeiro == NULL){
		printf("\nNão há veiculos cadastrados.\n\n");
	}else{
		printf("\n-----Lista de carros-----\n\n");
		for(l = c->primeiro; l != NULL; l = l->proximo){
			printf("%s | %s | %s\n",l->Modelo,l->NumeroDoChassi,l->Cor);
		}
		printf("\n");
	}
}

void imprime_menu_principal(){
	limpa_tela();
	printf("\n[1] - Cadastrar Clientes\n");
	printf("[2] - Visualizar Clientes\n");
	printf("[3] - Cadastrar Carro no Estoque\n");
	printf("[4] - Visualizar Carros no Estoque\n");
	printf("[5] - Entregar Carro/Cliente\n");
	printf("[6] - Gerar arquivo de Clientes Ordenado por nome\n");
	printf("[7] - Sair\n");
}

void limpa_tela(){
	system("clear || cls");
}

