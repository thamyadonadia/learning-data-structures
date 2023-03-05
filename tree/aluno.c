#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct aluno{
    char* nome;
    int matricula;
};

Aluno* criaAluno(char* nome, int matricula){
    Aluno* aluno = (Aluno*) malloc(sizeof(Aluno));

    aluno->matricula = matricula;
    aluno->nome = strdup(nome);
    
    return aluno;
}

char* getNome(Aluno* aluno){
    return aluno->nome;
}

int getMatricula(Aluno* aluno){
    return aluno->matricula;
}

void imprimeAluno(Aluno* aluno){
    printf("   Nome: %s\n", aluno->nome);
    printf("   Matricula: %d\n\n", aluno->matricula);
}

void excluiAluno(Aluno* aluno){
    free(aluno->nome);
    free(aluno);
}