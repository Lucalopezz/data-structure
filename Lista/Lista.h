#define ERROR 0
#define SUCCESS 1

typedef struct lista Lista;

Lista *criar_lista();
int inserir(Lista *lista, int valor, int posicao);
int remover(Lista *lista, int posicao, int *valorRemovido);
void liberar_lista(Lista *lista);

int buscar(Lista *lista, int valorProcurado, int *posicaoEncontrada);


void imprimir_lista(Lista *lista);
