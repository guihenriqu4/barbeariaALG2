#ifndef COLAB_H
#define COLAB_H

typedef struct {
    int id;
    char nome[50];
    long long int celular;
    char **servicosPrestados;
    int nServicos;
}Colab;

void inserirColab(Colab **p, FILE *fcolab);
void listarColabs(Colab *colabs);
void alterarColabs(Colab **colabs);
void removerColabs(Colab **colabs);

#endif
