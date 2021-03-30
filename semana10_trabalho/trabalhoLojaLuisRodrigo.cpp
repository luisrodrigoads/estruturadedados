#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

#include "fila_cliente.h"
#include "pilha_carros.h"

#define TAM_STRING_GRANDE 50
#define TAM_STRING_MEDIO 40
#define TAM_STRING_PEQUENO 20
#define TAM_LINHA_ARQUIVO 130

/*
------ Definição das funções -------
*/

void imprime_menu_principal();
void limpa_tela();

main(){
	
	int opcao;
	
	char voltar[1];
	
	Clientes* filaDeClientes;
	Carro* listaDeCarros;
	
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
				
				fflush(stdin);
				printf("Para voltar digite qualquer letra ");
				scanf("%s",voltar);
				if(voltar != NULL)
					break;
			case 2:		//Visualizar clientes
				limpa_tela();
				imprime_fila(filaDeClientes);
				
				fflush(stdin);
				printf("Para voltar digite qualquer letra ");
				scanf("%s",voltar);
				if(voltar != NULL)	
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
				
				fflush(stdin);
				printf("Para voltar digite qualquer letra ");
				scanf("%s",voltar);
				if(voltar != NULL)
					break;
			case 4:		//Visualizar carros no estoque
				limpa_tela();
				imprime_pilha(listaDeCarros);

				fflush(stdin);
				printf("Para voltar digite qualquer letra ");
				scanf("%s",voltar);
				if(voltar != NULL)
					break;
			case 5:		//Entregar carro/cliente
				limpa_tela();
				if((filaDeClientes->inicial == NULL) || (listaDeCarros->primeiro == NULL)){
					printf("\n-----Não foi possível realizar a entrega!-----");
					printf("\nCarro ou cliente não disponíveis\n\n");
				}else{
					printf("\n-----Dados da entrega-----\n\n");
					retira_da_fila(filaDeClientes);
					retira_da_pilha(listaDeCarros);
					salva_clientes_no_arquivo(filaDeClientes);
					salva_carros_no_arquivo(listaDeCarros);	
				}
				
				fflush(stdin);
				printf("Para voltar digite qualquer letra ");
				scanf("%s",voltar);
				if(voltar != NULL)
					break;
			case 6:		//Gerar arquivo de clientes ordenado(nome)
				limpa_tela();
				organiza_fila(filaDeClientes);
				
				fflush(stdin);
				printf("Para voltar digite qualquer letra ");
				scanf("%s",voltar);
				if(voltar != NULL)
					break;
			default:	//Sair
				break;
		}
	}while(opcao != 7);
	
	libera_fila(filaDeClientes);
	libera_pilha(listaDeCarros);
	
}

//mostra ao usuário a tela inicial ao usuário
void imprime_menu_principal(){
	limpa_tela();
	printf("\n------- Institute Veículos -------\n\n");
	printf("[1] - Cadastrar Clientes\n");
	printf("[2] - Visualizar Clientes\n");
	printf("[3] - Cadastrar Carro no Estoque\n");
	printf("[4] - Visualizar Carros no Estoque\n");
	printf("[5] - Entregar Carro/Cliente\n");
	printf("[6] - Gerar arquivo de Clientes Ordenado (Nome)\n");
	printf("[7] - Sair\n");
}

//função auxiliar para limpar a tela quando o usuário navega entre elas
void limpa_tela(){
	system("clear || cls");
}

