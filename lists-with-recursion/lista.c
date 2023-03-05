#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

typedef struct celula Celula;

struct celula{
    Celula* prox;
    Aluno* aluno;
};

struct lista{
    Celula* prim;
    Celula* ult;
};

Lista* inicializaLista(){
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    lista->prim = NULL;
    lista->ult = NULL;
    return lista;
}

void insereAluno(Lista* lista, Aluno* aluno){
    Celula* nova = (Celula*) malloc(sizeof(Celula));
    nova->prox = NULL;
    nova->aluno = aluno;
    
    // se a lista estiver vazia
    if(lista->prim == NULL && lista->ult == NULL){
        lista->prim = nova;
        lista->ult = nova;

    }else{
        lista->ult->prox = nova;
        lista->ult = nova;
    }
}

static Celula* retiraCelula(Celula* p, Lista* lista, char* nome){
    if(p){
        // verifica se é o primeiro elemento da lista 
        if(!strcmp(getNome(p->aluno), nome)){
            Celula* temp = p;
            
            if(lista->prim == p && lista->ult == p){
                lista->ult = NULL;
            }
            p = p->prox;
            free(temp);

        // caso não seja o primeiro da lista, contiua procurando na sublista 
        }else{  
            // verifica se o que vai ser retirado é o último da lista 
            if(p->prox == lista->ult && !strcmp(getNome(p->prox->aluno),nome)){
                lista->ult = p;
            }
            p->prox = retiraCelula(p->prox, lista, nome);
        }

        return p;
    }

    return NULL;
}


void retiraAluno(Lista* lista, Aluno* aluno){
    if(!lista || !lista->prim){
        printf("Lista indefinida ou vazia\n");
        return;
    }

    Celula* p;

    p = retiraCelula(lista->prim, lista, getNome(aluno));

    if(lista->prim != p){
        lista->prim = p;
    }
}

static void imprimeCelula(Celula* p){
    if(p){
        imprimeAluno(p->aluno);
        imprimeCelula(p->prox);
    }

    return;
}

void imprimeLista(Lista* lista){
    if(!lista || !lista->prim){
        printf("Lista indefinida ou vazia\n");
        return;
    }

    Celula* p  = lista->prim;
    imprimeCelula(p);
    printf("último aluno: ");
    imprimeAluno(lista->ult->aluno);
}

static void destroiCelula(Celula* p){
    Celula* temp;

    if(p){
        temp = p;
        p = p->prox;
        free(temp);
        destroiCelula(p);
    }
}

void destroiLista(Lista* lista){
    if(!lista){
        printf("Lista indefinida\n");
        return;
    }

    Celula* p = lista->prim;
    destroiCelula(p);
    free(lista);
}

//int verificaIgualdade(Lista* lista1, Lista* lista2);

