#include "read.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Listando todos os Clientes
void listarClientes(Cliente *clientes, int qtd) {
    if (qtd == 0) {
        printf("Nenhum cliente cadastrado.\n\n");
        return;
    }

    for (int i = 0; i < qtd; i++) {
        printf("Cliente %d:\n", i + 1);
        printf("CPF: %s\n", clientes[i].cpf);
        printf("Nome: %s\n", clientes[i].nome);
        printf("Celular: %ld\n", clientes[i].celular);
        printf("Data de integração: %s\n\n", clientes[i].dataIntegracao);
    }
}

//Listando todos os Colaboradores
void listarColabs(Colab *colabs, int qtd) {
    if (qtd == 0) {
        printf("Nenhum colaborador cadastrado.\n\n");
        return;
    }

    for (int i = 0; i < qtd; i++) {
        printf("Colaborador %d:\n", i + 1);
        printf("ID: %d\n", colabs[i].id);
        printf("Nome: %s\n", colabs[i].nome);
        printf("Celular: %ld\n", colabs[i].celular);
        printf("Serviços prestados:\n");
        for (int j = 0; colabs[i].servicosPrestados[j] != NULL; j++) 
            printf("- %s\n", colabs[i].servicosPrestados[j]);
        printf("\n");
    }
}

//Listando todos os Agendamentos
void listarAgendamentos(Agendamento *agendamentos, int qtd) {
    if (qtd == 0) {
        printf("Nenhum agendamento realizado.\n\n");
        return;
    }

    for (int i = 0; i < qtd; i++) {
        printf("Agendamento %d:\n", i + 1);
        printf("ID: %ld\n", agendamentos[i].id);
        printf("CPF do cliente: %s\n", agendamentos[i].cpfClinte);
        printf("ID do colaborador: %d\n", agendamentos[i].idColab);
        printf("Data: %s\n", agendamentos[i].data);
        printf("Horário: %s\n", agendamentos[i].horario);
        printf("Serviços desejados:\n");
        for (int j = 0; agendamentos[i].servicoDesejado[j] != NULL; j++)
            printf("- %s\n", agendamentos[i].servicoDesejado[j]);
        printf("\n");
    }
} 

/*Falta: Mostre todos os dados de todos os registros da Estrutura 3 a partir de caracteristica especifica,
incluindo campos de pelo menos uma entre as Estruturas 1 e 2 relacionadas com cada registro.
Obrigatorio ter, pelo menos, 3 caracteristicas especificas para esse item, ou seja,
mostrar todos os registros a partir de uma caracteristica especifica de valor dado pelo usuario,
com tres opcoes possiveis de campos para a listagem. No exemplo da clinica, poderiam ser mostrados
a data do atendimento, o nome do medico e o CRM de todas as consultas feitas a partir de uma certa
data de valor indicado pelo usuario.*/
