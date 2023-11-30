// DESENHA UMA CARTA FECHADA
#include <stdio.h>
#include "tela.h"

void desenha_carta_fechada();

int main()
{
  
  desenha_carta_fechada();
  
}

void desenha_carta_fechada() 
{
  printf("\u250F");
  for(int i = 0; i < 5; i++) {
    printf("\u2501");
  }
  printf("\u2513\n");

  for(int i = 0; i < 4; i++) {
    printf("\u2503");
      printf("\u2573\u2573\u2573\u2573\u2573");
      printf("\u2503\n");
  }
  
  printf("\u2517");
  for(int i = 0; i < 5; i++) {
    printf("\u2501");
  }
  printf("\u251B\n");
}

