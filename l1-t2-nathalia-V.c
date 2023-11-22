// l123b - t2 - partes II e III
// programa para digitar letras aleatórias dentro de um limite de tempo
// Nathália Oliveira de Almeida
// * 2023-xx-xx

/// Você só pode alterar o nome e data acima, e os locais marcados,
///   no final do arquivo.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "tecla.h"
#include "tela.h"

// definições de constantes
// número de palavras do banco de palavras
#define TAM_BANCO 920
// quantas palavras gerar
#define NUM_PALAVRAS 10
// tamanho máximo de uma palavra
#define NUM_LETRAS 16
// quantos segundos para digitar
#define TEMPO 180

// seleciona uma palavra na matriz, ou retorna -1
int seleciona_palavra(int t, char v[t][t], char letra);
// imprime a palavra selecionada no fim da matriz
void imprime_palavra(int p, int t, char v[t][t]);
// exclui a palavra caso o jogador tenha acertado todas as letras
void exclui_palavra(int posicao, char palavras[][NUM_LETRAS], int n_palavras);
// remove o dado na posição p de v[p][i], deslocando os v[<i]
void remove_letra(int p, int t, char v[t][t], char letra);

// funções auxiliares
// apresenta o programa
void apresentacao();
// encerra o programa
void encerramento();
// executa uma partida
void jogo();
// verifica a vontade do jogador
bool quer_jogar_de_novo();
// limpa a linha de entrada
void espera_enter();
// lê um arquivo .txt e gera uma matriz de palavras
void cria_banco_de_palavras();
// preenche uma matriz com palavras do banco de palavras
void preenche_matriz(char banco_palavras[TAM_BANCO][NUM_LETRAS], int l, int c, char v[l][c]);
// mostra o vetor de números
void imprime_matriz(int palavra, int l, int c, char v[l][c]);
// gera uma letra/valor aleatório
int aleatorio(int min, int max);
// verifica se uma palavra contém acentuação
bool tem_acento(int tam, char v[tam]);
// desenha a tela
void desenha_tela(char matriz[NUM_PALAVRAS][NUM_LETRAS], int palavra_selecionada, int palavras_acertadas, double tempo_restante);
// processa entrada
void processa_entrada(char matriz[NUM_PALAVRAS][NUM_LETRAS], int *palavra_selecionada, int *palavras_acertadas);

int main()
{
  tecla_ini();

  // inicializa o gerador de números aleatórios
  srand(time(0));

  apresentacao();

  do {
    jogo();
  } while(quer_jogar_de_novo());

  encerramento();

  tecla_fim();
  tela_fim();
}

void jogo()
{
  // inicializa variáveis
  int num_palavras = NUM_PALAVRAS;
  int num_letras = NUM_LETRAS;
  char banco_de_palavras[TAM_BANCO][NUM_LETRAS];
  char palavras[] = "palavras.txt";
  char matriz_palavras[num_palavras][num_letras];
  int palavra_selecionada = -1;
  int palavras_acertadas = 0;

  // inicializa banco de palavras
  cria_banco_de_palavras(palavras, banco_de_palavras);
  
  preenche_matriz(banco_de_palavras, num_palavras, num_letras, matriz_palavras);
  
  // inicializa timer
  double t0 = tela_relogio();
  double tempo_restante = TEMPO - (tela_relogio() - t0);

  desenha_tela(matriz_palavras, palavra_selecionada, palavras_acertadas, tempo_restante);
  processa_entrada(matriz_palavras, &palavra_selecionada, &palavras_acertadas);

}

void espera_enter()
{
  while (getchar() != '\n') {
    ; /* não faz nada */
  }
}

void apresentacao()
{
  printf("Você deve digitar as letras que aparecerão na tela.\n");
  printf("A ordem não é importante.\n");
  printf("Tecle <enter> para iniciar. ");
  
}

void encerramento()
{
  printf("Até a próxima.\n");
}

bool quer_jogar_de_novo()
{
  // limpa a entrada
  espera_enter();

  printf("Digite 's' para jogar de novo ");
  while (true) {
    char c = getchar();
    if (c == '\n') {
      return false;
    } else if (c == 's' || c == 'S') {
        espera_enter();
        return true;
    }
  }
}

int seleciona_palavra(int t, char v[][t], char letra)
{
  for (int i = 0; i < t; i++) {
    if (v[i][0] == letra) {
      return i;
    }
  }  
  return -1; 
}

void imprime_palavra(int p, int t, char v[t][t]) 
{
  for (int i = 0; i < t; i++) {
    if (v[p][i] == '\0') {
      printf("\n");
      break;
    } else {
        printf("%c ", v[p][i]);
      }
  }
}

void exclui_palavra(int posicao, char palavras[][NUM_LETRAS], int n_palavras)
{
  for (int i = posicao; i < n_palavras; i++) {
    strcpy(palavras[i], palavras[i+1]); 
  }
}

void remove_letra(int p, int t, char v[][t], char letra) 
{
  if (v[p][0] == letra) {
    for (int i = 0; i < t; i++) {
      v[p][i] = v[p][i+1]; 
    }
  } 
}

void preenche_matriz(char banco_palavras[TAM_BANCO][NUM_LETRAS], int l, int c, char v[l][c])
{
  int i = 0;
  int j = 0;
  int num_sorteado = aleatorio(0, 919);
  for (i = 0; i < l; i++) {
      while (tem_acento(num_sorteado, banco_palavras[num_sorteado])) {
        num_sorteado = aleatorio(0,919);
      }
      strcpy(v[i], banco_palavras[num_sorteado]);
      v[i][j] = banco_palavras[num_sorteado][j];
      num_sorteado = aleatorio(0, 919);
  } 
}

void imprime_matriz(int palavra, int l, int c, char v[l][c])
{
  printf("\n[");
  for (int i = 0; i < l; i++) {
    if(i == palavra) {
      continue;
    }
    for(int j = 0; j < c; j++) {
      printf("%c", v[i][j]);
    }
    if(i != l-1) {
      printf("\n");
    }
  }
  printf(" ]\n\n");
}

int aleatorio(int min, int max)
{
  int r = rand() % (max - min + 1);
  return r + min;
}

void cria_banco_de_palavras(char *arquivo, char banco_palavras[TAM_BANCO][NUM_LETRAS])
{
  FILE *banco = fopen(arquivo, "r");
  int contador_palavras = 0;

    if (banco == NULL) {
        printf("Erro ao abrir o arquivo");
    }
    while (contador_palavras < TAM_BANCO && fscanf(banco, "%s", banco_palavras[contador_palavras]) == 1) {
        contador_palavras++;
    }

    fclose(banco);
}

bool tem_acento(int tam, char v[tam])
{
 for (int i = 0; i < tam; i++) {
  if (v[i] < 0) {
    return true;
  } 
 } 
 return false;
}

void desenha_tela(char matriz[NUM_PALAVRAS][NUM_LETRAS], int palavra_selecionada, int palavras_acertadas, double tempo_restante)
{
  tela_limpa();
  int lin = tela_nlin() / 2 - 1;
  int col = tela_ncol() / 2 - 26 / 2;

  printf("Digite uma palavra:\n");

  tela_cor_normal();
  tela_cor_letra(150, 80, 50);
  
  if (palavra_selecionada >= 0) {
    imprime_palavra(palavra_selecionada, NUM_LETRAS, matriz);
  }
  
  imprime_matriz(palavra_selecionada, NUM_PALAVRAS, NUM_LETRAS, matriz);

  tela_lincol(lin + 2, col);
  tela_cor_normal();
  printf("Faltam %d palavras, ", NUM_PALAVRAS - palavras_acertadas);
  if (tempo_restante < 5) {
    tela_cor_letra(200, 0, 0);
  }
  printf("%.1f", tempo_restante);
  tela_cor_normal();
  printf(" segundos");

  if (palavras_acertadas == NUM_PALAVRAS) { 
      printf("Parabéns, você acertou todas, e sobraram %f segundos!\n", tempo_restante); 
  }

  tela_atualiza();
}

void processa_entrada(char matriz[NUM_PALAVRAS][NUM_LETRAS], int *palavra_selecionada, int *palavras_acertadas)
{
  char c = tecla_le_char();
  int acertos = 0;
  int palavra;
  // se não foi digitado nada, não tem o que fazer
  if (c == '\0') return;
  // CONSERTAR ESSAS COISAS AQUI
  while (*palavra_selecionada < 0) {
    *palavra_selecionada = seleciona_palavra(NUM_PALAVRAS, matriz, c);
  }

  char proxima_letra = matriz[*palavra_selecionada][acertos];

  remove_letra(*palavra_selecionada, NUM_LETRAS, matriz, c);

  if (matriz[palavra][0] == '\0') {
    exclui_palavra(*palavra_selecionada, matriz, NUM_PALAVRAS);
    *palavra_selecionada = -1;
    *palavras_acertadas++;
  } 
}