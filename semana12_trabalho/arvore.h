#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAM_STRING 200

typedef struct arv Arvore;

struct arv{
	bool ehUmaResposta;
	char pergunta[TAM_STRING];
	struct arv* esquerda;//caso resposta for sim
	struct arv* direita;//caso reposta for não, assim seguindo a lógica apresentada no slide da aula
};

Arvore* criaArvore(char novaPergunta[TAM_STRING], bool novaResposta){
	Arvore* novaArvore = (Arvore*) malloc(sizeof(Arvore));
	novaArvore->ehUmaResposta = novaResposta;
	strcpy(novaArvore->pergunta,novaPergunta);
	novaArvore->esquerda = NULL;
	novaArvore->direita = NULL;
	return novaArvore;
}

Arvore* insereArvoreEsquerda(Arvore* a,Arvore* b){
	a->esquerda = b;
}

Arvore* insereArvoreDireita(Arvore* a,Arvore* b){
	a->direita = b;
}

Arvore* carregaArvore(Arvore* arvore){
	Arvore* aux = arvore;
	int resposta;
	do{
		if(!aux){
			printf("********** Treinando programa **********\n\n");
			char pergunta[TAM_STRING];
			int ehUmaResposta;
			
			fflush(stdin);
			printf("Insira uma nova pergunta: ");
			scanf("%[^\n]s",pergunta);
			
			fflush(stdin);
			printf("\n-------- Escolha uma das opcoes --------\n");
			printf("[1] - Pergunta\n[2] - Reposta\n");
			scanf("%d",&ehUmaResposta);
			
			if(ehUmaResposta == 1){
				arvore = criaArvore(pergunta,false);
				aux = arvore;
			}else{
				arvore = criaArvore(pergunta,true);
				aux = arvore;
			}
		
		}else{
			printf("*************** Pergunta ***************\n\n");
			printf("%s\n",aux->pergunta);
			printf("[1] - Sim\n[2] - Nao\n\n");
			scanf("%d",&resposta);
			system("clear || cls");
			
			if(resposta == 1){
				if(!aux->esquerda && !aux->ehUmaResposta){
					printf("********** Treinando programa **********\n\n");
					char pergunta[TAM_STRING];
					int ehUmaResposta;
					
					fflush(stdin);
					printf("Insira uma nova pergunta: ");
					scanf("%[^\n]s",pergunta);
					
					fflush(stdin);
					printf("\n-------- Escolha uma das opcoes --------\n");
					printf("[1] - Pergunta\n[2] - Reposta\n");
					scanf("%d",&ehUmaResposta);
					
					if(ehUmaResposta == 1){
						Arvore* novaPergunta = criaArvore(pergunta,false);
						insereArvoreEsquerda(aux,novaPergunta);	
					}else{
						Arvore* novaResposta = criaArvore(pergunta,true);
						insereArvoreEsquerda(aux,novaResposta);
					}
				
				}else if(!aux->esquerda){
					printf("*************** Resposta ***************\n\n");
					printf("%s\n\n",aux->pergunta);
					system("pause");
					resposta = 3;
				}
				aux = aux->esquerda;
			}
			
			if(resposta == 2){
				if(!aux->direita){
					printf("********** Treinando programa **********\n\n");
					char pergunta[TAM_STRING];
					int ehUmaResposta;
					
					fflush(stdin);
					printf("Insira uma nova pergunta: ");
					scanf("%[^\n]s",pergunta);
					
					fflush(stdin);
					printf("\n-------- Escolha uma das opcoes --------\n");
					printf("[1] - Pergunta\n[2] - Reposta\n");
					scanf("%d",&ehUmaResposta);
					
					if(ehUmaResposta == 1){
						Arvore* novaPergunta = criaArvore(pergunta,false);
						insereArvoreDireita(aux,novaPergunta);
					}else{
						Arvore* novaResposta = criaArvore(pergunta,true);
						insereArvoreDireita(aux,novaResposta);
					}
					aux = aux->direita;
				}
			}
		}
		
		system("clear || cls");	
	}while(resposta != 3);
	return arvore;
}


