#include "colab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int qtdColab = 0;
long int id = 1;

//Cadastrando colaborador
void inserirColab(Colab *p) {
    p = realloc(p, (qtdColab + 1) * sizeof(Colab));
    if(p == NULL){
        perror("Erro ao realocar memória\n");
        return;
    }

    Colab c;
    int n;
    c.id = id++;
    printf("Informe o nome do colaborador: "); scanf(" %[^\n]s", c.nome);
    printf("Informe o celular do colaborador (00900000000): "); scanf("%ld", &c.celular);
    printf("Informe quantos serviços esse colaborador prestará: "); scanf("%d", &n);

    c.servicosPrestados = malloc(n * sizeof(char *));
    if(c.servicosPrestados == NULL){
        perror("Erro ao realocar memória\n");
        return;
    }
    for(int i = 0; i < n; i++){
        c.servicosPrestados[i] = malloc(200 * sizeof(char));
        if(c.servicosPrestados[i] == NULL){
            perror("Erro ao realocar memória\n");
            return;
        }
        printf("Informe o nome do %d˚serviço: ", i+1);
        scanf(" %[^\n]s", c.servicosPrestados[i]);
    }

    p[qtdColab] = c;
    printf("Colaborador inserido com sucesso! ID: %ld\n", c.id);
    qtdColab++;
}

//Listando todos os Colaboradores
void listarColabs(Colab *colabs) {
    if (qtdColab == 0) {
        printf("Nenhum colaborador cadastrado.\n\n");
        return;
    }

    for (int i = 0; i < qtdColab; i++) {
        printf("--Colaborador %d--\n", i + 1);
        printf("ID: %d\n", colabs[i].id);
        printf("Nome: %s\n", colabs[i].nome);
        printf("Celular: %ld\n", colabs[i].celular);
        printf("Servicos prestados:\n");
        for (int j = 0; colabs[i].servicosPrestados[j] != NULL; j++) 
            printf("- %s\n", colabs[i].servicosPrestados[j]);
        printf("\n");
    }
}

//Alterando as informações dos Colaboradores
void alterarColabs(Colab *colabs){
    if (qtdColab == 0){
       printf("\nNenhum colaborador cadastrado.\n\n");
       return;
    }

    int idBusca;
    printf("\nInforme o ID do Colaborador que deseja alterar: ");
    scanf("%d",&idBusca);

    int colabEncontrado = 0;
    for(int i=0;i<qtdCliente;i++){

        if(strcmp(Colab[i].id,idBusca) == 0){
            printf("\nInforme o novo nome do Colaborador: ");
            scanf("%[^\n]s",colab[i].nome);
            printf("\nInforme o novo celular do Colaborador (00900000000): ");
            scanf("%ld",&Colab[i].celular);
            getchar();
            printf("\nInforme o(s) novo(s) servico(s) prestado(s) pelo Colaborador: ");
            scanf("%[^\n]s",Colab[i].servicoPrestados);

            printf("\n\nColaborador alterado com sucesso!\n\n");
            colabEncontrado = 1;
            break;
        }
    }

    if(!colabEncontrado){
        printf("Colaborador com ID %s nao encontrado.", idBusca);
    }
}
