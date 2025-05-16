/******************************************************************************
Elabore um algoritmo que permita cadastrar até 10 clientes, 
exiba um menu que permita efetuar o cadastro e exibir os clientes cadastrados

*******************************************************************************/
#include <stdio.h>
#include <string.h>

int main() {
    struct cliente {
        int codigo;
        char nome[50];
        char sexo;
        int idade;
    };

    struct cliente clientes[10];
    int op = -1;
    int posAtual = 0;

    while (op != 0) {
        printf("\n1 - Cadastrar Cliente\n");
        printf("2 - Exibir Clientes\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &op);
        getchar(); // Limpa o buffer do teclado

        switch (op) {
            case 1:
                if (posAtual < 10) {
                    printf("\nInforme o código do cliente: ");
                    scanf("%d", &clientes[posAtual].codigo);
                    getchar(); // Limpa o buffer do teclado

                    printf("Informe o nome do cliente: ");
                    fgets(clientes[posAtual].nome, 50, stdin);
                    clientes[posAtual].nome[strcspn(clientes[posAtual].nome, "\n")] = '\0'; // Remove o \n

                    printf("Informe o sexo do cliente (M/F): ");
                    scanf(" %c", &clientes[posAtual].sexo);

                    printf("Informe a idade do cliente: ");
                    scanf("%d", &clientes[posAtual].idade);

                    posAtual++;
                    printf("\nCliente cadastrado com sucesso!\n");
                } else {
                    printf("\nCadastro cheio! Não é possível adicionar mais clientes.\n");
                }
                break;

            case 2:
                if (posAtual == 0) {
                    printf("\nNenhum cliente cadastrado.\n");
                } else {
                    printf("\nLista de Clientes:\n");
                    for (int i = 0; i < posAtual; i++) {
                        printf("Código: %d | Nome: %s | Sexo: %c | Idade: %d\n", 
                               clientes[i].codigo, clientes[i].nome, clientes[i].sexo, clientes[i].idade);
                    }
                }
                break;

            case 0:
                printf("\nSaindo do sistema...\n");
                break;

            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
    }

    return 0;
}

