#include <stdio.h>
#include "lista.h"
#include "lista.h"
#include "aluno.h"

int main(){
    Lista* lista1 = inicializaLista();

    Aluno* aluno1 = criaAluno("a1", 123);
    Aluno* aluno2 = criaAluno("a2", 456);
    Aluno* aluno3 = criaAluno("a3", 789);

    insereAluno(lista1, aluno1);
    insereAluno(lista1, aluno2);
    insereAluno(lista1, aluno3);
    imprimeLista(lista1);

    printf("\n--------------------------\n");
    retiraAluno(lista1, aluno3);
    imprimeLista(lista1);

    retiraAluno(lista1, aluno1);
    retiraAluno(lista1, aluno2);

    printf("\n--------------------------\n");
    imprimeLista(lista1);

    printf("\n--------------------------\n");
    insereAluno(lista1, aluno1);
    insereAluno(lista1, aluno2);
    insereAluno(lista1, aluno3);
    imprimeLista(lista1);

    destroiLista(lista1);
    excluiAluno(aluno2);
    excluiAluno(aluno3);
    excluiAluno(aluno1);
  
    return 0;
}