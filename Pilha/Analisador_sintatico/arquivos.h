#include <stdio.h>

#define ERROR 0
#define SUCCESS 1

FILE *abre_arquivo(char *nome_arquivo, char *modo);
void fecha_arquivo(FILE *arquivo);
