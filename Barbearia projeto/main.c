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

/*
void inicializarDados() {
    // --- Inicializa Clientes ---
    int capacidadeCl = 15;
    qtdCliente = 10;
    clientes = (Cliente *) malloc(capacidadeCl * sizeof(Cliente));
    if (clientes == NULL) {
        perror("Falha ao alocar memoria inicial para clientes");
        exit(1);
    }

    // Populando todos os 10 clientes
    strcpy(clientes[0].cpf, "321.654.987-00");
    strcpy(clientes[0].nome, "Lucas Andrade");
    clientes[0].celular = 11987654322;
    strcpy(clientes[0].dataIntegracao, "14/02/25");

    strcpy(clientes[1].cpf, "654.321.987-11");
    strcpy(clientes[1].nome, "Mariana Costa");
    clientes[1].celular = 11976543211;
    strcpy(clientes[1].dataIntegracao, "23/05/24");

    strcpy(clientes[2].cpf, "222.333.444-55");
    strcpy(clientes[2].nome, "Pedro Henrique");
    clientes[2].celular = 11998765433;
    strcpy(clientes[2].dataIntegracao, "30/09/23");

    strcpy(clientes[3].cpf, "777.888.999-00");
    strcpy(clientes[3].nome, "Juliana Martins");
    clientes[3].celular = 11981234568;
    strcpy(clientes[3].dataIntegracao, "11/12/24");

    strcpy(clientes[4].cpf, "888.777.666-11");
    strcpy(clientes[4].nome, "Thiago Oliveira");
    clientes[4].celular = 11976549871;
    strcpy(clientes[4].dataIntegracao, "07/08/25");

    strcpy(clientes[5].cpf, "123.456.789-01");
    strcpy(clientes[5].nome, "Mariana Silva");
    clientes[5].celular = 98987654321;
    strcpy(clientes[5].dataIntegracao, "12/03/25");

    strcpy(clientes[6].cpf, "987.654.321-99");
    strcpy(clientes[6].nome, "Carlos Eduardo");
    clientes[6].celular = 1198765432;
    strcpy(clientes[6].dataIntegracao, "05/07/24");

    strcpy(clientes[7].cpf, "111.222.333-44");
    strcpy(clientes[7].nome, "Fernanda Oliveira");
    clientes[7].celular = 21998765432;
    strcpy(clientes[7].dataIntegracao, "28/11/23");

    strcpy(clientes[8].cpf, "555.666.777-88");
    strcpy(clientes[8].nome, "Joao Pedro Santos");
    clientes[8].celular = 47998765432;
    strcpy(clientes[8].dataIntegracao, "09/01/25");

    strcpy(clientes[9].cpf, "999.888.777-66");
    strcpy(clientes[9].nome, "Beatriz Almeida");
    clientes[9].celular = 31998765432;
    strcpy(clientes[9].dataIntegracao, "21/08/24");


    // --- Inicializa Colaboradores ---
    int capacidadeC = 15;
    qtdColab = 10;
    colabs = (Colab *) malloc(capacidadeC * sizeof(Colab));
    if (colabs == NULL) {
        perror("Falha ao alocar memoria inicial para colaboradores");
        exit(1);
    }

    // Colaborador 1
    colabs[0].id = 1;
    strcpy(colabs[0].nome, "Lucas Ferreira");
    colabs[0].celular = 11987654321;
    colabs[0].nServicos = 2;
    strcpy(colabs[0].servicosPrestados[0], "Corte de cabelo");
    strcpy(colabs[0].servicosPrestados[1], "Barba");

    // Colaborador 2
    colabs[1].id = 2;
    strcpy(colabs[1].nome, "Ana Beatriz");
    colabs[1].celular = 11976543210;
    colabs[1].nServicos = 2;
    strcpy(colabs[1].servicosPrestados[0], "Corte de cabelo");
    strcpy(colabs[1].servicosPrestados[1], "Hidratacao");

    // Colaborador 3
    colabs[2].id = 3;
    strcpy(colabs[2].nome, "Rafael Souza");
    colabs[2].celular = 11998765432;
    colabs[2].nServicos = 1;
    strcpy(colabs[2].servicosPrestados[0], "Corte Infantil");

    // Colaborador 4
    colabs[3].id = 4;
    strcpy(colabs[3].nome, "Camila Dias");
    colabs[3].celular = 11981234567;
    colabs[3].nServicos = 2;
    strcpy(colabs[3].servicosPrestados[0], "Barboterapia");
    strcpy(colabs[3].servicosPrestados[1], "Corte de cabelo");

    // Colaborador 5
    colabs[4].id = 5;
    strcpy(colabs[4].nome, "Gustavo Lima");
    colabs[4].celular = 11976549870;
    colabs[4].nServicos = 2;
    strcpy(colabs[4].servicosPrestados[0], "Corte de cabelo");
    strcpy(colabs[4].servicosPrestados[1], "Barba");

    // Colaborador 6
    colabs[5].id = 6;
    strcpy(colabs[5].nome, "Fabio Almeida");
    colabs[5].celular = 11987654323;
    colabs[5].nServicos = 2;
    strcpy(colabs[5].servicosPrestados[0], "Tratamento capilar");
    strcpy(colabs[5].servicosPrestados[1], "Hidratacao");

    // Colaborador 7
    colabs[6].id = 7;
    strcpy(colabs[6].nome, "Patricia Lima");
    colabs[6].celular = 11976543212;
    colabs[6].nServicos = 2;
    strcpy(colabs[6].servicosPrestados[0], "Corte de cabelo");
    strcpy(colabs[6].servicosPrestados[1], "Sobrancelha");

    // Colaborador 8
    colabs[7].id = 8;
    strcpy(colabs[7].nome, "Bruno Carvalho");
    colabs[7].celular = 11998765434;
    colabs[7].nServicos = 2;
    strcpy(colabs[7].servicosPrestados[0], "Corte de cabelo");
    strcpy(colabs[7].servicosPrestados[1], "Barba");

    // Colaborador 9
    colabs[8].id = 9;
    strcpy(colabs[8].nome, "Aline Souza");
    colabs[8].celular = 11981234569;
    colabs[8].nServicos = 2;
    strcpy(colabs[8].servicosPrestados[0], "Corte de cabelo");
    strcpy(colabs[8].servicosPrestados[1], "Barba");

    // Colaborador 10
    colabs[9].id = 10;
    strcpy(colabs[9].nome, "Renato Silva");
    colabs[9].celular = 11976549872;
    colabs[9].nServicos = 2;
    strcpy(colabs[9].servicosPrestados[0], "Corte de cabelo");
    strcpy(colabs[9].servicosPrestados[1], "Hidratacao");

    // --- Inicializa Agendamentos ---
    int capacidadeA = 15;
    qtdAgend = 10;

    agendamentos = (Agendamento *) malloc(capacidadeA * sizeof(Agendamento));
    if (agendamentos == NULL) {
        perror("Falha ao alocar memoria inicial para agendamentos");
        exit(1);
    }
    // Agendamento 1
    agendamentos[0].id = 1;
    strcpy(agendamentos[0].cpfCliente, "321.654.987-00");
    agendamentos[0].idColab = 1;
    strcpy(agendamentos[0].data, "14/02/25");
    strcpy(agendamentos[0].horario, "09:00");
    strcpy(agendamentos[0].servicoDesejado[0], "Corte de cabelo");
    strcpy(agendamentos[0].servicoDesejado[1], "Barba");

    // Agendamento 2
    agendamentos[1].id = 2;
    strcpy(agendamentos[1].cpfCliente, "654.321.987-11");
    agendamentos[1].idColab = 2;
    strcpy(agendamentos[1].data, "23/05/24");
    strcpy(agendamentos[1].horario, "10:30");
    strcpy(agendamentos[1].servicoDesejado[0], "Hidratacao");

    // Agendamento 3
    agendamentos[2].id = 3;
    strcpy(agendamentos[2].cpfCliente, "222.333.444-55");
    agendamentos[2].idColab = 3;
    strcpy(agendamentos[2].data, "30/09/23");
    strcpy(agendamentos[2].horario, "14:00");
    strcpy(agendamentos[2].servicoDesejado[0], "Corte Infantil");

    // Agendamento 4
    agendamentos[3].id = 4;
    strcpy(agendamentos[3].cpfCliente, "777.888.999-00");
    agendamentos[3].idColab = 4;
    strcpy(agendamentos[3].data, "11/12/24");
    strcpy(agendamentos[3].horario, "16:00");
    strcpy(agendamentos[3].servicoDesejado[0], "Barboterapia");
    strcpy(agendamentos[3].servicoDesejado[1], "Corte de cabelo");

    // Agendamento 5
    agendamentos[4].id = 5;
    strcpy(agendamentos[4].cpfCliente, "888.777.666-11");
    agendamentos[4].idColab = 5;
    strcpy(agendamentos[4].data, "07/08/25");
    strcpy(agendamentos[4].horario, "11:00");
    strcpy(agendamentos[4].servicoDesejado[0], "Corte de cabelo");
    strcpy(agendamentos[4].servicoDesejado[1], "Barba");

    // Agendamento 6
    agendamentos[5].id = 6;
    strcpy(agendamentos[5].cpfCliente, "123.456.789-01");
    agendamentos[5].idColab = 6;
    strcpy(agendamentos[5].data, "12/03/25");
    strcpy(agendamentos[5].horario, "13:30");
    strcpy(agendamentos[5].servicoDesejado[0], "Tratamento capilar");
    strcpy(agendamentos[5].servicoDesejado[1], "Hidratacao");

    // Agendamento 7
    agendamentos[6].id = 7;
    strcpy(agendamentos[6].cpfCliente, "987.654.321-99");
    agendamentos[6].idColab = 7;
    strcpy(agendamentos[6].data, "05/07/24");
    strcpy(agendamentos[6].horario, "15:00");
    strcpy(agendamentos[6].servicoDesejado[0], "Sobrancelha");

    // Agendamento 8
    agendamentos[7].id = 8;
    strcpy(agendamentos[7].cpfCliente, "111.222.333-44");
    agendamentos[7].idColab = 8;
    strcpy(agendamentos[7].data, "28/11/23");
    strcpy(agendamentos[7].horario, "17:30");
    strcpy(agendamentos[7].servicoDesejado[0], "Corte de cabelo");
    strcpy(agendamentos[7].servicoDesejado[1], "Barba");

    // Agendamento 9
    agendamentos[8].id = 9;
    strcpy(agendamentos[8].cpfCliente, "555.666.777-88");
    agendamentos[8].idColab = 9;
    strcpy(agendamentos[8].data, "09/01/25");
    strcpy(agendamentos[8].horario, "09:30");
    strcpy(agendamentos[8].servicoDesejado[0], "Barba");

    // Agendamento 10
    agendamentos[9].id = 10;
    strcpy(agendamentos[9].cpfCliente, "999.888.777-66");
    agendamentos[9].idColab = 10;
    strcpy(agendamentos[9].data, "21/08/24");
    strcpy(agendamentos[9].horario, "18:00");
    strcpy(agendamentos[9].servicoDesejado[0], "Corte de cabelo");
    strcpy(agendamentos[9].servicoDesejado[1], "Hidratacao");

    printf("Dados iniciais carregados com sucesso!\n");

    fcliente = fopen("clientes.bin", "wb");
    if(fcliente == NULL){
        printf("Erro ao abrir arquivo.\n");
        exit(1);
    }
    fwrite(&qtdCliente, sizeof(int), 1, fcliente);
    fwrite(clientes, sizeof(Cliente), qtdCliente, fcliente);
    fclose(fcliente);

    fcolabs = fopen("colabs.bin", "wb");
    if(fcolabs == NULL){
        printf("Erro ao abrir arquivo.\n");
        exit(1);
    }
    fwrite(&qtdColab, sizeof(int), 1, fcolabs);
    fwrite(colabs, sizeof(Colab), qtdColab, fcolabs);
    fclose(fcolabs);

    fagen = fopen("agendamentos.bin", "wb");
    if(fagen == NULL){
        printf("Erro ao abrir arquivo.\n");
        exit(1);
    }
    fwrite(&qtdAgend, sizeof(long int), 1, fagen);
    fwrite(agendamentos, sizeof(Agendamento), qtdAgend, fagen);
    fclose(fagen);
}
*/

 void inicializarDados() {
     // Carrega Clientes se o arquivo existir
     fcliente = fopen("clientes.bin", "rb");
     if (fcliente != NULL) {
         fread(&qtdCliente, sizeof(int), 1, fcliente);
         if (qtdCliente > 0) {
             clientes = (Cliente *) malloc((qtdCliente + 5) * sizeof(Cliente));
             if (clientes == NULL) { exit(1); }
             fread(clientes, sizeof(Cliente), qtdCliente, fcliente);
         }
         fclose(fcliente);
     }

     // Carrega Colaboradores se o arquivo existir
     fcolabs = fopen("colabs.bin", "rb");
     if (fcolabs != NULL) {
         fread(&qtdColab, sizeof(int), 1, fcolabs);
         if (qtdColab > 0) {
             colabs = (Colab *) malloc((qtdColab + 5) * sizeof(Colab));
             if (colabs == NULL) { exit(1); }
             fread(colabs, sizeof(Colab), qtdColab, fcolabs);
         }
         fclose(fcolabs);
     }

     // Carrega Agendamentos se o arquivo existir
     fagen = fopen("agendamentos.bin", "rb");
     if (fagen != NULL) {
         fread(&qtdAgend, sizeof(long int), 1, fagen);
         if (qtdAgend > 0) {
             agendamentos = (Agendamento *) malloc((qtdAgend + 5) * sizeof(Agendamento));
             if (agendamentos == NULL) { exit(1); }
             fread(agendamentos, sizeof(Agendamento), qtdAgend, fagen);
         }
         fclose(fagen);
     }
 }

void finalizarDados() {
    // Carrega Clientes se o arquivo existir
    fcliente = fopen("clientes.bin", "wb");
    if (fcliente != NULL) {
        fwrite(&qtdCliente, sizeof(int), 1, fcliente);
        fwrite(clientes, sizeof(Cliente), qtdCliente, fcliente);
        fclose(fcliente);
    }

    // Carrega Colaboradores se o arquivo existir
    fcolabs = fopen("colabs.bin", "wb");
    if (fcolabs != NULL) {
        fwrite(&qtdColab, sizeof(int), 1, fcolabs);
        fwrite(colabs, sizeof(Colab), qtdColab, fcolabs);
        fclose(fcolabs);
    }

    // Carrega Agendamentos se o arquivo existir
    fagen = fopen("agendamentos.bin", "wb");
    if (fagen != NULL) {
        fwrite(&qtdAgend, sizeof(long int), 1, fagen);
        fwrite(agendamentos, sizeof(Agendamento), qtdAgend, fagen);
        fclose(fagen);
    }
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
                    alterarClientes(&clientes, &qtdCliente,fcliente);
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
                    alterarColabs(&colabs, &qtdColab,fcolabs);
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

void menuAgendamentos() {
    int opcao;
    int retorno_scanf; // Vari�vel para verificar o retorno do scanf

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
                    inserirAgendamento(&agendamentos, clientes, &qtdCliente, colabs, &qtdColab, &qtdAgend, fagen);
                    break;
                case 2:
                    printf("\n-- LISTAGEM AGENDAMENTOS --\n");
                    printf("1. Listar por CPF Cliente\n");
                    printf("2. Listar por ID Colaborador\n");
                    printf("3. Listar por data\n");
                    printf("4. Voltar\n");
                    printf("Escolha uma opcao: ");
                    scanf("%d", &opcao);

                    if(opcao > 0 && opcao <= 4){
                        switch (opcao)
                        {
                        case 1:
                            buscarAgendamentosPorCPF(agendamentos, &qtdAgend, clientes, &qtdCliente, colabs, &qtdColab);
                            break;

                        case 2:
                            buscarAgendamentosPorIDdoColab(agendamentos, &qtdAgend, colabs, &qtdColab);
                            break;

                        case 3:
                            buscarAgendamentosPorData(agendamentos, &qtdAgend, clientes, &qtdCliente, colabs, &qtdColab);
                            break;
                        case 4:
                            break;
                        default:
                            printf("Opcao invalida, tente novamente.\n");
                        }
                    } else
                        perror("Opcao invalida!");

                    break;
                case 3:
                    alterarAgendamento(&agendamentos, &qtdAgend, clientes, &qtdCliente, colabs, &qtdColab, fagen);
                    break;
                case 4:
                    removerAgendamentos(&agendamentos, &qtdAgend, fagen);
                    break;
                case 5:
                    break;
                default:
                    printf("Opcao invalida, tente novamente.\n");
            }
       }
    } while (opcao != 5);
}

void menuPrincipal() {
    int opcao;
    int retorno_scanf; // Vari�vel para verificar o retorno do scanf

    do {
        printf("\n-- SISTEMA BARBEARIA --\n");
        printf("1. Menu Clientes\n");
        printf("2. Menu Colaboradores\n");
        printf("3. Menu Agendamentos\n");
        printf("4. Sair\n");
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
                    menuAgendamentos();
                    break;
                case 4:
                    printf("Saindo...\n");
                    break;
                default:
                    printf("Opcao invalida, tente novamente.\n");
            }
        }
    } while (opcao != 4);
}

void liberaDados() {
    free(clientes);
    free(colabs);
    free(agendamentos);
}

int main() {
    inicializarDados();
    menuPrincipal();
    finalizarDados();
    liberaDados();
    return 0;
}
