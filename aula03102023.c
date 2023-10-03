#include <stdio.h>


// strlen é uma função para ver o comprimento da string
// strcpy(d,o) copia de um vetor pra outro
// strcatt(d,o) concatena strings

int mstrlen(char v[]) // retorna o número de caracteres da string em v
{
  int i = 0;
  while(v[i] != '\0') {
    i++;
  }
  return i;
}

void mstrcpy(char d[], char o[])
{
  int tam = mstrlen(o);
  for(int i = 0; i < tam+1; i++) {
    d[i] = o[i];
  }
}

void mstrcat(char d[], char o[]) //concatenar os vetores
{

}
void imprime_stri(char v[]) 
{
  for(int i = 0; v[i] != '\0'; i++) {
    putchar(v[i]);
  }
  
}

int main() {
// dica jogo da velha 
// chama 3x uma função que confere se tem jogo em uma linha, depois outra função em uma coluna

// Aula Strings
// Não existe o tipo String em C
// Uma possível solução é um vetor do tipo char
// Existe um caractere especial p/ definir o fim de uma String dentro de um vetor
// A linguagem sempre vai inserir esse caractere quando terminar a String

char s[30] = "Nathalia";
char e[30];
// scanf("%s", s); // não precisa colocar o & na frente, pois o vetor de char já tem permissão para inserir valores
// scanf não aceita espaços
// scanf("%[^\n]", s); %[] só tem no scanf, não tem no printf
// printf("%29s", s);


mstrcpy(e, s);
printf("%s tem %d caracteres.\n", s, mstrlen(s));
printf("%s tem %d caracteres.\n", e, mstrlen(e));

}