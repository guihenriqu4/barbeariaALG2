#ifndef AGENDAMENTO_H
#define AGENDAMENTO_H

struct Cliente;
struct Colab;

typedef struct {
    long int id;
    char cpfClinte[14];
    int idColab;
    char data[8]; //formato dd/MM/YY
    char horario[5]; //formato HH:mm
    char **servicoDesejado;
}Agendamento;

#endif