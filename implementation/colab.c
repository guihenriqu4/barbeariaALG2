#include "../headers/colab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INCREMENTO 5

int capacidadeC = 15;
int idColab = 10;

void inserirColab(Colab **p, FILE *fcolab, int *qtdColab) {
    if(*qtdColab >= capacidadeC){

        fcolab = fopen("colabs.bin", "wb");
        if(fcolab == NULL){
            perror("Erro ao abrir o arquivo colabs.");
            exit(1);
        }

        fwrite(qtdColab,sizeof(int),1,fcolab);
        int result = fwrite(*p, sizeof(Colab), *qtdColab, fcolab);
        if(result < *qtdColab) perror("Erro na gravacao de algum dos colaboradores.");

        fclose(fcolab);

        capacidadeC += INCREMENTO;
        (*p) = (Colab *) realloc((*p), capacidadeC * sizeof(Colab));
        if(*p == NULL){
            perror("Erro ao realocar memoria\n");
            return;
        }
    }

    Colab c;
    int n;
    c.id = ++idColab;
    printf("Informe o nome do colaborador: ");
    scanf(" %[^\n]s", c.nome);

    printf("Informe o celular do colaborador (00900000000): ");
    scanf("%lld", &c.celular);

    do{
        printf("Informe a quantidade de servicos que esse colaborador presta (ate 5): ");
        scanf("%d", &n);
    }while(n <= 0 || n > 5);

    c.nServicos = n;

    for(int i = 0; i < n; i++){
        printf("Informe o nome do servico %d: ", i+1);
        scanf(" %[^\n]s", c.servicosPrestados[i]);
    }

    (*p)[*qtdColab] = c;
    printf("Colaborador inserido com sucesso! ID: %d\n", c.id);
    (*qtdColab)++;
}

void listarColabs(Colab *colabs, int *qtdColab) {
    if (*qtdColab == 0) {
        printf("Nenhum colaborador cadastrado.\n\n");
        return;
    }

    for (int i = 0; i < *qtdColab; i++) {
        printf("-- Colaborador %d --\n", i + 1);
        printf(" ID: %d\n", colabs[i].id);
        printf(" Nome: %s\n", colabs[i].nome);
        printf(" Celular: %lld\n", colabs[i].celular);

        if(colabs[i].nServicos == 0) {
            printf(" Nenhum servico prestado.\n");
            continue;
        }
        else{
            printf(" Servicos prestados:\n");
            for(int j = 0; j < colabs[i].nServicos; j++)
                printf("%d: %s\n", j+1, colabs[i].servicosPrestados[j]);
        }
        printf("\n");
    }
}

void alterarColabs(Colab **colabs, int *qtdColab, FILE *fcolabs){
    if (*qtdColab == 0){
       printf("\nNenhum colaborador cadastrado.\n\n");
       return;
    }

    int idBusca;
    printf("\nInforme o ID do Colaborador que deseja alterar: ");
    scanf("%d",&idBusca);

    int colabEncontrado = 0;
    int N;
    for(int i = 0; i < *qtdColab; i++){
        if((*colabs)[i].id == idBusca){
            printf("\nInforme o novo nome do Colaborador: ");
            scanf(" %[^\n]s",(*colabs)[i].nome);
            printf("\nInforme o novo celular do Colaborador (00900000000): ");
            scanf("%lld",&(*colabs)[i].celular);

            do{
                printf("\nInforme a nova quantidade de servicos que esse colaborador presta (ate 5): ");
                scanf("%d",&N);

            } while(N <= 0 || N > 5);

            (*colabs)[i].nServicos=N;

            for(int j=0;j<N;j++){
                printf("\nInforme o nome do servico %d: ", j+1);
                scanf(" %[^\n]s", (*colabs)[i].servicosPrestados[j]);
            }

            fcolabs = fopen("colabs.bin","wb");
            if(fcolabs==NULL){
                printf("\nErro ao abrir o arquivo colabs!\n");
                return;
            }
            fwrite(qtdColab,sizeof(int),1,fcolabs);

            fwrite(*colabs,sizeof(Colab),*qtdColab,fcolabs);
            fclose(fcolabs);

            printf("\n\nColaborador alterado com sucesso!\n\n");
            colabEncontrado = 1;
            break;
        }
    }

    if(!colabEncontrado){
        printf("Colaborador com ID %d nao encontrado.", idBusca);
    }
}

void removerColabs(Colab **colabs, Agendamento *agendamentos, long int *qtdAgendamentos, int *qtdColab, FILE *fcolabs) {
    if (*qtdColab == 0) {
        printf("\nNenhum colaborador cadastrado para remover.\n\n");
        return;
    }

    int idBusca;
    printf("Informe o ID do colaborador que deseja remover: ");
    scanf("%d", &idBusca);

    for (int i = 0; i < *qtdAgendamentos; i++) {
        if (agendamentos[i].idColab == idBusca) {
            printf("\nNao e possivel remover o colaborador %d, pois possui agendamentos ativos.\n", idBusca);
            return;
        }
    }

    int posicao = -1;
    for (int i = 0; i < *qtdColab; i++) {
        if ((*colabs)[i].id == idBusca) {
            posicao = i;
            break;
        }
    }

    if (posicao == -1) {
        printf("\nColaborador com ID %d nao encontrado.\n", idBusca);
        return;
    }

    (*colabs)[posicao] = (*colabs)[*qtdColab - 1];
    (*qtdColab)--;

    capacidadeC--;
    Colab *temp = realloc(*colabs, capacidadeC * sizeof(Colab));
    if (temp != NULL || capacidadeC == 0) {
        *colabs = temp;
    } else {
        perror("Erro ao realocar memoria apos remocao de colaborador");
        exit(1);
    }


    fcolabs = fopen("colabs.bin", "wb");
    if (fcolabs == NULL) {
        perror("\nErro: nao foi possivel abrir o arquivo colabs\n");
        exit(1);
    }
    fwrite(qtdColab,sizeof(int),1,fcolabs);
    fwrite(*colabs, sizeof(Colab), *qtdColab, fcolabs);
    fclose(fcolabs);


    printf("\nColaborador removido com sucesso!\n");
}

