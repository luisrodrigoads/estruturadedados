#include<stdio.h>
#include "arvore.h"

main(){
	Arvore* raizPrincipal = NULL;
	int resposta;
	do{
		printf("******** Akinator  simplificado ********\n\n");
		printf("[1] - Jogar\n[2] - Sair\n");
		scanf("%d",&resposta);
		switch(resposta){
			case 1:
				raizPrincipal = carregaArvore(raizPrincipal);
				break;
			default:
				break;
		}
		
	}while(resposta != 2);
	
	return 0;
}
