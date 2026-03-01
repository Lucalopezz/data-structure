#include <stdio.h>
#include <stdlib.h>
#include "fracao.h"


// gcc *.c -o main
int main()
{
    Fracao *f1 = criarFracao(3, 4);
    Fracao *f2 = criarFracao(1, 2);

    printf("Fração 1: %d/%d \n", obterNumerador(f1), obterDenumerador(f1));
    printf("Fração 2: %d/%d \n", obterNumerador(f2), obterDenumerador(f2));

    Fracao *soma = somarFracao(f1, f2);
    printf("Soma: %d/%d \n", obterNumerador(soma), obterDenumerador(soma));

    printf("Fracao 2 em decimal: %f \n", converterParaDecimal(f2));

    liberarFracao(f1);
    liberarFracao(f2);

    return 0;
}