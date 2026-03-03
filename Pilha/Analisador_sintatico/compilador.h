#define ERROR 0
#define SUCCESS 1

// Estrutura em pilha para o analisador sintático
typedef struct compilador Compilador;

Compilador *criarCompilador();
int pushCompilador(Compilador *c, char simbolo);
int peekCompilador(Compilador *c, char *simbolo);
int popCompilador(Compilador *c);
int pilhaCheia(Compilador *c);
int pilhaVazia(Compilador *c);
void destroyCompilador(Compilador *c);
