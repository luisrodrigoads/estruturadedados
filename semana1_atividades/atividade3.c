#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

#define SIZE 15

int main()
{
    int id;
    char company[SIZE];
    char lastName[SIZE];
    char firstName[SIZE];
    char occupation[SIZE];

    FILE *file;

    setlocale(LC_ALL,"");

    printf("\nLendo arquivo...\n\n");

    if((file = fopen("arquivo.txt","r")) == NULL)
        printf("Erro ao abrir arquivo");
    else {
        printf("id \t empresa      sobrenome    nome         função\n");
        printf("-------------------------------------------------------------\n");
        while (!feof(file)){
            fscanf(file,"%d %s %s %s %s",&id,company,lastName,firstName,occupation);
            printf("%d \t %-12s %-12s %-12s %-12s\n",id,company,lastName,firstName,occupation);
        }
        fclose(file);
    }

    return 0;
}
