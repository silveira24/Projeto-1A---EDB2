#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "../include/Livro.h"

Livro *criarLivro(int codigo, char titulo[], char autor[], char genero[], int ano, char editora[], int numPags) {
    Livro* novoLivro = (Livro*) malloc(sizeof(Livro));
    if (novoLivro == NULL)
    {
        return NULL;
    }
    
    novoLivro->codigo = codigo;
    strcpy(novoLivro->titulo, titulo);
    strcpy(novoLivro->autor, autor);
    strcpy(novoLivro->genero, genero);
    novoLivro->ano = ano;
    strcpy(novoLivro->editora, editora);
    novoLivro->numPags = numPags;

    return novoLivro;
}

void exibirLivro(Livro* livro) {
    if (livro == NULL) {
        return;
    }
    
    printf("LIVRO\n\n");
    printf("Código: %d\n", livro->codigo);
    printf("Título: %s\n", livro->titulo);
    printf("Autor: %s\n", livro->autor);
    printf("Gênero: %s\n", livro->genero);
    printf("Ano de publicação: %d\n", livro->ano);
    printf("Editora: %s\n", livro->editora);
    printf("Número de Páginas: %d\n\n", livro->numPags);
}