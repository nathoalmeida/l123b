// l123b
// desafio aula 10 - triângulos
// 17-09-2023
// nathália oliveira de almeida

#include <stdio.h>
#include <stdlib.h>

void preenche_vetor(int num, int v[num]) 
{
    for(int i = 0; i < num; i++) {
        v[i] = rand() % 10;
    }
}

void imprime_vetor(int num, int v[num])
{
    for(int i = 0; i < num; i++) {
        printf("%d\n", v[i]); 
    }
    printf("\n");
}

void mesclar_vetores(int v1, int v2, int vetor1[v1], int vetor2[v2], int vetor3[10])
{
  for(int i = 0; i < v1; i++) {
    vetor3[i] = vetor1[i];
  }
  for(int i = 0; i < v2; i++) {
    vetor3[i+v2] = vetor2[i];
  }
  
}

void mesclar_alternado(int v1, int v2, int vetor1[v1], int vetor2[v2], int vetor3[10]) {
    for(int i = 0; i < 5; i++) {
      vetor3[i*2] = vetor1[i];
      vetor3[(i*2)+1] = vetor2[i];    
    }
}

int main() {
  int vetor[5];
  int vector[5];
  int vetor3[10];

  preenche_vetor(5, vetor);
  preenche_vetor(5, vector);
  mesclar_alternado(5, 5, vetor, vector, vetor3);

  imprime_vetor(5, vetor);
  imprime_vetor(5, vector);
  imprime_vetor(10, vetor3);

}

/*
v0 = v0
v2 = v1
v4 = v2
v6 = v3
v8 = v4

v1 = v0
v3 = v1
v5 = v2
v7 = v3
v9 = v4

*/