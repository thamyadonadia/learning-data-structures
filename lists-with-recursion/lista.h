#ifndef LISTA_H
#define LISTA_H

#include "aluno.h"

typedef struct lista Lista;

Lista* inicializaLista();

void insereAluno(Lista* lista, Aluno* aluno);

void retiraAluno(Lista* lista, Aluno* aluno);

void imprimeLista(Lista* lista);

void destroiLista(Lista* lista);

//int verificaIgualdade(Lista* lista1, Lista* lista2);

#endif // LISTA_H