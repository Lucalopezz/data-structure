#define ERROR 0
#define SUCCESS 1

typedef struct aluno Aluno;

Aluno *criarAluno(int prontuario, char *nome);
int obterProntuario(Aluno *aluno, int *prontuario);
 obterNomeAluno(Aluno *aluno, char *nome);
void liberarAluno(Aluno *aluno);