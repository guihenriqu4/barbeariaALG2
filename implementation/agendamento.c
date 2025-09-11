#include "../headers/agendamento.h"
#include "../headers/cliente.h"
#include "../headers/colab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INCREMENTO 5

long int capacidadeA = 0;
long int idAgen = 10;

void inserirAgendamento(Agendamento **p, Cliente *clientes, int *qtdClientes, Colab *colabs, int *qtdColabs, long int *qtdAgen, FILE *fagen){
    if(*qtdAgen >= capacidadeA){

        fagen = fopen("agendamentos.bin", "wb");
        if(fagen == NULL){
            perror("Erro ao abrir o arquivo.");
            exit(1);
        }

        fwrite(qtdAgen,sizeof(long int),1,fagen);
        int result = fwrite(*p, sizeof(Agendamento), *qtdAgen, fagen);
        if(result < *qtdAgen) perror("Erro na gravacao de algum dos agendamentos.");

        fclose(fagen);

        capacidadeA += INCREMENTO;
        *p = (Agendamento *) realloc(*p, capacidadeA * sizeof(Agendamento));
        if(*p == NULL){
            perror("Erro ao realocar memória\n");
            exit(1);
        }
    }

    int n;
    Agendamento a;
    a.id = ++idAgen;
    printf("Informe o CPF do cliente (000.000.000-00): ");
    scanf(" %[^\n]s", a.cpfCliente);

    int r = 0;
    for(int i = 0; i < *qtdClientes; i++){
        if(strcmp(clientes[i].cpf, a.cpfCliente) == 0){
            r = 1;
            break;
        }
    }
    if(r == 0){
        perror("Cliente nao encontrado.");
        return;
    }

    printf("Informe o ID do colaborador: ");
    scanf("%d", &a.idColab);

    r = 0;
    Colab *c = NULL;
    for(int i = 0; i < *qtdColabs; i++){
        if(colabs[i].id == a.idColab){
            r = 1;
            c = &colabs[i];

            break;
        }
    }

    if(r == 0){
        perror("Colaborador nao encontrado.");
        return;
    }

    printf("Informe a data do agendamento (dd/MM//YY): ");
    scanf(" %[^\n]s", a.data);

    printf("Informe o horario do agendamento (HH:mm): ");
    scanf(" %[^\n]s", a.horario);

    do{
        printf("Informe quantos servicos foram solicitados (ate %d): ", c->nServicos);
        scanf("%d", &n);
    }while(n <= 0 || n > c->nServicos);


    for(int i = 0; i < n; i++){
        printf("Informe o nome do %d servico: ", i+1);
        scanf(" %[^\n]s", a.servicoDesejado[i]);
    }

    (*p)[*qtdAgen] = a;
    printf("Agendamento inserido com sucesso! ID: %ld\n", a.id);
    (*qtdAgen)++;
}

void buscarAgendamentosPorCPF(Agendamento *agendamentos, long int *qtdAgendamentos, Cliente *clientes, int *qtdClientes, Colab *colaboradores, int *qtdColaboradores) {
    int encontrouAgendamento = 0;
    char cpf[15];
    printf("Informe o CPF do cliente: ");
    scanf(" %[^\n]s", cpf);

    printf("--- Agendamentos para o CPF: %s ---\n", cpf);

    Cliente *clienteEncontrado = NULL;
    for (int i = 0; i < *qtdClientes; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0) {
            clienteEncontrado = &clientes[i];
            break;
        }
    }

    if (clienteEncontrado == NULL) {
        printf("Nenhum cliente encontrado com o CPF %s.\n", cpf);
        return;
    }

    printf("---Informacoes do Cliente---\n");
    printf("Nome do Cliente: %s\n", clienteEncontrado->nome);
    printf("Celular do Cliente: %lld\n", clienteEncontrado->celular);
    printf("\n");

    for (int i = 0; i < *qtdAgendamentos; i++) {
        if (strcmp(agendamentos[i].cpfCliente, cpf) == 0) {
            encontrouAgendamento = 1;
            printf("---Informacoes do Agendamento %d ---\n", i + 1);
            printf("ID do Agendamento: %ld\n", agendamentos[i].id);
            printf("ID do Colaborador: %d\n", agendamentos[i].idColab);
            printf("Data: %s\n", agendamentos[i].data);
            printf("Horario: %s\n", agendamentos[i].horario);
            printf("Servicos solicitados:\n");

            Colab *colabAtual = NULL;
            for (int k = 0; k < *qtdColaboradores; k++) {
                if (colaboradores[k].id == agendamentos[i].idColab) {
                    colabAtual = &colaboradores[k];
                    break;
                }
            }
            if (colabAtual != NULL) {
                for (int j = 0; j < colabAtual->nServicos; j++) {
                    printf("- %s\n", agendamentos[i].servicoDesejado[j]);
                }
            }
            printf("\n");
        }
    }

    if (encontrouAgendamento == 0)
        printf("Nenhum agendamento encontrado para o CPF %s.\n", cpf);
}

void buscarAgendamentosPorIDdoColab(Agendamento *agendamentos, long int *qtdAgendamentos, Colab *colaboradores, int *qtdColaboradores){
    int encontrouAgendamento = 0;
    int idCol;
    printf("Informe o ID do colaborador: ");
    scanf("%d", &idCol);

    printf("--- Agendamentos para o ID do Colaborador: %d ---\n", idCol);
    Colab *colaboradorEncontrado = NULL;
    for (int i = 0; i < *qtdColaboradores; i++) {
        if (colaboradores[i].id == idCol) {
            colaboradorEncontrado = &colaboradores[i];
            break;
        }
    }

    if (colaboradorEncontrado == NULL) {
        printf("Nenhum colaborador encontrado com o ID %d.\n", idCol);
        return;
    }

    printf("---Informacoes do Colaborador---\n");
    printf("Nome do Colaborador: %s\n", colaboradorEncontrado->nome);
    printf("Celular do Colaborador: %lld\n", colaboradorEncontrado->celular);
    printf("Servicos prestados pelo Colaborador:\n");
    for (int j = 0; j < colaboradorEncontrado->nServicos; j++)
        printf("- %s\n", colaboradorEncontrado->servicosPrestados[j]);
    printf("\n");

    for (int i = 0; i < *qtdAgendamentos; i++) {
        if (agendamentos[i].idColab == idCol) {
            encontrouAgendamento = 1;
            printf("---Informacoes do Agendamento %d ---\n", i + 1);
            printf("ID do Agendamento: %ld\n", agendamentos[i].id);
            printf("CPF do Cliente: %s\n", agendamentos[i].cpfCliente);
            printf("Data: %s\n", agendamentos[i].data);
            printf("Horario: %s\n", agendamentos[i].horario);
            printf("Servicos solicitados:\n");
            for (int j = 0; j < colaboradorEncontrado->nServicos; j++){
                printf("- %s\n", agendamentos[i].servicoDesejado[j]);
            }
            printf("\n");
        }
    }
    if (encontrouAgendamento == 0) {
        printf("Nenhum agendamento encontrado para o ID do Colaborador %d.\n", idCol);
    }
}


void buscarAgendamentosPorData(Agendamento *agendamentos, long int *qtdAgendamentos, Cliente *clientes, int *qtdClientes, Colab *colaboradores, int *qtdColaboradores) {
    int encontrouAgendamento = 0;
    char data[9];
    printf("Informe a data: ");
    scanf(" %[^\n]s", data);

    printf("--- Agendamentos para a Data: %s ---\n", data);

    for (int i = 0; i < *qtdAgendamentos; i++) {
        if (strcmp(agendamentos[i].data, data) == 0) {
            encontrouAgendamento = 1;
            printf("---Informacoes do Agendamento %d ---\n", i + 1);
            printf("ID do Agendamento: %ld\n", agendamentos[i].id);
            printf("Horario: %s\n", agendamentos[i].horario);

            Cliente *clienteAtual = NULL;
            for (int j = 0; j < *qtdClientes; j++) {
                if (strcmp(clientes[j].cpf, agendamentos[i].cpfCliente) == 0) {
                    clienteAtual = &clientes[j];
                    break;
                }
            }
            if (clienteAtual != NULL)
                printf("Nome do Cliente: %s\n", clienteAtual->nome);
            else
                printf("Cliente nao encontrado para o CPF: %s\n", agendamentos[i].cpfCliente);

            Colab *colabAtual = NULL;
            for (int k = 0; k < *qtdColaboradores; k++) {
                if (colaboradores[k].id == agendamentos[i].idColab) {
                    colabAtual = &colaboradores[k];
                    break;
                }
            }
            if (colabAtual != NULL)
                printf("Nome do Colaborador: %s\n", colabAtual->nome);
            else
                printf("Colaborador nao encontrado para o ID: %d\n", agendamentos[i].idColab);
            printf("\n");
        }
    }

    if (encontrouAgendamento == 0)
        printf("Nenhum agendamento encontrado para a data %s.\n", data);
}

void alterarAgendamento(Agendamento **agendamentos, long int *qtdAgen, Cliente *clientes, int *qtdClientes, Colab *colabs, int *qtdColabs, FILE *fagen){
    if(*qtdAgen == 0){
        printf("\nNenhum agendamento cadastrado para alterar.\n\n");
        return;
    }

    long int idBusca = -1;
    int opcaoBusca;


    printf("\nInforme o ID do agendamento: ");
    scanf("%ld",&idBusca);

    int posicao = -1;
    for (int i = 0; i < *qtdAgen; i++) {
        if ((*agendamentos)[i].id == idBusca) {
            posicao = i;
            break;
        }
    }

    if (posicao == -1){
        printf("\nNao foi possivel encontrar o agendamento selecionado. Tente novamente\n");
        return;
    }
    printf("\nAgendamento encontrado! Por favor, insira as novas informacoes\n");

    int nServicos,clienteValido,colabValido;

    do{
        printf("\nInforme o novo CPF do cliente (000.000.000-00): ");
        scanf(" %[^\n]s",(*agendamentos)[posicao].cpfCliente);
        clienteValido = 0;//
        for(int i=0;i<*qtdClientes;i++){
            if(strcmp(clientes[i].cpf,(*agendamentos)[posicao].cpfCliente)==0){
                clienteValido = 1;
                break;
            }
        }
        if(!clienteValido){
            printf("\nCPF de cliente nao encontrado. Tente novamente!\n");
        }
    }while(!clienteValido);

    Colab *c = NULL;

    do{
        printf("Informe o novo ID do colaborador: ");
        scanf("%d",&(*agendamentos)[posicao].idColab);
        colabValido = 0;
        for(int i=0; i < *qtdColabs; i++){
            if(colabs[i].id == (*agendamentos)[posicao].idColab){
                colabValido = 1;
                c = &colabs[i];
                break;
            }
        }
        if(!colabValido){
            printf("ID de colaborador nao encontrado. Tente novamente!\n");
        }
    }while(!colabValido);

    printf("Informe a nova data do agendamento (dd/MM/YY): ");
    scanf(" %[^\n]s", (*agendamentos)[posicao].data);
    printf("Informe o novo horario do agendamento (HH:mm): ");
    scanf(" %[^\n]s", (*agendamentos)[posicao].horario);

    for(int i=0;i<5;i++){
        strcpy((*agendamentos)[posicao].servicoDesejado[i],"");
    }

    do{
        printf("Informe a nova quantidade de servicos (ate %d): ", c->nServicos);
        scanf("%d", &nServicos);
    }while(nServicos <= 0 || nServicos > c->nServicos);

    for (int i = 0; i < nServicos; i++) {
        printf("Informe o nome do servico %d: ", i + 1);
        scanf(" %[^\n]s", (*agendamentos)[posicao].servicoDesejado[i]);
    }


    fagen = fopen("agendamentos.bin", "wb");
    if (fagen == NULL) {
        perror("\nErro ao abrir o arquivo de agendamentos para alteracao.\n");
        return;
    }
    fwrite(qtdAgen,sizeof(long int),1,fagen);
    fwrite(*agendamentos, sizeof(Agendamento), 1, fagen);
    fclose(fagen);
    printf("\nAgendamento alterado com sucesso!\n");

}

void removerAgendamentos(Agendamento **agendamentos, long int *qtdAgen, FILE *fagen) {
    if(capacidadeA == 0 && *qtdAgen > 0){
        capacidadeA = *qtdAgen + INCREMENTO;
        }
    if (*qtdAgen == 0) {
        printf("\nNenhum agendamento para remover.\n\n");
        return;
    }

    long int idBusca;
    printf("Informe o ID do agendamento que deseja remover: ");
    scanf("%ld", &idBusca);

    int posicao = -1;
    for (int i = 0; i < *qtdAgen; i++) {
        if ((*agendamentos)[i].id == idBusca) {
            posicao = i;
            break;
        }
    }

    if (posicao == -1) {
        printf("\nAgendamento com ID %ld não encontrado.\n", idBusca);
        return;
    }

    (*agendamentos)[posicao] = (*agendamentos)[*qtdAgen - 1];
    (*qtdAgen)--;

    capacidadeA--;
    Agendamento *temp = realloc(*agendamentos, capacidadeA * sizeof(Agendamento));
    if (temp != NULL || capacidadeA == 0) {
        *agendamentos = temp;
    } else {
        perror("Erro ao realocar memória após remoção de agendamento");
        exit(1);
    }

    fagen = fopen("agendamentos.bin", "wb");
    if (fagen == NULL) {
        perror("Erro ao abrir o arquivo de agendamentos.");
        exit(1);
    }
    fwrite(qtdAgen,sizeof(long int),1,fagen);
    fwrite(*agendamentos, sizeof(Agendamento), *qtdAgen, fagen);
    fclose(fagen);

    printf("\nAgendamento removido com sucesso!\n");
}

int converterData(const char *data) {
    return (data[6] - '0') * 10000 +
           (data[7] - '0') * 1000 +
           (data[3] - '0') * 100 +
           (data[4] - '0') * 10 +
           (data[0] - '0') * 1 +
           (data[1] - '0');
}

void gerarRelatorio(Agendamento *agendamentos, long int *qtdAgendamentos, Cliente *clientes, int *qtdClientes, Colab *colaboradores, int *qtdColaboradores) {
    int opcao;
    printf("\n-- GERAR RELATORIO --\n");
    printf("1. Relatorio por CPF do Cliente\n");
    printf("2. Relatorio por ID do Colaborador\n");
    printf("3. Relatorio por Data\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    FILE *fRelatorio = fopen("relatorio.txt", "w");
    if (fRelatorio == NULL) {
        perror("Nao foi possivel criar o arquivo de relatorio.");
        return;
    }

    int encontrou = 0;

    switch (opcao) {
        case 1: {
            char cpf[15];
            printf("Informe o CPF do cliente: ");
            scanf(" %[^\n]s", cpf);


            Cliente *clienteEncontrado = NULL;
            for (int i = 0; i < *qtdClientes; i++) {
                if (strcmp(clientes[i].cpf, cpf) == 0) {
                    clienteEncontrado = &clientes[i];
                    break;
                }
            }

            if (clienteEncontrado == NULL) {
                printf("Nenhum cliente encontrado com o CPF %s.\n", cpf);
                fclose(fRelatorio);
                return;
            }

            fprintf(fRelatorio, "--- RELATORIO DE AGENDAMENTOS POR CLIENTE ---\n\n");
            fprintf(fRelatorio, "Cliente: %s\n", clienteEncontrado->nome);
            fprintf(fRelatorio, "CPF: %s\n", clienteEncontrado->cpf);
            fprintf(fRelatorio, "Celular: %lld\n\n", clienteEncontrado->celular);
            fprintf(fRelatorio, "--------------------------------------------------\n\n");

            for (int i = 0; i < *qtdAgendamentos; i++) {
                if (strcmp(agendamentos[i].cpfCliente, cpf) == 0) {
                    encontrou = 1;
                    fprintf(fRelatorio, "Agendamento ID: %ld\n", agendamentos[i].id);
                    fprintf(fRelatorio, "Data: %s\n", agendamentos[i].data);
                    fprintf(fRelatorio, "Horario: %s\n", agendamentos[i].horario);

                    Colab *colabAtual = NULL;
                    for (int k = 0; k < *qtdColaboradores; k++) {
                        if (colaboradores[k].id == agendamentos[i].idColab) {
                            colabAtual = &colaboradores[k];
                            break;
                        }
                    }
                    if (colabAtual != NULL) {
                         fprintf(fRelatorio, "Colaborador: %s\n", colabAtual->nome);
                         fprintf(fRelatorio, "Servicos Solicitados:\n");
                         for (int j = 0; j < colabAtual->nServicos; j++) {
                            if(strlen(agendamentos[i].servicoDesejado[j]) > 0)
                                fprintf(fRelatorio, "- %s\n", agendamentos[i].servicoDesejado[j]);
                        }
                    }
                    fprintf(fRelatorio, "\n--------------------------------------------------\n\n");
                }
            }
            break;
        }
        case 2: {
            int idCol;
            printf("Informe o ID do colaborador: ");
            scanf("%d", &idCol);

            Colab *colaboradorEncontrado = NULL;
            for (int i = 0; i < *qtdColaboradores; i++) {
                if (colaboradores[i].id == idCol) {
                    colaboradorEncontrado = &colaboradores[i];
                    break;
                }
            }

            if (colaboradorEncontrado == NULL) {
                printf("Nenhum colaborador encontrado com o ID %d.\n", idCol);
                fclose(fRelatorio);
                return;
            }

            fprintf(fRelatorio, "--- RELATORIO DE AGENDAMENTOS POR COLABORADOR ---\n\n");
            fprintf(fRelatorio, "Colaborador: %s\n", colaboradorEncontrado->nome);
            fprintf(fRelatorio, "ID: %d\n", colaboradorEncontrado->id);
            fprintf(fRelatorio, "Celular: %lld\n\n", colaboradorEncontrado->celular);
            fprintf(fRelatorio, "--------------------------------------------------\n\n");

            for (int i = 0; i < *qtdAgendamentos; i++) {
                if (agendamentos[i].idColab == idCol) {
                    encontrou = 1;
                    fprintf(fRelatorio, "Agendamento ID: %ld\n", agendamentos[i].id);
                    fprintf(fRelatorio, "Data: %s\n", agendamentos[i].data);
                    fprintf(fRelatorio, "Horario: %s\n", agendamentos[i].horario);

                     Cliente *clienteAtual = NULL;
                    for (int j = 0; j < *qtdClientes; j++) {
                        if (strcmp(clientes[j].cpf, agendamentos[i].cpfCliente) == 0) {
                            clienteAtual = &clientes[j];
                            break;
                        }
                    }
                    if(clienteAtual != NULL)
                        fprintf(fRelatorio, "Cliente: %s (CPF: %s)\n", clienteAtual->nome, clienteAtual->cpf);


                    fprintf(fRelatorio, "Servicos Solicitados:\n");
                     for (int j = 0; j < colaboradorEncontrado->nServicos; j++) {
                        if(strlen(agendamentos[i].servicoDesejado[j]) > 0)
                            fprintf(fRelatorio, "- %s\n", agendamentos[i].servicoDesejado[j]);
                    }
                    fprintf(fRelatorio, "\n--------------------------------------------------\n\n");
                }
            }
            break;
        }
        case 3: {
            char data[9];
            printf("Informe a data (dd/MM/YY): ");
            scanf(" %[^\n]s", data);

            int data1 = converterData(data);

            fprintf(fRelatorio, "--- RELATORIO DE AGENDAMENTOS A PARTIR DA DATA: %s ---\n\n", data);

            for (int i = 0; i < *qtdAgendamentos; i++) {
                if (converterData(agendamentos[i].data) >= data1) {
                    encontrou = 1;
                    fprintf(fRelatorio, "Agendamento ID: %ld\n", agendamentos[i].id);
                    fprintf(fRelatorio, "Data: %s\n", agendamentos[i].data);
                    fprintf(fRelatorio, "Horario: %s\n", agendamentos[i].horario);

                    Cliente *clienteAtual = NULL;
                    for (int j = 0; j < *qtdClientes; j++) {
                        if (strcmp(clientes[j].cpf, agendamentos[i].cpfCliente) == 0) {
                            clienteAtual = &clientes[j];
                            break;
                        }
                    }

                    Colab *colabAtual = NULL;
                    for (int k = 0; k < *qtdColaboradores; k++) {
                        if (colaboradores[k].id == agendamentos[i].idColab) {
                            colabAtual = &colaboradores[k];
                            break;
                        }
                    }
                    if(clienteAtual != NULL)
                        fprintf(fRelatorio, "Cliente: %s\n", clienteAtual->nome);
                    else
                        fprintf(fRelatorio, "Cliente: Nao encontrado\n");

                    if(colabAtual != NULL)
                        fprintf(fRelatorio, "Colaborador: %s\n", colabAtual->nome);
                    else
                         fprintf(fRelatorio, "Colaborador: Nao encontrado\n");

                    fprintf(fRelatorio, "Servicos Solicitados:\n");
                     for (int j = 0; j < colabAtual->nServicos; j++) {
                        if(strlen(agendamentos[i].servicoDesejado[j]) > 0)
                            fprintf(fRelatorio, "- %s\n", agendamentos[i].servicoDesejado[j]);
                    }

                    fprintf(fRelatorio, "\n--------------------------------------------------\n\n");
                }
            }
            break;
        }
        default:
            printf("Opcao invalida.\n");
    }

    fclose(fRelatorio);

    if (encontrou) {
        printf("\nRelatorio 'relatorio.txt' gerado com sucesso!\n");
    } else {
        printf("\nNenhum agendamento encontrado para o criterio informado. O arquivo de relatorio foi gerado vazio.\n");
    }
}
