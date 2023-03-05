#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
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

// inicializa a lista vazia 
Lista* inicLista(){
    Lista* lista = (Lista*) malloc(sizeof(lista));  
    lista->prim = NULL;
    lista->ult = NULL;
    return lista;
}

// insere aluno na última posição da lista 
Lista* insereAluno(Lista* lista, Aluno* aluno){
    Celula* nova = (Celula*) malloc(sizeof(Celula));

    nova->aluno = aluno;
    nova->prox = NULL;
    
    if(lista->prim == NULL){
        lista->prim = nova;
    }else{
        lista->ult->prox = nova; 
    }

    lista->ult = nova;

    return lista;
}

// retira aluno por nome 
int retiraAluno(Lista* lista, char* nome){
    Celula* p = lista->prim;
    Celula* ant = NULL;

    while(p!=NULL){
        // verifica se os nomes são iguais
        if(strcmp(nome, recuperaNome(p->aluno))==0){

            // se o aluno for o primeiro da lista 
            if(p == lista->prim){
                lista->prim = p->prox;
                excluiAluno(p->aluno);
                free(p);
                return 1;
            
            // se o aluno for o último da lista 
            }else if(p->prox == NULL && ant!=NULL){
                lista->ult = ant;
                ant->prox = NULL;
                excluiAluno(p->aluno);
                free(p);
                return 1;

            // se o aluno estiver no meio da lista
            }else{
                ant->prox = p->prox;
                excluiAluno(p->aluno);
                free(p);
                return 1;
            }
        }

        ant = p;
        p = p->prox;

    }

    return 0;
}

// imprime a lista 
void imprimeLista(Lista* lista){
    Celula* p;

    for(p = lista->prim; p!=NULL; p = p->prox){
        imprimeAluno(p->aluno);
    }
}

// liberação da memória alocada para a lista 
void liberaLista(Lista* lista){
    Celula* p = lista->prim;
    Celula* temp = NULL;

    while(p!=NULL){
        temp = p->prox;
        excluiAluno(p->aluno);
        free(p);
        p = temp;
    }

    free(lista);
}


