#ifndef COLAB_H
#define COLAB_H

#include <stdio.h>
#include "agendamento.h"  // precisa do struct Agendamento

typedef struct {
    int id;
    char nome[50];
    long long int celular;
    char servicosPrestados[5][200];
    int nServicos;
} Colab;

void inserirColab(Colab **p, FILE *fcolab);
void listarColabs(Colab *colabs);
void alterarColabs(Colab **colabs);
void removerColabs(Colab **colabs, Agendamento *agendamentos, int qtdAgendamentos);

#endif
