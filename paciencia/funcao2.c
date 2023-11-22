#include <stdio.h>

typedef enum { ouro, copas, espadas, paus } naipe_t;
typedef enum { as = 1, valete = 11, dama, rei } valor_t;
typedef enum { vermelho, preto } cor_t;

typedef struct
{
  valor_t valor;
  naipe_t naipe;
} carta_t;

typedef struct
{
  int n_cartas;
  carta_t cartas[52];
} pilha_t;

carta_t retorna_carta_topo(pilha_t pilha);
int main() 
{
  
  carta_t carta1 = {as, ouro};
  pilha_t pilha1 = {1, carta1};

  carta_t carta_retornada = retorna_carta_topo(pilha1);

  printf("A carta do topo é %c", carta_retornada.valor);

  printf("A pilha tem %d carta(s)\n", pilha1.n_cartas);



}

carta_t retorna_carta_topo(pilha_t pilha)
{
  return pilha.cartas[pilha.n_cartas - 1];
}