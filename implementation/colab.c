#include "../headers/colab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INCREMENTO 5 //Número constante que incrementará as posições em blocos de 5

int qtdColab = 0; //Gerencia a quantidade de colaboradores existentes
int capacidadeC = 0; //Gerencia a capacidade do vetor de colaboradores (tamanho total alocado)
int id = 0; //Utilizado para vincular identificadores aos colaboradores

//Cadastrando colaborador
void inserirColab(Colab **p) {
    if(qtdColab >= capacidadeC){ //Verifica se existem colaboradores suficientes para preencher completamente o vetor
        capacidadeC += INCREMENTO; //Caso sim, aumenta a capacidade em um bloco de 5
        (*p) = (Colab *) realloc((*p), capacidadeC * sizeof(Colab)); //Realoca memória de acordo com o bloco
        if(p == NULL){ //Verifica se a alocação foi bem sucedida
            perror("Erro ao realocar memória\n");
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
    scanf("%ld", &c.celular);

    printf("Informe quantos serviços esse colaborador prestará: ");
    scanf("%d", &n);

    //Serviços prestados é uma matriz visto que é um vetor (char) de vetores (também do tipo char). Portanto, é necessário solicitar a informação de quantos serviços vão ser informados para alocar memória suficiente
    c.servicosPrestados = (char **) malloc(n * sizeof(char *));
    if(c.servicosPrestados == NULL){
        perror("Erro ao realocar memória\n");
        return;
    }

    //Aloca 200 caracteres de memória em cada posição do vetor de serviços para guardar o nome do serviço prestado
    for(int i = 0; i < n; i++){
        c.servicosPrestados[i] = (char *) malloc(200 * sizeof(char));
        if(c.servicosPrestados[i] == NULL){
            perror("Erro ao realocar memória\n");
            return;
        }
        //Ao alocar memória, já solicita ao usuário a informação que será armazenada na memória alocada
        printf("Informe o nome do %d˚serviço: ", i+1);
        scanf(" %[^\n]s", c.servicosPrestados[i]);
    }

    //Armazena o colaborador no vetor
    (*p)[qtdColab] = c;
    printf("Colaborador inserido com sucesso! ID: %d\n", c.id);
    qtdColab++; //Indica que houve um aumento na quantidade de colaboradores
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
void alterarColabs(Colab **colabs){
    if (qtdColab == 0){
       printf("\nNenhum colaborador cadastrado.\n\n");
       return;
    }

    int idBusca;
    printf("\nInforme o ID do Colaborador que deseja alterar: ");
    scanf("%d",&idBusca);

    int colabEncontrado = 0;
    int N;
    for(int i = 0; i < qtdColab; i++){

        if((*colabs)[i].id == idBusca){
            printf("\nInforme o novo nome do Colaborador: ");
            scanf(" %[^\n]s",(*colabs)[i].nome);
            printf("\nInforme o novo celular do Colaborador (00900000000): ");
            scanf("%ld",&(*colabs)[i].celular);
            printf("\nInforme quantos servicos esse colaborador prestará: ");
            scanf("%d",&N);

            for(int j=0;j<(*colabs)[i].nServicos;j++){
                free((*colabs)[i].servicosPrestados[j]);
            }

            (*colabs)[i].servicosPrestados = (char**)realloc((*colabs)[i].servicosPrestados, N*sizeof(char*));
            if((*colabs)[i].servicosPrestados == NULL){
                perror("\nErro ao realocar memoria para os servicos!\n");
                return;
            }

            (*colabs)[i].nServicos=N;

            for(int j=0;j<N;j++){
                (*colabs)[i].servicosPrestados[j] = (char *)malloc(200 * sizeof(char));
                if((*colabs)[i].servicosPrestados[j] == NULL){
                    perror("\nErro ao realocar memoria para a string de servico\n");
                    return;
                    }

                printf("\nInforme o nome do %d˚servico: ", j+1);
                scanf(" %[^\n]s", (*colabs)[i].servicosPrestados[j]);
            }

            printf("\n\nColaborador alterado com sucesso!\n\n");
            colabEncontrado = 1;
            break;
        }
    }

    if(!colabEncontrado){
        printf("Colaborador com ID %d nao encontrado.", idBusca);
    }
}
