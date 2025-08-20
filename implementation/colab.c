#include "../headers/colab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INCREMENTO 5 //Número constante que incrementará as posições em blocos de 5

int qtdColab = 10; //Gerencia a quantidade de colaboradores existentes
int capacidadeC = 15; //Gerencia a capacidade do vetor de colaboradores (tamanho total alocado)
int id = 10; //Utilizado para vincular identificadores aos colaboradores

//Cadastrando colaborador
void inserirColab(Colab **p) {
    if(qtdColab >= capacidadeC){ //Verifica se existem colaboradores suficientes para preencher completamente o vetor
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

    printf("Informe a quantidade de servicos que esse colaborador presta: ");
    scanf("%d", &n);

    c.nServicos = n;

    //Serviços prestados é uma matriz visto que é um vetor (char) de vetores (também do tipo char). Portanto, é necessário solicitar a informação de quantos serviços vão ser informados para alocar memória suficiente
    c.servicosPrestados = (char **) malloc(n * sizeof(char *));
    if(c.servicosPrestados == NULL){
        perror("Erro ao realocar memoria\n");
        return;
    }

    //Aloca 200 caracteres de memória em cada posição do vetor de serviços para guardar o nome do serviço prestado
    for(int i = 0; i < n; i++){
        c.servicosPrestados[i] = (char *) malloc(200 * sizeof(char));
        if(c.servicosPrestados[i] == NULL){
            perror("Erro ao realocar memoria\n");
            return;
        }
        //Ao alocar memória, já solicita ao usuário a informação que será armazenada na memória alocada
        printf("Informe o nome do servico %d: ", i+1);
        scanf(" %[^\n]s", c.servicosPrestados[i]);
    }

    //Armazena o colaborador no vetor
    (*p)[qtdColab] = c;
    printf("Colaborador inserido com sucesso! ID: %d\n", c.id);
    qtdColab++; //Indica que houve um aumento na quantidade de colaboradores
}

//Listando todos os Colaboradores
void listarColabs(Colab *colabs) {
    //Verifica se existem colaboradores cadastrados
    if (qtdColab == 0) {
        printf("Nenhum colaborador cadastrado.\n\n");
        return;
    }

    //Percorre o vetor de colaboradores e imprime as informações de cada um
    for (int i = 0; i < qtdColab; i++) {
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
void alterarColabs(Colab **colabs){
    if (qtdColab == 0){//Verifica se há colaboradores cadastrados
       printf("\nNenhum colaborador cadastrado.\n\n");
       return;
    }

    int idBusca;
    printf("\nInforme o ID do Colaborador que deseja alterar: ");//Recebe o ID (modo de identificar um colaborador) para saber qual será alterado
    scanf("%d",&idBusca);

    int colabEncontrado = 0;
    int N;
    for(int i = 0; i < qtdColab; i++){

        if((*colabs)[i].id == idBusca){//Encontra o ID do colaborador desejado
            printf("\nInforme o novo nome do Colaborador: ");
            scanf(" %[^\n]s",(*colabs)[i].nome);
            printf("\nInforme o novo celular do Colaborador (00900000000): ");
            scanf("%lld",&(*colabs)[i].celular);
            printf("\nInforme a nova quantidade de servicos que esse colaborador presta: ");
            scanf("%d",&N);

            for(int j=0;j<(*colabs)[i].nServicos;j++){//Saber se a quantidade de serviços prestados pelo colaborador será menor que anteriormente.
                free((*colabs)[i].servicosPrestados[j]);//Se for menor que anteriormente, libera o espaço que estava armazenado(já que não será utilizado)
            }

            (*colabs)[i].servicosPrestados = (char**)realloc((*colabs)[i].servicosPrestados, N*sizeof(char*));//Realoca a memória para a quantidade que precisará, para que nao sobre.
            if((*colabs)[i].servicosPrestados == NULL){//Verifica se a realocação ocorreu corretamente
                perror("\nErro ao realocar memoria para os servicos!\n");
                return;
            }

            (*colabs)[i].nServicos=N;//nServicos recebe a quantidade de serviços que o colaborador terá agora

            for(int j=0;j<N;j++){
                (*colabs)[i].servicosPrestados[j] = (char *)malloc(200 * sizeof(char));//Aloca a memoria para a string que usa ao receber os serviços prestados
                if((*colabs)[i].servicosPrestados[j] == NULL){
                    perror("\nErro ao realocar memoria para a string de servico\n");
                    return;
                    }

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
void removerColabs(Colab **colabs) {
    if (qtdColab == 0) {
        printf("\nNenhum colaborador cadastrado para remover.\n\n");
        return;
    }

    int idBusca;
    printf("Informe o ID do colaborador que deseja remover: ");
    scanf("%d", &idBusca);

    int posicao = -1;
    for (int i = 0; i < qtdColab; i++) {
        if ((*colabs)[i].id == idBusca) {
            posicao = i;
            break;
        }
    }

    if (posicao == -1) {
        printf("\nColaborador com ID %d nao encontrado.\n", idBusca);
        return;
    }

    // Libera memória alocada para os serviços prestados do colaborador a remover
    if ((*colabs)[posicao].servicosPrestados != NULL) {
        for (int j = 0; j < (*colabs)[posicao].nServicos; j++) {
            free((*colabs)[posicao].servicosPrestados[j]);
        }
        free((*colabs)[posicao].servicosPrestados);
    }

    // Substitui pelo último colaborador do vetor
    (*colabs)[posicao] = (*colabs)[qtdColab - 1];
    qtdColab--;

    // Reduz a capacidade e realoca memória
    capacidadeC--;
    Colab *temp = realloc(*colabs, capacidadeC * sizeof(Colab));
    if (temp != NULL || capacidadeC == 0) {
        *colabs = temp;
    } else {
        printf("Erro ao realocar memoria apos remocao de colaborador");
    }

    printf("\nColaborador removido com sucesso!\n");
}
