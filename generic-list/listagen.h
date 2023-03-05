#ifndef LISTAGEN_H
#define LISTAGEN_H

typedef struct listagen ListaGen;

// inicializa a lista vazia 
ListaGen* inicLista();

// insere o elemento na última posição da lista 
void insere(ListaGen* lista, void* item);

// retira o elemento 
void retira(ListaGen* lista, int (*cb) (void*, void*), void* chave);

// percorre a lista e realiza as funções determinadas para a função callback 
int percorreLista(ListaGen* lista, int (*cb)(void*, void*), void* dado);

// liberação da memória alocada para a lista 
void liberaLista(ListaGen* lista);

#endif // LISTAGEN_H