#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    Lista *lista = criar_lista();
    if (lista == NULL)
    {
        printf("Erro ao criar lista\n");
        return 1;
    }

    inserir(lista, 10, 0);
    inserir(lista, 20, 1);
    inserir(lista, 30, 2);

    int posicaoEncontrada;

    buscar(lista, 20, &posicaoEncontrada);
    printf("Posição encontrada: %d\n", posicaoEncontrada);

    
    imprimir_lista(lista);

    int valorRemovido;
    remover(lista, 1, &valorRemovido);
    printf("Valor removido: %d\n", valorRemovido);

    imprimir_lista(lista);

    liberar_lista(lista);

    return 0;
}