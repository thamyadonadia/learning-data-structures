#ifndef ABB_GENERICA_H
#define ABB_GENERICA_H

typedef struct arvgen ArvGen;

ArvGen* criaArvoreVazia();

ArvGen* criaArvore(ArvGen* arv, void* info);

ArvGen* insere(ArvGen* arv, int (*cb) (void*, void*), void* info);

//ArvGen* retira(ArvGen* arv, void* info);

int arvoreVazia(ArvGen* arv);

int busca(ArvGen* arv, int (*cb) (void*, void*), void* chave);

void imprimeArvore(ArvGen* arv, int (*cb) (void*));

void liberaArvore(ArvGen* arv);

#endif // ABB_GENERICA 