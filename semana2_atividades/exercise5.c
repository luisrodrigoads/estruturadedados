#include <stdio.h>
#include <stdlib.h>

/* RESPOSTAS 

   1)valor de b[2] é 2, valor de &b[2] é 0x55b35f2ec408, vale ressaltar que
   o valor de &b[2] muda a cada execução do programa, sendo este valor obtido
   em das execuções.

   2) A diferença é que enquanto o b[2] refere-se ao valor contido na variável,
   o &b[2] faz referência que é dada pelo operador & ao endereço da célula na 
   memória.
*/

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