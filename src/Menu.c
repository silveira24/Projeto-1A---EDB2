#include <stdio.h>
#include <string.h>

#include "../include/Menu.h"

void exibirMenu() {
    printf("Escolha uma das opções:\n");
    printf("1 - Adicionar livro\n");
    printf("2 - Exibir livros por autor\n");
    printf("3 - Exibir todos os livros\n");
    printf("0 - sair\n");    
}

Livro* adicionarLivro() {
    int codigo;
    char titulo[50];
    char autor[50];
    char genero[30];
    int ano;
    char editora[50];
    int numPags;

    printf("digite os dados do livro a ser adicionado\n");

    printf("Digite o código do livro: ");
    scanf("%d", &codigo);
    getchar();

    printf("Digite o título do livro: ");
    fgets(titulo, sizeof(titulo), stdin);
    titulo[strcspn(titulo, "\n")] = '\0';

    printf("Digite o autor do livro: ");
    fgets(autor, sizeof(autor), stdin);
    autor[strcspn(autor, "\n")] = '\0';

    printf("Digite o gênero do livro: ");
    fgets(genero, sizeof(genero), stdin);
    genero[strcspn(genero, "\n")] = '\0';

    printf("Digite o ano de publicação do livro: ");
    scanf("%d", &ano);
    getchar();

    printf("Digite a editora do livro: ");
    fgets(editora, sizeof(editora), stdin);
    editora[strcspn(editora, "\n")] = '\0';

    printf("Digite o número de páginas do livro: ");
    scanf("%d", &numPags);

    return criarLivro(codigo, titulo, autor, genero, ano, editora, numPags);

}