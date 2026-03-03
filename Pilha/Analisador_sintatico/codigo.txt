#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

#define MAXTAM 5

struct pilha
{
    int item[MAXTAM];
    int topo;
};

Pilha *criarPilha()
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    if (p != NULL)
        p->topo = -1;
    return p;
}

int pilhaCheia(Pilha *p)
{
    return p->topo == MAXTAM - 1;
}
int pilhaVazia(Pilha *p)
{
    return p->topo == -1;
}

int push(Pilha *p, int valor)
{
    if (pilhaCheia(p))
        return ERROR;

    p->topo++;
    p->item[p->topo] = valor;
    return SUCCESS;
}
int pop(Pilha *p, int *valor)
{
    if (pilhaVazia(p))
        return ERROR;
    *valor = p->item[p->topo];
    p->topo--;
    return SUCCESS;
}

int peek(Pilha *p, int *valor)
{
    if (pilhaVazia(p))
        return ERROR;
    *valor = p->item[p->topo];
    return SUCCESS;
}

void destroy(Pilha *p)
{
    free(p);
}

void printPilha(Pilha *p)
{
    if (pilhaVazia(p))
    {
        printf("Pilha vazia\n");
        return;
    }
    printf("Pilha: ");
    for (int i = p->topo; i >= 0; i--)
    {
        printf("%d ", p->item[i]);
    }
    printf("\n");
}