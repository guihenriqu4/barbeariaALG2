#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "colab.h"
#include "agendamento.h"

void menuPrincipal() {
    int opcao;

    do {
        printf("\n-- Sistema --\n");
        printf("1. Cadastrar cliente\n");
        printf("2. Listar clientes\n");
        printf("3. Alterar clientes");
        printf("4. Remover cliente\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
        case 1:
            inserirCliente();
            break;
        case 2:
            listarClientes();
        case 3:
            alterarClientes();
        case 4:
            removerClientes();
        case 5:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida, tente novamente.\n");

        }
    } while (opcao!=5);

}

int main()
{
    menuPrincipal();
    return 0;
}
