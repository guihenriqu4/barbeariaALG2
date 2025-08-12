#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>

int qtdCliente = 0;

//Cadastrando cliente
void inserirCliente(Cliente *p){
    p = realloc(p, (qtdCliente + 1) * sizeof(Cliente));
    if(p == NULL){
        perror("Erro ao realocar memória\n");
        return;
    }

    Cliente c;
    printf("Informe o CPF do cliente (000.000.000-00): "); scanf(" %[^\n]s", c.cpf);
    printf("Informe o nome do cliente: "); scanf(" %[^\n]s", c.nome);
    printf("Informe o celular do cliente (00900000000): "); scanf("%ld", &c.celular);
    printf("Informe a data do cadastro (dd/MM/YY): "); scanf(" %[^\n]s", c.dataIntegracao);

    p[qtdCliente] = c;
    printf("Cliente inserido com sucesso!\n");
    qtdCliente++;
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
        printf("Data de integração: %s\n\n", clientes[i].dataIntegracao);
    }
}