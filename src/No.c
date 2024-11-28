#include "stdlib.h"
#include "stdio.h"
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
    if (existeLivro(*raiz, livro)) {
        printf("livro com mesmo código já existe no sistema\n");
        return;
    }
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

No* carregar_livros(char* nome_arquivo, No* raiz) {
    
    FILE *arquivo;
    char linha[100];

    arquivo = fopen(nome_arquivo, "r");

    if (arquivo == NULL) {
        perror("Erro ao abrir arquivo\n");
        return NULL;
    }

    int codigo;
    char titulo[50];
    char autor[50];
    char genero[30];
    int ano;
    char editora[50];
    int numPags;
    while(fgets(linha, sizeof(linha), arquivo) != NULL) {
        int resultado = sscanf(linha, "%d,%49[^,],%49[^,],%29[^,],%d,%29[^,],%d", &codigo, titulo, autor, genero, &ano, editora, &numPags);

        if (resultado == 7) {
            Livro* novoLivro = criarLivro(codigo, titulo, autor, genero, ano, editora, numPags);
            inserir_livro(&raiz, novoLivro);
        } else {
            printf("erro ao ler livro na linha : %s\n", linha);
            printf("resultado = %d\n", resultado);
        }
    }

    fclose(arquivo);

    return raiz;
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

int existeLivro(No* raiz, Livro* livro) {
    if (raiz == NULL) {
        return 0;
    }

    if (raiz->data->codigo == livro->codigo) {
        return 1;
    }

    return (existeLivro(raiz->esquerdo, livro) || existeLivro(raiz->direito, livro));
    
}