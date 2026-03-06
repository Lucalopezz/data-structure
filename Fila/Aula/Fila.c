#include <stdio.h>  // printf -> se n tivesse no tad, podia tirar daqui
#include <stdlib.h> // maloc, free
#include "Fila.h"

#define MAXTAM 5

struct fila
{
    int dados[MAXTAM];
    int inicio;
    int fim;
    int qtd;
};

Fila *criarFila()
{
    Fila *f = (Fila *)malloc(sizeof(Fila));
    if (f != NULL)
    {
        f->inicio = 0;
        f->fim = -1;
        f->qtd = 0;
    }
    return f;
}
int filaCheia(Fila *f)
{
    return f->qtd == MAXTAM;
}
int filaVazia(Fila *f)
{
    return f->qtd == 0;
}
int enfileirar(Fila *f, int valor)
{
    if (filaCheia(f))
        return ERROR;

    f->fim = (f->fim + 1) % MAXTAM; // circular
    f->dados[f->fim] = valor;
    f->qtd++;
    return SUCCESS;
}
int desenfileirar(Fila *f, int *valor)
{
    if (filaVazia(f))
        return ERROR;

    *valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAXTAM; // circular
    f->qtd--;
    return SUCCESS;
}
int obterPrimeiro(Fila *f, int *valor)
{
    if (filaVazia(f))
        return ERROR;

    *valor = f->dados[f->inicio];
    return SUCCESS;
}
void liberarFila(Fila *f)
{
    free(f);
}

void imprimirFila(Fila *f)
{
    if (filaVazia(f))
    {
        printf("Fila vazia");
    }
    else
    {
        printf("\n");
        printf("Fila: ");
        int indice = f->inicio;
        for (int cont = 1; cont <= f->qtd; cont++)
        {
            printf("%d ", f->dados[indice]);
            indice = (indice + 1) % MAXTAM; // circular
            printf("\n");
        }
    }
}
