#include "agendamento.h"
#include <stdio.h>
#include <stdlib.h>

long int qtdAgen = 0;

void inserirAgendamento(Agendamento *p, Agendamento a){
    p = realloc(p, (qtdAgen + 1) * sizeof(Agendamento));
    if(p == NULL){
        perror("Erro ao realocar memória\n");
        return 1;
    }
    p[qtdAgen] = a;
    printf("Agendamento inserido com sucesso!\n");
}