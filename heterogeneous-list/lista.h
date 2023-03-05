// Aluna: Thamya Vieira Hashimoto Donadia 
// Lista implementada: Lista Heterogênea Duplamente Encadeada com Sentinela
// Testador 3

#ifndef LISTAHET_H
#define LISTAHET_H

#include "cachorro.h"
#include "gato.h"

typedef struct listahet ListaHet;

// inicializa a lista e os ponteiros pro início e fim da lista
ListaHet* inicializaLista();

// insere o cachorro na lista fornecida
void insereCachorro(ListaHet* lista, Cachorro* cachorro);

// insere o gato na lista fornecida 
void insereGato(ListaHet* lista, Gato* gato);

// retira o cachorro da lista fornecida 
Cachorro* retiraCachorro(ListaHet* lista, Cachorro* cachorro);

// retira o gato da lista fornecida 
Gato* retiraGato(ListaHet* lista, Gato* gato);

// imprime a lista fornecida 
void imprimeLista(ListaHet* lista);

// retorna o número de gatos que estão na lista fornecida 
int retornaNumGatos(ListaHet* lista);

// retorna o número de cachorros que estão na lista fornecida 
int retornaNumCachorros(ListaHet* lista);

// verifica se o gato em questão está na lista fornecida
int verificaGatoLista(ListaHet* lista, Gato* gato);

// verifica se o cachorro em questão está na lista fornecida
int verificaCachorroLista(ListaHet* lista, Cachorro* cachorro);

// libera a memória utilizada para a lista 
void destroiLista(ListaHet* lista);

#endif 