#ifndef COLAB_H
#define COLAB_H

#include <stdio.h>
#include "structs.h"

void inserirColab(Colab **p, FILE *fcolab, int *qtdColab);
void listarColabs(Colab *colabs, int *qtdColab);
void alterarColabs(Colab **colabs, int *qtdColab,FILE *fcolab);
void removerColabs(Colab **colabs, Agendamento *agendamentos, long int *qtdAgendamentos, int *qtdColab, FILE *fcolabs);

#endif
