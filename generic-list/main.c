#include <stdio.h>
#include "listaaluno.h"
#include "aluno.h"

int main(){

    // inicializa as listas e cria os alunos 
    ListaAluno* lista = inicListaAluno();
    Aluno* a1 = criaAluno("a1", 1);
    Aluno* a2 = criaAluno("a2", 2);
    Aluno* a3 = criaAluno("a3", 3);
    Aluno* a4 = criaAluno("a4", 4);
    Aluno* a5 = criaAluno("a5", 5);

    // insere os alunos na lista 
    insereAluno(lista, a1);
    insereAluno(lista, a2);
    insereAluno(lista, a3);
    insereAluno(lista, a4);
    insereAluno(lista, a5);

    printf("------------------------ Lista de Aluno -------------------------\n");
    imprimeListaAluno(lista);

    retiraAluno(lista, "a2");
    printf("--------------- Lista de Alunos - a2 foi retirado ----------------\n");
    imprimeListaAluno(lista);

    retiraAluno(lista, "a1");
    printf("--------------- Lista de Alunos - a1 foi retirado ----------------\n");
    imprimeListaAluno(lista);


    retiraAluno(lista, "a5");
    printf("--------------- Lista de Alunos - a5 foi retirado ----------------\n");
    imprimeListaAluno(lista);

    printf("------------- Lista de Alunos - Alunos reinseridos! --------------\n");
    insereAluno(lista, a1);
    insereAluno(lista, a2);
    insereAluno(lista, a5);
    imprimeListaAluno(lista);

    liberaListaAluno(lista);
    excluiAluno(a1);
    excluiAluno(a2);
    excluiAluno(a3);
    excluiAluno(a4);
    excluiAluno(a5);
    
    return 0;
}
