#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pilha.h"
#include "Aluno.h"
void cria_poe_aluno(Pilha *p)
{
    int prontuario;
    char nome[50];
    printf("Digite o prontuario do aluno novo: ");
    scanf("%d", &prontuario);
    getchar(); // Limpar o buffer do teclado
    printf("Digite o nome do aluno novo: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';
    Aluno *novoAluno = criarAluno(prontuario, nome);

    if (novoAluno == NULL)
    {
        printf("Erro ao criar aluno!\n");
    }
    if (push(p, novoAluno) == ERROR)
    {
        printf("Erro ao adicionar aluno na pilha!\n");
        liberarAluno(novoAluno);
    }
}

int main()
{
    Pilha *pilha = criarPilha();
    int opc;
    do
    {
        printf("1. Adicionar aluno\n");
        printf("2. Remove ultimo aluno adicionado\n");
        printf("3. Ver topo da pilha\n");
        printf("4. Ver pilha\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opc);
        getchar(); // Limpar o buffer do teclado

        switch (opc)
        {
        case 1:
            cria_poe_aluno(pilha);
            break;
        case 2:
            pop(pilha);
            break;
        case 3:
            Aluno *a = peek(pilha);
            int prontuario;
            char *nome;
            obterProntuario(a, &prontuario);
            obterNomeAluno(a, nome);
            printf("Prontuario: %d, Nome: %s\n",
                   prontuario,
                   nome);
            break;
        case 4:
            printPilha(pilha);
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida! Tente novamente.\n");
            break;
        }
    } while (opc != 0);

    return 0;
}