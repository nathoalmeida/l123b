// EMBARALHA AS CARTAS

#include <stdio.h>
#include <time.h>
#include <string.h>
#include "tela.h"

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

void gera_baralho(pilha_t *baralho);

void embaralha_cartas(pilha_t *baralho);

int aleatorio(int min, int max);

int main()
{
  srand(time(0));
  pilha_t baralho;
  gera_baralho(&baralho);
  embaralha_cartas(&baralho);
  
  
  int pos1 = aleatorio(0,51);
  int pos2 = aleatorio(0,51);

  for (int i = 0; i < 52; i++) {
    printf("%d ", baralho.cartas[i].naipe);
    printf("%d\n", baralho.cartas[i].valor);
  }
}

void gera_baralho(pilha_t *baralho)
{
  int cont = 0;

  for (int i = ouro; i <= paus; i++) {
    for (int j = as; j <= rei; j++) {
      carta_t carta = { j, i };
      baralho->cartas[cont] = carta;
      cont++;
    }
  }
}

void embaralha_cartas(pilha_t *baralho) 
{
  
  carta_t reserva;
  int pos1;
  int pos2;
  for (int i = 0; i < 300; i++)
  {
    pos1 = aleatorio(0,51);
    pos2 = aleatorio(0,51);

    reserva = baralho->cartas[pos1];
    baralho->cartas[pos1] = baralho->cartas[pos2];
    baralho->cartas[pos2] = reserva;
  }
}

int aleatorio(int min, int max)
{
  int r = rand() % (max - min + 1);
  return r + min;
}