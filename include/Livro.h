#ifndef LIVRO_H
#define LIVRO_H

typedef struct Livro
{
    int codigo;
    char titulo[50];
    char autor[20];
    char genero[10];
    int ano;
    char editora[20];
    int numPags; 
} Livro;

Livro *criarLivro(int codigo, char titulo[], char autor[], char genero[], int ano, char editora[], int numPags);
void exibirLivro(Livro* livro);

#endif