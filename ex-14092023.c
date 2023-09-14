// l123b
// 14-09-2023
// A soma dos divisores dá ele mesmo

#include <stdio.h>
#include <stdbool.h>
// Retorna se um valor é perfeito ou não
bool ehPerfeito(int numero);

// Função que encontra o maior perfeito menor do que o valor fornecido
int maiorPerfeito(int valor);

bool ehPerfeito(int numero) 
{
  int incrementa = 0;
  for(int i = numero-1; i > 0; i--) {
    if(numero % i == 0) {
      incrementa = incrementa + i;  
    } else {
        continue;
    }
  }

  if(incrementa == numero) {
    return true;
  } else {
    return false;
  }

}

int maiorPerfeito(int valor) 
{
  for(int i = valor-1; i > 0; i--) {
    if(ehPerfeito(i)) {
        return i;
        break;
    } else {
        continue;
    };
  }
}

int main() 
{
  int valor;
  
  printf("Insira um número:\n");
  scanf("%d", &valor);

  printf("%d é o maior número perfeito\n", maiorPerfeito(valor));

}