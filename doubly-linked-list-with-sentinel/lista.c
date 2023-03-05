#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
#include "lista.h"

typedef struct celula Celula;

struct celula{
    Celula* prox;
    Celula* ant;
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

    // se for o primeiro elemento a ser adicionado 
    if(lista->prim == NULL){
        lista->prim = nova;
        nova->ant = NULL;

    }else{
        lista->ult->prox = nova;
        nova->ant = lista->ult;
    }

    lista->ult = nova;
    return lista;
}

int retiraAluno(Lista* lista, char* nome){
    Celula* p = lista->prim;

    while(p!=NULL){
        // verifica se os nomes são iguais
        if(strcmp(nome, recuperaNome(p->aluno))==0){

            // se o aluno for o primeiro da lista 
            if(p == lista->prim && p->ant == NULL){
                lista->prim = p->prox;
                p->prox->ant = NULL;
                excluiAluno(p->aluno);
                free(p);
                return 1;
            
            // se o aluno for o último da lista 
            }else if(p->prox == NULL){
                lista->ult = p->ant;
                p->ant->prox = NULL;
                excluiAluno(p->aluno);
                free(p);
                return 1;

            // se o aluno estiver no meio da lista
            }else{
                p->ant->prox = p->prox;
                p->prox->ant = p->ant;
                excluiAluno(p->aluno);
                free(p);
                return 1;
            }
        }

        p = p->prox;

    }

    return 0;
}

// imprime a lista 
void imprimeLista(Lista* lista, int tipo){
    Celula* p;

    // imprime a lista do começo ao fim 
    if(tipo == 1){
        for(p = lista->prim; p!=NULL; p = p->prox){
            imprimeAluno(p->aluno);
        }

    // imprime a lista do fim ao começo
    }else if(tipo == 2){
        for(p = lista->ult ; p!=NULL; p = p->ant){
            imprimeAluno(p->aluno);
        }
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
