// Aluna: Thamya Vieira Hashimoto Donadia
// Testador 3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "banhoTosa.h"
#include "lista.h"

struct banhotosa{
    char* nome;
    ListaHet* agressivos;
    ListaHet* mansos;
};

BanhoTosa* inicBanhoTosa(char* nome){
    BanhoTosa* loja = (BanhoTosa*) malloc(sizeof(BanhoTosa));   
    loja->nome = strdup(nome);
    loja->agressivos = inicializaLista();
    loja->mansos = inicializaLista();
    return loja;
}

void cadastraCachorro(BanhoTosa* loja, Cachorro* dog){
    // verifica o nível de agressividade do cachorro para inserí-lo na lista correta 
    if(retornaNivelAgressividadeCachorro(dog) == MANSO){
        insereCachorro(loja->mansos, dog);
    
    }else if(retornaNivelAgressividadeCachorro(dog) == BRAVO){
        insereCachorro(loja->agressivos, dog);
    }
}

void cadastraGato(BanhoTosa* loja, Gato* cat){
    // verifica o nível de agressividade do gato para inserí-lo na lista correta 
    if(retornaNivelAgressividadeGato(cat) == MANSO){
        insereGato(loja->mansos, cat);

    }else if(retornaNivelAgressividadeGato(cat) == BRAVO){
        insereGato(loja->agressivos, cat);
    }
}

void atualizaSituacaoGato(BanhoTosa* loja, Gato* cat){
    // verifica se o gato está na lista errada para inserí-lo na correta 
    if(retornaNivelAgressividadeGato(cat) == MANSO){
        if(verificaGatoLista(loja->agressivos, cat)){
            retiraGato(loja->agressivos, cat);
            insereGato(loja->mansos, cat);
        }

    }else if(retornaNivelAgressividadeGato(cat) == BRAVO){
        if(verificaGatoLista(loja->mansos, cat)){
            retiraGato(loja->mansos, cat);
            insereGato(loja->agressivos, cat);
        }
    }
}

void atualizaSituacaoCachorro(BanhoTosa* loja, Cachorro* dog){
    // verifica se o cachorro está na lista errada para inserí-lo na correta 
    if(retornaNivelAgressividadeCachorro(dog) == MANSO){
        if(verificaCachorroLista(loja->agressivos, dog)){
            retiraCachorro(loja->agressivos, dog);
            insereCachorro(loja->mansos, dog);
        }

    }else if(retornaNivelAgressividadeCachorro(dog) == BRAVO){
        if(verificaCachorroLista(loja->mansos, dog)){
            retiraCachorro(loja->mansos, dog);
            insereCachorro(loja->agressivos, dog);
        }
    }
}

void imprimeBanhoTosa(BanhoTosa* loja){
    printf("\nNome da loja: %s\n", loja->nome);
    printf("\nAnimais mansos:\n");
    imprimeLista(loja->mansos);
    printf("\n\nAnimais agressivos:\n");
    imprimeLista(loja->agressivos);
    printf("\n");
}

float calculaReceita(BanhoTosa* loja){
    float valor = 0;

    valor = 30 * retornaNumGatos(loja->mansos);
    valor += 40 * retornaNumCachorros(loja->mansos);
    valor += 35 * retornaNumGatos(loja->agressivos);
    valor += 45 * retornaNumCachorros(loja->agressivos);

    return valor;
}

void liberaBanhoTosa(BanhoTosa* loja){
    free(loja->nome);
    destroiLista(loja->mansos);
    destroiLista(loja->agressivos);
    free(loja);
}


