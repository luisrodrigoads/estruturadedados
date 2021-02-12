#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

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

