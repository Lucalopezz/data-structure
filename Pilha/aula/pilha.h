#define ERROR 0;
#define SUCCESS 1;

typedef struct pilha Pilha;

Pilha *criarPilha();
int push(Pilha *p, int valor);
int pop(Pilha *p, int *valor);
int peek(Pilha *p, int *valor);
void destroy(Pilha *p);

void printPilha(Pilha *p);
