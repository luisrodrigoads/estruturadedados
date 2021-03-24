#include<stdio.h>
#include<stdlib.h>

int somatorio (int x){
	if(x == 1)
		return (1);
	else
		return (x + somatorio(x-1));
}

main(){
	
	int valor;
	printf("\nDigite um numero inteiro: ");
	scanf("%d",&valor);
	
	printf("\nO somatorio de %d eh: %d",valor,somatorio(valor));
}
