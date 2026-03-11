#include <stdio.h>
#include "Fila.h"

int main()
{
    int valor;
    Fila *par = criarFila();
    Fila *impar = criarFila();
    do
    {
        printf("Digite o numero que quiser e 0 para sair (maximo 20 vezes):  \n");
        scanf("%d", &valor);
        if (valor == 0)
            break;
        if (valor % 2 == 0)
        {
            if (enfileirar(par, valor))
            {
                printf("Entrou na lista par \n");
                continue;
            }
            return 1;
        }
        else
        {
            if (enfileirar(impar, valor))
            {
                printf("Entrou na lista impar \n");
                continue;
            }
            return 1;
        }
    } while (1);

    printf("\n Fila par \n");
    imprimirFila(par);
    printf("\n Fila impar \n");
    imprimirFila(impar);

    while (!filaVazia(impar) || !filaVazia(par))
    {
        int valor;
        if (!filaVazia(impar))
        {
            desenfileirar(impar, &valor);
            printf("\nSaiu: %d", valor);
        }
        if (!filaVazia(par))
        {
            desenfileirar(par, &valor);
            printf("\nSaiu: %d", valor);
        }
    }
    printf("\nAcabou");

    return 1;
}