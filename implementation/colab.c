#include "../headers/colab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INCREMENTO 5 //Número constante que incrementará as posições em blocos de 5

int capacidadeC = 15; //Gerencia a capacidade do vetor de colaboradores (tamanho total alocado)
int id = 10; //Utilizado para vincular identificadores aos colaboradores

//Cadastrando colaborador
void inserirColab(Colab **p, FILE *fcolab, int *qtdColab) {
    if(*qtdColab >= capacidadeC){ //Verifica se existem colaboradores suficientes para preencher completamente o vetor

        fcolab = fopen("clientes.txt", "wb"); //Abre um arquivo binário colaboradores
        if(fcolab == NULL){ //Verifica se houve algum erro na abertura do arquivo
            perror("Erro ao abrir o arquivo.");
            exit(1);
        }

        int result = fwrite(*p, sizeof(Colab), *qtdColab, fcolab); //Salva os dados do vetor colabs no arquivo binário
        if(result < *qtdColab) perror("Erro na gravacao de algum dos colaboradores."); //Verifica se houve algum erro na escrita

        fclose(fcolab); //Fecha o arquivo

        capacidadeC += INCREMENTO; //Caso sim, aumenta a capacidade em um bloco de 5
        (*p) = (Colab *) realloc((*p), capacidadeC * sizeof(Colab)); //Realoca memória de acordo com o bloco
        if(p == NULL){ //Verifica se a alocação foi bem sucedida
            perror("Erro ao realocar memoria\n");
            return;
        }
    }

    //Solicita as informações necessárias para inserir um novo colaborador
    Colab c;
    int n;
    c.id = ++id; //Atribui um identificador ao colaborador em uma sequência crescente
    printf("Informe o nome do colaborador: ");
    scanf(" %[^\n]s", c.nome);

    printf("Informe o celular do colaborador (00900000000): ");
    scanf("%lld", &c.celular);

    do{
        printf("Informe a quantidade de servicos que esse colaborador presta (ate 5): ");
        scanf("%d", &n);
    }while(n > 5);

    c.nServicos = n;

    //Aloca 200 caracteres de memória em cada posição do vetor de serviços para guardar o nome do serviço prestado
    for(int i = 0; i < n; i++){
        printf("Informe o nome do servico %d: ", i+1);
        scanf(" %[^\n]s", c.servicosPrestados[i]);
    }

    //Armazena o colaborador no vetor
    (*p)[*qtdColab] = c;
    printf("Colaborador inserido com sucesso! ID: %d\n", c.id);
    (*qtdColab)++; //Indica que houve um aumento na quantidade de colaboradores
}

//Listando todos os Colaboradores
void listarColabs(Colab *colabs, int *qtdColab) {
    //Verifica se existem colaboradores cadastrados
    if (*qtdColab == 0) {
        printf("Nenhum colaborador cadastrado.\n\n");
        return;
    }

    //Percorre o vetor de colaboradores e imprime as informações de cada um
    for (int i = 0; i < *qtdColab; i++) {
        printf("-- Colaborador %d --\n", i + 1);
        printf(" ID: %d\n", colabs[i].id);
        printf(" Nome: %s\n", colabs[i].nome);
        printf(" Celular: %lld\n", colabs[i].celular);

        //Verifica se o colaborador possui serviços prestados
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

//Alterando as informações dos Colaboradores
void alterarColabs(Colab **colabs, int *qtdColab){
    if (*qtdColab == 0){//Verifica se há colaboradores cadastrados
       printf("\nNenhum colaborador cadastrado.\n\n");
       return;
    }

    int idBusca;
    printf("\nInforme o ID do Colaborador que deseja alterar: ");//Recebe o ID (modo de identificar um colaborador) para saber qual será alterado
    scanf("%d",&idBusca);

    int colabEncontrado = 0;
    int N;
    for(int i = 0; i < *qtdColab; i++){

        if((*colabs)[i].id == idBusca){//Encontra o ID do colaborador desejado
            printf("\nInforme o novo nome do Colaborador: ");
            scanf(" %[^\n]s",(*colabs)[i].nome);
            printf("\nInforme o novo celular do Colaborador (00900000000): ");
            scanf("%lld",&(*colabs)[i].celular);

            do{
                printf("\nInforme a nova quantidade de servicos que esse colaborador presta (ate 5): ");
                scanf("%d",&N);

            } while(N > 5);

            (*colabs)[i].nServicos=N;//nServicos recebe a quantidade de serviços que o colaborador terá agora

            for(int j=0;j<N;j++){
                printf("\nInforme o nome do servico %d: ", j+1);
                scanf(" %[^\n]s", (*colabs)[i].servicosPrestados[j]);
            }

            printf("\n\nColaborador alterado com sucesso!\n\n");//Garante para o usuario que ocorreu tudo certo
            colabEncontrado = 1;//Sinaliza que o colaborador foi encontrado
            break;
        }
    }

    if(!colabEncontrado){//Se nao existir o CPF, ou o usario tenha digitado algo errado
        printf("Colaborador com ID %d nao encontrado.", idBusca);
    }
}

//Deletando algum colaborador
void removerColabs(Colab **colabs, Agendamento *agendamentos, int *qtdAgendamentos, int *qtdColab, FILE *fcolabs) {
    if (*qtdColab == 0) {
        printf("\nNenhum colaborador cadastrado para remover.\n\n");
        return;
    }

    int idBusca;
    printf("Informe o ID do colaborador que deseja remover: ");
    scanf("%d", &idBusca);

    // 🔹 Verifica se colaborador possui agendamentos
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
    

    // Substitui pelo último colaborador do vetor
    (*colabs)[posicao] = (*colabs)[*qtdColab - 1];
    (*qtdColab)--;

    // Reduz a capacidade e realoca memória
    capacidadeC--;
    Colab *temp = realloc(*colabs, capacidadeC * sizeof(Colab));
    if (temp != NULL || capacidadeC == 0) {
        *colabs = temp;
    } else {
        perror("Erro ao realocar memoria apos remocao de colaborador");
        exit(1);
    }

    // 🔹 Atualiza arquivo binário
    fcolabs = fopen("colabs.bin", "wb");
    if (fcolabs == NULL) {
        perror("\nErro: nao foi possivel abrir o arquivo colaboradores.bin\n");
        exit(1);
    }
    fwrite(*colabs, sizeof(Colab), *qtdColab, fcolabs);
    fclose(fcolabs);
    

    printf("\nColaborador removido com sucesso!\n");
}

