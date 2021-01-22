#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

#define SIZE 5

int main(void)
{
    int listOfNumbers[SIZE];
    int position=0;
    int fileSize = 0;
    int num;

    FILE *file;

    setlocale(LC_ALL,"");

   
    if((file = fopen("listOfNumbers.txt","r")) == NULL){

                printf("\nVocê pode inserir até %d valores inteiros",SIZE);
            while(position < SIZE){
                printf("\n-----------------------------------------------");
                printf("\n %d valores restantes de %d",(SIZE - position),SIZE);
                printf("\n-----------------------------------------------");
                printf("\nDigite um numero inteiro maior que 0, ou negativo para sair: ");
                scanf("%d",&listOfNumbers[position]);
                
                if((listOfNumbers[position] < 1))
                    break;
                
                position++;
            };

            file = fopen("listOfNumbers.txt","w");

            for(int i=0;i<position;i++){
                fprintf(file,"%d\n",listOfNumbers[i]);
            }
        
        fclose(file);
    
    } else {
   
            while (fscanf(file,"%d",&num) == 1){//checks by the scanf return if it is a number   
                printf("%d\n",num);
                fileSize++;
            }

            if(fileSize < 1){
                   
                        printf("\nVocê pode inserir até %d valores inteiros",SIZE);
                    while(position < SIZE){
                        printf("\n-----------------------------------------------");
                        printf("\n %d valores restantes de %d",(SIZE - position),SIZE);
                        printf("\n-----------------------------------------------");
                        printf("\nDigite um numero inteiro maior que 0, ou negativo para sair e gravar os dados: ");
                        scanf("%d",&listOfNumbers[position]);
                        
                        if((listOfNumbers[position] < 1))  
                            break;
                        
                        position++;
                    };

                    file = fopen("listOfNumbers.txt","w");

                    for(int i=0;i<position;i++){
                        fprintf(file,"%d\n",listOfNumbers[i]);
                    }
            }

        fclose(file);
    }
    return 0;
}
