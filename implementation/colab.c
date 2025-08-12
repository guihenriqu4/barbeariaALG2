#include "colab.h"
#include <stdio.h>
#include <stdlib.h>

int qtdColab = 0;
long int id = 1;

//Cadastrando colaborador
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

//Listando todos os Colaboradores
void listarColabs(Colab *colabs) {
    if (qtdColab == 0) {
        printf("Nenhum colaborador cadastrado.\n\n");
        return;
    }

    for (int i = 0; i < qtdColab; i++) {
        printf("--Colaborador %d--\n", i + 1);
        printf("ID: %d\n", colabs[i].id);
        printf("Nome: %s\n", colabs[i].nome);
        printf("Celular: %ld\n", colabs[i].celular);
        printf("Serviços prestados:\n");
        for (int j = 0; colabs[i].servicosPrestados[j] != NULL; j++) 
            printf("- %s\n", colabs[i].servicosPrestados[j]);
        printf("\n");
    }
}