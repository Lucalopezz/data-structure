#include "Aluno.h"

typedef struct pilha Pilha;

Pilha *criarPilha();
int push(Pilha *p, Aluno *aluno);
Aluno *pop(Pilha *p);
Aluno *peek(Pilha *p);
void destroy(Pilha *p);

void printPilha(Pilha *p);
