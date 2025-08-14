#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "colab.h"
#include "agendamento.h"

Cliente *clientes = NULL;
Colab *colabs = NULL;
Agendamento *agendamentos = NULL;

int quantClientes = 0;
int quantColabs = 0;
int quantAgend = 0;

void menuClientes();
void menuColabs();
void menuAgendamentos();

void listarClientes();
void alterarClientes();
void removerClientes();

void listarColabs();
void alterarColabs();
void removerColabs();

void listarAgendamentos();
void alterarAgendamentos();
void removerAgendamentos();

void menuPrincipal() {
    int opcao;

    do {
        printf("\n-- SISTEMA BARBEARIA --\n");
        printf("1. Menu Clientes\n");
        printf("2. Menu Colaboradores\n");
        printf("3. Menu Agendamentos\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
        case 1:
            menuClientes();
            break;
        case 2:
            menuColabs();
            break;
        case 3:
            menuAgendamentos();
            break;
        case 4:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida, tente novamente.\n");
        }
    } while (opcao != 4);
}

void menuClientes() {
    int opcao;
    do {
        printf("\n-- MENU CLIENTES --\n");
        printf("1. Cadastrar cliente\n");
        printf("2. Listar clientes\n");
        printf("3. Alterar cliente\n");
        printf("4. Remover cliente\n");
        printf("5. Voltar opcao\n");
        printf("Escolha a opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                inserirCliente(clientes);
                break;
            case 2:
                listarClientes();
                break;
            case 3:
                alterarClientes();
                break;
            case 4:
                removerClientes();
                break;
            case 5:
                break;
            default:
                printf("Opcao invalida, tente novamente.\n");
        }
    } while (opcao != 5);

}

void menuColabs() {
    int opcao;
    do {
        printf("\n-- MENU COLABORADORES --\n");
        printf("1. Cadastrar colaborador\n");
        printf("2. Listar colaboradores\n");
        printf("3. Alterar colaborador\n");
        printf("4. Remover colaborador\n");
        printf("5. Voltar opcao\n");
        printf("Escolha a opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                inserirColab(colabs);
                break;
            case 2:
                listarColabs();
                break;
            case 3:
                alterarColabs();
                break;
            case 4:
                removerColabs();
                break;
            case 5:
                break;
            default:
                printf("Opcao invalida, tente novamente.\n");
        }
    } while (opcao != 5);
}

void menuAgendamentos() {
    int opcao;
    do {
       printf("\n-- MENU AGENDAMENTOS --\n");
       printf("1. Cadastrar agendamento\n");
       printf("2. Listar agendamento\n");
       printf("3. Alterar agendamento\n");
       printf("4. Remover agendamento\n");
       printf("5. Voltar opcao\n");
       printf("Escolha uma opcao: ");
       scanf("%d", &opcao);

       switch(opcao) {
            case 1:
                inserirAgendamento(agendamentos);
                break;
            case 2:
                listarAgendamentos();
                break;
            case 3:
                alterarAgendamentos();
                break;
            case 4:
                removerAgendamentos();
                break;
            case 5:
                break;
            default:
                printf("Opcao invalida, tente novamente.\n");
       }
    } while (opcao != 5);

}

int main() {

    int tamanho = 5;

    clientes = malloc(tamanho * sizeof(Cliente));
    colabs = malloc(tamanho * sizeof(Colab));
    agendamentos = malloc(tamanho * sizeof(Agendamento));

    if (!clientes || !colabs || !agendamentos) {
        printf("Sem memoria suficiente!\n");
        return 1;
    }

    menuPrincipal();

    free(clientes);
    free(colabs);
    free(agendamentos);

    return 0;
}
