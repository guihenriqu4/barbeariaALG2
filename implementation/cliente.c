#include "../headers/cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INCREMENTO 5 //Número constante que incrementará as posições em blocos de 5

int qtdCliente = 0; //Gerencia a quantidade de clientes existentes
int capacidadeCl = 0; //Gerencia a capacidade do vetor de clientes (tamanho total alocado)

//Cadastrando cliente
void inserirCliente(Cliente *p){
    if(qtdCliente >= capacidadeCl){ //Verifica se existem clientes suficientes para preencher completamente o vetor
        capacidadeCl += INCREMENTO; //Caso sim, aumenta a capacidade em um bloco de 5
        p = (Cliente *) realloc(p, capacidadeCl * sizeof(Cliente)); //Realoca memória de acordo com o bloco
        if(p == NULL){ //Verifica se a alocação foi bem sucedida
            perror("Erro ao realocar memória\n");
            return;
        }
    }

    //Solicita as informações necessárias para inserir um novo cliente
    Cliente c;
    printf("Informe o CPF do cliente (000.000.000-00): ");
    scanf(" %[^\n]s", c.cpf);

    //Verifica se existe algum cadastro com a chave primária informada
    for(int i = 0; i < qtdCliente; i++){
        if(p[i].cpf == c.cpf){
            perror("CPF já cadastrado.\n");
            return;
        }
    }

    printf("Informe o nome do cliente: ");
    scanf(" %[^\n]s", c.nome);

    printf("Informe o celular do cliente (00900000000): ");
    scanf("%ld", &c.celular);

    printf("Informe a data do cadastro (dd/MM/YY): ");
    scanf(" %[^\n]s", c.dataIntegracao);

    //Armazena o cliente criado no vetor
    p[qtdCliente] = c;
    printf("Cliente inserido com sucesso!\n");
    qtdCliente++; //Indica que houve um aumento no número de clientes
}

//Listando todos os Clientes
void listarClientes(Cliente *clientes) {
    if (qtdCliente == 0) {
        printf("Nenhum cliente cadastrado.\n\n");
        return;
    }

    for (int i = 0; i < qtdCliente; i++) {
        printf("---Cliente %d---\n", i + 1);
        printf("CPF: %s\n", clientes[i].cpf);
        printf("Nome: %s\n", clientes[i].nome);
        printf("Celular: %ld\n", clientes[i].celular);
        printf("Data de integracao: %s\n\n", clientes[i].dataIntegracao);
    }
}

//Alterar as informações do Cliente
void alterarClientes(Cliente *clientes){
    if (qtdCliente == 0){
        printf("\nNenhum cliente cadastrado.\n\n");
        return;
    }

    char cpfBusca[14];
    printf("\n\nInforme o CPF do Cliente que deseja alterar (000.000.000-00): ");
    scanf("%[^\n]s",cpfBusca);

    int clienteEncontrado = 0;
    for(int i=0;i<qtdCliente;i++){

        if(strcmp(clientes[i].cpf,cpfBusca) == 0){
            printf("\n\nCliente encontrado! Por favor, insira as novas informações\n");
            printf("Informe o novo nome do cliente: ");
            scanf("%[^\n]s",clientes[i].nome);
            printf("\nInforme o novo celular do cliente (00900000000): ");
            scanf("%ld",&clientes[i].celular);
            getchar();
            printf("\nInforme a nova data do cadastro (dd/MM/YY): ");
            scanf("%[^\n]",clientes[i].dataIntegracao);

            printf("\n\nCliente alterado com sucesso!\n\n");
            clienteEncontrado = 1;
            break;
        }
    }

    if(!clienteEncontrado){
        printf("\nCliente com CPF %s nao encontrado.\n",cpfBusca);
    }
}
