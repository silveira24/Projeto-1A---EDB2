#include <stdio.h>
#include <stdlib.h>

#include "../include/No.h"

int main() {

    No* arvore = inicializar_arvore();

    arvore = carregar_livros("livros.csv", arvore);

    exibir_arvore(arvore);

    liberar_arvore(arvore);

    return 0;
}