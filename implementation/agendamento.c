// #include "../headers/agendamento.h"
// #include "cliente.h"
// #include "colab.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define INCREMENTO 5

// long int qtdAgen = 0;
// long int capacidadeA = 0;
// long int id = 1;

// //Cadastrando novo agendamento
// void inserirAgendamento(Agendamento **p, Cliente *clientes, int qtdClientes, Colab *colabs, int qtdColabs,FILE *fagen){
//     if(qtdAgen >= capacidadeA){ //Verifica se existem agendamentos suficientes para preencher completamente o vetor

//         fagen = fopen("agendamentos.txt", "wb"); //Abre um arquivo binário agendamentos
//         if(fagen == NULL){ //Verifica se houve algum erro na abertura do arquivo
//             perror("Erro ao abrir o arquivo.");
//             exit(1);
//         }

//         int result = fwrite(*p, sizeof(Agendamento), qtdAgen, fagen); //Salva os dados do vetor agendamentos no arquivo binário
//         if(result < qtdAgen) perror("Erro na gravacao de algum dos agendamentos."); //Verifica se houve algum erro na escrita

//         fclose(fagen); //Fecha o arquivo

//         capacidadeA += INCREMENTO; //Caso sim, aumenta a capacidade em um bloco de 5
//         *p = (Agendamento *) realloc(*p, capacidadeA * sizeof(Agendamento)); //Realoca memória de acordo com o bloco
//         if(*p == NULL){ //Verifica se a alocação foi bem sucedida
//             perror("Erro ao realocar memória\n");
//             exit(1);
//         }
//     }

//     //Solicita as informações necessárias para inserir um novo cliente
//     long int n;
//     Agendamento a;
//     a.id = id++; //Atribui um identificador ao agendamento em uma sequência crescente
//     printf("Informe o CPF do cliente: ");
//     scanf(" %[^\n]s", a.cpfClinte);

//     //Verifica se o cliente existe antes de cadastrar o agendamento
//     int r = 0;
//     for(int i = 0; i < qtdClientes; i++){
//         if(strcmp(clientes[i].cpf, a.cpfClinte) == 0){
//             r = 1;
//             break;
//         }
//     }
//     if(r == 0){
//         perror("Cliente nao encontrado.");
//         exit(1);
//     }

//     printf("Informe o ID do colaborador: ");
//     scanf("%d", &a.idColab);

//     //Verifica se o cliente existe antes de cadastrar o agendamento
//     for(int i = 0; i < qtdColabs; i++){
//         if(colabs[i].id == a.idColab){
//             r = 1;
//             break;
//         }
//     }
//     if(r == 0){
//         perror("Colaborador nao encontrado.");
//         exit(1);
//     }

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
//         exit(1);
//     }
//     for(int i = 0; i < n; i++){
//         a.servicoDesejado[i] = malloc(200 * sizeof(char));
//         if(a.servicoDesejado[i] == NULL){
//             perror("Erro ao realocar memória\n");
//             exit(1);
//         }
//         printf("Informe o nome do %d serviço: ", i+1);
//         scanf(" %[^\n]s", a.servicoDesejado[i]);
//     }

//     (*p)[qtdAgen] = a;
//     printf("Agendamento inserido com sucesso! ID: %ld\n", a.id);
//     qtdAgen++;
// }

// // CPF do cliente, retornando: Agendamentos ativos, nome e celular vinculados a esse CPF.
// // Colocar a struct Agendamento como parâmetro, junto a quantidade de agendamentos, struct Cliente e quantidade de clientes, struct Colab e quantidade de colaboradores, por fim o CPF a ser buscado.
// void buscarAgendamentosPorCPF(Agendamento *agendamentos, int qtdAgendamentos, Cliente *clientes, int qtdClientes, Colab *colaboradores, int qtdColaboradores, char *cpf) {
//     int encontrouAgendamento = 0;

//     printf("--- Agendamentos para o CPF: %s ---\n", cpf);
//     // Aqui é criado uma struct clientes que aponta para NULL
//     // Depois se encontrar eu aponto essa struct para o cliente desse CPF
//     Cliente *clienteEncontrado = NULL;
//     for (int i = 0; i < qtdClientes; i++) {
//         if (strcmp(clientes[i].cpf, cpf) == 0) {
//             clienteEncontrado = &clientes[i];
//             break;
//         }
//     }

//     if (clienteEncontrado == NULL) {
//         printf("Nenhum cliente encontrado com o CPF %s.\n", cpf);
//         return;
//     }

//     // Exibe as informações do cliente, uso do -> por ser um ponteiro
//     printf("---Informacoes do Cliente---\n");
//     printf("Nome do Cliente: %s\n", clienteEncontrado->nome);
//     printf("Celular do Cliente: %lld\n", clienteEncontrado->celular);
//     printf("\n");

//     // Agora, busca pelos agendamentos, basicmanete compara o CPF do agendamento com o CPF buscado e printa os dados
//     for (int i = 0; i < qtdAgendamentos; i++) {
//         if (strcmp(agendamentos[i].cpfClinte, cpf) == 0) {
//             encontrouAgendamento = 1;
//             printf("---Informacoes do Agendamento %d ---\n", i + 1);
//             printf("ID do Agendamento: %ld\n", agendamentos[i].id);
//             printf("ID do Colaborador: %d\n", agendamentos[i].idColab);
//             printf("Data: %s\n", agendamentos[i].data);
//             printf("Horario: %s\n", agendamentos[i].horario);
//             printf("Servicos desejados:\n");

//             // pegar quantos servicos o colaborador tem, faço como o cliente, crio uma struct que aponta para NULL
//             // depois se encontrar eu aponto essa struct para o colaborador desse ID
//             Colab *colabAtual = NULL;
//             for (int k = 0; k < qtdColaboradores; k++) {
//                 if (colaboradores[k].id == agendamentos[i].idColab) {
//                     colabAtual = &colaboradores[k];
//                     break;
//                 }
//             }
//             if (colabAtual != NULL) {
//                 for (int j = 0; j < colabAtual->nServicos; j++) {
//                     printf("- %s\n", agendamentos[i].servicoDesejado[j]);
//                 }
//             }
//             printf("\n");
//         }
//     }
    
//     if (encontrouAgendamento == 0)
//         printf("Nenhum agendamento encontrado para o CPF %s.\n", cpf);
// }

// //ID do colaborador, retornando: Agendamentos ativos, nome, celular e serviços vinculados a esse ID. 
// //Colocar a struct Agendamento como parâmetro, junto a quantidade de agendamentos, struct Colab e quantidade de colaboradores, por fim o ID a ser buscado.
// void buscarAgendamentosPorIDdoColab(Agendamento *agendamentos, int qtdAgendamentos, Colab *colaboradores, int qtdColaboradores, int idColab){
//     int encontrouAgendamento = 0;

//     printf("--- Agendamentos para o ID do Colaborador: %d ---\n", idColab);
//     // Aqui eu crio uma struct colaboradores que aponta para NULL
//     // Depois se encontrar eu aponto essa struct para o colaborador desse ID
//     Colab *colaboradorEncontrado = NULL;
//     for (int i = 0; i < qtdColaboradores; i++) {
//         if (colaboradores[i].id == idColab) {
//             colaboradorEncontrado = &colaboradores[i];
//             break;
//         }
//     }

//     if (colaboradorEncontrado == NULL) {
//         printf("Nenhum colaborador encontrado com o ID %d.\n", idColab);
//         return;
//     }

//     // Exibe as informações do colaborador, uso do -> por ser um ponteiro
//     printf("---Informacoes do Colaborador---\n");
//     printf("Nome do Colaborador: %s\n", colaboradorEncontrado->nome);
//     printf("Celular do Colaborador: %lld\n", colaboradorEncontrado->celular);
//     printf("Servicos prestados pelo Colaborador:\n");
//     for (int j = 0; colaboradorEncontrado->servicosPrestados[j] != NULL; j++)
//         printf("- %s\n", colaboradorEncontrado->servicosPrestados[j]);
//     printf("\n");

//     // Agora, busca pelos agendamentos, basicamente compara o ID do agendamento com o ID buscado e printa os dados
//     for (int i = 0; i < qtdAgendamentos; i++) {
//         if (agendamentos[i].idColab == idColab) {
//             encontrouAgendamento = 1;
//             printf("---Informacoes do Agendamento %d ---\n", i + 1);
//             printf("ID do Agendamento: %ld\n", agendamentos[i].id);
//             printf("CPF do Cliente: %s\n", agendamentos[i].cpfClinte);
//             printf("Data: %s\n", agendamentos[i].data);
//             printf("Horario: %s\n", agendamentos[i].horario);
//             printf("Servicos desejados:\n");
//             for (int j = 0; j < colaboradorEncontrado->nServicos; j++) {
//                 printf("- %s\n", agendamentos[i].servicoDesejado[j]);
//             }
//             printf("\n");
//         }
//     }      
//     if (encontrouAgendamento == 0)
//         printf("Nenhum agendamento encontrado para o ID do Colaborador %d.\n", idColab);
// }

// //Data indicada pelo usuário, retornando: Horários agendados, com nome do colaborador e do cliente 
// //Colocar a struct Agendamento como parametro, junto a quantidade de agendamentos, struct Cliente e quantidade de clientes, struct Colab e quantidade de colaboradores, por fim a data a ser buscada.
// //Data: formato dd/MM/YY
// void buscarAgendamentosPorData(Agendamento *agendamentos, int qtdAgendamentos, Cliente *clientes, int qtdClientes, Colab *colaboradores, int qtdColaboradores, char *data) {
//     int encontrouAgendamento = 0;

//     printf("--- Agendamentos para a Data: %s ---\n", data);

//     // Agora, busca pelos agendamentos, basicamente compara a data do agendamento com a data buscada e printa os dados
//     for (int i = 0; i < qtdAgendamentos; i++) {
//         if (strcmp(agendamentos[i].data, data) == 0) {
//             encontrouAgendamento = 1;
//             printf("---Informacoes do Agendamento %d ---\n", i + 1);
//             printf("ID do Agendamento: %ld\n", agendamentos[i].id);
//             printf("Horario: %s\n", agendamentos[i].horario);

//             // Buscar o nome do cliente pelo CPF
//             Cliente *clienteAtual = NULL;
//             for (int j = 0; j < qtdClientes; j++) {
//                 if (strcmp(clientes[j].cpf, agendamentos[i].cpfClinte) == 0) {
//                     clienteAtual = &clientes[j];
//                     break;
//                 }
//             }
//             if (clienteAtual != NULL) 
//                 printf("Nome do Cliente: %s\n", clienteAtual->nome);
//             else
//                 printf("Cliente nao encontrado para o CPF: %s\n", agendamentos[i].cpfClinte);

//             // Buscar o nome do colaborador pelo ID
//             Colab *colabAtual = NULL;
//             for (int k = 0; k < qtdColaboradores; k++) {
//                 if (colaboradores[k].id == agendamentos[i].idColab) {
//                     colabAtual = &colaboradores[k];
//                     break;
//                 }
//             }
//             if (colabAtual != NULL)
//                 printf("Nome do Colaborador: %s\n", colabAtual->nome);
//             else 
//                 printf("Colaborador nao encontrado para o ID: %d\n", agendamentos[i].idColab);
//             printf("\n");
//         }
//     }

//     if (encontrouAgendamento == 0)
//         printf("Nenhum agendamento encontrado para a data %s.\n", data);
// }





// // //Listando todos os Agendamentos "Nao obrigatorio"
// // /*
// // void listarAgendamentos(Agendamento *agendamentos, int qtd) {
// //     if (qtd == 0) {
// //         printf("Nenhum agendamento realizado.\n\n");
// //         return;
// //     }

// //     for (int i = 0; i < qtd; i++) {
// //         printf("---Agendamento %d---\n", i + 1);
// //         printf("ID: %ld\n", agendamentos[i].id);
// //         printf("CPF do cliente: %s\n", agendamentos[i].cpfClinte);
// //         printf("ID do colaborador: %d\n", agendamentos[i].idColab);
// //         printf("Data: %s\n", agendamentos[i].data);
// //         printf("Horário: %s\n", agendamentos[i].horario);
// //         printf("Serviços desejados:\n");
// //         for (int j = 0; agendamentos[i].servicoDesejado[j] != NULL; j++)
// //             printf("- %s\n", agendamentos[i].servicoDesejado[j]);
// //         printf("\n");
// //     }
// // }
// // */

// // //Alterar as informações do agendamento
// // void alterarAgendamento(Agendamento *agend){
// //     if (qtdAgen == 0){
// //         printf("\nNenhum agendamento realizado.\n\n");
// //         return;
// //     }

// //     long int idAgBusca;
// //     printf("\nInforme o ID do agendamento que deseja alterar: ");
// //     scanf("%ld",&idAgBusca);

// //     int encontrarAgendamento = 0;
// //    int N;
// //     for(int i=0;i<qtdAgen;i++){

// //         if(agend[i].id == idAgBusca){
// //             printf("\nInforme o novo CPF do Cliente(000.000.000-00): ");
// //             scanf(" %[^\n]s",agend[i].cpfCliente);
// //             printf("\nInforme o novo ID do Colaborador: ");
// //             scanf("%d",&agend[i].idColab);
// //             getchar();
// //             printf("\nInforme a nova data do agendamento(dd/MM/YY): ");
// //             scanf(" %[^\n]s",agend[i].data);
// //             printf("\nInforme o novo horario do agendamento (HH:mm): ");
// //             scanf(" %[^\n]s",agend[i].horario);
// //             printf("\nInforme a quantidade de servicos desejados: ");
// //             scanf("%d",&N);
// //
// //             agend.servicoDesejado = (char**)realloc((*agend)[i].servicoDesejado,N*sizeof(char*));
// //             if(agend.servicoDesejado == NULL){
// //                perror("\nErro ao realocar memoria\n");
// //                return;
// //             }
// //             for(int j=0;j<N;j++){
// //                (*agend)[i].servicoDesejado[j] = (char*)malloc(200*sizeof(char));
// //                if((*agend)[i].servicoDesejado[j] == NULL){
// //                    perror("\nErro ao realocar memoria!\n");
// //                    return;
// //                }
// //             printf("\nInforme o %d˚ servico desejado: ",j+1);
// //             scanf(" %[^\n]s",(*agend)[i].servicoDesejado[j]);
// //
// //             }
// //             printf("\n\nAgendamento alterado com sucesso!\n\n");
// //             encontrarAgendamento = 1;
// //             break;
// //         }
// //     }

// //     if(!encontrarAgendamento){
// //         printf("Nenhum agendamento realizaddo com o ID %ld",idAgBusca);
// //         return;
// //     }
// // }

// //void removerAgendamentos(Agendamento **agendamentos) {
// //    if (qtdAgen == 0) {
// //        printf("\nNenhum agendamento para remover.\n\n");
// //        return;
// //    }
// //
// //    long int idBusca;
// //    printf("Informe o ID do agendamento que deseja remover: ");
// //    scanf("%ld", &idBusca);
// //
// //    int posicao = -1;
// //    for (int i = 0; i < qtdAgen; i++) {
// //        if ((*agendamentos)[i].id == idBusca) {
// //            posicao = i;
// //            break;
// //        }
// //    }
// //
// //    if (posicao == -1) {
// //        printf("\nAgendamento com ID %ld não encontrado.\n", idBusca);
// //        return;
// //    }
// //
// //    // Libera memória do agendamento que será removido
// //    if ((*agendamentos)[posicao].servicoDesejado != NULL) {
// //        for (int j = 0; (*agendamentos)[posicao].servicoDesejado[j] != NULL; j++) {
// //            free((*agendamentos)[posicao].servicoDesejado[j]);
// //        }
// //        free((*agendamentos)[posicao].servicoDesejado);
// //    }
// //    // Substitui pelo último agendamento
// //   (*agendamentos)[posicao] = (*agendamentos)[qtdAgen - 1];
// //    qtdAgen--;
// //
// //    // Reduz capacidade em 1 e realoca memória
// //    capacidadeA--;
// //    Agendamento *temp = realloc(*agendamentos, capacidadeA * sizeof(Agendamento));
// //    if (temp != NULL || capacidadeA == 0) {
// //        *agendamentos = temp;
// //  } else {
// //     printf("Erro ao realocar memória após remoção de agendamento");
// //    }
// //
// //    printf("\nAgendamento removido com sucesso!\n");
// //}
