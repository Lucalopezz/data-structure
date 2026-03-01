#include "Curso.h"

typedef struct aluno Aluno;

Aluno *criarAluno(char *prontuario, char *nome, Curso *curso);
void obterProntuario(Aluno *aluno, char *prontuario);
void obterNomeAluno(Aluno *aluno, char *nome);
Curso *obterCurso(Aluno *aluno);
void liberarAluno(Aluno *aluno);