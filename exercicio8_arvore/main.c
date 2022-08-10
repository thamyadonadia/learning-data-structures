#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arvore.h"

int main(){
    Aluno* al1 = criaAluno("a1", 1);
    Aluno* al2 = criaAluno("a2", 2);
    Aluno* al3 = criaAluno("a3", 3);
    Aluno* al4 = criaAluno("a4", 4);
    Aluno* al5 = criaAluno("a5", 5);
    Aluno* al6 = criaAluno("a6", 6);
    Aluno* al7 = criaAluno("a7", 7);
    
    // criando a árvore  <al1 <al2 <> <al3 <> <>> <al4 <al5 <><> > <al6 <> <> > > >
    Arv* a3 = arv_cria(al3, arv_criaVazia(), arv_criaVazia());
    Arv* a2 = arv_cria(al2, arv_criaVazia(), a3);
    Arv* a5 = arv_cria(al5, arv_criaVazia(), arv_criaVazia());
    Arv* a6 = arv_cria(al6, arv_criaVazia(), arv_criaVazia());
    Arv* a4 = arv_cria(al4, a5, a6);
    Arv* a1 = arv_cria(al1, a2, a4);    

    // verifica se a árvore esá vazia
    if(arv_vazia(a1)){
        printf("\nA árvore está vazia!\n");

    }else{
        arv_imprime(a1);
    }

    Arv* pai = arv_pai(a1, al3);
    printf("\n\nO pai de a3 é:\n");
    imprimeAluno(info(pai));

    printf("A árvore possui %d folhas\n", folhas(a1));
    printf("\nO aluno a2 aparece %d vezes na árvore\n", ocorrencias(a1, al1));

    if(arv_pertence(a1, getNome(al7))){
        printf("\nO aluno a7 pertence à árvore!\n");

    }else {
        printf("\nO aluno a7 não pertence à árvore!\n");
    }

    arv_libera(a1);
    excluiAluno(al1);
    excluiAluno(al2);
    excluiAluno(al3);
    excluiAluno(al4);
    excluiAluno(al5);
    excluiAluno(al6);
    excluiAluno(al7);

    return 0;
}