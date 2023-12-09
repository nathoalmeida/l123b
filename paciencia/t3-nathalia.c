// T3 - JOGO "PACIÊNCIA"
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "tela.h"
#include "tecla.h"

#define MAX_CHAR_CMD 2

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
  int coordenadas_monte[2][2];
  int coordenadas_saida[4][2];
  int coordenadas_principal[7][2];
  float pontos;
  char comando[MAX_CHAR_CMD + 1];
  bool ultimo_comando_ok;
} jogo_t;

// PARTE 1 - FUNÇÕES AUXILIARES
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
// fecha todas as cartas da pilha
void fecha_cartas_pilha(pilha_t *pilha);
// esvazia uma pilha
void esvazia_pilha(pilha_t *pilha);
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

// PARTE 2 - FUNÇÕES DE JOGO
// inicializa o jogo
void inicializa_jogo(jogo_t *jogo);
// retorna se uma carta pode ser movida para a pilha de saída
bool pode_mover_p_saida(jogo_t *jogo, int n_pilha, carta_t carta);
// retorna se uma carta pode ser movida para a pilha de jogo (principal)
bool pode_mover_p_principal(jogo_t *jogo, int n_pilha, carta_t carta);
// verifica se pode mover "n" cartas de uma pilha
bool pode_mover_n_cartas(jogo_t *jogo, int n_pilha, int n_cartas_movidas);
// verifica se o jogador ganhou
bool jogador_ganhou(jogo_t *jogo);

// PARTE 3 - JOGADAS
// abre uma carta do monte
bool abre_carta_monte(jogo_t *jogo);
// recicla o descarte
bool recicla_descarte(jogo_t *jogo);
// move uma carta do descarte para a saída
bool move_descarte_para_saida(jogo_t *jogo, int n_pilha);
// move uma carta do descarte para uma pilha principal
bool move_descarte_para_principal(jogo_t *jogo, int n_pilha);
// move uma carta da pilha de jogo para uma pilha de saída
bool move_principal_para_saida(jogo_t *jogo, int n_pilha_principal, int n_pilha_saida);
// move uma carta da pilha de saída para a pilha de jogo
bool move_saida_para_principal(jogo_t *jogo, int n_pilha_saida, int n_pilha_principal);
// move "N" cartas de uma pilha principal para outra pilha principal (auxiliar)
bool move_varias_cartas_aux(jogo_t *jogo, int n_pilha_origem, int n_pilha_destino, int n_cartas_movidas);
// move "N" cartas de uma pilha principal para outra pilha principal
bool move_varias_cartas(jogo_t *jogo, int n_pilha_origem, int n_pilha_destino);
// recebe uma string e seleciona uma função que realiza uma jogada
bool faz_uma_jogada(jogo_t *jogo, char *jogada);
// retorna o caso da primeira string para fazer uma jogada
int faz_uma_jogada_aux(jogo_t *jogo, char *jogada);

// PARTE 4.1 - FUNÇÕES AUXILIARES DE DESENHO
// desenha a borda de um local vazio ou carta
void borda_retangulo(int li, int ci, int nl, int nc);
// preenche o retângulo com caracteres
void retangulo(int li, int ci, int nl, int nc, char *s);
// desenha o texto dentro de uma carta
void texto_esq(int lin, int col, char *txt);
// retorna o número de colunas para imprimir uma string
int nchar(char *s);

// PARTE 4.2 - DESENHO DE CARTAS
void desenha_carta_fechada(int lin, int col);
void desenha_carta_aberta(int lin, int col, carta_t carta);
void desenha_local(int lin, int col);
void desenha_pilha_fechada(int lin, int col, pilha_t *pilha);
void desenha_pilha_aberta(int lin, int col, pilha_t *pilha);

// PARTE 6 - DESENHOS DE TELA
// inicializa as posições de cada pilha
void inicializa_coordenadas(jogo_t *jogo);
// desenho inicial das pilhas
void inicializa_desenho_pilhas(jogo_t *jogo);
// desenho auxiliar das pilhas (muda o desenho se a pilha está vazia, fechada ou aberta)
void desenho_pilhas_aux(jogo_t *jogo, pilha_t *pilha, int lin, int col);
// desenhos extras
void desenho_extra(jogo_t *jogo);
// faz o desenho total da tela
void desenha_tela(jogo_t *jogo);

// PARTE 7 - PROCESSAMENTO DE ENTRADA
void processa_entrada_pelo_teclado(jogo_t *jogo);

int main() 
{
  srand(time(0));
  jogo_t jogo;
  inicializa_jogo(&jogo);

  tela_ini();

  while(!jogador_ganhou(&jogo)) {
    tela_limpa();

    desenha_tela(&jogo);
    processa_entrada_pelo_teclado(&jogo);

    tela_atualiza();
  }

   tela_fim();
   tecla_fim(); 

}
  

void gera_baralho(pilha_t *baralho)
{
  int cont = 0;

  for (int i = ouro; i <= paus; i++) {
    for (int j = as; j <= rei; j++) {
      carta_t carta = { j, i };
      baralho->cartas[cont] = carta;
      cont++;
      baralho->n_cartas++;
    }
  }
}

void embaralha_cartas(pilha_t *baralho) 
{
  
  carta_t reserva;
  int pos1;
  int pos2;
  for (int i = 0; i < 450; i++)
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
  return p->n_cartas == 0;
}

bool esta_cheia(pilha_t *p)
{
  return p->n_cartas == 52;
}

void empilha_carta(carta_t carta, pilha_t *pilha)
{
 // if (esta_vazia(pilha) /*|| pilha->n_cartas != pilha->n_cartas_fechadas */) {
    pilha->cartas[pilha->n_cartas] = carta;
    pilha->n_cartas++;
 /* } else {
      pilha->cartas[pilha->n_cartas] = carta;
      pilha->n_cartas++;
      pilha->n_cartas_fechadas++;
    } */
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

void fecha_cartas_pilha(pilha_t *pilha)
{
  pilha->n_cartas_fechadas = pilha->n_cartas;
}

void esvazia_pilha(pilha_t *pilha)
{
  pilha->n_cartas = 0;
  pilha->n_cartas_fechadas = 0;
}

void empilha_varias_cartas(int num_cartas_movidas, pilha_t *destino, pilha_t *origem) 
{
  assert(destino->n_cartas + num_cartas_movidas <= 52);
  assert(origem->n_cartas >= num_cartas_movidas);

  for (int i = 0; i < num_cartas_movidas; i++) {
      empilha_carta(origem->cartas[origem->n_cartas - i - 1], destino);
    }

  // destino->n_cartas = destino->n_cartas + num_cartas_movidas;
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
  if (pos < pilha->n_cartas && pos >= pilha->n_cartas - pilha->n_cartas_fechadas) {
    *esta_aberta = true;
  } else {
    *esta_aberta = false;
  }
  
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
  { 
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

bool sao_iguais(carta_t uma_carta, carta_t outra_carta)
{
  return (uma_carta.naipe == outra_carta.naipe) && (uma_carta.valor == outra_carta.valor);
}

int aleatorio(int min, int max)
{
  int r = rand() % (max - min + 1);
  return r + min;
}

void inicializa_jogo(jogo_t *jogo)
{
  esvazia_pilha(&jogo->monte);
  esvazia_pilha(&jogo->descarte);
  
    for (int i = 0; i < 7; i++) {
      esvazia_pilha(&jogo->pilha_principal[i]);
    }
    for (int i = 0; i < 4; i++) {
      esvazia_pilha(&jogo->pilha_saida[i]);
    }

  gera_baralho(&jogo->monte);
  embaralha_cartas(&jogo->monte);
  empilha_carta(jogo->monte.cartas[total_cartas_pilha(&jogo->monte) - 1], &jogo->pilha_principal[0]);
  empilha_varias_cartas(2, &jogo->pilha_principal[1], &jogo->monte);
  empilha_varias_cartas(7, &jogo->pilha_principal[6], &jogo->monte);
  fecha_cartas_pilha(&jogo->monte);
  fecha_cartas_pilha(&jogo->pilha_principal[0]);
  fecha_cartas_pilha(&jogo->pilha_principal[1]);
  fecha_cartas_pilha(&jogo->pilha_principal[6]);
  abre_carta_topo(&jogo->pilha_principal[0]);
  abre_carta_topo(&jogo->pilha_principal[1]);
  abre_carta_topo(&jogo->pilha_principal[6]); 
  jogo->pontos = 0;
}

bool pode_mover_p_saida(jogo_t *jogo, int n_pilha, carta_t carta)
{
  if(esta_vazia(&jogo->pilha_saida[n_pilha])) {
    return carta.valor == as;
  } else {
    return (carta.valor == retorna_carta_topo(&jogo->pilha_saida[n_pilha]).valor + 1) && (carta.naipe == retorna_carta_topo(&jogo->pilha_saida[n_pilha]).naipe);
  }
}

bool pode_mover_p_principal(jogo_t *jogo, int n_pilha, carta_t carta)
{
  if(esta_vazia(&jogo->pilha_principal[n_pilha])) {
    return carta.valor == rei;
  } else {
    return (cor(carta) != cor(retorna_carta_topo(&jogo->pilha_principal[n_pilha]))) && (carta.valor == retorna_carta_topo(&jogo->pilha_principal[n_pilha]).valor - 1);
  }
}

bool pode_mover_n_cartas(jogo_t *jogo, int n_pilha, int n_cartas_movidas)
{
  assert(n_cartas_movidas <= total_cartas_abertas(&jogo->pilha_principal[n_pilha]));

  int pos_cartas = total_cartas_pilha(&jogo->pilha_principal[n_pilha]) - n_cartas_movidas;
  bool todas_moviveis = true;

  for (int i = 0; i < n_cartas_movidas - 1; i++) {
    
    if ((cor(jogo->pilha_principal[n_pilha].cartas[pos_cartas + i]) != cor(jogo->pilha_principal[n_pilha].cartas[pos_cartas + i + 1])) 
    && (retorna_valor_carta(jogo->pilha_principal[n_pilha].cartas[pos_cartas + i]) == retorna_valor_carta(jogo->pilha_principal[n_pilha].cartas[pos_cartas + i + 1]) + 1)) {
      continue; 
    } else {
        todas_moviveis = false;
        break;
      }
}
  return todas_moviveis;
}

bool jogador_ganhou(jogo_t *jogo) 
{
  return total_cartas_pilha(&jogo->pilha_saida[0]) + total_cartas_pilha(&jogo->pilha_saida[1]) + 
  total_cartas_pilha(&jogo->pilha_saida[2]) + total_cartas_pilha(&jogo->pilha_saida[3]) == 52;
}

bool abre_carta_monte(jogo_t *jogo)
{
  if (!esta_vazia(&jogo->monte)) {
    empilha_carta(retira_carta_topo(&jogo->monte), &jogo->descarte);
    jogo->monte.n_cartas_fechadas--;
    return true;
  } else {
    return false;
  }
}

bool recicla_descarte(jogo_t *jogo)
{
  if (!esta_vazia(&jogo->descarte) && esta_vazia(&jogo->monte)) {
    int n_cartas = total_cartas_pilha(&jogo->descarte);

    for (int i = 0; i < n_cartas; i++) {
      empilha_carta(retira_carta_topo(&jogo->descarte), &jogo->monte);
    }

    fecha_cartas_pilha(&jogo->monte);
    jogo->pontos = 0;
    return true;
  } else {
    return false;
  }
}

bool move_descarte_para_saida(jogo_t *jogo, int n_pilha)
{
  assert(!esta_vazia(&jogo->descarte));

  if (pode_mover_p_saida(jogo, n_pilha, retorna_carta_topo(&jogo->descarte))) {
    empilha_carta(retira_carta_topo(&jogo->descarte), &jogo->pilha_saida[n_pilha]);
    jogo->pontos += 15;
    return true;
  } else return false;
}

bool move_descarte_para_principal(jogo_t *jogo, int n_pilha)
{
  assert(!esta_vazia(&jogo->descarte));

  if (pode_mover_p_principal(jogo, n_pilha, retorna_carta_topo(&jogo->descarte))) {
    empilha_carta(retira_carta_topo(&jogo->descarte), &jogo->pilha_principal[n_pilha]);
    jogo->pontos += 10;
    return true;
  } else return false;
}

bool move_principal_para_saida(jogo_t *jogo, int n_pilha_principal, int n_pilha_saida)
{
  assert(!esta_vazia(&jogo->pilha_principal[n_pilha_principal]));
  assert(!esta_cheia(&jogo->pilha_saida[n_pilha_saida]));

  if (pode_mover_p_saida(jogo, n_pilha_saida, retorna_carta_topo(&jogo->pilha_principal[n_pilha_principal]))) {
    empilha_carta(retira_carta_topo(&jogo->pilha_principal[n_pilha_principal]), &jogo->pilha_saida[n_pilha_saida]);
    jogo->pontos += 15;
    return true;
  } else return false;
}

bool move_saida_para_principal(jogo_t *jogo, int n_pilha_saida, int n_pilha_principal)
{
  assert(!esta_vazia(&jogo->pilha_saida[n_pilha_saida]));
  assert(!esta_cheia(&jogo->pilha_principal[n_pilha_principal]));

  if (pode_mover_p_principal(jogo, n_pilha_principal, retorna_carta_topo(&jogo->pilha_saida[n_pilha_saida]))) {
    empilha_carta(retira_carta_topo(&jogo->pilha_saida[n_pilha_saida]), &jogo->pilha_principal[n_pilha_principal]);
    jogo->pontos -= 15;
    return true;
  } else return false;
}

bool move_varias_cartas_aux(jogo_t *jogo, int n_pilha_origem, int n_pilha_destino, int n_cartas_movidas) {
  assert(total_cartas_pilha(&jogo->pilha_principal[n_pilha_destino]) + n_cartas_movidas <= 52);

  int pos_cartas = total_cartas_pilha(&jogo->pilha_principal[n_pilha_origem]) - n_cartas_movidas;
  for (int i = pos_cartas; i <= n_cartas_movidas; i++) {
    empilha_carta(jogo->pilha_principal[n_pilha_origem].cartas[i], &jogo->pilha_principal[n_pilha_destino]);
  }
  
 return true;
}

bool move_varias_cartas(jogo_t *jogo, int n_pilha_origem, int n_pilha_destino)
{
  int n_cartas = 0;
  int pos_cartas = total_cartas_pilha(&jogo->pilha_principal[n_pilha_origem]) - total_cartas_abertas(&jogo->pilha_principal[n_pilha_origem]);
  bool moveu_cartas = false;

  for (int i = pos_cartas; i < total_cartas_pilha(&jogo->pilha_principal[n_pilha_origem]); i++) {
    if (pode_mover_p_principal(jogo, n_pilha_destino, jogo->pilha_principal[n_pilha_origem].cartas[i])) {
        n_cartas = total_cartas_pilha(&jogo->pilha_principal[n_pilha_origem]) - i;
        
        if(pode_mover_n_cartas(jogo, n_pilha_origem, n_cartas)) {
          moveu_cartas = move_varias_cartas_aux(jogo, n_pilha_origem, n_pilha_destino, n_cartas);
          break;
        }
    } else {
        continue;
    }
  }
  
  return moveu_cartas;
}

bool faz_uma_jogada(jogo_t *jogo, char *jogada)
{
  int num_jogada = faz_uma_jogada_aux(jogo, jogada);

  switch (num_jogada)
  {
  case -1: return false; 
    break;
  case 0: 
    if (jogada[1] == 'p' || jogada[1] == '\0') {
        return abre_carta_monte(jogo);
    } else return false;
      break;
  case 1:
    if (jogada[1] == 'm' || jogada[1] == '\0') {
      return recicla_descarte(jogo);
    } else if (jogada[1] >= 'a' && jogada[1] <= 'd') {
        return move_descarte_para_saida(jogo, jogada[1] - 'a');
    } else if (jogada[1] >= '1' && jogada[1] <= '7') {
        return move_descarte_para_principal(jogo, jogada[1] - '1'); 
    } else return false;
    break;
  case 2: 
    if (jogada[1] >= 'a' && jogada[1] <= 'd') {
      return move_principal_para_saida(jogo, jogada[0] - '1', jogada[1] - 'a');
    } else if (jogada[1] >= '1' && jogada[1] <= '7') {
      return move_varias_cartas(jogo, jogada[0] - '1', jogada[1] - '1');
    } else return false;
    break;
  case 3:
    if (jogada[1] >= '1' && jogada[1] <= '7') {
      return move_saida_para_principal(jogo, jogada[0] - 'a', jogada[1] - '1');
    } else return false;
    break;
  default: return false;
    break;
  }

  return true;
}

int faz_uma_jogada_aux(jogo_t *jogo, char *jogada)
{
  int num_jogada;
  
  if (jogada[0] == 'm') {
    num_jogada = 0;
  } else if (jogada[0] == 'p') {
    num_jogada = 1;
  } else if (jogada[0] >= '1' && jogada[0] <= '7') {
    num_jogada = 2;
  } else if (jogada[0] >= 'a' && jogada[0] <= 'd') {
    num_jogada = 3;
  } else {
    num_jogada = -1;
  }

  return num_jogada;
}

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

void retangulo(int li, int ci, int nl, int nc, char *s)
{
  for (int lin = li; lin < li + nl; lin++) {
    tela_lincol(lin, ci);
    for (int col = ci; col < ci + nc; col++) {
      printf("%s", s);
    }
  }
}

void texto_esq(int lin, int col, char *txt)
{
  int col_ini = col - nchar(txt) + 1;
  tela_lincol(lin, col_ini);
  printf("%s", txt);
}

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

void desenha_carta_fechada(int lin, int col)
{
  int nl = 7;
  int nc = 8;

  borda_retangulo(lin, col, nl, nc);
  retangulo(lin + 1, col + 1, nl-2, nc-2, "\u2573");
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
    tela_cor_normal();
    retangulo(lin + 1, col + 4, nl-7, nc-1, " ");
  } else {
    texto_esq(lin+1, col+2, descricao);
    tela_cor_normal();
    retangulo(lin + 1, col + 3, nl-2, nc-4, " ");
  }
  retangulo(lin + 2, col+1, nl-3, nc-2, " ");
  
}

void desenha_local(int lin, int col) 
{
  int nl = 7;
  int nc = 8;

  borda_retangulo(lin, col, nl, nc);
  retangulo(lin + 1, col + 1, nl-2, nc-2, " ");
}

void desenha_pilha_fechada(int lin, int col, pilha_t *pilha)
{
  if (esta_vazia(pilha)) {
    desenha_local(lin, col);
  } else if (pilha->n_cartas == pilha->n_cartas_fechadas) {
      desenha_carta_fechada(lin, col);
  } else {
      desenha_carta_aberta(lin, col, retorna_carta_topo(pilha));
  }
}

void desenha_pilha_aberta(int lin, int col, pilha_t *pilha)
{
  bool esta_aberta;
  int pos_carta = 0;

  for (int i = 0; i < total_cartas_pilha(pilha); i++) {
    if(i >= total_cartas_fechadas(pilha)) {
      desenha_carta_aberta(lin+pos_carta, col, retorna_carta(pilha, i, &esta_aberta));
    } else {
        desenha_carta_fechada(lin+pos_carta, col);
      }
    pos_carta += 2;
  }
}

void inicializa_coordenadas(jogo_t *jogo) {
  int saida = 35;
  int principal = 5;
  for (int i = 0; i < 2; i++) {
    jogo->coordenadas_monte[0][i] = 5;
  }

  for (int i = 0; i < 2; i++) {
    if (i == 0) {
      jogo->coordenadas_monte[1][i] = 5;
    } else {
      jogo->coordenadas_monte[1][i] = 16;
    }
  }

  for (int i = 0; i < 4; i++) {
    jogo->coordenadas_saida[i][0] = 5;
  }

  for (int i = 0; i < 4; i++) {
    jogo->coordenadas_saida[i][1] = saida;
    saida += 10;
  }

  for (int i = 0; i < 7; i++) {
    jogo->coordenadas_principal[i][0] = 16;
  }

  for (int i = 0; i < 7; i++) {
    jogo->coordenadas_principal[i][1] = principal;
    principal += 10;
  }
}

void inicializa_desenho_pilhas(jogo_t *jogo)
{
  // desenha monte
  desenho_pilhas_aux(jogo, &jogo->monte, jogo->coordenadas_monte[0][0], jogo->coordenadas_monte[0][0]);
  //desenha_pilha_fechada(jogo->coordenadas_monte[0][0], jogo->coordenadas_monte[0][0], &jogo->monte);
  // desenha descarte
  desenho_pilhas_aux(jogo, &jogo->descarte, jogo->coordenadas_monte[1][0], jogo->coordenadas_monte[1][1]);
  
  // desenha pilhas de saida
  for (int i = 0; i < 4; i++) {
    desenho_pilhas_aux(jogo, &jogo->pilha_saida[i], jogo->coordenadas_saida[i][0], jogo->coordenadas_saida[i][1]);
  }
  
  // desenha pilhas de jogo
  for (int i = 0; i < 7; i++) {
    desenho_pilhas_aux(jogo, &jogo->pilha_principal[i], jogo->coordenadas_principal[i][0], jogo->coordenadas_principal[i][1]);
  }
}

void desenho_pilhas_aux(jogo_t *jogo, pilha_t *pilha, int lin, int col) {
  if (esta_vazia(pilha)) {
    desenha_local(lin, col);
  } else if (!(esta_vazia(pilha)) && pilha->n_cartas == pilha->n_cartas_fechadas) {
      desenha_pilha_fechada(lin, col, pilha);
  } else {
      desenha_pilha_aberta(lin, col, pilha);
  }
}

void desenho_extra(jogo_t *jogo)
{
  char aviso[30];
  tela_lincol(45, 5);
  bool jogada_concluida = jogo->ultimo_comando_ok;
  sprintf(aviso, "%s", "faça uma jogada");

  if(jogada_concluida) {
    sprintf(aviso, "%s", "\u2705  jogada realizada");
  } else {
    sprintf(aviso, "%s", "\u274c  jogada inválida");
  }

  printf("%s", aviso); 

  tela_lincol(45, 50);
  printf("PONTOS: %f", jogo->pontos);
}

void processa_entrada_pelo_teclado(jogo_t *jogo)
{
  char tecla;

  tecla = tecla_le_char(); // ou tela_tecla();
  if (tecla == '\0') return;

  int nchar = strlen(jogo->comando);

  switch (tecla) {
    case '\b':
      if (nchar > 0) {
        jogo->comando[--nchar] = '\0';
      }
      break;
    case '\n':
      if (nchar > 0) {
        jogo->ultimo_comando_ok = faz_uma_jogada(jogo, jogo->comando);
        jogo->comando[0] = '\0';
      }
      break;
    default:
      if (nchar < MAX_CHAR_CMD) {
        jogo->comando[nchar++] = tecla;
        jogo->comando[nchar] = '\0';
      }
      break;
  }
}

void desenha_tela(jogo_t *jogo) {
  inicializa_coordenadas(jogo);
  inicializa_desenho_pilhas(jogo);
  desenho_extra(jogo);
  tela_atualiza();
}