#include "read.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//função para converter a data do formato dd/MM/YY para um inteiro
int converterData(const char *data) {
    return (data[6] - '0') * 10000 +
           (data[7] - '0') * 1000 +
           (data[3] - '0') * 100 +
           (data[4] - '0') * 10 +
           (data[0] - '0') * 1 +
           (data[1] - '0');
}

//Listando todos os Clientes
void listarClientes(Cliente *clientes, int qtd) {
    if (qtd == 0) {
        printf("Nenhum cliente cadastrado.\n\n");
        return;
    }

    for (int i = 0; i < qtd; i++) {
        printf("---Cliente %d---\n", i + 1);
        printf("CPF: %s\n", clientes[i].cpf);
        printf("Nome: %s\n", clientes[i].nome);
        printf("Celular: %ld\n", clientes[i].celular);
        printf("Data de integração: %s\n\n", clientes[i].dataIntegracao);
    }
}

//Listando todos os Colaboradores
void listarColabs(Colab *colabs, int qtd) {
    if (qtd == 0) {
        printf("Nenhum colaborador cadastrado.\n\n");
        return;
    }

    for (int i = 0; i < qtd; i++) {
        printf("--Colaborador %d--\n", i + 1);
        printf("ID: %d\n", colabs[i].id);
        printf("Nome: %s\n", colabs[i].nome);
        printf("Celular: %ld\n", colabs[i].celular);
        printf("Serviços prestados:\n");
        for (int j = 0; colabs[i].servicosPrestados[j] != NULL; j++) 
            printf("- %s\n", colabs[i].servicosPrestados[j]);
        printf("\n");
    }
}

//Listar todos os Agendamentos pos data informada, recebendo um cliente, colaborador e data base especificos
void listarAgendamentosPosData(Agendamento *agendamentos, int qtdAg, Cliente *clientes, int qtdCl, Colab *colabs, int qtdCol) {
    if (qtdAg == 0) {
        printf("Nenhum agendamento realizado.\n");
        return;
    }

    int idColab;
    char cpf[14], dataBase[9];

    printf("Digite o ID do colaborador: ");
    scanf("%d", &idColab);
    getchar();

    printf("Digite o CPF do cliente (000.000.000-00): ");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = '\0';

    printf("Digite a data base (dd/MM/YY), para informar agendamentos subsequentes: ");
    scanf(" %[^\n]", dataBase);

    int dataCmp = converterData(dataBase);
    int encontrados = 0;
    
    printf("\nTodos os agendamentos do colaborador ID %d e cliente CPF %s após a data %s:\n\n", idColab, cpf, dataBase);

    for (int i = 0; i < qtdAg; i++) {
        if (strcmp(agendamentos[i].cpfClinte, cpf) == 0 && agendamentos[i].idColab == idColab) {
            
            int dataAg = converterData(agendamentos[i].data);

            if (dataAg > dataCmp) {
                encontrados++;

                Cliente *cli = NULL;
                for (int c = 0; c < qtdCl; c++) {
                    if (strcmp(clientes[c].cpf, cpf) == 0) {
                        cli = &clientes[c];
                        break;
                    }
                }

                Colab *col = NULL;
                for (int c = 0; c < qtdCol; c++) {
                    if (colabs[c].id == idColab) {
                        col = &colabs[c];
                        break;
                    }
                }

                printf("\n--- Agendamento %ld ---\n", agendamentos[i].id);
                printf("Data: %s\n", agendamentos[i].data);
                printf("Horário: %s\n", agendamentos[i].horario);
                
                //mantendo por boa pratica, mas no caso nao sei se precisa
                if (cli == NULL)
                    printf("Cliente: Informação não encontrada\n");

                if (col == NULL)
                    printf("Colaborador: Informação não encontrada\n");

                printf("Serviços desejados:\n");
                for (int j = 0; agendamentos[i].servicoDesejado[j] != NULL; j++) {
                    printf("- %s\n", agendamentos[i].servicoDesejado[j]);
                }
            }
        }
    }

    if (encontrados == 0) {
        printf("\nNenhum agendamento encontrado para os filtros informados.\n");
    }
}

//Listando todos os Agendamentos "Nao obrigatorio"
/*
void listarAgendamentos(Agendamento *agendamentos, int qtd) {
    if (qtd == 0) {
        printf("Nenhum agendamento realizado.\n\n");
        return;
    }

    for (int i = 0; i < qtd; i++) {
        printf("---Agendamento %d---\n", i + 1);
        printf("ID: %ld\n", agendamentos[i].id);
        printf("CPF do cliente: %s\n", agendamentos[i].cpfClinte);
        printf("ID do colaborador: %d\n", agendamentos[i].idColab);
        printf("Data: %s\n", agendamentos[i].data);
        printf("Horário: %s\n", agendamentos[i].horario);
        printf("Serviços desejados:\n");
        for (int j = 0; agendamentos[i].servicoDesejado[j] != NULL; j++)
            printf("- %s\n", agendamentos[i].servicoDesejado[j]);
        printf("\n");
    }
} 
*/



