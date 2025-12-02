
#ifndef _DATA_H
#define _DATA_H

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

/*
Função que cria a estrutura Data (alocando memória), lê os valores da entrada padrão
de acordo com a descrição, e retorna o ponteiro para a estrutura criada.
*/
Data *leData();

/*
Função que cria uma estrutura Data (alocando memória), inicializa os campos da estrutura
com os valores passados como parâmetro, e retorna o ponteiro para a estrutura criada.
*/
Data *criaData(int dia, int mes, int ano);

/*
Função que libera a memória alocada para a estrutura Data.
Ela verifica se o ponteiro passado é nulo antes de tentar liberar a memória.
*/
void liberaData(Data *d);

/*
Função que compara duas datas e retorna um valor inteiro que indica a diferença em anos.
Essa diferença deve ser calculada como nós calculamos a idade de uma pessoa. Ou seja, uma pessoa
que nasceu em 10/10/2000 no dia 15/09/2020 tem 19 anos.
*/
int calculaDiffAnosData(Data *d, Data *atual);

/*
Função que imprime a data no formato dd/mm/aaaa.
Não é necessário incluir zeros à esquerda.
*/
void imprimeData(Data *d);

#endif