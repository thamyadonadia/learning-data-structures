#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

struct arv{
    Arv* esq;
    Arv* dir;
    Aluno* info;
};

Arv* arv_criaVazia (void){
    return NULL;
}

Arv* arv_cria (Aluno* al, Arv* e, Arv* d){
    Arv* nova = (Arv*) malloc(sizeof(Arv));
    nova->info = al;
    nova->esq = e;
    nova->dir = d;
    return nova;
}

Arv* arv_libera (Arv* a){
    if(a->dir == NULL && a->esq == NULL){
        free(a);
        return NULL;

    }else{
        
        if(a->dir == NULL){
            arv_libera(a->esq);
        
        }else if(a->esq == NULL){
            arv_libera(a->dir);

        }else{
            arv_libera(a->esq);
            arv_libera(a->dir);
        }

        free(a);
        return NULL;
    }
}

int arv_vazia (Arv* a){
    if(a == NULL){
        return 1;
    }

    return 0;
}

int arv_pertence (Arv* a, char* nome){
    if(a==NULL){
        return 0;

    }else if(!strcmp(getNome(a->info), nome)){
        return 1;

    }else{
        if(arv_pertence(a->dir, nome) || arv_pertence(a->esq, nome)){
            return 1;
        }

        return 0;
    }
}

int ocorrencias (Arv* a, Aluno* al){
    if(a == NULL){
        return 0;

    }else if(a->esq == NULL && a->dir == NULL && a->info == al){
        return 1;

    }else if(a->info == al){
        return ocorrencias(a->dir, al) + ocorrencias(a->esq, al) + 1;

    }else{
        return ocorrencias(a->dir, al) + ocorrencias(a->esq, al);
    }
}

static int ocorrencias_2 (Arv* a, Aluno* al){
    if(a == NULL){
        return 0;

    }else if(a->esq == NULL && a->dir == NULL && a->info == al){
        return 1;

    }else if(a->dir == NULL && a->info == al){
        return ocorrencias_2(a->esq, al) + 1;

    }else if(a->esq == NULL && a->info == al){  
        return ocorrencias_2(a->dir, al) + 1;

    }else if(a->info == al){
        return ocorrencias_2(a->dir, al) + ocorrencias_2(a->esq, al) + 1;

    }else{
        return ocorrencias_2(a->dir, al) + ocorrencias_2(a->esq, al); 
    }
}

int folhas (Arv* a){
    if(a == NULL){
        return 0;

    }else if(a->esq == NULL && a->dir == NULL){
        return 1;

    }else {
        return folhas(a->esq) + folhas(a->dir);
    }

}

Aluno* info (Arv* a){
    return a->info;
}

void arv_imprime (Arv* a){
    printf("<");

    if(a!=NULL){
        printf("%s", getNome(a->info));
        arv_imprime(a->esq);
        arv_imprime(a->dir);
    }

    printf(">");
}

Arv* arv_pai (Arv* a, Aluno* al){
    if(a == NULL){
        return NULL;

    // se o aluno estiver na esquerda   
    }else if(arv_pertence(a->esq, getNome(al))){
        if(!strcmp(getNome(a->esq->info), getNome(al))){
            return a;

        }else{
            return arv_pai(a->esq, al);
        }

    // se o aluno estiver na direita 
    }else if(arv_pertence(a->dir, getNome(al))){
        if(!strcmp(getNome(a->dir->info), getNome(al))){
            return a;

        }else{
            return arv_pai(a->dir, al);
        }
    // se o aluno não estiver em nenhum lugar 
    }else{
        return NULL;
    }
}