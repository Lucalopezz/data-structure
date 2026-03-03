#include <stdlib.h>
#include <stdio.h>
#include "arquivos.h"

FILE *abre_arquivo(char *nome_arquivo, char *modo)
{
    FILE *arquivo = fopen(nome_arquivo, modo);
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        exit(ERROR);
    }
    return arquivo;
}
void fecha_arquivo(FILE *arquivo)
{
    if (fclose(arquivo) != 0)
    {
        printf("Erro ao fechar o arquivo\n");
        exit(ERROR);
    }
}
