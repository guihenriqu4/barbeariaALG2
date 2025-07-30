#ifndef COLAB_H
#define COLAB_H

typedef struct {
    int id;
    char nome[50];
    long int celular;
    char servicosPrestados[];
}Colab;

#endif