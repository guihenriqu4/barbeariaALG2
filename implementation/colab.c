#include "colab.h"
#include <stdio.h>
#include <stdlib.h>

int qtdColab = 0;

void inserirColab(Colab *p, Colab c) {
    p = realloc(p, (qtdColab + 1) * sizeof(Colab));
    if(p == NULL){
        perror("Erro ao realocar memória\n");
        return 1;
    }
    p[qtdColab] = c;
    qtdColab++;
    printf("Colaborador inserido com sucesso!\n");
}