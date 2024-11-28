#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/No.h"
#include "../include/Menu.h"

int main() {

    No* arvore = inicializar_arvore();

    arvore = carregar_livros("livros.csv", arvore);

    int codigo;
    char buscarAutor[50];

    exibirMenu();
    scanf("%d", &codigo);
    getchar();

    while (codigo != 0) {
        switch (codigo) {
            case 1:
                inserir_livro(&arvore, adicionarLivro());
                break;
            case 2:
                printf("Digite o nome do autor que deseja buscar:");
                fgets(buscarAutor, sizeof(buscarAutor), stdin);
                buscarAutor[strcspn(buscarAutor, "\n")] = '\0';
                buscar_por_autor(arvore, buscarAutor);
                break;
            case 3:
                printf("entrou no 3\n");
                exibir_arvore(arvore);
                break;
            default:
                printf("Código informado é inválido\n");
        }

        exibirMenu();
        scanf("%d", &codigo);
        getchar();
    }

    printf("Saindo do sistema...\n");

    liberar_arvore(arvore);

    return 0;
}