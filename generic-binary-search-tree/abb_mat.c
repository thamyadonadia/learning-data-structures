#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abb_mat.h"

/* ---------------- funções de callback  ---------------- */
static int comparaMatriculas(void* aluno, void* alunoArvore){
    Aluno* alArvore = (Aluno*) alunoArvore;

    /* retorna um num<0 se a matrícula do aluno for menor do que a chave 
       retorna zero se a matricula do aluno for igual à chave  
       retorna um num>0 se a matrícula do aluno for maior do que a chave 
    */

    if(getMatricula(aluno) < getMatricula(alArvore)){
        return -1;

    }else if(getMatricula(aluno) == getMatricula(alArvore)){
        return 0;
    
    }else if(getMatricula(aluno) > getMatricula(alArvore)){
        return 1;
    }
    
    return 0;
}

static int imprimeMatricula(void* aluno){
    Aluno* al = (Aluno*) aluno;
    int mat = getMatricula(al);
    printf("%d", mat);
    return 1;
}

/* ---------------------------------------------------- */

ArvMat* criaArvoreVaziaMatriculas(){
    return criaArvoreVazia();
}

ArvMat* criaArvoreMatriculas(ArvMat* arv, Aluno* al){
    int mat = getMatricula(al);
    return criaArvore(arv, &mat);
}

ArvMat* insereMatriculas(ArvMat* arv, Aluno* al){
    arv = insere(arv, comparaMatriculas, al);
    return arv;
}

//ArvMat* retira(ArvMat* arv, void* info);

int arvoreVaziaMatriculas(ArvMat* arv){
    return arvoreVazia(arv);
}

int buscaMatriculas(ArvMat* arv, Aluno* al){
    return busca(arv, comparaMatriculas, al);
}

void imprimeArvoreMatriculas(ArvMat* arv){
    imprimeArvore(arv, imprimeMatricula);
}

void liberaArvoreMatriculas(ArvMat* arv){
    liberaArvore(arv);
}