#include <stdio.h>
#include "lista.h"
#include "aluno.h"

int main(){
    int op = 0, matricula;
    char nome[100];

    Lista* lista = inicLista();
    Aluno* aluno;


    printf("1. Cadastrar um aluno\n2. Retirar um aluno por nome\n");
    printf("3. Imprimir todos os alunos\n4. Finalizar o programa");
    printf("\n\nDigite a operação desejada: ");
    scanf(" %d", &op);

    while(op!=4){
        switch (op){
        
        case 1:
            printf("Digite o nome do aluno: ");
            scanf(" %99[^\n]", nome);
            printf("Digite a matrícula do aluno: ");
            scanf(" %d", &matricula);

            aluno = criaAluno(nome, matricula);
            lista = insereAluno(lista, aluno);
            
            break;
        
        case 2:
            printf("Digite o nome do aluno a ser retirado da lista: ");
            scanf(" %99[^\n]", nome);

            if(retiraAluno(lista, nome)) printf("Aluno %s retirado com sucesso\n", nome);
            else printf("O aluno %s não existe\n", nome);
            
            break;
        
        case 3: 
            printf("-------------------- Lista de alunos --------------------\n");
            imprimeLista(lista);

            break;
        
        default:
            printf("Operação inválida, tente novamente\n");
            break;
        }

        printf("\nDigite a operação desejada: ");
        scanf(" %d", &op);

    }
    
    liberaLista(lista);
    return 0;
}