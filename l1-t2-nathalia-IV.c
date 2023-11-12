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
  long t0 = time(0);

  while (true) {
    int resta = TEMPO - (time(0) - t0);
    if (resta <= 0) {
      printf("Tempo esgotado\n");
      break;
    }

    if (palavras_acertadas == NUM_PALAVRAS) { 
      printf("Parabéns, você acertou todas, e sobraram %d segundos!\n", resta); 
      break;
    }

    imprime_matriz(palavra_selecionada, num_palavras, num_letras, matriz_palavras); 

    if (palavra_selecionada >= 0) {
      imprime_palavra(palavra_selecionada, num_letras, matriz_palavras);
    }

    printf("você tem %d segundos\n", resta);
    printf("digite uma das letras");
    char letra;
    letra = tecla_le_char();

    if (letra != '\0') {
      if (palavra_selecionada < 0) {
        palavra_selecionada = seleciona_palavra(num_letras, matriz_palavras, letra);
      }

      if (letra == -1) {
        printf("Letra %c não encontrada\n", letra);
      } else {
          remove_letra(palavra_selecionada, num_letras, matriz_palavras, letra);
          if (matriz_palavras[palavra_selecionada][0] == '\0') {
            exclui_palavra(palavra_selecionada, matriz_palavras, num_palavras);
            palavra_selecionada = -1;
            palavras_acertadas++;
            num_palavras--;
          } 
        }
    }
  } 
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

void remove_letra(int p, int t, char v[t][t], char letra) 
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