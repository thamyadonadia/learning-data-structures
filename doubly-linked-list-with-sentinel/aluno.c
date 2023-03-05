#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct aluno{
    char* nome;
    int matricula;
};

Aluno* criaAluno(char* nome, int matricula){
    Aluno* aluno = (Aluno*) malloc(sizeof(aluno));

    aluno->matricula = matricula;
    aluno->nome = strdup(nome);
    
    return aluno;
}

char* recuperaNome(Aluno* aluno){
    return aluno->nome;
}

void imprimeAluno(Aluno* aluno){
    printf("Nome: %s\n", aluno->nome);
    printf("Matricula: %d\n\n", aluno->matricula);
}

void excluiAluno(Aluno* aluno){
    free(aluno->nome);
    free(aluno);
}