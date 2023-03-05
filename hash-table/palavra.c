#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "palavra.h"

struct palavra{
    char* str;
    int ocorrencias;
    struct palavra* prox;
};

Palavra* inicPalavra(char* p){
    Palavra* nova = (Palavra*) malloc(sizeof(Palavra));
    nova->str = strdup(p);
    nova->ocorrencias = 0;
    nova->prox = NULL;
    return nova;
}

Palavra* inserePalavra(Palavra* lista, Palavra* p){
    p->prox = lista; // inserção na primeira posição da lista
    return p;
}

Palavra* buscaPalavra(Palavra* p, char* str){
    Palavra* aux;
    
    for(aux = p; aux!=NULL; aux = aux->prox){
        if(!strcmp(aux->str, str)){
            return aux;
        }
    }

    return NULL;
}

int contaNumPalavras(Palavra* p){
    Palavra* aux; int count = 0;

    for(aux = p; aux!=NULL; aux = aux->prox){
        count++;
    }

    return count;
}

char* retornaPalavra(Palavra* p){
    return p->str;
}

void atualizaOcorrencias(Palavra* p){
    p->ocorrencias++;
}

int retornaOcorrencias(Palavra* p){
    return p->ocorrencias;
}

void imprimeListaPalavras(Palavra* p){
    Palavra* aux;

    for(aux = p; aux!=NULL; aux = aux->prox){
        printf("   Palavra: %s, Ocorrencias: %d\n", aux->str, aux->ocorrencias);
    }
}

void liberaListaPalavras(Palavra* p){
   Palavra* aux = p; Palavra* temp;

   while(aux!=NULL){
        temp = aux->prox;
        free(aux->str);
        free(aux);
        aux = temp;
    }
}