# Barbearia (NOME)

## Integrantes: 

> Adriano Ferro de Oliveira Filho / 12511BSI261
> Emerson Gustavo Cintra Silva / 12421BSI300
> Felipe Caseri Piva / 12421BSI340
> Guilherme Conegundes Pereira / 12421BSI254
> Guilherme Henrique Souza da Silva / 12421BSI358

SOBRE O SISTEMA DE GERENCIAMENTO DE BARBEARIA

## Descrição do Sistema

O tema escolhido pelo grupo foi o gerenciamento de uma barbearia. A ideia é simular o funcionamento de um estabelecimento que oferece serviços variados, como corte de cabelo, barba, tratamentos capilares, entre outros.
O programa vai utilizar dos dados coletados para otimizar os agendamentos e retornar informações relevantes para o usuário.

------------------------------
## FUNCIONALIDADES
------------------------------
- Create: Cadastro de clientes, colaboradores e agendamentos
- Read: Listagem dos dados cadastrados
- Update: Edição de dados existentes
- Delete: Remoção de registros
- Menu interativo: Interface via terminal para navegar entre as opções

------------------------------
## ESTRUTURA DO PROJETO
------------------------------
- cliente.h / cliente.c: Estrutura e funções para clientes
- colab.h / colab.c: Estrutura e funções para colaboradores
- agendamento.h / agendamento.c: Estrutura e funções para agendamentos
- read.h / read.c: Funções de leitura dos dados
- main.c: Menu principal e integração das funcionalidades

------------------------------
## FUNCIONAMENTO DO SISTEMA
------------------------------
O sistema é dividido em três módulos principais: Clientes, Colaboradores e Agendamentos, cada um com seu próprio menu e conjunto de funcionalidades.
A lógica principal está centralizada na função main(), que inicializa os dados, exibe o menu principal e finaliza os dados ao encerrar.

# Ciclo de Execução:
1. Inicialização (inicializarDados)
   - Carrega os dados previamente salvos em arquivos binários (clientes.bin, colabs.bin, agendamentos.bin)
   - Realiza alocação dinâmica dos vetores com base na quantidade de registros

2. Menu Principal (menuPrincipal)
   - Exibe opções para acessar os menus de Clientes, Colaboradores ou Agendamentos
   - Cada submenu permite realizar operações de CRUD e outras ações específicas

------------------------------
# MENUS E FUNCIONALIDADES
------------------------------

Menu Clientes (menuClientes)
- 1. Cadastrar cliente
- 2. Listar clientes
- 3. Alterar cliente
- 4. Remover cliente
- 5. Voltar

Menu Colaboradores (menuColabs)
- 1. Cadastrar colaborador
- 2. Listar colaboradores
- 3. Alterar colaborador
- 4. Remover colaborador
- 5. Voltar

Menu Agendamentos (menuAgendamentos)
- 1. Cadastrar agendamento
- 2. Listar agendamento
   - Por CPF do cliente
   - Por ID do colaborador
   - Por data
- 3. Alterar agendamento
- 4. Remover agendamento
- 5. Gerar relatório
- 6. Voltar

------------------------------
# PERSISTÊNCIA DE DADOS
------------------------------
- Os dados são salvos em arquivos binários ao final da execução (finalizarDados)
- São carregados novamente na próxima inicialização
- Isso garante que os registros sejam mantidos entre sessões

------------------------------
# LIBERAÇÃO DE MEMÓRIA
------------------------------
- A função liberaDados() é chamada ao final para liberar toda a memória alocada dinamicamente

