// RETIRA A CARTA DO TOPO
#include <stdio.h>
#include <assert.h>

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

carta_t retira_carta_topo(pilha_t *pilha);


int main() 
{
  pilha_t pilha1 = {0};
  carta_t carta1 = {as, ouro};

  retira_carta_topo(&pilha1);

  printf("A pilha tem %d carta(s)\n", pilha1.n_cartas);

}

carta_t retira_carta_topo(pilha_t *pilha) 
{
  // carta_t carta = retorna_carta_topo(pilha);
  pilha->n_cartas--;
  // return carta;
}

