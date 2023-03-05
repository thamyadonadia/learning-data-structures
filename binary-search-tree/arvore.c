#include <stdio.h>
#include <stdlib.h>

#include "arvore.h"

struct arvore{
    Aluno* info;
    struct arvore* esq;
    struct arvore* dir;
};

Arvore* criaArvoreVazia(){
    return NULL;
}

Arvore* criaArvore(Arvore* arv, Aluno* al){
    Arvore* nova = (Arvore*) malloc(sizeof(Arvore));
    nova->info = al;
    nova->esq = NULL;
    nova->dir = NULL;
    return nova;
}

void liberaArvore(Arvore* arv){
    if(!arvoreVazia(arv)){
        liberaArvore(arv->esq); 
        liberaArvore(arv->dir); 
        free(arv); 
    }
}

int arvoreVazia(Arvore* arv){
    if(arv==NULL){
        return 1;
    }

    return 0;
}

int busca(Arvore* arv, Aluno* al){
    if(arvoreVazia(arv)){ 
        return 0; 

    }else if(getMatricula(al) < getMatricula(arv->info)){
        return busca(arv->esq, al);

    }else if(getMatricula(al) > getMatricula(arv->info)){
        return busca(arv->dir, al);

    }else if(getMatricula(al) == getMatricula(arv->info)){
        return 1;
    }

    return 0;
}

void imprimeArvore(Arvore* arv){
    printf("<");

    if(!arvoreVazia(arv)){
        printf("%d", getMatricula(arv->info));
        imprimeArvore(arv->esq);
        imprimeArvore(arv->dir);
    }

    printf(">");
}

Arvore* insere(Arvore* arv, Aluno* al){
   
    if(arvoreVazia(arv)){
        arv = criaArvore(arv, al);

    }else if(!arvoreVazia(arv)){
        // elemento vai para esquerda
        if(getMatricula(al) < getMatricula(arv->info)){
            arv->esq = insere(arv->esq, al);

        // elemento vai para a direita 
        }else{
            arv->dir = insere(arv->dir, al);
        }
    }
    
    return arv;
}

Arvore* retira(Arvore* arv, Aluno* al){
    if(arvoreVazia(arv)){
        return NULL;
        
    }else if(getMatricula(arv->info) < getMatricula(al)){
        arv->dir = retira(arv->dir, al);

    }else if(getMatricula(arv->info) > getMatricula(al)){
        arv->esq = retira(arv->esq, al);

    }else{
            
        if(arv->esq == NULL && arv->dir == NULL){
            free(arv);
            return NULL;

        }else if(arv->dir != NULL && arv->esq == NULL){
            Arvore* t = arv;
            arv = arv->dir;
            free(t);

        }else if(arv->dir == NULL && arv->esq != NULL){
            Arvore* t = arv;
            arv = arv->esq;
            free(t);

        }else{
            Arvore* ant = arv->esq;

            while(ant->dir!=NULL){
                ant = ant->dir;
            }

            Aluno* t = arv->info;
            arv->info = ant->info;
            ant->info = t;

            arv->esq = retira(arv->esq, al);
        }
    }

    return arv;
}
