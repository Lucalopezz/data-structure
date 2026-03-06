#include <stdio.h>
#include "Fila.h"

int main()
{
    Fila *f = criarFila();
    if (f == NULL)
    {
        printf("Erro ao criar a fila.\n");
        return 1;
    }
    int valor;

    enfileirar(f, 10);
    enfileirar(f, 20);
    enfileirar(f, 30);

    imprimirFila(f);

    desenfileirar(f, &valor);
    printf("Elemento desenfileirado: %d\n", valor);

    printf("\n");
    enfileirar(f, 40);
    enfileirar(f, 50);
    enfileirar(f, 60);

    desenfileirar(f, &valor);
    printf("Elemento desenfileirado: %d\n", valor);

    enfileirar(f, 70);

    imprimirFila(f);

    liberarFila(f);
    return 0;
}