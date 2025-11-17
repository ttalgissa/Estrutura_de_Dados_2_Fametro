Tabela de dispersão ou como comumente chamada tabela hash é um vetor onde cada posiçao denominada bucket ou slot, pode armazenar um ou mais elementos, seu acesso aos dados é feito através de uma chave, a chave é um identificador único associado a um valor que se deseja armazenar ou recuperar. 
A função hash é a função que transforma a chave de entrada em um índice válido dentro do vetor da tabela hash, idealmente espalhando as chaves uniformemente pela tabela.
O valor hash é o indice numérico retornado pela funçao hash, indica a posição do slot na tabela onde o valor associado a chave é armazenado.
Colisão ocorre quando duas chaves diferentes resultam no mesmo valor hash e é inevitável, é necessário um mecanismo para tratá-las.
Fator de Carga é a razão entre o número de itens armazenados e o tamanho da tabela. Um fator de carga alto geralmente aumenta a probabilidade de colisões e diminui o desempenho.
As principais operações em uma Tabela Hash são Inserção, Busca e Remoção.
Um exemplo de operação de inserção é com a chave 12 com seu indice 2, o valor associado a 12 será colocado na lista do indice 2.
  inserir  12 mod 10 = 2
De busca com a chave 12 e indice 2 ele irá acessar o indice 2 que foi anteriormente inserido a chave 12.
  buscar 12 mod 10 = 2
De remoção com a chave 12 e indice 2, acessa o índice 2, percorre a lista e remove o elemento 12.
  remover 12 mod 10 = 2

QUESTOES
    1. O que é uma colisão em uma Tabela Hash
    2. Defina os três componentes principais de uma Tabela Hash, a Tabela Hash, a Chave e a Função Hash.
    3. Qual é o papel do Fator de Carga e como ele afeta o desempenho da Tabela Hash?
    4. Nomeie as três principais operações que podem ser realizadas em uma Tabela Hash
    5. Descreva a função do Valor Hash na estrutura da Tabela Hash, em relação à chave e ao slot.
