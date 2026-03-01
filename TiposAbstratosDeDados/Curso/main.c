#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Curso.h"
#include "Aluno.h"

int main()
{

    Curso *curso1 = criarCurso("ADS", "Análise e Desenvolvimento de Sistemas");
    Curso *curso2 = criarCurso("BES", "Bach. Engenharia de Software");

    Aluno *aluno1 = criarAluno("João", "12345", curso1);
    Aluno *aluno2 = criarAluno("Maria", "67890", curso2);

    char nomeAluno[100];
    obterNomeAluno(aluno2, nomeAluno);

    Curso *cursoAluno = obterCurso(aluno2);
    char nomeCurso[100];
    obterNomeCurso(cursoAluno, nomeCurso);

    char prontuario[10];
    obterProntuario(aluno2, prontuario);

    printf("Pront: %s, Nome: %s, Curso: %s \n", nomeAluno, prontuario, nomeCurso);

    liberarCurso(curso1);
    liberarCurso(curso2);
    liberarAluno(aluno1);
    liberarAluno(aluno2);

    return 0;
}