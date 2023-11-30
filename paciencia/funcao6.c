// FUNÇÃO 6 - ABRE A CARTA DO TOPO DA PILHA
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
  int n_cartas_fechadas;
  carta_t cartas[52];
} pilha_t;

void abre_carta_topo(pilha_t *pilha);

int main() 
{
 pilha_t pilha1 = {2, {4, ouro}, {5, copas}};
 pilha_t pilha2 = {0};

 empilha_varias_cartas(2, &pilha2, &pilha1);

 printf("%d\n", pilha2.n_cartas);
}

void abre_carta_topo(pilha_t *pilha)
{
  if(pilha->n_cartas == pilha->n_cartas_fechadas) {
    pilha->n_cartas_fechadas--;
  }
}


