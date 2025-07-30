#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct{
    char cpf[14]; //formato 000.000.000-00
    char nome[200];
    long int celular; //formato 00900000000
    char dataIntegracao[8]; //formato dd/MM/YY
}Cliente;

#endif