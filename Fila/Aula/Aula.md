## Fila

First in, first out (FIFO)
Inicio = 0;
Fim = -1;
Operações:

- Criar fila
- Enfileirar (inserir)
- Desenfileirar (remover)
- Verificar se a fila está vazia -> inicio > fim
- Verificar o tamanho da fila -> fim == maxtamanho - 1

Do modo acima, se a fila estiver cheia, não é possível enfileirar novos elementos, mesmo tirando elementos da fila.
Para resolver isso, podemos dar shift nos elementos da fila, ou seja, quando desenfileiramos um elemento, deslocamos os elementos restantes para o início da fila. <strong>No entanto, isso pode ser ineficiente.</strong>

## Fila Circular

Para resolver o problema da fila cheia, podemos usar uma fila circular. Nessa estrutura, quando o fim da fila é alcançado, ele volta para o início da fila, permitindo que novos elementos sejam enfileirados mesmo que o fim da fila tenha sido alcançado, desde que haja espaço disponível.

Inicio = 0;
Fim = -1;

Cria variavel qtd para contar a quantidade de elementos na fila.
Solução:

- Fila cheia: qtd == maxtamanho
- Fila vazia: qtd == 0
