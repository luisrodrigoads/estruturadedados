#include<stdio.h>

#define SIZE 7

int main(){
	
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(j<= (SIZE/2) && (i <= (SIZE/2))){
                printf(" x");
            }else if((i >= (SIZE/2)) && (j >= (SIZE/2))){
                printf(" x");
            }else{
                printf(" -"); 
            }
        }
        printf("\n");
    }
	
	return 0;
}