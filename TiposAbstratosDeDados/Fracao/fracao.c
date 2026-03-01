#include <stdio.h>
#include <stdlib.h>
#include "fracao.h"

struct fracao
{
    int numerador, denominador;
};

Fracao *criarFracao(int numerador, int denominador)
{
    Fracao *f = (Fracao *)malloc(sizeof(Fracao));
    if (f == NULL)
    {
        printf("Erro de alocação de memória\n");
        return NULL;
    }
    f->numerador = numerador;
    f->denominador = denominador;
    return f;
}

Fracao *somarFracao(Fracao *f1, Fracao *f2)
{
    int numerador = f1->numerador * f2->denominador + f2->numerador * f1->denominador;
    int denominador = f1->denominador * f2->denominador;
    return criarFracao(numerador, denominador);
}

float converterParaDecimal(Fracao *f)
{
    return (float)f->numerador / f->denominador;
}

int obterNumerador(Fracao *f)
{
    return f->numerador;
}

int obterDenumerador(Fracao *f)
{
    return f->denominador;
}

void liberarFracao(Fracao *f)
{
    free(f);
}