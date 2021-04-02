# Programa

Uma loja de carros (Institute Veículos) quer que você desenvolva um sistema para gerenciar o processo de Venda e Estoque dos carros novos. Atualmente é controlado de forma manual (papel) e houveram muitos erros e por isso necessitam urgente do sistema.

## O processo na loja é o seguinte:

Como nesse momento não há carros novos, todos os clientes são colocados em uma lista de espera. Considerando que é uma lista, a ordem é dada pelo primeiro que faz o pedido, será primeiro a receber o veiculo (quando chegar).
Além disso, o sistema gerencia a ordem de transporte do carro da “cegonha” (nome dado ao veiculo que transporte os carros novos) até a chegada na loja, organizando o estoque. A ordem de entrega é dada pela ordem de inserção de carros no estoque, o primeiro carro que entra no estoque será o último a sair do estoque.

## Você deve fazer um sistema que gerencie os clientes, o estoque e as entregas.

Um detalhe muito importante é que o cliente irá receber o carro novo conforme o estoque (ele não tem o direito de escolha) ou seja, se o Carro A é o primeiro a no estoque, será o vendido ao primeiro cliente da Fila, o Carro B, será vendido ao segundo cliente da fila e assim sucessivamente, até não ter mais carros ou clientes (não posso entregar se não tenho mais carro disponível ou se na há clientes na fila).

Os dados serão armazenados obrigatoriamente em um arquivo chamada “clientes.txt” e “carros.txt” (conteúdo separado por |  - pipe)

Dados do Cliente:  Nome, CPF e Telefone.

Dados do Carro:  Modelo,Numero do  Chassi e Cor.

O conjunto de dados é indeterminado, ou seja, pode ser gerado um arquivo de dados com 1 ou 1 milhão de registros e o sistema precisa atender todas as demandas que deve ser carregado no inicio do programa.

## O menu principal deve conter:

[1] – Cadastrar Clientes

[2]- Visualizar Clientes

[3] – Cadastrar Carro no Estoque

[4] – Visualizar Carros no Estoque

[5]- Entregar Carro/Cliente

[6] – Gerar arquivo de Clientes Ordenado (Nome)

[7] - Sair