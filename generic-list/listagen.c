#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listagen.h"

typedef struct celula Celula;

struct celula{
    Celula* prox;
    Celula* ant;
    void* item;
};

struct listagen{
    Celula* prim;
    Celula* ult;
};
// inicializa a lista vazia 
ListaGen* inicLista(){
    ListaGen* lista = (ListaGen*) malloc(sizeof(ListaGen));
    lista->prim = NULL;
    lista->ult = NULL;
    return lista;
}

// insere o elemento na última posição da lista 
void insere(ListaGen* lista, void* item){
    Celula* nova = (Celula*) malloc(sizeof(Celula));

    nova->item = item;
    nova->prox = NULL;
    
    if(lista->prim == NULL){
        lista->prim = nova;
        nova->ant = NULL;

    }else{
        lista->ult->prox = nova;
        nova->ant = lista->ult;
    }

    lista->ult = nova;
}

// retira o elemento da lista 
void retira(ListaGen* lista, int (*cb) (void*, void*), void* chave){
    Celula* p = lista->prim;

    for(p = lista->prim; p!=NULL; p = p->prox){
        // encontra o elemento com a chave de busca 
        if(cb(p->item, chave)){
           // se for o único elemento da lista 
            if(lista->prim == lista->ult){
                lista->prim = NULL;
                lista->ult = NULL;
                free(p);
                return;
                
            // se o elemento for o primeiro da lista 
            }else if(p == lista->prim){
                lista->prim = p->prox;
                p->prox->ant = NULL;
                free(p);
                return;
            
            // se o elemento for o último da lista 
            }else if(lista->ult == p){
                lista->ult = p->ant;
                p->ant->prox = NULL;
                free(p);
                return;

            // se o elemento estiver no meio da lista
            }else{
                p->ant->prox = p->prox;
                p->prox->ant = p->ant;
                free(p);
                return;

            }
        }
    }
}

// percorre a lista e realiza as funções determinadas para a função callback 
int percorreLista(ListaGen* lista, int (*cb)(void*, void*), void* dado){
    Celula* p; int resultado;

    for(p = lista->prim; p!=NULL; p = p->prox){
        resultado = cb(p->item, dado);
        
        if(resultado == 0){
            return resultado;
        }     
    }

    return 1;
}

// liberação da memória alocada para a lista 
void liberaLista(ListaGen* lista){
    Celula* p = lista->prim; Celula* temp = NULL;

    while(p!=NULL){
        temp = p->prox;
        free(p);
        p = temp;
    }

    free(lista);
}