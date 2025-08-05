#include "colab.h"
#include <stdio.h>
#include <stdlib.h>

int qtdColab = 0;
long int id = 1;

void inserirColab(Colab *p) {
    p = realloc(p, (qtdColab + 1) * sizeof(Colab));
    if(p == NULL){
        perror("Erro ao realocar memória\n");
        return;
    }

    Colab c;
    int n;
    c.id = id++;
    printf("Informe o nome do colaborador: "); scanf(" %[^\n]s", c.nome);
    printf("Informe o celular do colaborador (00900000000): "); scanf("%ld", &c.celular);
    printf("Informe quantos serviços esse colaborador prestará: "); scanf("%d", &n);

    c.servicosPrestados = malloc(n * sizeof(char *));
    if(c.servicosPrestados == NULL){
        perror("Erro ao realocar memória\n");
        return;
    }
    for(int i = 0; i < n; i++){
        c.servicosPrestados[i] = malloc(200 * sizeof(char));
        if(c.servicosPrestados[i] == NULL){
            perror("Erro ao realocar memória\n");
            return;
        }
        printf("Informe o nome do %d˚serviço: ", i+1);
        scanf(" %[^\n]s", c.servicosPrestados[i]);
    }

    p[qtdColab] = c;
    printf("Colaborador inserido com sucesso! ID: %ld\n", c.id);
    qtdColab++;
}