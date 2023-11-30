// 12 pilhas
// 1 baralho - 52 cartas

// pilha - vetor de cartas
// as cartas na pilha podem estar fechadas ou abertas
// EMBARALHAR: sorteia dois números aleatórios várias vezes e troca as posições
// A JOGADA É FEITA POR DUAS LETRAS: M P A B C D 1 2 3 4 5 6 7 

// ASSERT = TESTA UMA FUNÇÃO E RETORNA ERRO


#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdbool.h>
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

typedef struct 
{
  pilha_t monte;
  pilha_t descarte;
  pilha_t pilha_saida[4];
  pilha_t pilha_principal[7];
} jogo_t;


// cria um baralho completo
void gera_baralho(pilha_t *baralho);
// embaralha as cartas
void embaralha_cartas(pilha_t *baralho);
// retorna se uma pilha está vazia
bool esta_vazia(pilha_t *p);
// retorna se uma pilha está cheia
bool esta_cheia(pilha_t *p);
// coloca uma carta no topo da pilha
void empilha_carta(carta_t carta, pilha_t *pilha);
// retorna a carta que está no topo da pilha
carta_t retorna_carta_topo(pilha_t *pilha);
// retira a carta que está no topo da pilha
carta_t retira_carta_topo(pilha_t *pilha);
// empilha várias cartas no topo da pilha
void empilha_varias_cartas(int num_cartas, pilha_t *destino, pilha_t *origem);
// abre a carta do topo da pilha
void abre_carta_topo(pilha_t *pilha);
// retorna o total de cartas da pilha
int total_cartas_pilha(pilha_t *pilha);
// retorna o número de cartas fechadas da pilha
int total_cartas_fechadas(pilha_t *pilha);
// retorna o número de cartas abertas da pilha
int total_cartas_abertas(pilha_t *pilha);
// retorna uma carta aberta da pilha
carta_t retorna_carta(pilha_t *pilha, int pos, bool *esta_aberta);
// cria uma carta
carta_t cria_carta(valor_t valor, naipe_t naipe);
// retorna o naipe de uma carta
naipe_t retorna_naipe_carta(carta_t cria_carta);
// retorna o valor de uma carta
valor_t retorna_valor_carta(carta_t carta);
// retorna a cor da carta
cor_t cor(carta_t carta);
// imprime o valor e o naipe da carta
void descricao_carta(carta_t carta, char *tipo_carta);
// compara duas cartas e retorna se são iguais
bool sao_iguais(carta_t uma_carta, carta_t outra_carta);
// gera um valor aleatório
int aleatorio(int min, int max);

int main() 
{
  int r = srand(time(0));
  pilha_t baralho;
  gera_baralho(&baralho);

  printf("valor: %d  naipe: %d\n", baralho.cartas[14].valor, baralho.cartas[14].naipe);

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

bool esta_vazia(pilha_t *p)
{
  p->n_cartas == 0;
}

bool esta_cheia(pilha_t *p)
{
  p->n_cartas == 52;
}

void empilha_carta(carta_t carta, pilha_t *pilha)
{
  if (esta_vazia(pilha) || pilha->n_cartas != pilha->n_cartas_fechadas) {
    pilha->cartas[pilha->n_cartas] = carta;
    pilha->n_cartas++;
  } else {
      pilha->cartas[pilha->n_cartas] = carta;
      pilha->n_cartas_fechadas++;
    }
}

carta_t retorna_carta_topo(pilha_t *pilha)
{
  return pilha->cartas[pilha->n_cartas - 1];
}

carta_t retira_carta_topo(pilha_t *pilha) 
{
  carta_t carta = retorna_carta_topo(pilha);
  pilha->n_cartas--;
  return carta;
}

void empilha_varias_cartas(int num_cartas_movidas, pilha_t *destino, pilha_t *origem) 
{
  // INCLUIR UM ASSERT PARA VER SE EXISTEM CARTAS SUFICIENTES NA PILHA DE ORIGEM E SE TEM ESPAÇO NA PILHA DE DESTINO
    for (int i = 0; i < num_cartas_movidas; i++) {
      empilha_carta(origem->cartas[origem->n_cartas + i], destino);
    }

  destino->n_cartas = destino->n_cartas + num_cartas_movidas;
  origem->n_cartas = origem->n_cartas - num_cartas_movidas;
}

void abre_carta_topo(pilha_t *pilha)
{
  if(pilha->n_cartas == pilha->n_cartas_fechadas) {
    pilha->n_cartas_fechadas--;
  }
}

int total_cartas_pilha(pilha_t *pilha)
{
  return pilha->n_cartas;
}

int total_cartas_fechadas(pilha_t *pilha)
{
  return pilha->n_cartas_fechadas;
}

int total_cartas_abertas(pilha_t *pilha)
{
  return pilha->n_cartas - pilha->n_cartas_fechadas;
}

carta_t retorna_carta(pilha_t *pilha, int pos, bool *esta_aberta)
{
  esta_aberta = pos < pilha->n_cartas && pos >= (pilha->n_cartas - pilha->n_cartas_fechadas);
  assert(!esta_aberta);
  
  return pilha->cartas[pos];
}

naipe_t retorna_naipe_carta(carta_t carta)
{
  return carta.naipe;
}

valor_t retorna_valor_carta(carta_t carta)
{
  return carta.valor;
}

cor_t cor(carta_t carta) 
{
  if (carta.naipe == ouro || carta.naipe == copas) return vermelho;
  return preto;
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
  printf("%s\n", tipo_carta);
}

bool sao_iguais(carta_t uma_carta, carta_t outra_carta)
{
  return (uma_carta.naipe == outra_carta.naipe) && (uma_carta.valor == outra_carta.valor);
}

int aleatorio(int min, int max)
{
  int r = rand() % (max - min + 1);
  return r + min;
}