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

Pilha* leitura_inicial_arquivo(Pilha* p);//carrega os dados do arquivo na pilha
void salva_dados_no_arquivo(Pilha* p);//salva os novos dados no arquivo

main(){
	
	int opcao;
	
	setlocale(LC_ALL,"");
	
	printf("inicio do Programa de Pilhas\n");

	Pilha * duracel;
	duracel = leitura_inicial_arquivo(duracel);
	
	Pilha * duracel_nova;
	duracel_nova = pilha_cria();
	int vazia=1;
	char tmp[30];
		
	do{
		imprime_menu();
		scanf("%d",&opcao);
		switch(opcao){
			case 1:
				limpa_tela();
				if(!pilha_vazia(duracel_nova)){
					imprime_pilha(duracel_nova);
				}else{
					imprime_pilha(duracel);
				}
				
				printf("\n-----------------------------");
				printf("\nPara voltar digite [s]: ");
				scanf("%s",tmp);
				if(strcmp(tmp,"s") == 0)
					break;
				
			case 2:
				
				
				if(!pilha_vazia(duracel_nova))
					vazia = 0;
					
				do{
					limpa_tela();
					fflush(stdin);
					printf("\nCaso queira voltar ao menu principal e salvar dados digite [s]\n");
					printf("-----------------------------");
					printf("\nDigite o nome da peça a retirar: ");
					scanf("%[^\n]",tmp);
					
					if(strcmp(tmp,"s") != 0){
						if(vazia == 0){
							pilha_libera(duracel_nova);
							duracel_nova = pilha_cria();
							vazia = 1;
						}
						push(duracel_nova,tmp);
					}
						
							
				}while(strcmp(tmp,"s") != 0);
				
				if(pilha_vazia(duracel_nova)){
					break;
				}else{
					salva_dados_no_arquivo(duracel_nova);
					break;
				}

			default:
				break;	
		}
	}while(opcao != 3);
	
	pilha_libera(duracel);
	pilha_libera(duracel_nova);
		
	system("pause");
          
}

Pilha* leitura_inicial_arquivo(Pilha* p){
	
	char linha[1024];
	char * ultima;
	FILE *file;
	
	p = pilha_cria();
	
	if((file = fopen("arquivo.txt","r")) != NULL){
		while(!feof(file)){
			fgets(linha,1024,file);
			ultima = strtok(linha,"\\");
			while(ultima != NULL){
				push(p,ultima);
				ultima = strtok(NULL,"\\");
			}
		}
		fclose(file);
	}
	
	return p;	
}

void salva_dados_no_arquivo(Pilha* p){
	
	FILE *file;
	
	file = fopen("arquivo.txt","w+");
	
	Lista * q;
	for(q = p->prim;q != NULL;q = q->prox){
		fprintf(file,"%s \\",q->info);
	}
	fclose(file);
	printf("\nSalvando no arquivo e substituindo por novo manual");
	
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

