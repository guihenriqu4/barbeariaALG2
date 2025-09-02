#include "../headers/agendamento.h"
#include "cliente.h"
#include "colab.h"
#include <stdio.h>
#include <stdlib.h>

// #define INCREMENTO 5

long int qtdAgen = 0;
long int capacidadeA = 0;
long int id = 1;


// CPF do cliente, retornando: Agendamentos ativos, nome e celular vinculados a esse CPF.
void buscarAgendamentosPorCPF(Agendamento *agendamentos, int qtd, const char *cpf) {
    int encontrou = 0;
    for (int i = 0; i < qtd; i++) {
        if (strcmp(agendamentos[i].cpfClinte, cpf) == 0) {
            printf("Agendamento ID: %ld\n", agendamentos[i].id);
            printf("ID do Colaborador: %d\n", agendamentos[i].idColab);
            printf("Data: %s\n", agendamentos[i].data);
            printf("Horário: %s\n", agendamentos[i].horario);
            printf("Serviços desejados:\n");
            for (int j = 0; agendamentos[i].servicoDesejado[j] != NULL; j++)
                printf("- %s\n", agendamentos[i].servicoDesejado[j]);
            printf("\n");
            encontrou = 1;
        }
    }
    if (!encontrou) {
        printf("Nenhum agendamento encontrado para o CPF %s.\n", cpf);
    }
}


// //Cadastrando novo agendamento
// void inserirAgendamento(Agendamento *p){
//     if(qtdAgen >= capacidadeA){ //Verifica se existem agendamentos suficientes para preencher completamente o vetor
//         capacidadeA += INCREMENTO; //Caso sim, aumenta a capacidade em um bloco de 5
//         p = (Agendamento *) (p, capacidadeA * sizeof(Agendamento)); //Realoca memória de acordo com o bloco
//         if(p == NULL){ //Verifica se a alocação foi bem sucedida
//             perror("Erro ao realocar memória\n");
//             return;
//         }
//     }

//     //Solicita as informações necessárias para inserir um novo cliente
//     long int n;
//     Agendamento a;
//     a.id = id++; //Atribui um identificador ao agendamento em uma sequência crescente
//     printf("Informe o CPF do cliente: ");
//     scanf(" %[^\n]s", a.cpfClinte);

//     printf("Informe o ID do colaborador: ");
//     scanf("%d", &a.idColab);

//     printf("Informe a data do agendamento (dd/MM//YY): ");
//     scanf(" %[^\n]s", &a.data);

//     printf("Informe o horário do agendamento (HH:mm): ");
//     scanf(" %[^\n]s", &a.horario);

//     printf("Informe quantos serviços foram solicitados: ");
//     scanf("%d", &n);

//     //Segue a mesma ideia do cadastro de serviços prestados na aba de colaboradores, ou seja, é uma matriz tendo em vista que é um vetor de vetores de caracteres
//     a.servicoDesejado = (char **) malloc(n * sizeof(char *));
//     if(a.servicoDesejado == NULL){
//         perror("Erro ao realocar memória\n");
//         return;
//     }
//     for(int i = 0; i < n; i++){
//         a.servicoDesejado[i] = malloc(200 * sizeof(char));
//         if(a.servicoDesejado[i] == NULL){
//             perror("Erro ao realocar memória\n");
//             return;
//         }
//         printf("Informe o nome do %d˚ serviço: ", i+1);
//         scanf(" %[^\n]s", a.servicoDesejado[i]);
//     }

//     p[qtdAgen] = a;
//     printf("Agendamento inserido com sucesso! ID: \n", a.id);
//     qtdAgen++;
// }


// //Listando todos os Agendamentos "Nao obrigatorio"
// /*
// void listarAgendamentos(Agendamento *agendamentos, int qtd) {
//     if (qtd == 0) {
//         printf("Nenhum agendamento realizado.\n\n");
//         return;
//     }

//     for (int i = 0; i < qtd; i++) {
//         printf("---Agendamento %d---\n", i + 1);
//         printf("ID: %ld\n", agendamentos[i].id);
//         printf("CPF do cliente: %s\n", agendamentos[i].cpfClinte);
//         printf("ID do colaborador: %d\n", agendamentos[i].idColab);
//         printf("Data: %s\n", agendamentos[i].data);
//         printf("Horário: %s\n", agendamentos[i].horario);
//         printf("Serviços desejados:\n");
//         for (int j = 0; agendamentos[i].servicoDesejado[j] != NULL; j++)
//             printf("- %s\n", agendamentos[i].servicoDesejado[j]);
//         printf("\n");
//     }
// }
// */

// //Alterar as informações do agendamento
// void alterarAgendamento(Agendamento *agend){
//     if (qtdAgen == 0){
//         printf("\nNenhum agendamento realizado.\n\n");
//         return;
//     }

//     long int idAgBusca;
//     printf("\nInforme o ID do agendamento que deseja alterar: ");
//     scanf("%ld",&idAgBusca);

//     int encontrarAgendamento = 0;
//    int N;
//     for(int i=0;i<qtdAgen;i++){

//         if(agend[i].id == idAgBusca){
//             printf("\nInforme o novo CPF do Cliente(000.000.000-00): ");
//             scanf(" %[^\n]s",agend[i].cpfCliente);
//             printf("\nInforme o novo ID do Colaborador: ");
//             scanf("%d",&agend[i].idColab);
//             getchar();
//             printf("\nInforme a nova data do agendamento(dd/MM/YY): ");
//             scanf(" %[^\n]s",agend[i].data);
//             printf("\nInforme o novo horario do agendamento (HH:mm): ");
//             scanf(" %[^\n]s",agend[i].horario);
//             printf("\nInforme a quantidade de servicos desejados: ");
//             scanf("%d",&N);
//
//             agend.servicoDesejado = (char**)realloc((*agend)[i].servicoDesejado,N*sizeof(char*));
//             if(agend.servicoDesejado == NULL){
//                perror("\nErro ao realocar memoria\n");
//                return;
//             }
//             for(int j=0;j<N;j++){
//                (*agend)[i].servicoDesejado[j] = (char*)malloc(200*sizeof(char));
//                if((*agend)[i].servicoDesejado[j] == NULL){
//                    perror("\nErro ao realocar memoria!\n");
//                    return;
//                }
//             printf("\nInforme o %d˚ servico desejado: ",j+1);
//             scanf(" %[^\n]s",(*agend)[i].servicoDesejado[j]);
//
//             }
//             printf("\n\nAgendamento alterado com sucesso!\n\n");
//             encontrarAgendamento = 1;
//             break;
//         }
//     }

//     if(!encontrarAgendamento){
//         printf("Nenhum agendamento realizaddo com o ID %ld",idAgBusca);
//         return;
//     }
// }

//void removerAgendamentos(Agendamento **agendamentos) {
//    if (qtdAgen == 0) {
//        printf("\nNenhum agendamento para remover.\n\n");
//        return;
//    }
//
//    long int idBusca;
//    printf("Informe o ID do agendamento que deseja remover: ");
//    scanf("%ld", &idBusca);
//
//    int posicao = -1;
//    for (int i = 0; i < qtdAgen; i++) {
//        if ((*agendamentos)[i].id == idBusca) {
//            posicao = i;
//            break;
//        }
//    }
//
//    if (posicao == -1) {
//        printf("\nAgendamento com ID %ld não encontrado.\n", idBusca);
//        return;
//    }
//
//    // Libera memória do agendamento que será removido
//    if ((*agendamentos)[posicao].servicoDesejado != NULL) {
//        for (int j = 0; (*agendamentos)[posicao].servicoDesejado[j] != NULL; j++) {
//            free((*agendamentos)[posicao].servicoDesejado[j]);
//        }
//        free((*agendamentos)[posicao].servicoDesejado);
//    }
//    // Substitui pelo último agendamento
//   (*agendamentos)[posicao] = (*agendamentos)[qtdAgen - 1];
//    qtdAgen--;
//
//    // Reduz capacidade em 1 e realoca memória
//    capacidadeA--;
//    Agendamento *temp = realloc(*agendamentos, capacidadeA * sizeof(Agendamento));
//    if (temp != NULL || capacidadeA == 0) {
//        *agendamentos = temp;
//  } else {
//     printf("Erro ao realocar memória após remoção de agendamento");
//    }
//
//    printf("\nAgendamento removido com sucesso!\n");
//}
