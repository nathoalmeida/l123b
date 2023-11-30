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

carta_t retorna_carta(pilha_t *pilha, int pos, bool *esta_aberta);

int main() 
{
 carta_t carta = {as, copas};
 carta_t carta2 =  {8, espadas};
 carta_t carta3 = { valete, ouro};

 pilha_t pilha = {3, 2, {carta, carta2, carta3}};
 bool esta_aberta;
 
 carta_t carta4 = retorna_carta(&pilha, 0, &esta_aberta); 

 printf("%d\n", carta4.valor);
}

carta_t retorna_carta(pilha_t *pilha, int pos, bool *esta_aberta)
{
  esta_aberta = (pos < pilha->n_cartas) && (pos >= pilha->n_cartas - pilha->n_cartas_fechadas);
  assert(!esta_aberta);
  
  return pilha->cartas[pos];
}
