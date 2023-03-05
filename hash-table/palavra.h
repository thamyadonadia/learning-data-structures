#ifndef PALAVRA_H
#define PALAVRA_H

typedef struct palavra Palavra;

Palavra* inicPalavra(char* p);

Palavra* inserePalavra(Palavra* lista, Palavra* p);

Palavra* buscaPalavra(Palavra* p, char* str);

int contaNumPalavras(Palavra* p);

char* retornaPalavra(Palavra* p);

void atualizaOcorrencias(Palavra* p);

int retornaOcorrencias(Palavra* p);

void imprimeListaPalavras(Palavra* p);

void liberaListaPalavras(Palavra* p);

#endif // PALAVRA_H