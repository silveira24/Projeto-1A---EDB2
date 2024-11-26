#ifndef NO_H
#define NO_H

#include "Livro.h";

typedef struct No
{
    Livro* data;
    No* esquerdo;
    No* direito;
} No;

No* inicializar_arvore();
No* criarNo(Livro* livro);
void inserir_livro(No* raiz, Livro* livro);
void exibirLivro(Livro* livro);
void buscar_por_autor(No* raiz, char autor[]);
void exibir_arvore(No* raiz);
void liberar_arvore(No* raiz);

#endif