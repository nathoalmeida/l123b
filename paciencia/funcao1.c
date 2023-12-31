// FUNÇÃO 1 - EMPILHA UMA CARTA EM UMA PILHA
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

void empilha_carta(carta_t carta, pilha_t *pilha);
int main() 
{
  pilha_t pilha1 = {0};
  carta_t carta1 = {as, ouro};

  empilha_carta(carta1, &pilha1);

  printf("A pilha tem %d carta(s)\n", pilha1.n_cartas);

}

void empilha_carta(carta_t carta, pilha_t *pilha)
{
  pilha->cartas[pilha->n_cartas] = carta;
  pilha->n_cartas++;
}