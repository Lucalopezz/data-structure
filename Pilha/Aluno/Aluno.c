#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aluno.h"

struct aluno
{
    int prontuario;
    char nome[100];
};

Aluno *criarAluno(int prontuario, char *nome){
    Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));
    if (aluno == NULL)
    {
        return NULL;
    }
    aluno->prontuario = prontuario;
    strcpy(aluno->nome, nome);
    return aluno;
}
int obterProntuario(Aluno *aluno, int *prontuario){
    if (aluno == NULL || prontuario == NULL)
    {
        return ERROR;
    }
    *prontuario = aluno->prontuario;
    return SUCCESS;
}
int obterNomeAluno(Aluno *aluno, char *nome){
    if (aluno == NULL || nome == NULL)
    {
        return ERROR;
    }
    strcpy(nome, aluno->nome);
    return SUCCESS;
}
void liberarAluno(Aluno *aluno){
    free(aluno);
}