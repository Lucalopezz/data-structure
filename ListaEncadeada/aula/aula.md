Até agora tinhamos visto apenas estruturas sequenciais estáticas, ou seja, aquelas que tem um tamanho pré-definido. Agora vamos aprender a criar estruturas dinâmicas, ou seja, aquelas que podem crescer e diminuir de acordo com a necessidade do programa.

A estrutura dinâmica mais simples é a lista encadeada, onde cada elemento da lista é um nó que contém um valor e um ponteiro para o próximo nó da lista.

Percorrer uma lista encadeada é simples, basta seguir os ponteiros até chegar no final da lista, onde o ponteiro do último nó aponta para NULL. Com uma variável auxiliar, podemos acessar cada elemento da lista e realizar as operações desejadas, como imprimir os valores ou modificar os dados.

````
No *aux = lista->inicio;
while (aux != NULL) {
    printf("%d ", aux->valor);
    aux = aux->proximo;
}
````

Funcionamento da uma lista encadeada:

<img src="https://media.geeksforgeeks.org/wp-content/uploads/20250619155958124670/Linked-list.webp" alt="Lista Encadeada" width="400"/>