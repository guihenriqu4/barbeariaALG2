#include "../headers/agendamento.h"
#include "../headers/cliente.h"
#include "../headers/colab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INCREMENTO 5

long int capacidadeA = 0;
long int idAgen = 1;

//Cadastrando novo agendamento
void inserirAgendamento(Agendamento **p, Cliente *clientes, int *qtdClientes, Colab *colabs, int *qtdColabs, long int *qtdAgen, FILE *fagen){
    if(*qtdAgen >= capacidadeA){ //Verifica se existem agendamentos suficientes para preencher completamente o vetor

        fagen = fopen("agendamentos.bin", "wb"); //Abre um arquivo binário agendamentos
        if(fagen == NULL){ //Verifica se houve algum erro na abertura do arquivo
            perror("Erro ao abrir o arquivo.");
            exit(1);
        }

        fwrite(qtdAgen,sizeof(long int),1,fagen);
        int result = fwrite(*p, sizeof(Agendamento), *qtdAgen, fagen); //Salva os dados do vetor agendamentos no arquivo binário
        if(result < *qtdAgen) perror("Erro na gravacao de algum dos agendamentos."); //Verifica se houve algum erro na escrita

        fclose(fagen); //Fecha o arquivo

        capacidadeA += INCREMENTO; //Caso sim, aumenta a capacidade em um bloco de 5
        *p = (Agendamento *) realloc(*p, capacidadeA * sizeof(Agendamento)); //Realoca memória de acordo com o bloco
        if(*p == NULL){ //Verifica se a alocação foi bem sucedida
            perror("Erro ao realocar memória\n");
            exit(1);
        }
    }

    //Solicita as informações necessárias para inserir um novo cliente
    int n;
    Agendamento a;
    a.id = idAgen++; //Atribui um identificador ao agendamento em uma sequência crescente
    printf("Informe o CPF do cliente: ");
    scanf(" %[^\n]s", a.cpfCliente);

    //Verifica se o cliente existe antes de cadastrar o agendamento
    int r = 0;
    for(int i = 0; i < *qtdClientes; i++){
        if(strcmp(clientes[i].cpf, a.cpfCliente) == 0){
            r = 1;
            break;
        }
    }
    if(r == 0){
        perror("Cliente nao encontrado.");
        return;
    }

    printf("Informe o ID do colaborador: ");
    scanf("%d", &a.idColab);

    //Verifica se o cliente existe antes de cadastrar o agendamento
    r = 0;
    for(int i = 0; i < *qtdColabs; i++){
        if(colabs[i].id == a.idColab){
            r = 1;
            break;
        }
    }
    if(r == 0){
        perror("Colaborador nao encontrado.");
        return;
    }

    printf("Informe a data do agendamento (dd/MM//YY): ");
    scanf(" %[^\n]s", a.data);

    printf("Informe o horário do agendamento (HH:mm): ");
    scanf(" %[^\n]s", a.horario);

    printf("Informe quantos serviços foram solicitados (ate 5): ");
    scanf("%d", &n);


    for(int i = 0; i < n; i++){
        printf("Informe o nome do %d serviço: ", i+1);
        scanf(" %[^\n]s", a.servicoDesejado[i]);
    }

    (*p)[*qtdAgen] = a;
    printf("Agendamento inserido com sucesso! ID: %ld\n", a.id);
    (*qtdAgen)++;
}

// CPF do cliente, retornando: Agendamentos ativos, nome e celular vinculados a esse CPF.
// Colocar a struct Agendamento como parâmetro, junto a quantidade de agendamentos, struct Cliente e quantidade de clientes, struct Colab e quantidade de colaboradores, por fim o CPF a ser buscado.
void buscarAgendamentosPorCPF(Agendamento *agendamentos, long int *qtdAgendamentos, Cliente *clientes, int *qtdClientes, Colab *colaboradores, int *qtdColaboradores) {
    int encontrouAgendamento = 0;
    char cpf[15];
    printf("Informe o CPF do cliente: ");
    scanf(" %[^\n]s", cpf);

    printf("--- Agendamentos para o CPF: %s ---\n", cpf);
    // Aqui é criado uma struct clientes que aponta para NULL
    // Depois se encontrar eu aponto essa struct para o cliente desse CPF
    Cliente *clienteEncontrado = NULL;
    for (int i = 0; i < *qtdClientes; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0) {
            clienteEncontrado = &clientes[i];
            break;
        }
    }

    if (clienteEncontrado == NULL) {
        printf("Nenhum cliente encontrado com o CPF %s.\n", cpf);
        return;
    }

    // Exibe as informações do cliente, uso do -> por ser um ponteiro
    printf("---Informacoes do Cliente---\n");
    printf("Nome do Cliente: %s\n", clienteEncontrado->nome);
    printf("Celular do Cliente: %lld\n", clienteEncontrado->celular);
    printf("\n");

    // Agora, busca pelos agendamentos, basicmanete compara o CPF do agendamento com o CPF buscado e printa os dados
    for (int i = 0; i < *qtdAgendamentos; i++) {
        if (strcmp(agendamentos[i].cpfCliente, cpf) == 0) {
            encontrouAgendamento = 1;
            printf("---Informacoes do Agendamento %d ---\n", i + 1);
            printf("ID do Agendamento: %ld\n", agendamentos[i].id);
            printf("ID do Colaborador: %d\n", agendamentos[i].idColab);
            printf("Data: %s\n", agendamentos[i].data);
            printf("Horario: %s\n", agendamentos[i].horario);
            printf("Servicos desejados:\n");

            // pegar quantos servicos o colaborador tem, faço como o cliente, crio uma struct que aponta para NULL
            // depois se encontrar eu aponto essa struct para o colaborador desse ID
            Colab *colabAtual = NULL;
            for (int k = 0; k < *qtdColaboradores; k++) {
                if (colaboradores[k].id == agendamentos[i].idColab) {
                    colabAtual = &colaboradores[k];
                    break;
                }
            }
            if (colabAtual != NULL) {
                for (int j = 0; j < colabAtual->nServicos; j++) {
                    printf("- %s\n", agendamentos[i].servicoDesejado[j]);
                }
            }
            printf("\n");
        }
    }

    if (encontrouAgendamento == 0)
        printf("Nenhum agendamento encontrado para o CPF %s.\n", cpf);
}

//ID do colaborador, retornando: Agendamentos ativos, nome, celular e serviços vinculados a esse ID.
//Colocar a struct Agendamento como parâmetro, junto a quantidade de agendamentos, struct Colab e quantidade de colaboradores, por fim o ID a ser buscado.
void buscarAgendamentosPorIDdoColab(Agendamento *agendamentos, long int *qtdAgendamentos, Colab *colaboradores, int *qtdColaboradores){
    int encontrouAgendamento = 0;
    int idCol;
    printf("Informe o ID do colaborador: ");
    scanf("%d", &idCol);

    printf("--- Agendamentos para o ID do Colaborador: %d ---\n", idCol);
    // Aqui eu crio uma struct colaboradores que aponta para NULL
    // Depois se encontrar eu aponto essa struct para o colaborador desse ID
    Colab *colaboradorEncontrado = NULL;
    for (int i = 0; i < *qtdColaboradores; i++) {
        if (colaboradores[i].id == idCol) {
            colaboradorEncontrado = &colaboradores[i];
            break;
        }
    }

    if (colaboradorEncontrado == NULL) {
        printf("Nenhum colaborador encontrado com o ID %d.\n", idCol);
        return;
    }

    // Exibe as informações do colaborador, uso do -> por ser um ponteiro
    printf("---Informacoes do Colaborador---\n");
    printf("Nome do Colaborador: %s\n", colaboradorEncontrado->nome);
    printf("Celular do Colaborador: %lld\n", colaboradorEncontrado->celular);
    printf("Servicos prestados pelo Colaborador:\n");
    for (int j = 0; j < colaboradorEncontrado->nServicos; j++)
        printf("- %s\n", colaboradorEncontrado->servicosPrestados[j]);
    printf("\n");

    // Agora, busca pelos agendamentos, basicamanete compara o ID do agendamento com o ID buscado e printa os dados
    for (int i = 0; i < *qtdAgendamentos; i++) {
        if (agendamentos[i].idColab == idCol) {
            encontrouAgendamento = 1;
            printf("---Informacoes do Agendamento %d ---\n", i + 1);
            printf("ID do Agendamento: %ld\n", agendamentos[i].id);
            printf("CPF do Cliente: %s\n", agendamentos[i].cpfCliente);
            printf("Data: %s\n", agendamentos[i].data);
            printf("Horario: %s\n", agendamentos[i].horario);
            printf("Servicos desejados:\n");
            for (int j = 0; j < colaboradorEncontrado->nServicos; j++){
                printf("- %s\n", agendamentos[i].servicoDesejado[j]);
            }
            printf("\n");
        }
    }
    if (encontrouAgendamento == 0) {
        printf("Nenhum agendamento encontrado para o ID do Colaborador %d.\n", idCol);
    }
}

//Data indicada pelo usuário, retornando: Horários agendados, com nome do colaborador e do cliente
//Colocar a struct Agendamento como parametro, junto a quantidade de agendamentos, struct Cliente e quantidade de clientes, struct Colab e quantidade de colaboradores, por fim a data a ser buscada.
//Data: formato dd/MM/YY
void buscarAgendamentosPorData(Agendamento *agendamentos, long int *qtdAgendamentos, Cliente *clientes, int *qtdClientes, Colab *colaboradores, int *qtdColaboradores) {
    int encontrouAgendamento = 0;
    char data[9];
    printf("Informe a data: ");
    scanf(" %[^\n]s", data);

    printf("--- Agendamentos para a Data: %s ---\n", data);

    // Agora, busca pelos agendamentos, basicamente compara a data do agendamento com a data buscada e printa os dados
    for (int i = 0; i < *qtdAgendamentos; i++) {
        if (strcmp(agendamentos[i].data, data) == 0) {
            encontrouAgendamento = 1;
            printf("---Informacoes do Agendamento %d ---\n", i + 1);
            printf("ID do Agendamento: %ld\n", agendamentos[i].id);
            printf("Horario: %s\n", agendamentos[i].horario);

            // Buscar o nome do cliente pelo CPF
            Cliente *clienteAtual = NULL;
            for (int j = 0; j < *qtdClientes; j++) {
                if (strcmp(clientes[j].cpf, agendamentos[i].cpfCliente) == 0) {
                    clienteAtual = &clientes[j];
                    break;
                }
            }
            if (clienteAtual != NULL)
                printf("Nome do Cliente: %s\n", clienteAtual->nome);
            else
                printf("Cliente nao encontrado para o CPF: %s\n", agendamentos[i].cpfCliente);

            // Buscar o nome do colaborador pelo ID
            Colab *colabAtual = NULL;
            for (int k = 0; k < *qtdColaboradores; k++) {
                if (colaboradores[k].id == agendamentos[i].idColab) {
                    colabAtual = &colaboradores[k];
                    break;
                }
            }
            if (colabAtual != NULL)
                printf("Nome do Colaborador: %s\n", colabAtual->nome);
            else
                printf("Colaborador nao encontrado para o ID: %d\n", agendamentos[i].idColab);
            printf("\n");
        }
    }

    if (encontrouAgendamento == 0)
        printf("Nenhum agendamento encontrado para a data %s.\n", data);
}

void alterarAgendamento(Agendamento **agendamentos, long int *qtdAgen, Cliente *clientes, int *qtdClientes, Colab *colabs, int *qtdColabs, FILE *fagen){
    if(*qtdAgen == 0){//Verifica se tem algum agendamento cadastrado
        printf("\nNenhum agendamento cadastrado para alterar.\n\n");
        return;
    }

    long int idBusca = -1;//Inicia o ID como invalido
    int opcaoBusca;

    printf("\n---MENU DE BUSCA---\n");//Ofere ao usuario diferentes maneiras de encontrar o agendamento desejado.
    printf("\nComo deseja buscar o agendamento para alterar?\n");
    printf("1. Pelo ID do agendamento\n");
    printf("2. Pela Data do agendamento\n");
    //printf("3. Pelo CPF do cliente\n");
    //printf("4. Pelo ID do colaborador\n");
    printf("3. Voltar\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcaoBusca);

    switch(opcaoBusca){
        case 1: {
            printf("\nInforme o ID do agendamento: ");
            scanf("%ld",&idBusca);
            break;
        }

        case 2: {
            char dataBusca[11];
            printf("\nInforme a data do agendamento (dd/MM/YY): ");
            scanf(" %[^\n]s", dataBusca);

            printf("\n--- Agendamentos para a data: %s ---\n",dataBusca);
            long int idsEncontrados[*qtdAgen];//Array temporario para armazenar os IDs dos agendamentos encontrados nesta data
            int contagem = 0;//Contador para os resultados encontrados

            for (int i=0;i<*qtdAgen;i++){//Percorre todos os agendamentos para encontrar a data
                if (strcmp((*agendamentos)[i].data, dataBusca) == 0) {
                    printf("--- Agendamento [%d] ---\n", contagem + 1);
                    printf(" ID: %ld\n", (*agendamentos)[i].id);
                    printf(" Horario: %s\n", (*agendamentos)[i].horario);
                    printf(" CPF do cliente: %s\n",(*agendamentos)[i].cpfCliente);
                    printf(" ID do colaborador: %d\n",(*agendamentos)[i].idColab);
                    printf(" Servicos Solicitados:\n");
                    for(int j=0;i<5;j++){
                        if(strlen((*agendamentos)[i].servicoDesejado[j]) > 0) {
                            printf(" -%s\n",(*agendamentos[i]).servicoDesejado[j]);
                        }
                    }
                    printf("\n");
                    idsEncontrados[contagem] = (*agendamentos)[i].id;
                    contagem++;
                }
            }
            if (contagem == 0){//Se nao tiver agendamento nesta data, informa ao usuario
                printf("\nNenhum agendamento encontrado para a data %s\n",dataBusca);
                return;
            }
            int escolha;//Pede ao usuario para escolher o numero do agendamento na lista exibida
            printf("\nEscolha o numero de agendamento que deseja alterar: ");
            scanf("%d",&escolha);

            if(escolha > 0 && escolha <= contagem){
                //O ID de busca final é definido com base na escolha
                idBusca = idsEncontrados[escolha-1];
                printf("Opcao invalida\n");
                return;
            }
            break;
        }

        /*case 3: {
            char cpfBusca[15];
            printf("\nInforme o CPF do cliente (000.000.000-00): ");
            scanf(" %[^\n]s", cpfBusca);

            printf("\n--- Agendamentos para o CPF: %s ---\n", cpfBusca);
            long int idsEncontrados[*qtdAgen];
            int contagem = 0;

            for (int i = 0; i < *qtdAgen; i++) {
                if (strcmp((*agendamentos)[i].cpfCliente, cpfBusca) == 0) {
                    printf("--- Agendamento [%d] ---\n", contagem + 1);
                    printf(" ID: %ld\n", (*agendamentos)[i].id);
                    printf(" Data: %s\n", (*agendamentos)[i].data);
                    printf(" Horario: %s\n", (*agendamentos)[i].horario);
                    printf(" Servicos Desejados:\n");
                    for(int j=0;i<5;j++){
                        if(strlen((*agendamentos)[i].servicoDesejado[j]) > 0) {
                            printf(" -%s\n",(*agendamentos[i].servicoDesejado[j]));
                        }
                    }
                    printf("\n");
                    idsEncontrados[contagem] = (*agendamentos)[i].id;
                    contagem++;
                }
            }

            if (contagem == 0) {
                printf("Nenhum agendamento encontrado para o CPF %s.\n", cpfBusca);
                return;
            }

            int escolha;
            printf("\nEscolha o numero do agendamento que deseja alterar: ");
            scanf("%d", &escolha);

            if (escolha > 0 && escolha <= contagem) {
                idBusca = idsEncontrados[escolha - 1];
            } else {
                printf("Opcao invalida.\n");
                return;
            }
            break;
        }

        case 4{
            int idColabBusca;
            printf("Informe o ID do colaborador: ");
            scanf("%d", &idColabBusca);

            printf("\n--- Agendamentos para o Colaborador ID: %d ---\n", idColabBusca);
            long int idsEncontrados[*qtdAgen];
            int contagem = 0;

            for (int i = 0; i < *qtdAgen; i++) {
                if ((*agendamentos)[i].idColab == idColabBusca) {
                    printf("--- Agendamento [%d] ---\n", contagem + 1);
                    printf(" ID: %ld\n", (*agendamentos)[i].id);
                    printf(" Data: %s\n", (*agendamentos)[i].data);
                    printf(" Horario: %s\n", (*agendamentos)[i].horario);
                    idsEncontrados[contagem] = (*agendamentos)[i].id;
                    contagem++;
                }
            }

            if (contagem == 0) {
                printf("Nenhum agendamento encontrado para o colaborador com ID %d.\n", idColabBusca);
                return;
            }

            int escolha;
            printf("\nEscolha o numero do agendamento que deseja alterar: ");
            scanf("%d", &escolha);

            if (escolha > 0 && escolha <= contagem) {
                idBusca = idsEncontrados[escolha - 1];
            } else {
                printf("Opcao invalida.\n");
                return;
            }
            break;
        }*/

        case 3:{
            break;
        }
        default: {//Qualquer entrada invalida no menu eh detectada
            printf("Opcao de busca invalida!\n");
            return;
        }
        if (idBusca == -1){
            printf("ID de Agendamento invalido!\n");
            return;
        }
    }

    // Encontra o índice (posição) real do agendamento no vetor principal.
    int posicao = -1;
    for (int i = 0; i < *qtdAgen; i++) {
        if ((*agendamentos)[i].id == idBusca) {
            posicao = i;
            break;
        }
    }

    if (posicao == -1){//Verifica se o ID foi encontrado
        printf("\nNao foi possivel encontrar o agendamento selecionado. Tente novamente\n");
        return;
    }
    printf("\nAgendamento encontrado! Por favor, insira as novas informacoes\n");

    int nServicos,clienteValido,colabValido;

    do{//Garantir que o usuario ira fornecer um CPF que realmente exista
        printf("\nInforme o novo CPF do cliente (000.000.000-00): ");
        scanf(" %[^\n]s",(*agendamentos)[posicao].cpfCliente);
        clienteValido = 0;//
        //Percorre o vetor de clientes para verificar se o CPF digitado existe
        for(int i=0;i<*qtdClientes;i++){
            if(strcmp(clientes[i].cpf,(*agendamentos)[posicao].cpfCliente)==0){
                clienteValido = 1;//Garantir que existe um CPF valido
                break;
            }
        }
        if(!clienteValido){
            printf("\nCPF de cliente nao encontrado. Tente novamente!\n");
        }
    }while(!clienteValido);
    //A mesma logica que a anterior, mas para ID do colaborador
    do{
        printf("Informe o novo ID do colaborador: ");
        scanf("%d",&(*agendamentos)[posicao].idColab);
        colabValido = 0;
        for(int i=0; i < *qtdColabs; i++){
            if(colabs[i].id == (*agendamentos)[posicao].idColab){
                colabValido = 1;
                break;
            }
        }
        if(!colabValido){
            printf("ID de colaborador nao encontrado. Tente novamente!\n");
        }
    }while(!colabValido);

    //Coleta os outros dados para realizar a alteracao do agendamento
    printf("Informe a nova data do agendamento (dd/MM/YY): ");
    scanf(" %[^\n]s", (*agendamentos)[posicao].data);
    printf("Informe o novo horario do agendamento (HH:mm): ");
    scanf(" %[^\n]s", (*agendamentos)[posicao].horario);

    //Limpa os servicos antigos antes de ler os novos
    for(int i=0;i<5;i++){
        strcpy((*agendamentos)[posicao].servicoDesejado[i],"");
    }

    printf("Informe a nova quantidade de servicos (ate 5): ");
    scanf("%d", &nServicos);
    for (int i = 0; i < nServicos; i++) {
        printf("Informe o nome do servico %d: ", i + 1);
        scanf(" %[^\n]s", (*agendamentos)[posicao].servicoDesejado[i]);
    }

    //Abre o arquivo binario para escrita dos novos dados
    fagen = fopen("agendamentos.bin", "wb");
    if (fagen == NULL) {
        perror("\nErro ao abrir o arquivo de agendamentos para alteracao.\n");
        return;
    }
    fwrite(qtdAgen,sizeof(long int),1,fagen);//Escreve a quantidade total de agendamento no inicio do programa
    fwrite(*agendamentos, sizeof(Agendamento), 1, fagen);//Sobrescre os dados antigos
    fclose(fagen);//Fecha o arquivo

    printf("\nAgendamento alterado com sucesso!\n");

}

void removerAgendamentos(Agendamento **agendamentos, long int *qtdAgen, FILE *fagen) {
    if (*qtdAgen == 0) {
        printf("\nNenhum agendamento para remover.\n\n");
        return;
    }

    long int idBusca;
    printf("Informe o ID do agendamento que deseja remover: ");
    scanf("%ld", &idBusca);

    int posicao = -1;
    for (int i = 0; i < *qtdAgen; i++) {
        if ((*agendamentos)[i].id == idBusca) {
            posicao = i;
            break;
        }
    }

    if (posicao == -1) {
        printf("\nAgendamento com ID %ld não encontrado.\n", idBusca);
        return;
    }

    // Substitui o agendamento removido pelo último
    (*agendamentos)[posicao] = (*agendamentos)[*qtdAgen - 1];
    (*qtdAgen)--;

    // Reduz capacidade e realoca memória
    capacidadeA--;
    Agendamento *temp = realloc(*agendamentos, capacidadeA * sizeof(Agendamento));
    if (temp != NULL || capacidadeA == 0) {
        *agendamentos = temp;
    } else {
        perror("Erro ao realocar memória após remoção de agendamento");
        exit(1);
    }

    // Atualiza o arquivo binário
    fagen = fopen("agendamentos.bin", "wb");
    if (fagen == NULL) {
        perror("Erro ao abrir o arquivo de agendamentos.");
        exit(1);
    }
    fwrite(qtdAgen,sizeof(long int),1,fagen);
    fwrite(*agendamentos, sizeof(Agendamento), *qtdAgen, fagen);
    fclose(fagen);

    printf("\nAgendamento removido com sucesso!\n");
}
