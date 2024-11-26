#include "../include/No.h"
#include "stdlib.h"

No* inicializar_arvore() {
    No* raiz = NULL;
    return raiz;
}

No* criarNo(Livro* livro) {
    No* novoNo = (No*) malloc(sizeof(No));
    novoNo->data = livro;
    novoNo->esquerdo = NULL;
    novoNo->direito = NULL;
    return novoNo;
}

void inserir_livro(No* raiz, Livro* livro) {
    if (raiz == NULL) {
        raiz = criarNo(livro);
    } else if (livro->codigo < raiz->data->codigo) {
        inserir_livro(raiz->esquerdo, livro);
    } else {
        inserir_livro(raiz->direito, livro);
    }
    
}

void buscar_por_autor(No* raiz, char autor[]) {
    if (raiz != NULL) {
        if (raiz->data->autor == autor) {
            exibirLivro(raiz->data);
        }
        buscar_por_autor(raiz->esquerdo, autor);
        buscar_por_autor(raiz->direito, autor);
    }
    
}