#include "Lista.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 5

struct lista
{
    int items[MAX_SIZE];
    int quantidade;
};

Lista *criar_lista()
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    if (lista != NULL)
    {
        lista->quantidade = 0;
    }
    return lista;
}

int listaCheia(Lista *lista)
{
    return lista->quantidade == MAX_SIZE;
}
int listaVazia(Lista *lista)
{
    return lista->quantidade == 0;
}

int inserir(Lista *lista, int valor, int posicao)
{
    if (listaCheia(lista))
        return ERROR;
    if (posicao < 0 || posicao > lista->quantidade)
        return ERROR;
    for (int i = lista->quantidade; i > posicao; i--)
    {
        lista->items[i] = lista->items[i - 1];
    }
    lista->items[posicao] = valor;
    lista->quantidade++;
    return SUCCESS;
}
int remover(Lista *lista, int posicao, int *valorRemovido)
{
    if (listaVazia(lista))
        return ERROR;
    if (posicao < 0 || posicao >= lista->quantidade)
        return ERROR;
    *valorRemovido = lista->items[posicao];
    for (int i = posicao; i < lista->quantidade - 1; i++)
    {
        lista->items[i] = lista->items[i + 1];
    }
    lista->quantidade--;
    return SUCCESS;
}
void liberar_lista(Lista *lista)
{
    free(lista);
}

int buscar(Lista *lista, int valorProcurado, int *posicaoEncontrada)
{
    for (int i = 0; i < lista->quantidade; i++)
    {
        if (lista->items[i] == valorProcurado)
        {
            *posicaoEncontrada = i;
            return SUCCESS;
        }
    }
    return ERROR;
}

void imprimir_lista(Lista *lista)
{
    printf("Lista: ");
    for (int i = 0; i < lista->quantidade; i++)
    {
        printf("%d ", lista->items[i]);
    }
    printf("\n");
}