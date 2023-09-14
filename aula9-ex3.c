// l123b
// aula 9 - número aleatório
// nathália oliveira de almeida
// 2023-09-06

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
  srand(time(NULL));
  int palpite = rand()%100 + 1;
  int palpiteControle;
  int controller; 
  

  printf("Pense em um número secreto de 1 a 99\n");

  do {
    printf("O número pensado foi %d?\n", palpite);
    printf("Se sim, pressione 0; se o número pensado for menor, digite 1; se for um número maior, digite 2\n");
    scanf("%d", &controller);

    if(controller == 1) {
      do { 
         palpiteControle = rand()%100 + 1;
      } while(palpiteControle >= palpite);
       palpite = palpiteControle;
    } else if(controller == 2) {
      do { 
        palpiteControle = rand()%100 + 1;
      } while(palpiteControle <= palpite);
       palpite = palpiteControle;
    } else {
        continue;
    }

  } while(controller != 0);

}