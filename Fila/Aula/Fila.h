#define ERROR 0
#define SUCCESS 1

typedef struct fila Fila;

Fila *criarFila();
int enfileirar(Fila *f, int valor); // queue
int desenfileirar(Fila *f, int *valor);  // dequeue
int obterPrimeiro(Fila *f, int *valor);
void liberarFila(Fila *f);

// Função para imprimir os elementos da fila (opcional), é responsabilidade da camada de apresentação
void imprimirFila(Fila *f);
