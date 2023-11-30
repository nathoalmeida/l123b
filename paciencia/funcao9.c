// DESENHA UM LOCAL VAZIO QUE RECEBE CARTAS

#include <stdio.h>
#include "tela.h"

void desenha_pilha_vazia();

int main()
{
  
  desenha_pilha_vazia();
  
}

void desenha_pilha_vazia() 
{
  printf("\u2554");
  for(int i = 0; i < 5; i++) {
    printf("\u2550");
  }
  printf("\u2557\n");

  for(int i = 0; i < 4; i++) {
    printf("\u2551");
  printf("     ");
  printf("\u2551\n");
  }
  
  printf("\u255A");
  for(int i = 0; i < 5; i++) {
    printf("\u2550");
  }
  printf("\u255D\n");
}

