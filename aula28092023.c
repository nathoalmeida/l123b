// l123b 
// 12-09-2023
// MATRIZES

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // int mat[4][5] = {{3,7,8,9,14}, {2,3,4,5,6}}; 
  // cada chave é uma linha da matriz
  
  int m[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

/*
 //imprimir número da linha e coluna da matriz

  for(int linha = 0; linha < 3; linha++) {
    printf("início do for externo\n");
    for(int coluna = 0; coluna < 4; coluna++) {
      printf("l=%d, c=%d\n", linha, coluna);
    }
  }

*/

// início 
 int matriz[3][3];
 srand(time(0));
 for(int linha = 0; linha < 3; linha++) {
    for(int coluna = 0; coluna < 3; coluna++){
      matriz[linha][coluna] = rand() % 2;
    }
 }

// início matriz
printf("\u2552");

  for(int i=0; i < 7; i++) {
    printf("\u2550");
  }
  printf("\u2555\n");
    for(int linha = 0; linha < 3; linha++) {
      printf("\u2502");
      for(int coluna = 0; coluna < 3; coluna++) {
        printf("%2d", matriz[linha][coluna]);
      }
      printf(" \u2502");
      printf("\n");
    }
  printf("\u2514");

  for(int i=0; i < 7; i++) {
    printf("\u2500");
  }
  printf("\u2518\n");

  // comparar as linhas
  int soma = 0;
  for(int linha = 0; linha < 3; linha++) {
    for(int coluna = 0; coluna < 3; coluna++) {
      soma = soma + matriz[linha][coluna];
    }
    if(soma == 3) {
      printf("1 ganhou");
    } else if(soma == 0) {
        printf("0 ganhou");
    } else {
        soma = 0;
    }
    soma = 0;
  }

  // comparar as colunas
  for(int coluna = 0; coluna < 3; coluna++) {
    for(int linha = 0; linha < 3; linha++) {
      soma = soma + matriz[linha][coluna];
    }
    if(soma == 3) {
      printf("1 ganhou");
    } else if(soma == 0) {
        printf("0 ganhou");
    } else {
        soma = 0;
    }
    soma = 0;
  }
  // comparar as diagonais
  for(int linha = 0; linha < 3; linha++) {
    for(int coluna = 0; coluna < 3; coluna++) {
      soma = soma + matriz[linha][coluna];
    }
    if(soma == 3) {
      printf("1 ganhou");
    } else if(soma == 0) {
        printf("0 ganhou");
    } else {
        soma = 0;
    }
    soma = 0;
  }



// outra matriz

/*
  printf("\n");
  printf("\u2552");

  for(int i=0; i < 9; i++) {
    printf("\u2550");
  }
  printf("\u2555\n");
    for(int linha = 0; linha < 3; linha++) {
      printf("\u2502");
      for(int coluna = 0; coluna < 4; coluna++) {
        printf("%2d", m[linha][coluna]);
      }
      printf(" \u2502");
      printf("\n");
    }
  printf("\u2514");

  for(int i=0; i < 9; i++) {
    printf("\u2500");
  }
  printf("\u2518\n");

*/

    
}