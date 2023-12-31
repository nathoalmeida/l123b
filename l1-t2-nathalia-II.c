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
// quantas palavras gerar
#define NUM_PALAVRAS 10
// quantas letras tem cada palavra
#define NUM_LETRAS 10
// quantos segundos para digitar
#define TEMPO 180

// funções a implementar
// retorna a posição de n em v[t], ou -1
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
// preenche v[t] com números
void preenche_vet(int l, int c, char v[l][c]);
// mostra o vetor de números
void mostra_vet(int palavra, int l, int c, char v[l][c]);
// gera uma letra aleatória
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
  // inicializa o vetor de números a digitar
  int num_palavras = NUM_PALAVRAS;
  int num_letras = NUM_LETRAS;
  char letras[num_palavras][num_letras];
  int palavra_selecionada = -1;
  int palavras_acertadas = 0;
  

  preenche_vet(num_palavras, num_letras, letras);
  
  // inicializa timer
  long t0 = time(0);

  while (true) {
    int resta = TEMPO - (time(0) - t0);
    if (resta <= 0) {
      printf("Tempo esgotado\n");
      break;
    }

    if (palavras_acertadas == NUM_PALAVRAS) { // DEFINIR CONDIÇÃO DE PARADA
      printf("Parabéns, você acertou todas, e sobraram %d segundos!\n", resta); 
      break;
    }

    mostra_vet(palavra_selecionada, num_palavras, num_letras, letras); // CONSERTAR OS B.O AQUI
    if (palavra_selecionada >= 0) {
      imprime_palavra(palavra_selecionada, num_letras, letras);
    }
    printf("você tem %d segundos\n", resta);
    printf("digite uma das letras");
    char letra;
    letra = tecla_le_char();

    if (letra != '\0') {
      if ( palavra_selecionada < 0 ) {
        palavra_selecionada = seleciona_palavra(num_letras, letras, letra);
      }

      if ( letra == -1 ) {
        printf("Letra %c não encontrada\n", letra);
      } else {
          remove_letra(palavra_selecionada, num_letras, letras, letra);
          if ( letras[palavra_selecionada][0] == '\0' ) {
            exclui_palavra(palavra_selecionada, letras, num_palavras);
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

void preenche_vet(int l, int c, char v[l][c])
{
  int i = 0;
  int j = 0;
  for (i = 0; i < l; i++) {
    for (j = 0; j < c-1; j++) {
      v[i][j] = aleatorio('a', 'z');
    }
    v[i][j] = '\0';
  } 
}

void mostra_vet(int palavra, int l, int c, char v[l][c])
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

void remove_letra(int p, int t, char v[t][t], char letra) 
{
    if (v[p][0] == letra) {
      for (int i = 0; i < t; i++) {
        v[p][i] = v[p][i+1]; 
      }
    } 
}

int aleatorio(int min, int max)
{
  int r = rand() % (max - min + 1);
  return r + min;
}
