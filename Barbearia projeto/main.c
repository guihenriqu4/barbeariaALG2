#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/cliente.h"
#include "../headers/colab.h"
#include "../headers/agendamento.h"

Cliente *clientes = NULL;
Colab *colabs = NULL;
Agendamento *agendamentos = NULL;

void menuClientes() {
    int opcao;
    int retorno_scanf; // Variável para verificar o retorno do scanf

    do {
        printf("\n-- MENU CLIENTES --\n");
        printf("1. Cadastrar cliente\n");
        printf("2. Listar clientes\n");
        printf("3. Alterar cliente\n");
        printf("4. Remover cliente\n");
        printf("5. Voltar\n");
        printf("Escolha a opcao: ");

        retorno_scanf = scanf("%d", &opcao);

        if (retorno_scanf == 0) {
            // Se a leitura falhou, o usuário não digitou um número
            printf("Opcao invalida, tente novamente.\n");

            // Limpa o buffer de entrada
            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            opcao = 0; // Atribui um valor inválido para garantir que o menu continue
        } else {
            // Se a leitura foi um sucesso, executa o switch
            switch(opcao) {
                case 1:
                    inserirCliente(&clientes);
                    break;
                case 2:
                    listarClientes(clientes);
                    break;
                case 3:
                    alterarClientes(&clientes);
                    break;
                case 4:
                    removerClientes(&clientes);
                    break;
                case 5:
                    break;
                default:
                    printf("Opcao invalida, tente novamente.\n");
            }
        }
    } while (opcao != 5);
}

void menuColabs() {
    int opcao;
    int retorno_scanf; // Variável para verificar o retorno do scanf

    do {
        printf("\n-- MENU COLABORADORES --\n");
        printf("1. Cadastrar colaborador\n");
        printf("2. Listar colaboradores\n");
        printf("3. Alterar colaborador\n");
        printf("4. Remover colaborador\n");
        printf("5. Voltar\n");
        printf("Escolha a opcao: ");

        retorno_scanf = scanf("%d", &opcao);

        if (retorno_scanf == 0) {
            // Se a leitura falhou, o usuário não digitou um número
            printf("Opcao invalida, tente novamente.\n");

            // Limpa o buffer de entrada
            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            opcao = 0; // Atribui um valor inválido para garantir que o menu continue
        } else {
            // Se a leitura foi um sucesso, executa o switch
            switch(opcao) {
                case 1:
                    inserirColab(&colabs);
                    break;
                case 2:
                    listarColabs(colabs);
                    break;
                case 3:
                    alterarColabs(&colabs);
                    break;
                case 4:
                    removerColabs(&colabs);
                    break;
                case 5:
                    break;
                default:
                    printf("Opcao invalida, tente novamente.\n");
            }
        }
    } while (opcao != 5);
}

/*void menuAgendamentos() {
//    int opcao;
//    int retorno_scanf; // Variável para verificar o retorno do scanf

    do {
       printf("\n-- MENU AGENDAMENTOS --\n");
       printf("1. Cadastrar agendamento\n");
       printf("2. Listar agendamento\n");
       printf("3. Alterar agendamento\n");
       printf("4. Remover agendamento\n");
       printf("5. Voltar\n");
       printf("Escolha uma opcao: ");

       retorno_scanf = scanf("%d", &opcao);

       if (retorno_scanf == 0) {
            // Se a leitura falhou, o usuário não digitou um número
            printf("Opcao invalida, tente novamente.\n");

            // Limpa o buffer de entrada
            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            opcao = 0; // Atribui um valor inválido para garantir que o menu continue
       } else {
            // Se a leitura foi um sucesso, executa o switch
            switch(opcao) {
                case 1:
                    //inserirAgendamento(agendamentos);
                    break;
                case 2:
                    //listarAgendamentos(agendamentos);
                    break;
                case 3:
                    //alterarAgendamentos(agendamentos);
                    break;
                case 4:
                    //removerAgendamentos(agendamentos);
                    break;
                case 5:
                    break;
                default:
                    printf("Opcao invalida, tente novamente.\n");
            }
       }
    } while (opcao != 5);
}*/

void menuPrincipal() {
    int opcao;
    int retorno_scanf; // Variável para verificar o retorno do scanf

    do {
        printf("\n-- SISTEMA BARBEARIA --\n");
        printf("1. Menu Clientes\n");
        printf("2. Menu Colaboradores\n");
//        printf("3. Menu Agendamentos\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");

        retorno_scanf = scanf("%d", &opcao);

        if (retorno_scanf == 0) {
            // Se a leitura falhou, o usuário não digitou um número
            printf("Opcao invalida, tente novamente.\n");

            // Limpa o buffer de entrada
            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            opcao = 0; // Atribui um valor inválido para garantir que o menu continue
        } else {
            // Se a leitura foi um sucesso, executa o switch
            switch(opcao) {
                case 1:
                    menuClientes();
                    break;
                case 2:
                    menuColabs();
                    break;
//                case 3:
//                    menuAgendamentos();
//                    break;
                case 3:
                    printf("Saindo...\n");
                    break;
                default:
                    printf("Opcao invalida, tente novamente.\n");
            }
        }
    } while (opcao != 3);
}

int main() {
    menuPrincipal();
    return 0;
}
