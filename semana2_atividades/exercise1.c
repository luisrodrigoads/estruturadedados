#include<stdio.h>
#include<stdlib.h>

int main(){
    
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            if(i==j)
                printf(" x");
            else
                printf(" -");            
        }
        printf("\n");
    }

    return 0;
}
