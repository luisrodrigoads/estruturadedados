#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    char nome[20];
    int idade;
} Cpessoa;

int main(void){ 

    Cpessoa *paluno;
    int tam=0;
    int opcao;

    paluno = (Cpessoa *) malloc(sizeof(Cpessoa));

    while (opcao != 0){
        system("clear || cls");
        paluno= (Cpessoa*) realloc(paluno, (sizeof(Cpessoa) * (tam+1)));
        printf("\nDigite o nome: ");
        scanf("%s",paluno[tam].nome);
        printf("\nDigite a idade: ");
        scanf("%d",&paluno[tam].idade);
        printf("\nPara continuar a inserir dados digite:\n[1] sim\n[0] nao\n");
        scanf("%d",&opcao);
        if(opcao == 0)
            break;

        tam++;
    }
    
    for (int i = 0; i<(tam+1); i++){
        printf("\nnome: %s\nidade: %d\n", paluno[i].nome, paluno[i].idade);
    }
    
}