#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"
#define tamTabela 13

int main(){
    char* str = (char*) malloc(sizeof(char)*10);
    Hash* tabela = inicTabela(tamTabela);

    while(scanf("%[^\n]%*[\n]", str)==1){
        Palavra* p = acessaTabela(tabela, str);
        atualizaOcorrencias(p);
    }

    imprimeTabela(tabela);
    liberaTabela(tabela);
    free(str);
    return 0;
}