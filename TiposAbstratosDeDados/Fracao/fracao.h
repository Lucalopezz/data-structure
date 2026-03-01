typedef struct fracao Fracao;

Fracao *criarFracao(int numerador, int denominador);
Fracao *somarFracao(Fracao *f1, Fracao *f2);
float converterParaDecimal(Fracao *f);
int obterNumerador(Fracao *f);
int obterDenumerador(Fracao *f);
void liberarFracao(Fracao *f);