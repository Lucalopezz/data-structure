#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pilha.h"

struct pilha
{
    Aluno **alunos;
    int topo;
    int capacidade;
};

// struct pilha
// {
//     Aluno alunos[MAX]; // vetor estático
//     int topo;
// };


// Pilha *criarPilha()
// {
//     Pilha *p = malloc(sizeof(Pilha));
//     if (!p)
//         return NULL;

//     p->topo = -1;
//     return p;
// }
Pilha *criarPilha()
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    if (p == NULL)
    {
        return NULL;
    }
    p->capacidade = 10;
    p->topo = -1;
    p->alunos = malloc(p->capacidade * sizeof(Aluno *));
    if (p->alunos == NULL)
    {
        free(p);
        return NULL;
    }
    return p;
}

// int push(Pilha *p, Aluno aluno)
// {
//     if (!p)
//         return ERROR;

//     if (p->topo == MAX - 1)
//         return ERROR; // pilha cheia

//     p->alunos[++p->topo] = aluno; // copia struct
//     return SUCCESS;
// }
int push(Pilha *p, Aluno *aluno)
{
    if (!p || !aluno)
        return ERROR;

    if (p->topo == p->capacidade - 1)
    {
        p->capacidade *= 2;

        Aluno **novoArray =
            realloc(p->alunos, p->capacidade * sizeof(Aluno *));

        if (!novoArray)
            return ERROR;

        p->alunos = novoArray;
    }

    p->alunos[++p->topo] = aluno; // guarda ponteiro
    return SUCCESS;
}
// int pop(Pilha *p, Aluno *aluno)
// {
//     if (!p || p->topo == -1)
//         return ERROR;

//     *aluno = p->alunos[p->topo--];
//     return SUCCESS;
// }
Aluno *pop(Pilha *p)
{
    if (p == NULL || p->topo == -1)
    {
        return NULL;
    }
    return p->alunos[p->topo--];
}

// int peek(Pilha *p, Aluno *aluno)
// {
//     if (!p || p->topo == -1)
//         return ERROR;

//     *aluno = p->alunos[p->topo];
//     return SUCCESS;
// }
Aluno *peek(Pilha *p)
{
    if (p == NULL || p->topo == -1)
    {
        return NULL;
    }
    return p->alunos[p->topo];
}
// void destroy(Pilha *p)
// {
//     free(p);
// }
void destroy(Pilha *p)
{
    if (!p)
        return;

    for (int i = 0; i <= p->topo; i++)
        liberarAluno(p->alunos[i]);

    free(p->alunos);
    free(p);
}

// void printPilha(Pilha *p)
// {
//     if (!p || p->topo == -1)
//     {
//         printf("Pilha vazia\n");
//         return;
//     }

//     printf("Pilha:\n");

//     for (int i = p->topo; i >= 0; i--)
//     {
//         int pront;
//         char nome[100];

//         obterProntuario(&p->alunos[i], &pront);
//         obterNomeAluno(&p->alunos[i], nome);

//         printf("Prontuario: %d, Nome: %s\n", pront, nome);
//     }
// }
void printPilha(Pilha *p)
{
    if (p == NULL)
    {
        printf("Pilha vazia\n");
        return;
    }
    printf("Pilha: ");
    for (int i = p->topo; i >= 0; i--)
    {
        int pront;
        char nome[100];
        obterProntuario(p->alunos[i], &pront);
        obterNomeAluno(p->alunos[i], nome);
        printf("Prontuario: %d, Nome: %s \n", pront, nome);
    }
    printf("\n");
}