#include <stdio.h>
#include <stdlib.h>

#include "gerenciador.h"
#include "paciente.h"
#include "lesao.h"
#include "data.h"

int main(int argc, char const *argv[])
{
    Gerenciador *g = criaGerenciador();
    preencheBancoPacientesGerenciador(g);
    imprimeRelatorioGerenciador(g);
    liberaGerenciador(g);
    return 0;
}
