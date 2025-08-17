#include "../headers/cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INCREMENTO 5 //Número constante que incrementará as posições em blocos de 5

int qtdCliente = 0; //Gerencia a quantidade de clientes existentes
int capacidadeCl = 0; //Gerencia a capacidade do vetor de clientes (tamanho total alocado)

//Cadastrando cliente
void inserirCliente(Cliente **p){
    if(qtdCliente >= capacidadeCl){ //Verifica se existem clientes suficientes para preencher completamente o vetor
        capacidadeCl += INCREMENTO; //Caso sim, aumenta a capacidade em um bloco de 5
        *p = (Cliente *) realloc(*p, capacidadeCl * sizeof(Cliente)); //Realoca memória de acordo com o bloco
        if(*p == NULL){ //Verifica se a alocação foi bem sucedida
            perror("Erro ao realocar memoria\n");
            return;
        }
    }

    //Solicita as informações necessárias para inserir um novo cliente
    Cliente c;
    printf("Informe o CPF do cliente (000.000.000-00): ");
    scanf(" %[^\n]s", c.cpf);

    //Verifica se existe algum cadastro com a chave primária informada
    for(int i = 0; i < qtdCliente; i++){
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

    //Armazena o cliente criado no vetor
    (*p)[qtdCliente] = c;
    printf("Cliente inserido com sucesso!\n");
    qtdCliente++; //Indica que houve um aumento no número de clientes
}

//Listando todos os Clientes
void listarClientes(Cliente *clientes) {
    //Verifica se existem clientes cadastrados
    if (qtdCliente == 0) {
        printf("Nenhum cliente cadastrado.\n\n");
        return;
    }
    //Percorre o vetor de clientes e imprime as informações de cada um
    for (int i = 0; i < qtdCliente; i++) {
        printf("-- Cliente %d --\n", i + 1);
        printf(" CPF: %s\n", clientes[i].cpf);
        printf(" Nome: %s\n", clientes[i].nome);
        printf(" Celular: %lld\n", clientes[i].celular);
        printf(" Data de integracao: %s\n\n", clientes[i].dataIntegracao);
    }
}

//Alterar as informações do Cliente
void alterarClientes(Cliente **clientes){
    if (qtdCliente == 0){//Garante que tem algum cliente cadastrado
        printf("\nNenhum cliente cadastrado.\n\n");
        return;
    }

    char cpfBusca[15];
    printf("Informe o CPF do Cliente que deseja alterar (000.000.000-00): ");
    scanf(" %[^\n]s",cpfBusca);//Recebe o CPF para saber qual será alterado

    int clienteEncontrado = 0;

    for(int i = 0; i < qtdCliente; i++){
        if(strcmp((*clientes)[i].cpf, cpfBusca) == 0){//Encontra o CPF do cliente desejado para ser alterado
            printf("Cliente encontrado! Por favor, insira as novas informacoes\n");

            printf("Informe o novo nome do cliente: ");
            scanf(" %[^\n]s",(*clientes)[i].nome);

            printf("\nInforme o novo celular do cliente (00900000000): ");
            scanf("%lld",&(*clientes)[i].celular);

            printf("\nInforme a nova data do cadastro (dd/MM/YY): ");
            scanf(" %[^\n]",(*clientes)[i].dataIntegracao);

            printf("\nCliente alterado com sucesso!\n");//Garante ao usuario que a alteração tenha sido concluida
            clienteEncontrado = 1;//Mostra que o cliente foi encontrado
            break;
        }
    }

    if(!clienteEncontrado){//Caso o usuario tenha digitado errado o CPF, ou simplesmente não exista esse CPF no armazenamento
        printf("\nCliente com CPF %s nao encontrado.\n",cpfBusca);
    }
}

void removerClientes(Cliente **clientes) {
    if (qtdCliente == 0) {
        printf("\nNenhum cliente cadastrado para remover.\n\n");
        return;
    }

    char cpfBusca[14];
    printf("Informe o CPF do cliente que deseja remover (000.000.000-00): ");
    scanf(" %[^\n]s", cpfBusca);

    int posicao = -1;
    for (int i = 0; i < qtdCliente; i++) {
        if (strcmp((*clientes)[i].cpf, cpfBusca) == 0) {
            posicao = i;
            break;
        }
    }

    if (posicao == -1) {
        printf("\nCliente com CPF %s nao encontrado.\n", cpfBusca);
        return;
    }

    // Substitui pelo último cliente do vetor
    (*clientes)[posicao] = (*clientes)[qtdCliente - 1];
    qtdCliente--;

    // Diminui a capacidade em 1 posição e realoca
    capacidadeCl--;
    Cliente *temp = realloc(*clientes, capacidadeCl * sizeof(Cliente));
    if (temp != NULL || capacidadeCl == 0) {
        *clientes = temp; // atualiza o ponteiro se realloc funcionar
    } else {
        printf("Erro ao realocar memoria apos remocao");
    }

    printf("\nCliente removido com sucesso!\n");
}
