#include<stdio.h>

int main(){
	
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            if((j >= i)){
                printf(" x");
            }else{
                printf(" -");
            }
        }
        printf("\n");
    }
	
	return 0;
}