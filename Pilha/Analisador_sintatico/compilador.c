#include <stdlib.h>
#include <stdio.h>
#include "compilador.h"

struct compilador
{
    char *codigo;
    int topo;
    int capacidade;
};

int pilhaCheia(Compilador *p)
{
    return p->topo == p->capacidade - 1;
}
int pilhaVazia(Compilador *p)
{
    return p->topo == -1;
}

Compilador *criarCompilador()
{
    Compilador *c = malloc(sizeof(Compilador));
    if (!c)
        return NULL;

    c->capacidade = 4;
    c->topo = -1;
    c->codigo = malloc(c->capacidade * sizeof(char));

    if (!c->codigo)
    {
        free(c);
        return NULL;
    }

    return c;
}
int pushCompilador(Compilador *c, char simbolo)
{
    if (c->topo + 1 == c->capacidade)
    {
        c->capacidade *= 2;

        char *novo = realloc(c->codigo, c->capacidade * sizeof(char));

        if (!novo)
            return ERROR;

        c->codigo = novo;
    }

    c->topo++;
    c->codigo[c->topo] = simbolo;

    return SUCCESS;
}
int peekCompilador(Compilador *c, char *simbolo)
{
    if (pilhaVazia(c))
        return ERROR;
    *simbolo = c->codigo[c->topo];
    return SUCCESS;
}
int popCompilador(Compilador *c)
{
    if (pilhaVazia(c))
        return ERROR;
    c->topo--;
    return SUCCESS;
}
void destroyCompilador(Compilador *c)
{
    free(c->codigo);
    free(c);
}
