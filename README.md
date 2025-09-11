
# Barbearia (NOME)

## Integrantes: 

> Adriano Ferro de Oliveira Filho / 12511BSI261 <br>
> Emerson Gustavo Cintra Silva / 12421BSI300 <br>
> Felipe Caseri Piva / 12421BSI340 <br>
> Guilherme Conegundes Pereira / 12421BSI254 <br>
> Guilherme Henrique Souza da Silva / 12421BSI358 <br>

## Descrição do Sistema:

O tema escolhido pelo grupo foi o gerenciamento de uma barbearia. A ideia é simular o funcionamento de um estabelecimento que oferece serviços variados, como corte de cabelo, barba, tratamentos capilares, entre outros. O programa vai utilizar dos dados coletados para otimizar os agendamentos e retornar informações relevantes para o usuário.


## Descrição para funcionamento correto do sistema:

1- Para que o código funcione corretamente, os arquivos "colabs.bin", "clientes.bin", "agendamentos.bin" e "relatorio.txt" devem permanecer na mesma pasta que está a "main.c".
Caso o "relatorio" mude de pasta, não haverá problema para gerar um novo, entretanto esse antigo não será diretamente atualizado.

2- Para que não ocorra nenhum imprevisto ao salvar alguma informação nos arquivos, fechar o programa através da própria função de "sair" do menu.

3- A pasta enviada já contém dentro de "Barbearia projeto", além da main e o arquivo do projeto no CodeBlocks (.cbp) e as pastas "bin" e "obj" que são necessárias para compilação do código, os arquivos pré-preenchidos com dados aleatórios de clientes, colaboradores, agendamentos e um relatório (gerado a partir da data mais antiga registrada). Sendo assim, ao abrir o projeto no CodeBlocks, basta apenas apertar para compilar a main.c

   Caso faça alterações nos arquivos ao testar o programa, e deseje resetar as informações para que os arquivos fiquem iguais quando foram baixados, deverá fazer os seguintes passo:
	1º: Abrir a main.c. 
	2º: Comentar a função inicializarDados (pode ser digitando " /* " no começo da linha 292 e " */ " no final da linha 326) e descomentar a função que também se chama inicializarDados (apagar o " /* " da linha 17 e " */ " da linha 291).
	3º: Compilar e rodar o código (Isso fará que os arquivos .bin recebam novamente os dados aleatórios de pessoas que já foram pré-definidos).
	4º: Fazer alguma alteração caso queira e fechar o programa corretamente.
	5º: Reverter as instruções do 2º passo, ou seja comentar a função inicializarDados que contém os dados aleatórios e descomentar a outra função inicializarDados.



