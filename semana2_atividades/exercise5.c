#include <stdio.h>
#include <stdlib.h>
int main()
{
int *a, *b;
a = (int * ) malloc ( sizeof(int) * 100);
b = (int * ) malloc ( sizeof(int) * 3 );
for (int i = 0; i< 100; i++)
{
a[i] = 0;
}
b[0] = 0;
b[1] = 1;
b[2] = 2;
printf("valor %d - endereco %p \n",a[0] ,&a[0]);
printf("valor %d - endereco %p \n", a[1], &a[1]);
printf("valor %d - endereco %p \n", a[2], &a[2]);
printf("valor %d - endereco %p \n", b[0],&b[0]);
printf("valor %d - endereco %p \n", b[1],&b[1]);
printf("valor %d - endereco %p \n", b[2],&b[2]);
printf("--> a %ld\n", sizeof *a);
//system("pause");
return(0);
}