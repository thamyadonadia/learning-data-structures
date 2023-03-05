#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abb_generica.h"

struct arvgen{
    ArvGen* esq;
    ArvGen* dir;
    void* info;
};

ArvGen* criaArvoreVazia(){
    return NULL;
}

ArvGen* criaArvore(ArvGen* arv, void* info){
    ArvGen* nova = (ArvGen*) malloc(sizeof(ArvGen));
    nova->esq = criaArvoreVazia();
    nova->dir = criaArvoreVazia();
    nova->info = info;
    return nova;
}

ArvGen* insere(ArvGen* arv, int (*cb) (void*, void*), void* info){
    if(arvoreVazia(arv)){
        arv = criaArvore(arv, info);

    }else if(!arvoreVazia(arv)){
        if(cb(info, arv->info)==-1){
            arv->esq = insere(arv->esq, cb, info);
        
        }else if(cb(info, arv->info)==1){
            arv->dir = insere(arv->dir, cb, info);
        }

    }

    return arv;
}

//ArvGen* retira(ArvGen* arv, void* info);

int arvoreVazia(ArvGen* arv){
    if(arv==NULL) return 1;

    return 0;
}

int busca(ArvGen* arv, int (*cb) (void*, void*), void* info){
    if(arvoreVazia(arv)){
        return 0;
    
    /* para comparação de strings: info é menor (em ASCII) do que info
       para comparação de matrícula: info é menor do que info */ 

    }else if(cb(info, arv->info)==-1){
        return busca(arv->esq, cb, info);

    /* para comparação de strings: info é maior (em ASCII) do que info
       para comparação de matrícula: info é maior do que info */ 

    }else if(cb(info, arv->info)==1){
        return busca(arv->dir, cb, info);
    
    // info é igual a info da árvore 
    }else if(cb(info, arv->info)==0){
        return 1;
    }

    return 0;
}

void imprimeArvore(ArvGen* arv, int (*cb) (void*)){
    printf("<");

    if(!arvoreVazia(arv)){
        cb(arv->info);
        imprimeArvore(arv->esq, cb);
        imprimeArvore(arv->dir, cb);
    }

    printf(">");
}

void liberaArvore (ArvGen* arv){
    if(!arvoreVazia(arv)){
        liberaArvore(arv->esq);
        liberaArvore(arv->dir);
        free(arv);
    }
}