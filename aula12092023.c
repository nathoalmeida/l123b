// l123b 
// 12-09-2023

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include <stdbool.h> // acrescenta valores booleanos

int main() 
{
  srand(time(NULL));
  int cont1, cont2, cont3, cont4, cont5, cont6;
  int random;
  cont1 = 0;
  cont2 = 0;
  cont3 = 0;
  cont4 = 0;
  cont5 = 0;
  cont6 = 0;

  for(int i = 0; i < 1200; i++) {
    random = rand()%6 + 1;
    printf("%d - ", random);

    if(random == 1) {
        cont1++;
    } else if(random == 2) {
        cont2++;
    } else if(random == 3) {
        cont3++;
    } else if(random == 4) {
        cont4++;
    } else if(random == 5) {
        cont5++;
    } else if(random == 6) {
        cont6++;
    } else {
        printf("Erro de cálculo");
    }
  }

  printf("\nNúmeros 1: %d\n", cont1);
  printf("Números 2: %d\n", cont2);
  printf("Números 3: %d\n", cont3);
  printf("Números 4: %d\n", cont4);
  printf("Números 5: %d\n", cont5);
  printf("Números 6: %d\n", cont6);
}