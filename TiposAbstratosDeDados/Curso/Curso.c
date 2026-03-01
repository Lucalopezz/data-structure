#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Curso.h"

struct curso
{
    char sigla[10];
    char nome[50];
};

Curso *criarCurso(char *sigla, char *nome)
{
    Curso *curso = (Curso *)malloc(sizeof(Curso));
    if (curso == NULL)
    {
        printf("Erro ao alocar memoria\n");
        return NULL;
    }
    strcpy(curso->nome, nome);
    strcpy(curso->sigla, sigla);

    return curso;
}
void obterSigla(Curso *c, char *sigla)
{
    if (c != NULL && sigla != NULL)
        strcpy(sigla, c->sigla);
}
void obterNomeCurso(Curso *c, char *nome)
{
    if (c != NULL && nome != NULL)
        strcpy(nome, c->nome);
}
void liberarCurso(Curso *c)
{
    free(c);
}