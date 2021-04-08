#include<stdio.h>
#include<stdio.h>
#include "arvore.h"

main(){
	
	Arvore * a = arvore_cria('a');
    Arvore * x = arvore_cria('x');
    Arvore * b = arvore_cria('b');
    Arvore * c = arvore_cria('c');
    Arvore * d = arvore_cria('d');
    Arvore * e = arvore_cria('e');
    Arvore * f = arvore_cria('f');
    Arvore * g = arvore_cria('g');
    Arvore * y = arvore_cria('y');
    Arvore * h = arvore_cria('h');
    Arvore * i = arvore_cria('i');
    Arvore * j = arvore_cria('j');
    
    arvore_insere(a,b);
    arvore_insere(b,c);
    arvore_insere(a,x);
	arvore_insere(c,d);
    arvore_insere(d,e);
    arvore_insere(e,f);
    arvore_insere(f,g);
    arvore_insere(g,h);
    arvore_insere(g,y);
    arvore_insere(h,i);
    arvore_insere(i,j);
    
    arvore_imprime(a);
    
    printf("Altura: %d \n",arvore_altura(a));
    printf("Localizar: %d \n", arvore_localiza(a,'a'));
    
    system("pause");
}
