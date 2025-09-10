#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/cliente.h"
#include "../headers/colab.h"
#include "../headers/agendamento.h"

FILE *fcliente = NULL;
FILE *fcolabs = NULL;
FILE *fagen = NULL;
Cliente *clientes = NULL;
Colab *colabs = NULL;
Agendamento *agendamentos = NULL;
int qtdCliente = 0, qtdColab = 0;
long int qtdAgend = 0;

// void inicializarDados() {
//     // --- Inicializa Clientes ---
//     int capacidadeCl = 15;
//     int qtdCliente = 10;
//     clientes = (Cliente *) malloc(capacidadeCl * sizeof(Cliente));
//     if (clientes == NULL) {
//         perror("Falha ao alocar memoria inicial para clientes");
//         exit(1);
//     }

//     // Populando todos os 10 clientes
//     strcpy(clientes[0].cpf, "321.654.987-00");
//     strcpy(clientes[0].nome, "Lucas Andrade");
//     clientes[0].celular = 11987654322;
//     strcpy(clientes[0].dataIntegracao, "14/02/25");

//     strcpy(clientes[1].cpf, "654.321.987-11");
//     strcpy(clientes[1].nome, "Mariana Costa");
//     clientes[1].celular = 11976543211;
//     strcpy(clientes[1].dataIntegracao, "23/05/24");

//     strcpy(clientes[2].cpf, "222.333.444-55");
//     strcpy(clientes[2].nome, "Pedro Henrique");
//     clientes[2].celular = 11998765433;
//     strcpy(clientes[2].dataIntegracao, "30/09/23");

//     strcpy(clientes[3].cpf, "777.888.999-00");
//     strcpy(clientes[3].nome, "Juliana Martins");
//     clientes[3].celular = 11981234568;
//     strcpy(clientes[3].dataIntegracao, "11/12/24");

//     strcpy(clientes[4].cpf, "888.777.666-11");
//     strcpy(clientes[4].nome, "Thiago Oliveira");
//     clientes[4].celular = 11976549871;
//     strcpy(clientes[4].dataIntegracao, "07/08/25");

//     strcpy(clientes[5].cpf, "123.456.789-01");
//     strcpy(clientes[5].nome, "Mariana Silva");
//     clientes[5].celular = 98987654321;
//     strcpy(clientes[5].dataIntegracao, "12/03/25");

//     strcpy(clientes[6].cpf, "987.654.321-99");
//     strcpy(clientes[6].nome, "Carlos Eduardo");
//     clientes[6].celular = 1198765432;
//     strcpy(clientes[6].dataIntegracao, "05/07/24");

//     strcpy(clientes[7].cpf, "111.222.333-44");
//     strcpy(clientes[7].nome, "Fernanda Oliveira");
//     clientes[7].celular = 21998765432;
//     strcpy(clientes[7].dataIntegracao, "28/11/23");

//     strcpy(clientes[8].cpf, "555.666.777-88");
//     strcpy(clientes[8].nome, "Joao Pedro Santos");
//     clientes[8].celular = 47998765432;
//     strcpy(clientes[8].dataIntegracao, "09/01/25");

//     strcpy(clientes[9].cpf, "999.888.777-66");
//     strcpy(clientes[9].nome, "Beatriz Almeida");
//     clientes[9].celular = 31998765432;
//     strcpy(clientes[9].dataIntegracao, "21/08/24");


//     // --- Inicializa Colaboradores ---
//     int capacidadeC = 15;
//     int qtdColab = 10;
//     colabs = (Colab *) malloc(capacidadeC * sizeof(Colab));
//     if (colabs == NULL) {
//         perror("Falha ao alocar memoria inicial para colaboradores");
//         exit(1);
//     }

//     // Colaborador 1
//     colabs[0].id = 1;
//     strcpy(colabs[0].nome, "Lucas Ferreira");
//     colabs[0].celular = 11987654321;
//     colabs[0].nServicos = 2;
//     strcpy(colabs[0].servicosPrestados[0], "Corte de cabelo");
//     strcpy(colabs[0].servicosPrestados[1], "Barba");

//     // Colaborador 2
//     colabs[1].id = 2;
//     strcpy(colabs[1].nome, "Ana Beatriz");
//     colabs[1].celular = 11976543210;
//     colabs[1].nServicos = 2;
//     strcpy(colabs[1].servicosPrestados[0], "Corte de cabelo");
//     strcpy(colabs[1].servicosPrestados[1], "Hidratacao");

//     // Colaborador 3
//     colabs[2].id = 3;
//     strcpy(colabs[2].nome, "Rafael Souza");
//     colabs[2].celular = 11998765432;
//     colabs[2].nServicos = 1;
//     strcpy(colabs[2].servicosPrestados[0], "Corte Infantil");

//     // Colaborador 4
//     colabs[3].id = 4;
//     strcpy(colabs[3].nome, "Camila Dias");
//     colabs[3].celular = 11981234567;
//     colabs[3].nServicos = 2;
//     strcpy(colabs[3].servicosPrestados[0], "Barboterapia");
//     strcpy(colabs[3].servicosPrestados[1], "Corte de cabelo");

//     // Colaborador 5
//     colabs[4].id = 5;
//     strcpy(colabs[4].nome, "Gustavo Lima");
//     colabs[4].celular = 11976549870;
//     colabs[4].nServicos = 2;
//     strcpy(colabs[4].servicosPrestados[0], "Corte de cabelo");
//     strcpy(colabs[4].servicosPrestados[1], "Barba");

//     // Colaborador 6
//     colabs[5].id = 6;
//     strcpy(colabs[5].nome, "Fabio Almeida");
//     colabs[5].celular = 11987654323;
//     colabs[5].nServicos = 2;
//     strcpy(colabs[5].servicosPrestados[0], "Tratamento capilar");
//     strcpy(colabs[5].servicosPrestados[1], "Hidratacao");

//     // Colaborador 7
//     colabs[6].id = 7;
//     strcpy(colabs[6].nome, "Patricia Lima");
//     colabs[6].celular = 11976543212;
//     colabs[6].nServicos = 2;
//     strcpy(colabs[6].servicosPrestados[0], "Corte de cabelo");
//     strcpy(colabs[6].servicosPrestados[1], "Sobrancelha");

//     // Colaborador 8
//     colabs[7].id = 8;
//     strcpy(colabs[7].nome, "Bruno Carvalho");
//     colabs[7].celular = 11998765434;
//     colabs[7].nServicos = 2;
//     strcpy(colabs[7].servicosPrestados[0], "Corte de cabelo");
//     strcpy(colabs[7].servicosPrestados[1], "Barba");

//     // Colaborador 9
//     colabs[8].id = 9;
//     strcpy(colabs[8].nome, "Aline Souza");
//     colabs[8].celular = 11981234569;
//     colabs[8].nServicos = 2;
//     strcpy(colabs[8].servicosPrestados[0], "Corte de cabelo");
//     strcpy(colabs[8].servicosPrestados[1], "Barba");

//     // Colaborador 10
//     colabs[9].id = 10;
//     strcpy(colabs[9].nome, "Renato Silva");
//     colabs[9].celular = 11976549872;
//     colabs[9].nServicos = 2;
//     strcpy(colabs[9].servicosPrestados[0], "Corte de cabelo");
//     strcpy(colabs[9].servicosPrestados[1], "Hidratacao");

//     printf("Dados iniciais carregados com sucesso!\n");

//     fcliente = fopen("clientes.bin", "wb");
//     if(fcliente == NULL){
//         printf("Erro ao abrir arquivo.\n");
//         exit(1);
//     }
//     fwrite(&qtdCliente, sizeof(int), 1, fcliente);
//     fwrite(clientes, sizeof(Cliente), 10, fcliente);
//     fclose(fcliente);

//     fcolabs = fopen("colabs.bin", "wb");
//     if(fcolabs == NULL){
//         printf("Erro ao abrir arquivo.\n");
//         exit(1);
//     }
//     fwrite(&qtdColab, sizeof(int), 1, fcolabs);
//     fwrite(colabs, sizeof(Colab), 10, fcolabs);
//     fclose(fcolabs);
// }

void inicializarDados(){
    fcliente = fopen("clientes.bin", "rb");
    if(fcliente == NULL){
        perror("Erro ao abrir arquivo\n");
        exit(1);
    }
    fread(&qtdCliente, sizeof(int), 1, fcliente);
    
    clientes = (Cliente *) malloc(qtdCliente * sizeof(Cliente));
    if(clientes == NULL){
        perror("Erro ao alocar memória.\n");
        exit(1);
    }

    fread(clientes, sizeof(Cliente), qtdCliente, fcliente);
    fclose(fcliente);

    fcolabs = fopen("colabs.bin", "rb");
    if(fcolabs == NULL){
        perror("Erro ao abrir arquivo\n");
        exit(1);
    }
    fread(&qtdColab, sizeof(int), 1, fcolabs);
    
    colabs = (Colab *) malloc(qtdColab * sizeof(Colab));
    if(colabs == NULL){
        perror("Erro ao alocar memória.\n");
        exit(1);
    }

    fread(colabs, sizeof(Colab), qtdColab, fcolabs);
    fclose(fcolabs);
}

void menuClientes() {
    int opcao;
    int retorno_scanf; // Variavel para verificar o retorno do scanf

    do {
        printf("\n-- MENU CLIENTES --\n");
        printf("1. Cadastrar cliente\n");
        printf("2. Listar clientes\n");
        printf("3. Alterar cliente\n");
        printf("4. Remover cliente\n");
        printf("5. Voltar\n");
        printf("Escolha a opcao: ");

        retorno_scanf = scanf("%d", &opcao);

        if (retorno_scanf == 0) {
            // Se a leitura falhou, o usu�rio n�o digitou um n�mero
            printf("Opcao invalida, tente novamente.\n");

            // Limpa o buffer de entrada
            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            opcao = 0; // Atribui um valor inv�lido para garantir que o menu continue
        } else {
            // Se a leitura foi um sucesso, executa o switch
            switch(opcao) {
                case 1:
                    inserirCliente(&clientes, fcliente, &qtdCliente);
                    break;
                case 2:
                    listarClientes(clientes, &qtdCliente);
                    break;
                case 3:
                    alterarClientes(&clientes, &qtdCliente);
                    break;
                case 4:
                    removerClientes(&clientes, agendamentos, &qtdAgend, &qtdCliente, fcliente);
                    break;
                case 5:
                    break;
                default:
                    printf("Opcao invalida, tente novamente.\n");
            }
        }
    } while (opcao != 5);
}

void menuColabs() {
    int opcao;
    int retorno_scanf; // Vari�vel para verificar o retorno do scanf

    do {
        printf("\n-- MENU COLABORADORES --\n");
        printf("1. Cadastrar colaborador\n");
        printf("2. Listar colaboradores\n");
        printf("3. Alterar colaborador\n");
        printf("4. Remover colaborador\n");
        printf("5. Voltar\n");
        printf("Escolha a opcao: ");

        retorno_scanf = scanf("%d", &opcao);

        if (retorno_scanf == 0) {
            // Se a leitura falhou, o usu�rio n�o digitou um n�mero
            printf("Opcao invalida, tente novamente.\n");

            // Limpa o buffer de entrada
            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            opcao = 0; // Atribui um valor inv�lido para garantir que o menu continue
        } else {
            // Se a leitura foi um sucesso, executa o switch
            switch(opcao) {
                case 1:
                    inserirColab(&colabs, fcolabs, &qtdColab);
                    break;
                case 2:
                    listarColabs(colabs, &qtdColab);
                    break;
                case 3:
                    alterarColabs(&colabs, &qtdColab);
                    break;
                case 4:
                    removerColabs(&colabs, agendamentos, &qtdAgend, &qtdColab, fcolabs);
                    break;
                case 5:
                    break;
                default:
                    printf("Opcao invalida, tente novamente.\n");
            }
        }
    } while (opcao != 5);
}

/*void menuAgendamentos() {
//    int opcao;
//    int retorno_scanf; // Vari�vel para verificar o retorno do scanf

    do {
       printf("\n-- MENU AGENDAMENTOS --\n");
       printf("1. Cadastrar agendamento\n");
       printf("2. Listar agendamento\n");
       printf("3. Alterar agendamento\n");
       printf("4. Remover agendamento\n");
       printf("5. Voltar\n");
       printf("Escolha uma opcao: ");

       retorno_scanf = scanf("%d", &opcao);

       if (retorno_scanf == 0) {
            // Se a leitura falhou, o usu�rio n�o digitou um n�mero
            printf("Opcao invalida, tente novamente.\n");

            // Limpa o buffer de entrada
            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            opcao = 0; // Atribui um valor inv�lido para garantir que o menu continue
       } else {
            // Se a leitura foi um sucesso, executa o switch
            switch(opcao) {
                case 1:
                    //inserirAgendamento(agendamentos);
                    break;
                case 2:
                    //listarAgendamentos(agendamentos);
                    break;
                case 3:
                    //alterarAgendamentos(agendamentos);
                    break;
                case 4:
                    //removerAgendamentos(agendamentos);
                    break;
                case 5:
                    break;
                default:
                    printf("Opcao invalida, tente novamente.\n");
            }
       }
    } while (opcao != 5);
}*/

void menuPrincipal() {
    int opcao;
    int retorno_scanf; // Vari�vel para verificar o retorno do scanf

    do {
        printf("\n-- SISTEMA BARBEARIA --\n");
        printf("1. Menu Clientes\n");
        printf("2. Menu Colaboradores\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");

        retorno_scanf = scanf("%d", &opcao);

        if (retorno_scanf == 0) {
            // Se a leitura falhou, o usu�rio n�o digitou um n�mero
            printf("Opcao invalida, tente novamente.\n");

            // Limpa o buffer de entrada
            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            opcao = 0; // Atribui um valor inv�lido para garantir que o menu continue
        } else {
            // Se a leitura foi um sucesso, executa o switch
            switch(opcao) {
                case 1:
                    menuClientes();
                    break;
                case 2:
                    menuColabs();
                    break;
                case 3:
                    printf("Saindo...\n");
                    break;
                default:
                    printf("Opcao invalida, tente novamente.\n");
            }
        }
    } while (opcao != 3);
}

void liberaDados() {
    free(clientes);
    free(colabs);
    free(agendamentos);
}

int main() {
    inicializarDados();
    menuPrincipal();
    liberaDados();
    return 0;
}
