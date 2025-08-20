#ifndef AGENDAMENTO_H
#define AGENDAMENTO_H

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

#endif