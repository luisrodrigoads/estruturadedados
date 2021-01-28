#include<stdio.h>
#include<stdlib.h>


#define SIZE 7

int main(){

    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){ 
            if( (i == j) || (j == (SIZE - (i + 1))) ){
                printf(" x");
            }else{
                printf(" -");   
            }
        }
        printf("\n");
    }

    return 0;
}