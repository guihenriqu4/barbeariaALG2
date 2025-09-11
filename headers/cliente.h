#ifndef CLIENTE_H
#define CLIENTE_H

#include <stdio.h>
#include "structs.h"

void inserirCliente(Cliente **p, FILE *fcliente, int *qtdCliente);
void listarClientes(Cliente *clientes, int *qtdCliente);
void alterarClientes(Cliente **clientes, int *qtdCliente, FILE *fcliente);
void removerClientes(Cliente **clientes, Agendamento *agendamentos, long int *qtdAgendamentos, int *qtdCliente, FILE *fcliente);

#endif
