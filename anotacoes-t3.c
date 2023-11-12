#include <stdbool.h>
#include <stdio.h>
#include "tela.h"

// 0, 2= vermelhos
// 1, 3 = pretos
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

cor_t cor(carta_t c) 
{
  if (c.naipe == ouro || c.naipe == copas) return vermelho;
  return preto;
}

bool pode_empilhar(carta_t c, pilha_t p)
{
  if (p.n_cartas == 0) {
    return c.valor == rei;
  } else {
    carta_t topo = p.cartas[p.n_cartas - 1];
    if (cor(c) == cor(topo)) return false;
    return c.valor == topo.valor -1;
  }
}

int main() 
{
 pilha_t pilha = { 1, {{valete, ouro}}};
 carta_t c1 = { 10, espadas };
 carta_t c2 = { as, paus };
 if (!pode_empilhar(c1, pilha)) printf("Deveria poder empilhar c1\n");
 if (pode_empilhar(c2, pilha)) printf("Não deveria poder empilhar c2\n");

}

// função empilhar (coloca na próxima posição livre; incrementa n_cartas)
// função desempilhar (tira da última posição, decrementa n_cartas)
// função embaralhar
// função empilhar 

/*
  void desenha(carta_t c) 
  {
    tela_cor_fundo()
    if (cor(c) == vermelho) tela_cor_letra(200, 0, 0);
    else tela_cor_letra(0, 0, 0);
    switch (c.valor) {
      case as:     putchar('A'); break;
      case valete: putchar('J'); break;
      case dama:   putchar('Q'); break;
      case rei:    putchar('K'); break;
      default:     printf("%d", c.valor);
    }
    switch (c.naipe) {
      case copas: printf(""); break;
      case ouro:  printf(""); break;
      case paus:  printf(""); break;
    }
    tela_cor_normal();
  }
*/

// #define ouro 0
// #define copas 1

/*
typedef
enum {
    as = 1,
    valete = 11,
    dama,
    rei
} valor_t;
*/

// GERAR UM BARALHO EM ORDEM
// EMBARALHAR: SORTEIA DUAS POSIÇÕES ALEATÓRIAS E TROCA ESSAS POSIÇÕES
// REPETE VÁRIAS VEZES 