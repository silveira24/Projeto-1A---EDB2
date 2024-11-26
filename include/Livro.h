#ifndef LIVRO_H
#define LIVRO_H

typedef struct Livro
{
    int codigo;
    char *titulo;
    char *autor;
    char *genero;
    int ano;
    char *editora;
    int numPags; 
} Livro;

Livro *criarLivro(int codigo, char *titulo, char *autor, char *genero, int ano, char *editora, int numPags);

#endif