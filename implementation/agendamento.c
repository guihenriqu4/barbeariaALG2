#include "agendamento.h"
#include "cliente.h"
#include "colab.h"
#include <stdio.h>
#include <stdlib.h>

long int qtdAgen = 0;
long int id = 1;


//Cadastrando novo agendamento
void inserirAgendamento(Agendamento *p){
    p = realloc(p, (qtdAgen + 1) * sizeof(Agendamento));
    if(p == NULL){
        perror("Erro ao realocar memória\n");
        return;
    }

    int n;
    Agendamento a;
    a.id = id++;
    printf("Informe o CPF do cliente: "); scanf(" %[^\n]s", a.cpfClinte);
    printf("Informe o ID do colaborador: "); scanf("%d", &a.idColab);
    printf("Informe a data do agendamento (dd/MM//YY): "); scanf(" %[^\n]s", &a.data);
    printf("Informe o horário do agendamento (HH:mm): "); scanf(" %[^\n]s", &a.horario);
    printf("Informe quantos serviços foram solicitados: "); scanf("%d", &n);

    a.servicoDesejado = malloc(n * sizeof(char *));
    if(a.servicoDesejado == NULL){
        perror("Erro ao realocar memória\n");
        return;
    }
    for(int i = 0; i < n; i++){
        a.servicoDesejado[i] = malloc(200 * sizeof(char));
        if(a.servicoDesejado[i] == NULL){
            perror("Erro ao realocar memória\n");
            return;
        }
        printf("Informe o nome do %d˚ serviço: ", i+1);
        scanf(" %[^\n]s", a.servicoDesejado[i]);
    }

    p[qtdAgen] = a;
    printf("Agendamento inserido com sucesso! ID: \n", a.id);
    qtdAgen++;
}

//função para converter a data do formato dd/MM/YY para um inteiro
int converterData(const char *data) {
    return (data[6] - '0') * 10000 +
           (data[7] - '0') * 1000 +
           (data[3] - '0') * 100 +
           (data[4] - '0') * 10 +
           (data[0] - '0') * 1 +
           (data[1] - '0');
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
    scanf(" %13[^\n]", cpf);

    printf("Digite a data base (dd/MM/YY), para informar agendamentos subsequentes: ");
    scanf(" %[^\n]", dataBase);

    int dataCmp = converterData(dataBase);
    int encontrados = 0;
    
    printf("\nTodos os agendamentos do colaborador ID %d e cliente CPF %s apos a data %s:\n\n", idColab, cpf, dataBase);

    for (int i = 0; i < qtdAg; i++) {
        if (strcmp(agendamentos[i].cpfClinte, cpf) == 0 && agendamentos[i].idColab == idColab) {
            
            int dataAg = converterData(agendamentos[i].data);

            if (dataAg > dataCmp) {
                encontrados++;

                printf("\n--- Agendamento %ld ---\n", agendamentos[i].id);
                printf("Data: %s\n", agendamentos[i].data);
                printf("Horario: %s\n", agendamentos[i].horario);


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