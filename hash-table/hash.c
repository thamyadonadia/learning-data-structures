#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "hash.h"

struct hash{
    Palavra** vet;
    int tamanho;
};

static int hash(char* p, int tamanhoVet){
    int soma = 0;

    for(int i = 0; p[i]!='\0'; i++){
        soma+=p[i];
    }

    return (soma%tamanhoVet);
}

Hash* inicTabela(int tamanhoVet){
    Hash* tabela = (Hash*)malloc(sizeof(Hash));
    tabela->vet = (Palavra**) malloc(sizeof(Palavra*)*tamanhoVet);
    tabela->tamanho = tamanhoVet;

    for(int i=0; i<tamanhoVet; i++){
        tabela->vet[i] = NULL;
    }

    return tabela;
}

Palavra* acessaTabela(Hash* tabela, char* str){
    int indice = hash(str, tabela->tamanho);
    Palavra* p = buscaPalavra(tabela->vet[indice], str);

    // se a palavra já estiver na tabela 
    if(p!=NULL){
        return p;
    }

    p = inicPalavra(str);
    tabela->vet[indice] = inserePalavra(tabela->vet[indice], p);
    return p;
}

int contaPalavras(Hash* tabela){
    int count = 0;

    for(int i =0; i<tabela->tamanho; i++){
        if(tabela->vet[i]!=NULL){
            count += contaNumPalavras(tabela->vet[i]);
        }
    }

    return count;
}

void imprimeTabela(Hash* tabela){
    for(int i=0; i<tabela->tamanho; i++){
        printf("Posição vet[%d]:\n", i);
        imprimeListaPalavras(tabela->vet[i]);
    }
}

void liberaTabela(Hash* tabela){
    for(int i = 0; i<tabela->tamanho; i++){
        if(tabela->vet[i]!=NULL){
            liberaListaPalavras(tabela->vet[i]);
        }
    }

    free(tabela->vet);
    free(tabela);
}
