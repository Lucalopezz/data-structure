#define ERROR 0
#define SUCCESS 1

// Estrutura em pilha para o analisador sintático
typedef struct compilador Compilador;

Compilador *criarCompilador();
int pushCompilador(Compilador *c, char simbolo);
int peekCompilador(Compilador *c, char *simbolo);
int popCompilador(Compilador *c);
// Posso tirar esse pilha cheia, pra ele n aparecer na main
int pilhaCheia(Compilador *c);
int pilhaVazia(Compilador *c);


void destroyCompilador(Compilador *c);
