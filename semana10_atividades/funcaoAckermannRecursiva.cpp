#include<stdio.h>
#include<stdlib.h>

/* a(m,n) 	-> m=0 -> a(m,n+1)
			-> m > 0 e n = 0 -> a(m-1,1)
			-> m > 0 e n > 0 -> a(m-1, a(m,n-1))


*/

int A(int m, int n){
	if(m == 0)
		return n + 1;
	if((m > 0) && (n == 0))
		return A(m - 1,1);
	else if((m > 0) && (n > 0))
		return A(m - 1, A(m,n - 1));
}

main(){
	printf("\nO resultado da funcao de ackermann(%d,%d) eh %d",2,1,A(2,1));
}
