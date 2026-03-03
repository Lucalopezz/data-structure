#include <stdlib.h>
#include <stdio.h>
#include "compilador.h"
#include "arquivos.h"

int main()
{
    Compilador *comp = criarCompilador();
    FILE *codigo = abre_arquivo("codigo.txt", "r");
    int c;
    int erro = 0;
    while ((c = getc(codigo)) != EOF)
    {
        if (c == '{')
        {
            if (pushCompilador(comp, '{') == ERROR)
            {
                erro = 1; // overflow da pilha
                break;
            }
        }
        else if (c == '}')
        {
            if (pilhaVazia(comp))
            {
                erro = 1; // fechou sem abrir
                break;
            }
            popCompilador(comp);
        }
    }

    if (!erro && pilhaVazia(comp))
        printf("Código sintaticamente correto.\n");
    else
        printf("Código sintaticamente incorreto.\n");

    destroyCompilador(comp);
    fecha_arquivo(codigo);

    return 0;
}