#ifndef LISTA_H
#define LISTA_H

#include "aluno.h"

typedef struct lista Lista;

// inicializa a lista vazia 
Lista* inicLista();

// insere aluno na última posição da lista 
Lista* insereAluno(Lista* lista, Aluno* aluno);

// retira aluno por nome 
int retiraAluno(Lista* lista, char* nome);

// imprime a lista 
void imprimeLista(Lista* lista, int tipo);

// liberação da memória alocada para a lista 
void liberaLista(Lista* lista);

#endif