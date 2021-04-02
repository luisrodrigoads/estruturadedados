# Trabalho alocação dinâmica de memória

Faça um programa em C que cadastre alunos com suas respectivas notas. Para cada aluno, deverá ser armazenado 4 notas: N1, N2, N3 e N4, todas com uma casa decimal. Além disso, deverá armazenar a média das 4 notas,sempre com um casa decimal (calculado automaticamente). Também deverá armazenar o nome do aluno e a matricula (formado por 4 números)

## O programa deverá ter um menu principal, com as opções:

1) Novo Registro,
2) Salvar todos no Arquivo TXT,
3) Pesquisar Nome de Aluno e
4) Sair. (não conterá opções Alterar e Excluir, neste momento)

## Detalhes do Programa:

1) Sempre ao a abrir o programa, deverá ler os registros do arquivo TXT e carregar no vetor de Estruturas (registro), alocando de forma dinâmica mais uma posição no vetor (malloc).
2) Quando inserir um novo registro, deverá ser inserido no final do vetor (na posição livre e alocar mais uma posição de memória).
3) Quando usar a opção “Salvar”, deverá sobrescrever todo o arquivo com os dados do vetor de Estruturas.
4) A opção pesquisar, procura o nome,  realizando uma leitura seqüencial do vetor (mostrar o primeiro aluno encontrado, caso exista dois alunos com o mesmo nome). Caso encontre, deverá mostrar as notas e a média. Caso não localize, deverá mostrar uma mensagem informando que não foi possível localizar.
