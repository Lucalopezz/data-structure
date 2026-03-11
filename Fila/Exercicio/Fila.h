#define ERROR 0
#define SUCCESS 1

typedef struct fila Fila;

Fila *criarFila();
int enfileirar(Fila *f, int valor);
int desenfileirar(Fila *f, int *valor);
int obterPrimeiro(Fila *f, int *valor);
void liberarFila(Fila *f);

int filaCheia(Fila *f);
int filaVazia(Fila *f);

void imprimirFila(Fila *f);