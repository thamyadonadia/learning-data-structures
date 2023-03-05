#ifndef ALUNO_H
#define ALUNO_H

typedef struct aluno Aluno;

Aluno* criaAluno(char* nome, int matricula);

char* recuperaNome(Aluno* aluno);

void imprimeAluno(Aluno* aluno);

void excluiAluno(Aluno* aluno);

#endif 