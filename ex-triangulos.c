// l123b
// desafio aula 10 - triângulos
// 17-09-2023
// nathália oliveira de almeida

#include <stdio.h>

// forma o primeiro exemplo de triângulo
void trianguloTipo1(int numero);

// forma o segundo exemplo de triângulo
void trianguloTipo2(int numero);

// forma o terceiro exemplo de triângulo
void trianguloTipo3(int numero);

// forma o primeiro exemplo de losango
void losangoTipo1();

void imprimeAsterisco(int numero) 
{
  do {
    printf("*");  
    numero--;
  } while(numero > 0);
}

void imprimeTriangulo1(int numero) 
{
  for(int i = 0; i < numero; i++) {
    imprimeAsterisco(i+1);
    printf("\n");
  }
}

//escreveLinha(l,n) (o número total de linhas e a linha que se está)
// segundo losango (l-2*2 + 1) pra calcular o número de espaços


void trianguloTipo2(int numero) 
{
  if(numero == 4) {
    for(int i = 0; i < 10; i++) {
      printf("* ");
        if(i == 3 || i == 6 || i == 8 || i == 9) {
          printf("\n");
        }
      
    }
  } else {
      printf("Argumento inválido");
  }
}

void trianguloTipo3(int numero)
{
  if(numero == 4) {
    for(int i = 0; i < 4; i++) {
      if(i == 0) {
        printf("   *\n");
      } else if(i == 1) {
          printf("  **\n");
      } else if(i == 2) {
          printf(" ***\n");
      } else {
        printf("****\n");
      }
      
    }
  } else {
      printf("Argumento inválido");
  }
}

void losangoTipo1() 
{
  for(int i = 0; i < 43; i++) {
    if(i == 11) {
      printf("  ");
    } else if(i == 17) {
        printf("    ");
    } else if(i == 21) {
        printf("      ");
    } else if(i == 25) {
        printf("    ");
    } else if(i == 31) {
        printf("  ");
    } else {
        if(i == 7 || i == 14 || i == 19 || i == 22 || i == 27 || i == 34 || i == 42)  {
          printf("*\n");
        } else {
           printf("*");
          }
      } 
  }
}


int main()
{
   imprimeTriangulo1(5);
}


 /* ********
    ***  ***
    **    **
    *      *
    **    **
    ***  ***
    ******** */