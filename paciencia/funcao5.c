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

void empilha_varias_cartas(pilha_t *destino, pilha_t *origem);

int main() 
{
 pilha_t pilha1 = {2, {4, ouro}, {5, copas}};
 pilha_t pilha2 = {0};


}

void empilha_varias_cartas(pilha_t *destino, pilha_t *origem)
{
  for (int i = destino->n_cartas; i < destino->n_cartas )
}