#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "lesao.h"

#define TAM_ID 10
#define TAM_DIAG 100
#define TAM_REG 100

struct
{
    char *id;        // salva o id da lesão
    char *diag;      // salva o diagnóstico da lesão
    char *regiao;    // salva a região da lesão
    int malignidade; // salva o grau de malignidade da lesão
};

/*
Função que cria uma estrutura Lesao (alocando memória para o que for necessário), lê os valores da entrada padrão
de acordo com a descrição, e retorna o ponteiro para a estrutura criada.
*/
Lesao *leLesao()
{
    Lesao *les = (Lesao *)malloc(sizeof(Lesao));
    if (les == NULL)
    {
        printf("Erro ao alocar memoria para o lesao.\n");
        exit(1);
    }
    les->id = (char *)malloc(sizeof(char) * TAM_ID);
    if (les->id == NULL)
    {
        printf("Erro ao alocar memoria para o identificacao da lesao.\n");
        exit(1);
    }
    les->diag = (char *)malloc(sizeof(char) * TAM_DIAG);
    if (les->diag == NULL)
    {
        printf("Erro ao alocar memoria para o diagnóstico da lesao .\n");
        exit(1);
    }
    les->regiao = (char *)malloc(sizeof(char) * TAM_REG);
    if (les->regiao == NULL)
    {
        printf("Erro ao alocar memoria para a regiao da lesao .\n");
        exit(1);
    }

    scanf("%9[^\n] %99[^\n] %99[^\n] %d", les->id, les->diag, les->regiao, &les->malignidade);
    scanf("%*c");

    return les;
}

/*
Função que libera a memória alocada para a estrutura Lesao.
Ela verifica se o ponteiro passado é nulo antes de tentar liberar a memória.
*/
void liberaLesao(Lesao *l)
{
    if (l != NULL)
    {
        free(l->id);
        free(l->diag);
        free(l->regiao);
        free(l);
    }
}

/*
Função que retorna o Id da lesão passada como parâmetro.
*/
char *getIdLesao(Lesao *l)
{
    return (l->id);
}

/*
Função que calcula se a lesão passada como parâmetro precisa de cirurgia de acordo com a regra
informada na descrição.
*/
int precisaCirurgiaLesao(Lesao *l)
{
    if (l->malignidade > 50)
    {
        return 1;
    }
    return 0;
}