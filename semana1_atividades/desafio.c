#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

/*
Correct number of words according teacher is 61964
*/

#define SIZE 10000

int main(void){

    char line[SIZE];
    char * last;
    int numberOfWords=0;

    FILE *file;

    setlocale(LC_ALL,"");

    if((file = fopen("ConstituicaoBrasil88.txt","r")) == NULL){
        printf("Erro ao abrir arquivo");
    } else {
        while (!feof(file)){
            fgets(line, SIZE, file);
            last = strtok(line, " ");
                while(last != NULL){
                    numberOfWords++;
                    last = strtok(NULL, " ");  
                }
            
        }
        fclose(file);
    }
    printf("\n------------------------------------------\nA Constituição de 88 possui %d palavras\n------------------------------------------\n",numberOfWords);

    return 0;
}
