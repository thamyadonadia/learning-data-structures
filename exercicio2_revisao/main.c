#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno {
  char *nome;
  int matricula;
  float p1;
  float p2;
  float p3;
};

typedef struct aluno Aluno;

void imprime_aprovados(int n, Aluno **turma);
float media_turma(int n, Aluno **turma);
Aluno **preenche_turma(int n, Aluno **turma);
Aluno *preenche_aluno(Aluno *aluno, char *nome, int matricula, float p1, float p2, float p3);
float media_aluno(Aluno *aluno);

int main() {
  int numAlunos;

  printf("Digite o número de alunos na turma:");
  scanf("%d", &numAlunos);

  /* Turma é um ponteiro para Aluno*, que é vetor da struct aluno */
  Aluno **turma = (Aluno **)malloc(sizeof(Aluno *) * numAlunos);

  preenche_turma(numAlunos, turma);

  return 0;
}

Aluno **preenche_turma(int n, Aluno **turma) {
  char nome[100];
  int matricula;
  float p1, p2, p3;

  for (int i = 0; i < n; i++) {
    printf("Aluno %d:\n", i + 1);

    printf("Digite o nome do aluno:");
    scanf("%99[^\n]", nome);
    printf("\n");

    printf("Digite a matricula do aluno:");
    scanf("%d", &matricula);
    printf("\n");

    printf("Digite, em sequência, as notas das 3 provas do aluno:");
    scanf("%f %f %f", &p1, &p2, &p3);
    printf("\n");

    turma[i] = preenche_aluno(turma[i], nome, matricula, p1, p2, p3);
  }

  return turma;
}

Aluno *preenche_aluno(Aluno *aluno, char *nome, int matricula, float p1, float p2, float p3){

  aluno->nome = strdup(nome);
  aluno->matricula = matricula;
  aluno->p1 = p1;
  aluno->p2 = p2;
  aluno->p3 = p3;

  return aluno;
}

void imprime_aprovados(int n, Aluno **turma) {
  float mediaAluno;

  printf("Alunos aprovados:\n");

  for (int i = 0; i < n; i++) {
    mediaAluno = media_aluno(turma[i]);

    if (mediaAluno >= 5) {
      printf("Nome: %s\n", turma[i]->nome);
      printf("Matricula: %d\n\n", turma[i]->matricula);
    }
  }
}

float media_aluno(Aluno *aluno) {
  float media = (float)(aluno->p1 + aluno->p2 + aluno->p3) / 3;
  return media;
}

float media_turma(int n, Aluno **turma) {
  float somaMedias, mediaTurma;

  for (int i = 0; i < n; i++) {
    somaMedias += media_aluno(turma[i]);
  }

  mediaTurma = (float)somaMedias / n;
  return mediaTurma;
}
