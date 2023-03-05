// Aluna: Thamya Vieira Hashimoto Donadia
// Lista implementada: Lista Heterogênea Duplamente Encadeada com Sentinela
// Testador 3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

#define CACHORRO 0
#define GATO 1

typedef struct celula Celula;

struct celula{
    Celula* prox;
    Celula* ant;
    void* animal;
    int tipo;
};

struct listahet{
    Celula* prim;
    Celula* ult;
};

ListaHet* inicializaLista(){
    ListaHet* lista = (ListaHet*) malloc(sizeof(ListaHet));
    lista->prim = NULL;
    lista->ult = NULL;
    return lista;
}

void insereCachorro(ListaHet* lista, Cachorro* cachorro){
    Celula* nova = (Celula*) malloc(sizeof(Celula));
    nova->animal = cachorro;
    nova->tipo = CACHORRO;
    nova->prox =  NULL;

    // se for o primeiro animal a ser inserido
    if(lista->prim == NULL && lista->ult == NULL){
        lista->prim = nova;
        nova->ant = NULL;
    }else {
        lista->ult->prox = nova;
        nova->ant = lista->ult;
    }

    lista->ult = nova;
}

void insereGato(ListaHet* lista, Gato* gato){
    Celula* nova = (Celula*) malloc(sizeof(Celula));
    nova->animal = gato;
    nova->tipo = GATO;
    nova->prox = NULL;

    // se for o primeiro animal a ser inserido
    if(lista->prim == NULL && lista->ult == NULL){
        lista->prim = nova;
        nova->ant = NULL;
    }else {
        lista->ult->prox = nova;
        nova->ant = lista->ult;
    }

    lista->ult = nova;
}

Cachorro* retiraCachorro(ListaHet* lista, Cachorro* cachorro){
    Celula* p; Cachorro* aux;
    
    for(p=lista->prim; p!=NULL; p=p->prox){
        if(p->animal == cachorro){
            if(lista->prim == NULL){
                printf("Lista vazia\n");

            // lista contendo apenas um animal 
            }else if(lista->prim == lista->ult){
                lista->prim = NULL;
                lista->ult = NULL;
                aux = p->animal;
                free(p);
                return aux;
            
            // animal a ser retirado está na primeira posição da lista 
            }else if(p == lista->prim){
                lista->prim = p->prox;
                p->prox->ant = NULL;
                aux = p->animal;
                free(p);
                return aux;
            
            // animal a ser retirado está na última posição da lista 
            }else if(p == lista->ult){
                lista->ult = p->ant;
                p->ant->prox = NULL;
                aux = p->animal;
                free(p);
                return aux;
        
            }else{
                p->ant->prox = p->prox;
                p->prox->ant = p->ant;
                aux = p->animal;
                free(p);
                return aux;
            }
        }
    }

    return NULL;
}

Gato* retiraGato(ListaHet* lista, Gato* gato){
    Celula* p; Gato* aux;

    for(p=lista->prim; p!=NULL; p=p->prox){
        if(p->animal == gato){
            if(lista->prim == NULL){
                printf("Lista vazia\n");

            // lista contendo apenas um animal 
            }else if(lista->prim == lista->ult){
                lista->prim = NULL;
                lista->ult = NULL;
                aux = p->animal;
                free(p);
                return aux;

            // animal a ser retirado está na primeira posição da lista 
            }else if(p == lista->prim){
                lista->prim = p->prox;
                p->prox->ant = NULL;
                aux = p->animal;
                free(p);
                return aux;
            
            // animal a ser retirado está na última posição da lista 
            }else if(p == lista->ult){
                lista->ult = p->ant;
                p->ant->prox = NULL;
                aux = p->animal;
                free(p);
                return aux;
        
            }else{
                p->ant->prox = p->prox;
                p->prox->ant = p->ant;
                aux = p->animal;
                free(p);
                return aux;
            }
        }
    }

    return NULL;
}

void imprimeLista(ListaHet* lista){
    Celula* p;

    for(p = lista->prim; p!=NULL; p = p->prox){
        if(p->tipo == CACHORRO){
            imprimeCachorro(p->animal);

        }else if(p->tipo == GATO){
            imprimeGato(p->animal);
        }
    }
}


int retornaNumGatos(ListaHet* lista){
    Celula* p; int numGatos = 0;

    for(p = lista->prim; p!=NULL; p = p->prox){
        if(p->tipo == GATO){
            numGatos++;
        }
    }

    return numGatos;
}

int retornaNumCachorros(ListaHet* lista){
    Celula* p; int numCachorros = 0;

    for(p = lista->prim; p!=NULL; p = p->prox){
        if(p->tipo == CACHORRO){
            numCachorros++;
        }
    }

    return numCachorros;
}

int verificaGatoLista(ListaHet* lista, Gato* gato){
    Celula* p;

    for(p = lista->prim; p!=NULL; p = p->prox){
        if(p->animal == gato){
            return 1;
        }
    }

    return 0;
}


int verificaCachorroLista(ListaHet* lista, Cachorro* cachorro){
    Celula* p;

    for(p = lista->prim; p!=NULL; p = p->prox){
        if(p->animal == cachorro){
            return 1;
        }
    }

    return 0;
}


void destroiLista(ListaHet* lista){
    Celula* p = lista->prim; Celula* temp;

    while(p!=NULL){
        temp = p->prox;
        free(p);
        p = temp;
    }

    free(lista);
}