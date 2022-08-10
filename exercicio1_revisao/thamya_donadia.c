/* Aluna: Thamya Vieira Hashimoto Donadia */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14

void calc_esfera (float r, float* area, float* volume);
int raizes (float a, float b, float c, float* x1, float* x2);
int pares (int n, int* vet);
void inverte (int n, int* vet);
double avalia (double * poli, int grau, double x);

int main (){
  /* função que calcula área e volume */
  float area, volume;
  calc_esfera(2, &area, &volume);
  printf("Area da esfera: %.2f\nVolume da esfera: %.2f\n\n", area, volume); 

  /* função que calcula as raízes da equação */
  float x1, x2;
  int raiz = raizes(1.0, -6.0, 8.0, &x1, &x2);

  if(raiz){
    printf("Raizes da equacao: x1 = %.2f e x2 = %.2f\n\n", x1, x2);
  }else{
    printf("A equacao nao possui raizes reais\n\n");
  }

  /* função que verifica a qntd de números pares em um vetor */
  int* vet = (int*) malloc(sizeof(int)*10);
  int qtdPares =0;
  
  for(int i=0; i<10; i++){
    vet[i]=i;
  }

  qtdPares = pares(10, vet);
  printf("Quantidade de pares: %d\n\n", qtdPares);

  /* função que inverte os valores de um vetor */
  inverte(10, vet);
  
  printf("Vetor invertido: [ ");
  for(int i=0; i<10; i++){
    printf("%d ", vet[i]);
  }
  printf("]\n\n");

  /* função que calcula o polinômio */
  double* poli = (double*) malloc(sizeof(double)*3);
  poli[0] = 12; poli[1] = 2; poli[2] = 3;   
  double res;

  res = avalia(poli, 2, 2.5);
  printf("Resultado do polinomio: %.2f\n\n", res);

  free(vet);
  free(poli);
	return 0;
}

void calc_esfera (float r, float* area, float* volume){ 
  *area = 4*PI*pow(r,2);
  *volume = (4*PI*pow(r,3))/3;
}

int raizes (float a, float b, float c, float* x1, float* x2){
  int delta=0;
  delta = pow(b,2) - 4*a*c;

  /* verifica se as raizes são reais */
  if(delta<0){
    return 0;
  }
  
  *x1 = (-b + sqrt(delta))/(2*a);
  *x2 = (-b - sqrt(delta))/(2*a);

  return 1;
}

int pares (int n, int* vet){
  int qtdPares = 0, i=0;

  for(i=0;i<n;i++){
    if(vet[i]%2 ==0){
      qtdPares++; 
    }
  }

  return qtdPares;
}


void inverte (int n, int* vet){
  int i=0, j=0;
  int* vetCopia = (int*) malloc(sizeof(int)*n);
  
  for(i=0;i<n;i++){
    vetCopia[i] = vet[i];
  }

  for(i=n-1, j=0; i>=0 && j<n ; i--, j++){
    vet[j] = vetCopia[i];
  }

  free(vetCopia);
}

double avalia (double* poli, int grau, double x){ 
  double res=0; int i=0;
  
  for(i=1; i<grau+1; i++){
    res += poli[i]*(pow(x, i));
  }
  
  res += poli[0];

  return res;
}
