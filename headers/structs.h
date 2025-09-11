#ifndef STRUCTS_H
#define STRUCTS_H

// Definimos TODOS os tipos de dados aqui.

typedef struct Cliente {
    char cpf[15];
    char nome[200];
    long long int celular;
    char dataIntegracao[9];
} Cliente;

typedef struct Colab {
    int id;
    char nome[50];
    long long int celular;
    char servicosPrestados[5][200];
    int nServicos;
} Colab;

typedef struct Agendamento {
    long int id;
    char cpfCliente[15];
    int idColab;
    char data[9];
    char horario[6];
    char servicoDesejado[5][200];
} Agendamento;


#endif // STRUCTS_H
