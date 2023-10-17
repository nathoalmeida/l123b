// PARTE III T2 - CRIA UM ÍNDICE
// SE O ÍNDICE É -1 NÃO TEM PALAVRA SELECIONADA
// QUANDO CHEGA NO ÍNDICE SELECIONADO, NÃO IMPRIME
// IMPRIME O ÍNDICE NO FINAL

// Abertura de arquivos
// terá uma variável que representa o arquivo

#include <stdio.h>

int main() {
/*
  FILE *a, *b;
  int x;

  a = fopen("nome.txt", "r"); // "w" para gravar dados e "r" para leitura
  // Se o arquivo não pôde ser aberto, a variável vai retornar NULL
  // Se abrir com "w", perdeu o conteúdo anterior
  // "a" abre sem destruir o conteúdo, só destrói no fim da operação

  fscanf(a, "%d", &x); // if(fscanf == 1) a leitura deu certo
  feof(a); // eof = end of file; retorna um boolean
  fprintf(a, "oi %d", x);
  fclose(a); */

  FILE *a;
  
  char nomee[50];

  char texto[20][80];

  printf("Digite o nome do arquivo de entrada: ");
  scanf("%s", nomee);
  a = fopen(nomee, "r");
  if(a == NULL) {
    printf("Erro na abertura do arquivo '%s'\n", nomee);
    return 1;
  }

  int linha;
  for (linha = 0; linha < 20; linha++) {
    if(fscanf(a, " %[^\n]", texto[linha]) != 1) {
      
    }
  }


}