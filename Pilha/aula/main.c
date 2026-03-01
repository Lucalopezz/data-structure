#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

void empilhar(Pilha *p, int valor)
{
    if (push(p, valor))
        printf("Valor %d empilhado com sucesso.\n", valor);
    else
        printf("Erro ao empilhar o valor %d. Pilha cheia.\n", valor);
}



int main()
{
    Pilha *p = criarPilha();
    if(p == NULL)
    {
        printf("Erro ao criar a pilha.\n");
        return 1;
    }
    int valor;

    empilhar(p, 10);
    empilhar(p, 20);
    empilhar(p, 30);
    empilhar(p, 40);
    empilhar(p, 50);
    empilhar(p, 60);

    printPilha(p);

    if (peek(p, &valor))
        printf("Valor no topo: %d\n", valor);

    if (pop(p, &valor))
        printf("Valor removido: %d\n", valor);

    printPilha(p);

    destroy(p);
    return 0;
}