#ifndef ARVORE_H
#define ARVORE_H

#include "aluno.h"

typedef struct arvore Arvore;
 
Arvore* criaArvoreVazia();

Arvore* criaArvore(Arvore* arv, Aluno* al);

void liberaArvore (Arvore* arv);

int arvoreVazia(Arvore* arv);

int busca(Arvore* arv, Aluno* al);

void imprimeArvore(Arvore* arv);

Arvore* insere(Arvore* arv, Aluno* al);

Arvore* retira(Arvore* arv, Aluno* al);

#endif // ARVORE_H