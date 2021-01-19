#include<stdio.h>
#include<string.h>

int main()
{
    char name[30];
    int age;
    int option;
    FILE *file;

    printf("\nDigite um nome qualquer a ser gravado: ");
    scanf("%s",name);

    printf("\nDigite uma idade qualquer a ser gravada: ");
    scanf("%d",&age);

    printf("\nCaso queira sobrescrever dados do arquivo digite 1.");
    printf("\nCaso queira adicionar ao final do arquivo digite qualquer tecla.\n");
    scanf("%d",&option);

    printf("\nGravando dados no arquivo...");

    if((file = fopen("dados2.txt",option == 1 ? "w+" : "a+")) == NULL)
        printf("Erro ao abrir arquivo");
    else {
        fprintf(file,"%s\t%d\n",name,age);
        fclose(file);
    }

    printf("\nFIM\n");

    return 0;
}
