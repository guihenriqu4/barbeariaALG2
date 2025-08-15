#ifndef COLAB_H
#define COLAB_H

typedef struct {
    int id;
    char nome[50];
    long int celular;
    char **servicosPrestados;
}Colab;

void inserirColab(Colab **p);
void listarColabs(Colab *colabs);
void alterarColabs(Colab **colabs);
void removeColabs(Colab *colabs);

#endif