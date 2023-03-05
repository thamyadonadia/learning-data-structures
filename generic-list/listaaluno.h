#ifndef LISTAALUNO_H
#define LISTAALUNO_H

#include "aluno.h"

typedef struct listaaluno ListaAluno;

// inicializa a lista vazia 
ListaAluno* inicListaAluno();

// insere aluno na última posição da lista 
void insereAluno(ListaAluno* lista, Aluno* aluno);

// retira aluno por nome 
void retiraAluno(ListaAluno* lista, char* nome);

// imprime a lista 
void imprimeListaAluno(ListaAluno* lista);

// liberação da memória alocada para a lista 
void liberaListaAluno(ListaAluno* lista);

#endif // LISTAALUNO_H