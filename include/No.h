#ifndef NO_H
#define NO_H

#include "Livro.h"

typedef struct No
{
    Livro* data;
    struct No* esquerdo;
    struct No* direito;
} No;

No* inicializar_arvore();
No* criarNo(Livro* livro);
void inserir_livro(No** raiz, Livro* livro);
void buscar_por_autor(No* raiz, char autor[]);
No* carregar_livros(char* nome_arquivo, No* raiz);
void exibir_arvore(No* raiz);
void liberar_arvore(No* raiz);

#endif