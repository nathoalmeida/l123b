// DESENHA UMA CARTA ABERTA
#include <stdio.h>
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

void descricao_carta(carta_t carta, char *tipo_carta);

cor_t cor(carta_t c);

void desenha_carta_aberta(carta_t carta, int linha, int coluna);

int main()
{
  carta_t carta = { valete, ouro};
  tela_limpa();
  desenha_carta_aberta(carta, 10, 10);
  
}

void desenha_carta_aberta(carta_t carta, int linha, int coluna) 
{
  char tipo_carta[10];
  tela_lincol(linha, coluna);
  printf("\u250F");
  for(int i = 0; i < 5; i++) {
    printf("\u2501");
  }
  printf("\u2513\n");
  printf("\u2503");
  descricao_carta(carta, tipo_carta);
  tela_cor_normal();
  printf("   \u2503\n");
  for(int i = 0; i < 2; i++) {
    printf("\u2503     \u2503\n");
  }
  printf("\u2503   ");
  descricao_carta(carta, tipo_carta);
  tela_cor_normal();
  printf("\u2503\n");
  printf("\u2517");
  for(int i = 0; i < 5; i++) {
    printf("\u2501");
  }
  printf("\u251B\n");
}

void descricao_carta(carta_t carta, char *tipo_carta)
{
  switch (carta.valor)
  { // transforma em srtcat no vetor;
    case as:     sprintf(tipo_carta, "%c", 'A'); break;
    case valete: sprintf(tipo_carta, "%c", 'J'); break;
    case dama:   sprintf(tipo_carta, "%c", 'Q'); break;
    case rei:    sprintf(tipo_carta, "%c", 'K'); break;
    default:     sprintf(tipo_carta, "%d", carta.valor); break;
  }

  switch (carta.naipe) {
    
    case copas:   strcat(tipo_carta, "\u2665"); break;
    case ouro:    strcat(tipo_carta, "\u2666"); break;
    case paus:    strcat(tipo_carta, "\u2663"); break;
    case espadas: strcat(tipo_carta, "\u2660"); break;
  }

  if (cor(carta) == vermelho) tela_cor_letra(200,0,0);
  else tela_cor_letra(0,0,0);
  printf("%s", tipo_carta);
}

cor_t cor(carta_t c) 
{
  if (c.naipe == ouro || c.naipe == copas) return vermelho;
  return preto;
}