// CRIA UMA CARTA

// RETORNA UMA CARTA EM UMA POSIÇÃO QUALQUER DA PILHA

// FUNÇÃO QUE PREENCHE UM VETOR COM A DESCRIÇÃO DA CARTA

#include <stdio.h>
#include <string.h>
#include <assert.h>
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

carta_t cria_carta(valor_t valor, naipe_t naipe);

int main() 
{
carta_t carta = cria_carta(valete, copas);

printf("%d\n", carta.valor);
}

carta_t cria_carta(valor_t valor, naipe_t naipe)
{
  carta_t carta = {valor, naipe};

  return carta;
}
