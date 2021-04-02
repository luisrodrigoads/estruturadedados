# Recursividade

## Atividade 1
Fazer uma função recursiva que receba um valor como parâmetro de mostre o somatório do valor.
Ex: valor = 5
Calcular 5+4+3+2+1

## Atividade 2

A função de Ackermann é definida para valores inteiros e não negativos “m” e “n” da seguinte forma:

A(m,n) = { n + 1                se m=0

         { A(m - 1,1)           se m > 0 e n=0
         
         { A(m - 1,A(m,n-1))    se m > 0 e n > 0

Faça uma função recursiva para implementá-la.
Qual o valor de A(2,1)?