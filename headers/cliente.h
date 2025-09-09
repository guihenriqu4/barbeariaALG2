#ifndef CLIENTE_H
#define CLIENTE_H

#include <stdio.h>
#include "agendamento.h"  // precisa do struct Agendamento

typedef struct {
    char cpf[15];          // formato 000.000.000-00
    char nome[200];
    long long int celular; // formato 00900000000
    char dataIntegracao[9];// formato dd/MM/YY
} Cliente;

void inserirCliente(Cliente **p, FILE *fcliente);
void listarClientes(Cliente *clientes);
void alterarClientes(Cliente **clientes);
void removerClientes(Cliente **clientes, Agendamento *agendamentos, int qtdAgendamentos);

#endif
