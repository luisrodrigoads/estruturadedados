#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

typedef struct pilha Pilha;
typedef struct lista Lista;

struct pilha{
	Lista * prim;
};

struct lista{
	char info[30];
	struct lista * prox;
};

Pilha* pilha_cria (void);//Cria a pilha vazia 
int pilha_vazia (Pilha* p);//Verfica de a pilha esta vazia
void push (Pilha* p, char c[30]);//Função insere (push)
char* pop( Pilha* p);//Função Para Remover (pop)
void pilha_libera (Pilha* p);//Libera a pilha
void imprime_pilha(Pilha* p);
void imprime_menu();
void limpa_tela();


main(){
	
	int opcao;
	
	setlocale(LC_ALL,"");
	
	printf("inicio do Programa de Pilhas\n");

	Pilha * duracel = pilha_cria();
	char tmp[30]; 
	
	//ver manual de montagem / cadastrar novo processo de desmontagem / sair
	
	do{
		imprime_menu();
		scanf("%d",&opcao);
		switch(opcao){
			case 1:
				imprime_pilha(duracel);
				printf("\n-----------------------------");
				printf("\nPara voltar digite [s]: ");
				scanf("%s",tmp);
				if(strcmp(tmp,"s") == 0)
					break;
				
			case 2:
				limpa_tela();
				printf("\nCaso queira voltar digite [s]\n");
				printf("-----------------------------");
				printf("\nDigite o nome da peça a retirar: ");
				scanf("%s",tmp);
				if(strcmp(tmp,"s") == 0){
					break;
				}else
					push(duracel,tmp);
				
			default:
				break;	
		}
	}while(opcao != 3);
	
	pilha_libera(duracel);
		
	system("pause");
          
}

//Cria a pilha vazia 
 Pilha* pilha_cria (void) {
	 Pilha* p = (Pilha*)malloc(sizeof(Pilha));
	 p->prim = NULL; //inicializa com zero elementos
	 return p;
 }

 //Verfica de a pilha esta vazia
 int pilha_vazia (Pilha* p){
   	return (p->prim == NULL); 
 }

 
 //Função insere (push)
 void push (Pilha* p, char c[30]){
	 Lista *n = (Lista *) malloc (sizeof(Lista));
	 strcpy(n->info,c);
	 //n->info = v;
	 n->prox = p->prim;
	 p->prim = n;
}
 
//Função Para Remover (pop)
char* pop( Pilha* p){
	Lista * t; 
	char c[30];
	if (pilha_vazia (p)){
	        return (char*)"Pilha esta vazia!\n";
	     }else{
	       t = p->prim; /*agora retira o elemento do topo da pilha*/
	       strcpy(c,t->info);
	       //v = t->info;
	       p->prim = t->prox;
	       free(t);
	       return c;
	      }
 }
   
//Libera a pilha
void pilha_libera (Pilha* p){
	 Lista * q = p->prim;
	 while (q!= NULL){
	  Lista * t = q->prox;
	  free(q); 
	  q=t;
	 }
	free(p);
 }
 
void imprime_pilha(Pilha* p){
	Lista * q;
	if(p->prim == NULL){
		printf("\nLista vazia");
	}else{
		for(q = p->prim;q != NULL;q = q->prox){
			printf("coloca %s\n",q->info);
		}
	}

}

void imprime_menu(){
	limpa_tela();
	printf("\n1 - Ler manual\n");
	printf("2 - Registrar nova desmontagem\n");
	printf("3 - Sair\n");
}
void limpa_tela(){
	system("clear || cls");
}

