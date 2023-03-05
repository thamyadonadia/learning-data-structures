#ifndef ABB_MAT_H
#define ABB_MAT_H

#include "aluno.h"
#include "abb_generica.h"

typedef ArvGen ArvMat;

ArvMat* criaArvoreVaziaMatriculas();

ArvMat* criaArvoreMatriculas(ArvMat* arv, Aluno* al);

ArvMat* insereMatriculas(ArvMat* arv, Aluno* al);

//ArvMat* retira(ArvMat* arv, void* info);

int arvoreVaziaMatriculas(ArvMat* arv);

int buscaMatriculas(ArvMat* arv, Aluno* al);

void imprimeArvoreMatriculas(ArvMat* arv);

void liberaArvoreMatriculas(ArvMat* arv);

#endif // ABB_MAT_H