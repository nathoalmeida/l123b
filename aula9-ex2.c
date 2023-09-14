// l123b
// aula 9 - colônia de bactérias
// nathália oliveira de almeida
// 2023-09-06

#include <stdio.h>

int main() 
{
  int colonia1, colonia2;
  int i;

  colonia1 = 500;
  colonia2 = 100000;
  i = 0;

  while(colonia1 < colonia2) {
    colonia1 = colonia1 * 2;
    colonia2 = colonia2 * 1.8;
    i++;
  }

  printf("Serão necessárias %d horas", i);
}