#include <stdio.h>
#include "abb_mat.h"

int main(){

    Aluno* a1 = criaAluno("a1", 50);
    Aluno* a2 = criaAluno("a2", 30);
    Aluno* a3 = criaAluno("a3", 20);
    Aluno* a4 = criaAluno("a4", 40);
    Aluno* a5 = criaAluno("a5", 60);
    Aluno* a6 = criaAluno("a6", 80);
    Aluno* a7 = criaAluno("a7", 75);
    Aluno* a8 = criaAluno("a8", 22);

    ArvMat* arv = criaArvoreVaziaMatriculas();
    arv = insereMatriculas(arv, a1);
    arv = insereMatriculas(arv, a2);
    arv = insereMatriculas(arv, a3);
    arv = insereMatriculas(arv, a4);
    arv = insereMatriculas(arv, a5);
    arv = insereMatriculas(arv, a6);
    arv = insereMatriculas(arv, a7);

    printf("\n------- IImprimindo a árvore de alunos -------\n");
    imprimeArvoreMatriculas(arv);
    printf("\n\n");
    

    printf("\n-------- Verificação de alunos na árvore --------\n");
    if(buscaMatriculas(arv, a1)){
        printf("O aluno a1 (matrícula %d) está na árvore!\n", getMatricula(a1));
    }else{
        printf("O aluno a1 (matrícula %d) não está na árvore!\n", getMatricula(a1));
    }

    if(buscaMatriculas(arv, a8)){
        printf("O aluno a8 (matrícula %d) está na árvore!\n", getMatricula(a8));
    }else{
        printf("O aluno a8 (matrícula %d) não está na árvore!\n", getMatricula(a8));
    }
    
    liberaArvoreMatriculas(arv);
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

/*static int comparaNomes(void* aluno, void* nome){
     retorna um num<0 se o nome do aluno for menor (em ASCII) do que a chave 
       retorna zero se o nome do aluno for igual (em ASCII) à chave 
       retorna um num>0 se o nome do aluno for maior (em ASCII) do que a chave 
    

    return strcmp(getNome(aluno), nome);
}*/