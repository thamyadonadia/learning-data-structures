#ifndef HASH_H
#define HASH_H

#include "palavra.h"

typedef struct hash Hash;

Hash* inicTabela(int tamanhoVet);

Palavra* acessaTabela(Hash* tabela, char* str);

int contaPalavras(Hash* tabela);

void imprimeTabela(Hash* tabela);

void liberaTabela(Hash* tabela);

#endif // HASH_H