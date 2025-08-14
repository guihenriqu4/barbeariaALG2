// #include "../headers/agendamento.h"
// #include "cliente.h"
// #include "colab.h"
// #include <stdio.h>
// #include <stdlib.h>

// #define INCREMENTO 5

// long int qtdAgen = 0;
// long int capacidadeA = 0;
// long int id = 1;


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

// //função para converter a data do formato dd/MM/YY para um inteiro
// int converterData(const char *data) {
//     return (data[6] - '0') * 10000 +
//            (data[7] - '0') * 1000 +
//            (data[3] - '0') * 100 +
//            (data[4] - '0') * 10 +
//            (data[0] - '0') * 1 +
//            (data[1] - '0');
// }

// //Listar todos os Agendamentos pos data informada, recebendo um cliente, colaborador e data base especificos
// void listarAgendamentosPosData(Agendamento *agendamentos, int qtdAg, Cliente *clientes, int qtdCl, Colab *colabs, int qtdCol) {
//     if (qtdAg == 0) {
//         printf("Nenhum agendamento realizado.\n");
//         return;
//     }

//     int idColab;
//     char cpf[14], dataBase[9];

//     printf("Digite o ID do colaborador: ");
//     scanf("%d", &idColab);
//     getchar();

//     printf("Digite o CPF do cliente (000.000.000-00): ");
//     scanf(" %13[^\n]", cpf);

//     printf("Digite a data base (dd/MM/YY), para informar agendamentos subsequentes: ");
//     scanf(" %[^\n]", dataBase);

//     int dataCmp = converterData(dataBase);
//     int encontrados = 0;
// <<<<<<< HEAD

//     printf("\nTodos os agendamentos do colaborador ID %d e cliente CPF %s após a data %s:\n\n", idColab, cpf, dataBase);
// =======

//     printf("\nTodos os agendamentos do colaborador ID %d e cliente CPF %s apos a data %s:\n\n", idColab, cpf, dataBase);
// >>>>>>> 41d0ce020617a9417b24936d3b1666ef3df6c185

//     for (int i = 0; i < qtdAg; i++) {
//         if (strcmp(agendamentos[i].cpfClinte, cpf) == 0 && agendamentos[i].idColab == idColab) {

//             int dataAg = converterData(agendamentos[i].data);

//             if (dataAg > dataCmp) {
//                 encontrados++;

//                 printf("\n--- Agendamento %ld ---\n", agendamentos[i].id);
//                 printf("Data: %s\n", agendamentos[i].data);
// <<<<<<< HEAD
//                 printf("Horário: %s\n", agendamentos[i].horario);

//                 //mantendo por boa pratica, mas no caso nao sei se precisa
//                 if (cli == NULL)
//                     printf("Cliente: Informação não encontrada\n");
// =======
//                 printf("Horario: %s\n", agendamentos[i].horario);
// >>>>>>> 41d0ce020617a9417b24936d3b1666ef3df6c185


//                 printf("Serviços desejados:\n");
//                 for (int j = 0; agendamentos[i].servicoDesejado[j] != NULL; j++) {
//                     printf("- %s\n", agendamentos[i].servicoDesejado[j]);
//                 }
//             }
//         }
//     }

//     if (encontrados == 0) {
//         printf("\nNenhum agendamento encontrado para os filtros informados.\n");
//     }
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
//             scanf("%[^\n]s",agend[i].cpfCliente);
//             printf("\nInforme o novo ID do Colaborador: ");
//             scanf("%d",&agend[i].idColab);
//             getchar();
//             printf("\nInforme a nova data do agendamento(dd/MM/YY): ");
//             scanf("%[^\n]s",agend[i].data);
//             printf("\nInforme o novo horario do agendamento (HH:mm): ");
//             scanf("%[^\n]s",agend[i].horario);
//             printf("\nInforme a quantidade de servicos desejados: ");
//             scanf("%d",&N);
//
//             agend.servicoDesejado = (char**)realloc(N*sizeof(char*));
//             if(agend.servicoDesejado == NULL){
//                perror("\nErro ao realocar memoria\n");
//                return;
//             }
//             for(int j=0;j<N;j++){
//                agend.servicoDesejado[j] = (char*)malloc(200*sizeof(char));
//                if(agend.servicoDesejado == NULL){
//                    perror("\nErro ao realocar memoria!\n");
//                    return;
//                }
//             printf("\nInforme o %d˚ servico desejado: ",j+1);
//             scanf("%[^\n]s",agend.servicoDesejado[j]);
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
