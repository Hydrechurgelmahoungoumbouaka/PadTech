#include <stdio.h>
#include <stdlib.h>

#include "paciente.h"
#include "data.h"
#include "lesao.h"

#define TAM_NOME 100
#define TAM_SUS 19

struct Paciente
{
    char *nome;            // salva o nome do paciente
    Data *dataNasc;        // salva a data de nascimento do paciente
    char *cartaoSus;       // salva o cartão do SUS do paciente
    char genero;           // salva o gênero do paciente
    Lesao **lesoes;        // salva as lesões do paciente
    int qtdLesoes;         // salva a quantidade de lesões do paciente
    int qtdLesoesAlocadas; // controla a quantidade de lesões alocadas
};

/*
Função que cria uma estrutura Paciente (alocando memória para o que for necessário), lê os valores da entrada padrão
de acordo com a descrição, e retorna o ponteiro para a estrutura criada.
*/
Paciente *lePaciente()
{
    Paciente *p = (Paciente *)malloc(sizeof(Paciente));
    if (p == NULL)
    {
        printf("Erro ao alocar memoria para o paciente.\n");
        exit(1);
    }
    p->nome = (char *)malloc(sizeof(char) * TAM_NOME);
    if (p->nome == NULL)
    {
        printf("Erro ao alocar memoria para o nome do paciente.\n");
        exit(1);
    }
    p->cartaoSus = (char *)malloc(sizeof(char) * TAM_SUS);
    if (p->cartaoSus == NULL)
    {
        printf("Erro ao alocar memoria para  o cartao do SUS do paciente.\n");
        exit(1);
    }
    scanf("%99[^\n]", p->nome);
    scanf("%*c");
    p->dataNasc = leData();

    scanf("%18[^\n]", p->cartaoSus);
    scanf("%*c");

    scanf("%c", &p->genero);
    scanf("%*c");

    p->qtdLesoes = 0;
    p->qtdLesoesAlocadas = 1;

    p->lesoes = (Lesao **)malloc(sizeof(Lesao *) * p->qtdLesoesAlocadas);
    if (p->lesoes == NULL)
    {
        printf("Erro ao alocar memoria para a lesao do paciente.\n");
        free(p->lesoes);
        exit(1);
    }

    return p;
}

/*
Função que libera toda a memória alocada para a estrutura Paciente.
Ela verifica se o ponteiro passado é nulo antes de tentar liberar a memória.
*/
void liberaPaciente(Paciente *p)
{
    if (p != NULL)
    {
        free(p->nome);
        free(p->cartaoSus);
        liberaData(p->dataNasc);
        for (int i = 0; i < p->qtdLesoes; i++)
        {

            liberaLesao(p->lesoes[i]);
        }
        free(p->lesoes);
        free(p);
    }
}

/*
Função que recebe um paciente e uma lesão e adiciona a lesão ao paciente no grupo de lesões que ele possui.
Se for necessário mais memória para alocar uma nova lesão, essa função deve realocar a memória necessária.
*/
void adicionaLesaoPaciente(Paciente *p, Lesao *l)
{
    if (p->qtdLesoes == p->qtdLesoesAlocadas)
    {
        p->qtdLesoesAlocadas += 1;
        p->lesoes = (Lesao **)realloc(p->lesoes, sizeof(Lesao *) * p->qtdLesoesAlocadas);
    }
    p->lesoes[p->qtdLesoes++] = l;
}

/*
Função que calcula a idade do paciente em relação a uma data de referência informada.
*/
int calculaIdadePaciente(Paciente *p, Data *ref)
{
    return calculaDiffAnosData(p->dataNasc, ref);
}

/*
Função que retorna a quantidade de cirurgias associadas a este paciente de acordo com as regras
descritas na descrição.
*/
int getQtdCirurgiasPaciente(Paciente *p)
{
    int contador = 0;
    for (int i = 0; i < p->qtdLesoes; i++)
    {
        if (precisaCirurgiaLesao(p->lesoes[i]))
        {
            contador++;
        }
    }
    return contador;
}

/*
Função que retorna o cartão do sus do paciente.
*/
char *getCartaoSusPaciente(Paciente *p)
{
    return (p->cartaoSus);
}

/*
Função que retorna a data de nascimento do paciente.
*/
Data *getDataNascPaciente(Paciente *p)
{
    return (p->dataNasc);
}

/*
Função que retorna a quantidade de lesões do paciente
*/
int getQtdLesoesPaciente(Paciente *p)
{
    return (p->qtdLesoes);
}

/*
Função que imprime o nome do paciente, seguido do IDs das lesões associadas a ele.
Ela verifica se existe lesão. Se não existir, nada é impresso.
Essa impressão segue o padrão da descrição.
*/
void imprimeIdLesoesPaciente(Paciente *p)
{
    /*- TRISTANA - L8
- LUCIAN - L2
- LUX - L100 */
    if (p->qtdLesoes > 0)
    {

        printf("- %s - ", p->nome);
        for (int i = 0; i < p->qtdLesoes; i++)
        {
            printf("%s ", getIdLesao(p->lesoes[i]));
        }
        printf("\n");
    }
}