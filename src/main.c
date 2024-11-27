#include <stdio.h>

#include "../include/No.h"

int main() {

    Livro* livro1 = criarLivro(2, "livro1", "Gabriel Silveira", "romance", 2024, "bta", 200);
    Livro* livro2 = criarLivro(1, "livro2", "Gabriel Santos", "terror", 2023, "bta", 150);
    Livro* livro3 = criarLivro(4, "livro3", "Gabriel Silveira", "terror", 2023, "bta", 150);
    Livro* livro4 = criarLivro(5, "livro4", "Gabriel Santos", "terror", 2023, "bta", 150);
    Livro* livro5 = criarLivro(3, "livro5", "Gabriel Silveira", "terror", 2023, "bta", 150);

    No* arvore = inicializar_arvore();

    inserir_livro(&arvore, livro1);
    inserir_livro(&arvore, livro2);
    inserir_livro(&arvore, livro3);
    inserir_livro(&arvore, livro4);
    inserir_livro(&arvore, livro5);

    buscar_por_autor(arvore, "Gabriel Silveira");

    liberar_arvore(arvore);

    return 0;
}