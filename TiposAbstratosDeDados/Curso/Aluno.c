#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aluno.h"

struct aluno
{
    char prontuario[10];
    char nome[100];
    Curso *curso;
};

Aluno *criarAluno(char *prontuario, char *nome, Curso *curso)
{
    Aluno *novoAluno = (Aluno *)malloc(sizeof(Aluno));
    if (novoAluno == NULL)
    {
        printf("Erro ao alocar memoria\n");
        return NULL;
    }
    strcpy(novoAluno->nome, nome);
    strcpy(novoAluno->prontuario, prontuario);
    novoAluno->curso = curso;

    return novoAluno;
}
void obterProntuario(Aluno *aluno, char *prontuario)
{
    if (aluno != NULL)
        strcpy(prontuario, aluno->prontuario);
}
void obterNomeAluno(Aluno *aluno, char *nome)
{
    if (aluno != NULL)
        strcpy(nome, aluno->nome);
}
Curso *obterCurso(Aluno *aluno)
{
    if (aluno != NULL)
        return aluno->curso;
}
void liberarAluno(Aluno *aluno)
{
    free(aluno);
}