#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
#include "listaaluno.h"
#include "listagen.h"

/* ---------------- funções de callback  ---------------- */
static int comparaNomes(void* aluno, void* nome){
    //char* nomeA = (char*) nome;
  //  Aluno* a = (Aluno*) aluno;
    
    // retorna 1 se os nomes forem iguais 
    if(!strcmp(getNome(aluno), nome)){
        return 1;
    }

    return 0;
}

/*static int comparaMatriculas(void* aluno, void* matricula){
    int* mat = (int*) matricula;

    if(getMatricula(aluno) == *mat){
        return 1;
    }

    return 0;
}*/

static int imprime(void* aluno, void* dado){
    imprimeAluno(aluno);
    return 1; 
}

/* ---------------- ------------------------------------- */

struct listaaluno{
    ListaGen* listaGenerica;
};

// inicializa a lista vazia 
ListaAluno* inicListaAluno(){
    ListaAluno* lista = (ListaAluno*) malloc(sizeof(ListaAluno));  
    lista->listaGenerica = inicLista();
    return lista;
}

// insere aluno na última posição da lista 
void insereAluno(ListaAluno* lista, Aluno* aluno){
    insere(lista->listaGenerica, aluno);
}

// retira o aluno pelo nome 
void retiraAluno(ListaAluno* lista, char* nome){
    retira(lista->listaGenerica, comparaNomes, nome);
}

// imprime a lista 
void imprimeListaAluno(ListaAluno* lista){
    percorreLista(lista->listaGenerica, imprime, NULL);
}

// liberação da memória alocada para a lista 
void liberaListaAluno(ListaAluno* lista){
    liberaLista(lista->listaGenerica);
    free(lista);
}
