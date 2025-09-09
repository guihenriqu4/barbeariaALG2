#ifndef AGENDAMENTO_H
#define AGENDAMENTO_H

#include <stdio.h>

struct Cliente;
struct Colab;

typedef struct {
    long int id;
    char cpfClinte[15];
    int idColab;
    char data[9]; //formato dd/MM/YY
    char horario[6]; //formato HH:mm
    char **servicoDesejado;
}Agendamento;

void inserirAgendamento(Agendamento **p, Cliente *clientes, int qtdClientes, Colab *colabs, int qtdColabs,FILE *fagen);
void buscarAgendamentosPorCPF(Agendamento *agendamentos, int qtdAgendamentos, Cliente *clientes, int qtdClientes, char *cpf);
void buscarAgendamentosPorIDdoColab(Agendamento *agendamentos, int qtdAgendamentos, Colab *colaboradores, int qtdColaboradores, int idColab);
void removerAgendamentos(Agendamento **agendamentos);

#endif