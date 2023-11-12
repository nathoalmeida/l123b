#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_PALAVRAS 920
#define NUM_LETRAS 16

int aleatorio(int min, int max)
{
  int r = rand() % (max - min + 1);
  return r + min;
}

void readWordsFromFile(const char *filename, char words[NUM_PALAVRAS][NUM_LETRAS]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    int wordCount = 0;

    while (wordCount < NUM_PALAVRAS && fscanf(file, "%s", words[wordCount]) == 1) {
        wordCount++;
    }

    fclose(file);
}

void preenche_matriz(char banco_palavras[NUM_PALAVRAS][NUM_LETRAS], int l, int c, char v[l][c])
{
  int i = 0;
  int j = 0;
  int num_sorteado = aleatorio(0, 919);
  for (i = 0; i < l; i++) {
    for (j = 0; j < c-1; j++) {
      banco_palavras[num_sorteado][j] = v[i][j];
    }
    v[i][j] = '\0';
    num_sorteado = aleatorio(0,919);
  } 
}

int main() {
    char words[NUM_PALAVRAS][NUM_LETRAS];
    char teste[10][16];
    char filename[] = "palavras.txt"; // Substitua com o nome do seu arquivo

    readWordsFromFile(filename, words);
    preenche_matriz(words, 10, 16, teste);

    printf("%c\n", teste[0][0]);
    printf("%s\n", words[25]);

    /*int i;
    for (i = 0; i < NUM_PALAVRAS; i++) {
        if (strlen(words[i]) == 0) {
            break; // Sair do loop se não houver mais palavras
        }
        printf("Palavra %d: %s\n", i, words[i]);
    } */
}
