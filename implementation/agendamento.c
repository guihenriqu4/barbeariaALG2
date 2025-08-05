#include "agendamento.h"
#include <stdio.h>
#include <stdlib.h>

long int qtdAgen = 0;
long int id = 1;

void inserirAgendamento(Agendamento *p){
    p = realloc(p, (qtdAgen + 1) * sizeof(Agendamento));
    if(p == NULL){
        perror("Erro ao realocar memória\n");
        return;
    }

    int n;
    Agendamento a;
    a.id = id++;
    printf("Informe o CPF do cliente: "); scanf(" %[^\n]s", a.cpfClinte);
    printf("Informe o ID do colaborador: "); scanf("%d", &a.idColab);
    printf("Informe a data do agendamento (dd/MM//YY): "); scanf(" %[^\n]s", &a.data);
    printf("Informe o horário do agendamento (HH:mm): "); scanf(" %[^\n]s", &a.horario);
    printf("Informe quantos serviços foram solicitados: "); scanf("%d", &n);

    a.servicoDesejado = malloc(n * sizeof(char *));
    for(int i = 0; i < n; i++){
        a.servicoDesejado[i] = malloc(200 * sizeof(char));
        printf("Informe o nome do %d˚ serviço: ", i+1);
        scanf(" %[^\n]s", a.servicoDesejado[i]);
    }

    p[qtdAgen] = a;
    printf("Agendamento inserido com sucesso! ID: \n", a.id);
    qtdAgen++;
}