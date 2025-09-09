#ifndef CLIENTE_H
#define CLIENTE_H

#include <stdio.h>

typedef struct{
    char cpf[15]; //formato 000.000.000-00
    char nome[200];
    long long int celular; //formato 00900000000
    char dataIntegracao[9]; //formato dd/MM/YY
}Cliente;

void inserirCliente(Cliente **p, FILE *fcliente, int *qtdCliente);
void listarClientes(Cliente *clientes, int *qtdCliente);
void alterarClientes(Cliente **clientes, int *qtdCliente);
void removerClientes(Cliente **clientes, int *qtdCliente);

#endif
