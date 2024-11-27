#include "stdlib.h"
#include "string.h"

#include "../include/No.h"

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

void inserir_livro(No** raiz, Livro* livro) {
    if (*raiz == NULL) {
        *raiz = criarNo(livro);
    } else if (livro->codigo < (*raiz)->data->codigo) {
        inserir_livro(&(*raiz)->esquerdo, livro);
    } else {
        inserir_livro(&(*raiz)->direito, livro);
    }
    
}

void buscar_por_autor(No* raiz, char autor[]) {
    if (raiz != NULL) {
        if (strcmp(raiz->data->autor, autor) == 0) {
            exibirLivro(raiz->data);
        }
        buscar_por_autor(raiz->esquerdo, autor);
        buscar_por_autor(raiz->direito, autor);
    }
    
}

void exibir_arvore(No* raiz) {
    if (raiz != NULL) {
        exibirLivro(raiz->data);
        exibir_arvore(raiz->esquerdo);
        exibir_arvore(raiz->direito);
    }
}

void liberar_arvore(No* raiz) {
    if (raiz == NULL) {
        return;
    }

    liberar_arvore(raiz->esquerdo);
    liberar_arvore(raiz->direito);

    free(raiz->data);
    free(raiz);
}