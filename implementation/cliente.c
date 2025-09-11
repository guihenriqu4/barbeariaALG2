#include "../headers/cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INCREMENTO 5

int capacidadeCl = 15;


void inserirCliente(Cliente **p, FILE *fcliente, int *qtdCliente){
    if(*qtdCliente >= capacidadeCl){

        fcliente = fopen("clientes.bin", "wb");
        if(fcliente == NULL){
            perror("Erro ao abrir o arquivo clientes.");
            exit(1);
        }

        fwrite(qtdCliente,sizeof(int),1,fcliente);
        int result = fwrite(*p, sizeof(Cliente), *qtdCliente, fcliente);
        if(result < *qtdCliente) perror("Erro na gravacao de algum dos clientes.");

        fclose(fcliente);

        capacidadeCl += INCREMENTO;
        *p = (Cliente *) realloc(*p, capacidadeCl * sizeof(Cliente));
        if(*p == NULL){
            perror("Erro ao realocar memoria\n");
            return;
        }
    }

    Cliente c;
    printf("Informe o CPF do cliente (000.000.000-00): ");
    scanf(" %[^\n]s", c.cpf);

    for(int i = 0; i < *qtdCliente; i++){
        if(strcmp((*p)[i].cpf, c.cpf) == 0){
            perror("CPF ja cadastrado.\n");
            return;
        }
    }

    printf("Informe o nome do cliente: ");
    scanf(" %[^\n]s", c.nome);

    printf("Informe o celular do cliente (00900000000): ");
    scanf("%lld", &c.celular);

    printf("Informe a data do cadastro (dd/MM/YY): ");
    scanf(" %[^\n]s", c.dataIntegracao);

    (*p)[*qtdCliente] = c;
    printf("Cliente inserido com sucesso!\n");
    (*qtdCliente)++;
}

void listarClientes(Cliente *clientes, int *qtdCliente) {
    if (*qtdCliente == 0) {
        printf("Nenhum cliente cadastrado.\n\n");
        return;
    }
    for (int i = 0; i < *qtdCliente; i++) {
        printf("-- Cliente %d --\n", i + 1);
        printf(" CPF: %s\n", clientes[i].cpf);
        printf(" Nome: %s\n", clientes[i].nome);
        printf(" Celular: %lld\n", clientes[i].celular);
        printf(" Data de integracao: %s\n\n", clientes[i].dataIntegracao);
    }
}

void alterarClientes(Cliente **clientes, int *qtdCliente, FILE *fcliente){
    if (*qtdCliente == 0){
        printf("\nNenhum cliente cadastrado.\n\n");
        return;
    }

    char cpfBusca[15];
    printf("Informe o CPF do Cliente que deseja alterar (000.000.000-00): ");
    scanf(" %[^\n]s",cpfBusca);

    int clienteEncontrado = 0;

    for(int i = 0; i < *qtdCliente; i++){
        if(strcmp((*clientes)[i].cpf, cpfBusca) == 0){
            printf("Cliente encontrado! Por favor, insira as novas informacoes\n");

            printf("Informe o novo nome do cliente: ");
            scanf(" %[^\n]s",(*clientes)[i].nome);

            printf("\nInforme o novo celular do cliente (00900000000): ");
            scanf("%lld",&(*clientes)[i].celular);

            printf("\nInforme a nova data do cadastro (dd/MM/YY): ");
            scanf(" %[^\n]",(*clientes)[i].dataIntegracao);

            fcliente = fopen("clientes.bin","wb");
            if(fcliente==NULL){
                perror("\nErro ao abrir o arquivo clientes!\n");
                return;
            }

            fwrite(qtdCliente,sizeof(int),1,fcliente);
            fwrite(*clientes,sizeof(Cliente),*qtdCliente,fcliente);
            fclose(fcliente);

            printf("\nCliente alterado com sucesso!\n");
            clienteEncontrado = 1;
            break;
        }
    }

    if(!clienteEncontrado){
        printf("\nCliente com CPF %s nao encontrado.\n",cpfBusca);
    }
}

void removerClientes(Cliente **clientes, Agendamento *agendamentos, long int *qtdAgendamentos, int *qtdCliente, FILE *fcliente) {
    if (*qtdCliente == 0) {
        printf("\nNenhum cliente cadastrado para remover.\n\n");
        return;
    }

    char cpfBusca[15];
    printf("Informe o CPF do cliente que deseja remover (000.000.000-00): ");
    scanf(" %[^\n]s", cpfBusca);

    for (int i = 0; i < *qtdAgendamentos; i++) {
        if (strcmp(agendamentos[i].cpfCliente, cpfBusca) == 0) {
            printf("\nNao e possivel remover o cliente %s, pois possui agendamentos ativos.\n", cpfBusca);
            return;
        }
    }

    int posicao = -1;
    for (int i = 0; i < *qtdCliente; i++) {
        if (strcmp((*clientes)[i].cpf, cpfBusca) == 0) {
            posicao = i;
            break;
        }
    }

    if (posicao == -1) {
        printf("\nCliente com CPF %s nao encontrado.\n", cpfBusca);
        return;
    }

    (*clientes)[posicao] = (*clientes)[*qtdCliente - 1];
    (*qtdCliente)--;

    capacidadeCl--;
    Cliente *temp = realloc(*clientes, capacidadeCl * sizeof(Cliente));
    if (temp != NULL || capacidadeCl == 0) {
        *clientes = temp;
    } else {
        perror("Erro ao realocar memoria apos remocao");
        exit(1);
    }

    fcliente = fopen("clientes.bin", "wb");
    if (fcliente == NULL) {
        perror("\nErro: nao foi possivel abrir o arquivo clientes\n");
        exit(1);
    }
    fwrite(qtdCliente,sizeof(int),1,fcliente);
    fwrite(*clientes, sizeof(Cliente), *qtdCliente, fcliente);
    fclose(fcliente);

    printf("\nCliente removido com sucesso!\n");
}
