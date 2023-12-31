// l123b - t1 (acerte o número)
// programa para digitar números dentro do limite de tempo
// Nathália Oliveira de Almeida
// 2023-09-30

/// Você só pode alterar o nome e data acima, e os locais marcados,
///   no final do arquivo.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// definições de constantes
// quantos números gerar
#define N_NUM 10
// quantos segundos para digitar
#define TEMPO 20

// funções a implementar
// retorna a posição de n em v[t], ou -1
int acha_letra(int t, char v[t], char n);
// remove o dado na posição p de v[t], deslocando os v[>t]
void remove_pos(int t, char v[t], int p);

// funções auxiliares
// apresenta o programa
void apresentacao();
// encerra o programa
void encerramento();
// executa uma partida
void jogo();
// verifica a vontade do jogador
bool quer_jogar_de_novo();
// preenche v[t] com números
void preenche_vet(char t, char v[t]);
// mostra o vetor de números
void mostra_vet(int t, char v[t]);
// limpa a linha de entrada
void espera_enter();


int main()
{
  // inicializa o gerador de números aleatórios
  srand(time(0));

  apresentacao();

  do {
    jogo();
  } while(quer_jogar_de_novo());

  encerramento();
}

void jogo()
{
  // inicializa o vetor de números a digitar
  int n_num = N_NUM;
  char letras[N_NUM];
  preenche_vet(n_num, letras);

  // inicializa timer
  long t0 = time(0);

  while (true) {
    int resta = TEMPO - (time(0) - t0);
    if (resta <= 0) {
      printf("Tempo esgotado\n");
      break;
    }

    if (n_num <= 0) {
      printf("Parabéns, você acertou todas, e sobraram %d segundos!\n", resta);
      break;
    }

    mostra_vet(n_num, letras);
    printf("você tem %d segundos\n", resta);
    printf("digite um dos números ");
    char num;
    scanf("%c", &num);
    espera_enter();
    int pos = acha_letra(n_num, letras, num);
    if (pos < 0) {
      printf("Letra %d não encontrada\n", num);
    } else {
      remove_pos(n_num, letras, pos);
      n_num--;
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
  espera_enter();
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

void preenche_vet(char t, char v[t])
{
  for (int i = 0; i < t; i++) {
    // gera um número aleatório entre 0 e 999
    v[i] = 'a' + (rand() % 26);
  } 
}

void mostra_vet(int t, char v[t])
{
  printf("\n[");
  for (int i = 0; i < t; i++) {
    printf(" %c", v[i]);
  }
  printf(" ]\n\n");
}

int acha_letra(int t, char v[t], char n)
{
  /// você deve alterar abaixo desta linha
  for(int i = 0; i < t; i++) {
    if(n == v[i]) {
      return i;
    } else {
        if(i == t-1) {
          return -1;
        } 
    }
  }  
  /// você deve alterar acima desta linha  
}

void remove_pos(int t, char v[t], int p)
{
  /// você deve alterar abaixo desta linha
  int reserva = v[p];

    for(int i = p; i < t-1; i++) {
      v[i] = v[i+1];
    }
    
  v[t-1] = reserva;
  /// você deve alterar acima desta linha  
}
