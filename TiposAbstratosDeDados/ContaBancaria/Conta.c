#include <stdio.h>
#include <stdlib.h>
#include "Conta.h"

struct conta
{
    int num;
    double saldo;
};

Conta *criarConta(int num, double saldo)
{
    Conta *c = (Conta *)malloc(sizeof(Conta));
    if (c == NULL)
    {
        printf("Erro ao alocar memoria\n");
        return NULL;
    }
    c->num = num;
    c->saldo = saldo;
    return c;
}

int depositar(Conta *conta, double valor)
{
    if (valor <= 0)
    {
        return ERROR;
    }
    conta->saldo += valor;
    return SUCCESS;
}
int sacar(Conta *conta, double valor)
{
    if (valor <= 0)
    {
        return ERROR;
    }
    conta->saldo -= valor;
    return SUCCESS;
}
int transferir(Conta *origem, Conta *destino, double valor)
{
    if (valor <= 0)
    {
        return ERROR;
    }
    origem->saldo -= valor;
    destino->saldo += valor;
    return SUCCESS;
}

int obterNum(Conta *conta)
{
    return conta->num;
}
double obterSaldo(Conta *conta)
{
    return conta->saldo;
}
void liberarConta(Conta *conta)
{
    free(conta);
}