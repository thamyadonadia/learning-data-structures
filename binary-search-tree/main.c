#include <stdio.h>
#include "arvore.h"

int main(){

    Aluno* a1 = criaAluno("a1", 50);
    Aluno* a2 = criaAluno("a2", 30);
    Aluno* a3 = criaAluno("a3", 20);
    Aluno* a4 = criaAluno("a4", 40);
    Aluno* a5 = criaAluno("a5", 60);
    Aluno* a6 = criaAluno("a6", 80);
    Aluno* a7 = criaAluno("a7", 75);
    Aluno* a8 = criaAluno("a8", 22);

    Arvore* arv = criaArvoreVazia();
    arv = insere(arv, a1);
    arv = insere(arv, a2);
    arv = insere(arv, a3);
    arv = insere(arv, a4);
    arv = insere(arv, a5);
    arv = insere(arv, a6);
    arv = insere(arv, a7);

    printf("\n------- Imprimindo a árvore de alunos -------\n");
    imprimeArvore(arv);
    printf("\n\n");
    

    printf("\n-------- Verificação de alunos na árvore --------\n");
    if(busca(arv, a1)){
        printf("O aluno a1 (matrícula %d) está na árvore!\n", getMatricula(a1));
    }else{
        printf("O aluno a1 (matrícula %d) não está na árvore!\n", getMatricula(a1));
    }

    if(busca(arv, a8)){
        printf("O aluno a8 (matrícula %d) está na árvore!\n", getMatricula(a8));
    }else{
        printf("O aluno a8 (matrícula %d) não está na árvore!\n", getMatricula(a8));
    }
    
    // retirando e inserindo novamente um nó folha
    arv = retira(arv, a3);
    printf("\n-------- Imprimindo a árvore de alunos - Sem a3 (20) -------\n");

    imprimeArvore(arv);
    printf("\n\n");
    arv = insere(arv, a3);

    // retirando  um nó filho 
    arv = retira(arv, a5);
    printf("\n-------- Imprimindo a árvore de alunos - Sem a5 (60) -------\n");
    imprimeArvore(arv);
    printf("\n\n");

    // retirando e inserindo novamente um nó raiz
    arv = retira(arv, a1);
    printf("\n-------- Imprimindo a árvore de alunos - Sem a1 (50) -------\n");
    imprimeArvore(arv);
    printf("\n\n");
    arv = insere(arv, a1);

    liberaArvore(arv);
    excluiAluno(a1);
    excluiAluno(a2);
    excluiAluno(a3);
    excluiAluno(a4);
    excluiAluno(a5);
    excluiAluno(a6);
    excluiAluno(a7);
    excluiAluno(a8);

    return 0;   
}