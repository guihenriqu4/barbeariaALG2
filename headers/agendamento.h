#ifndef AGENDAMENTO_H
#define AGENDAMENTO_H

#include <stdio.h>
#include "structs.h"

void inserirAgendamento(Agendamento **p, Cliente *clientes, int *qtdClientes, Colab *colabs, int *qtdColabs, long int *qtdAgen, FILE *fagen);

void buscarAgendamentosPorCPF(Agendamento *agendamentos, long int *qtdAgendamentos, Cliente *clientes, int *qtdClientes, Colab *colaboradores, int *qtdColaboradores, char *cpf);

void buscarAgendamentosPorIDdoColab(Agendamento *agendamentos, long int *qtdAgendamentos, Colab *colaboradores, int *qtdColaboradores, int idColab);

void buscarAgendamentosPorData(Agendamento *agendamentos, long int *qtdAgendamentos, Cliente *clientes, int *qtdClientes, Colab *colaboradores, int *qtdColaboradores, char *data);

void removerAgendamentos(Agendamento **agendamentos, long int *qtdAgendamentos, FILE *fagen);

#endif