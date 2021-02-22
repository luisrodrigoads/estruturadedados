#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct lista  Lista;

struct lista{
	char nome[30];
    int matricula;
    struct lista * proximo; 
};

//Operação Criacao 
Lista * cria_lista(void){
 	return (NULL);      
}

//Operação SET - setar matricula da Lista
Lista * set_lista(Lista * l, int a,char c[30]){
 Lista * novo = (Lista *) malloc (sizeof(Lista));
 strcpy(novo->nome,c);
 novo->matricula = a; 
 novo->proximo = l;
 return(novo);
}

//Mostra Lista
void view_lista(Lista * l){
	
	Lista * pl;
	
      for (pl = l; pl != NULL; pl = pl->proximo){
          printf("nome: %s \t matricula: %d\n",pl->nome,pl->matricula);
      }
}

//Verifica se a lista esta Vazia
int verifica_lista(Lista * l){
	
	if (l == NULL)    
	   printf("\nLista Vazia\n"); 
	else
	    printf("\nLista nao vazia\n"); 
}

//Procura um matricula na Lista
Lista * find_lista(Lista * l, int argumento){
	
     Lista * pl;
      for (pl = l; pl != NULL; pl = pl->proximo)
      {
          if (pl->matricula == argumento)
             return (pl);
      }
      return(NULL);
}


//Deletar matricula na lista
Lista * delete_elemento(Lista * pl, int argumento){
	
      Lista * anterior = NULL;
      Lista * atual = pl;
      
      while (atual != NULL && atual->matricula != argumento)
      {
            anterior = atual;
            atual = atual->proximo;
      }

      if (atual == NULL)
      {
         printf ("Elemento nao localizado!\n"); 
         return(pl);
      }
      
      if (anterior == NULL)
          pl = pl->proximo; 
      else
      {
          anterior->proximo = atual->proximo;
      }
      
      free(atual);
      return(pl);
}


//Liberar a lista
void free_lista(Lista ** pl){
	
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
	
	Lista * lis = cria_lista();
	
	verifica_lista(lis);
	
	lis = set_lista(lis,5,(char*)"luis");
	lis = set_lista(lis,4,(char*)"carlos");
	lis = set_lista(lis,9,(char*)"bruno");
	lis = set_lista(lis,2,(char*)"fernando");
	lis = set_lista(lis,1,(char*)"timoteo");
	
	view_lista(lis);
	
	
	Lista * tmp = find_lista(lis, 9);
	if (tmp != NULL)
	   printf("\n*************\nnome: %s\nmatricula: %d\n**********\n",tmp->nome,tmp->matricula);
	else 
	     printf("Valor nao Localizado\n");
	
	
	lis = delete_elemento(lis, 9);
	
	view_lista(lis);
	
	free_lista(&lis);
	
	verifica_lista(lis);
	
	view_lista(lis);
	
	system("pause");
        
}

