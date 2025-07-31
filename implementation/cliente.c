#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>

int qtdCliente = 0;

void inserirCliente(Cliente *p, Cliente c){
    p = realloc(p, (qtdCliente + 1) * sizeof(Cliente));
    if(p == NULL){
        perror("Erro ao realocar memória\n");
        return 1;
    }
    p[qtdCliente] = c;
    printf("Cliente inserido com sucesso!\n");
}