// Programa de exemplo de uso de tela.h e tela.c e tecla.h e tecla.c
//
// Necessita os arquivos tela_exemplo.c (este), tela.h, tela.c, tecla.h, tecla.c
//
// para compilar este programa manualmente em linux:
// gcc -Wall -o desenhavazio desenhavazio.c tela.c tecla.c
//

#include "tela.h"
#include "tecla.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

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


void desenha_carta_aberta(int lin, int col, carta_t carta);

void descricao_carta(carta_t carta, char *tipo_carta);

cor_t cor(carta_t c);

// desenha a borda de um retângulo
void borda_retangulo(int li, int ci, int nl, int nc)
{
  int lin = li;
  int col = ci;
  tela_lincol(lin, col);
  printf("\u256d");
  for (int i = 0; i < nc - 2; i++) {
    printf("\u2500");
  }
  printf("\u256e");
  lin++;
  while (lin < li + nl - 1) {
    tela_lincol(lin, ci);
    printf("\u2502");
    tela_lincol(lin, ci + nc - 1);
    printf("\u2502");
    lin++;
  }
  tela_lincol(lin, col);
  printf("\u2570");
  for (int i = 0; i < nc - 2; i++) {
    printf("\u2500");
  }
  printf("\u256f");
}

// preenche um retângulo com os caracteres em s
void retangulo(int li, int ci, int nl, int nc, char *s)
{
  for (int lin = li; lin < li + nl; lin++) {
    tela_lincol(lin, ci);
    for (int col = ci; col < ci + nc; col++) {
      printf("%s", s);
    }
  }
}

// retorna o número de colunas usadas para imprimir a string
// é o tamanho da string menos os caracteres de continuação utf8
int nchar(char *s)
{
  // caracteres com código binário entre 0b10000000 e 0b10111111 são de
  // continuação em utf8
  char ci = 0b10000000;
  char cf = 0b10111111;
  int t = strlen(s);
  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] >= ci && s[i] <= cf) {
      t--;
    }
  }
  return t;
}

// desenha o texto em txt de forma que ele termine em lin, col
void texto_esq(int lin, int col, char *txt)
{
  int col_ini = col - nchar(txt) + 1;
  tela_lincol(lin, col_ini);
  printf("%s", txt);
}

// A função principal
int main(void)
{

  carta_t carta = { 10, copas};
  tela_ini();
  

  int lin = 4;
  int col = 4;


    tela_limpa();
    desenha_carta_aberta(lin, col, carta);
    printf("\n\n\n\n\n\n\n\n");

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
  // printf("%s\n", tipo_carta);
}

cor_t cor(carta_t c) 
{
  if (c.naipe == ouro || c.naipe == copas) return vermelho;
  return preto;
}

void desenha_carta_aberta(int lin, int col, carta_t carta)
{
  char descricao[10];
  int nl = 7;
  int nc = 8;

  borda_retangulo(lin, col, nl, nc);
  descricao_carta(carta, descricao);
  if (strlen(descricao) == 5) {
    texto_esq(lin+1, col+3, descricao);
  } else 
  {
    texto_esq(lin+1, col+2, descricao);
  }
}