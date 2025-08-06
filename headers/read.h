//Header do read
#ifndef READ_H
#define READ_H

//Pegando as structs necessárias
#include "cliente.h"
#include "colab.h"
#include "agendamento.h"

// Funções de leitura
void listarClientes(Cliente *clientes, int qtd);
void listarColabs(Colab *colabs, int qtd);
void listarAgendamentos(Agendamento *agendamentos, int qtd);

#endif