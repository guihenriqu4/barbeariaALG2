#ifndef COLAB_H
#define COLAB_H

#include <stdio.h>

typedef struct {
    int id;
    char nome[50];
    long long int celular;
    char servicosPrestados[5][200];
    int nServicos;
}Colab;

void inserirColab(Colab **p, FILE *fcolab, int *qtdColab);
void listarColabs(Colab *colabs, int *qtdColab);
void alterarColabs(Colab **colabs, int *qtdColab);
void removerColabs(Colab **colabs, int *qtdColab);

#endif
