#include <stdio.h>
#include <stdbool.h>

int mstrlen(char v[]) 
{
  int i = 0;
  while(v[i] != '\0') {
    i++;
  }
  return i;
}

void imprime_stri(char v[]) 
{
  for(int i = 0; v[i] != '\0'; i++) {
    putchar(v[i]);
  }
  printf("\n");
}

bool eh_palindromo(char p[]) 
{
  int tam = mstrlen(p);
  int t = tam-1;
  for(int i = 0; i < tam; i++) {
    if(p[i] != p[t]) {
        return false;
    } else if(i == tam-1) {
        return true;
    } else {
        t--;
    }
  } 
}



void copia_letras(char d[], char o[]) 
{
    /* int po = 0;
    int pd = 0; */

  int tam = mstrlen(o) + 1;
  for(int i = 0; i < tam; i++) {
    if(o[i] >= 'a' && o[i] <= 'z') {
      d[i] = o[i] - 'a' + 'A';
    } else {
        d[i] = o[i];
    }
  } 
}

int main() 
{

  char v[5];

  char s[10];

  copia_letras(v, "oVo");

  copia_letras(s, "Nathalia");

  imprime_stri(v);

  imprime_stri(s);

  
  if(!eh_palindromo("ovo")) {
    printf("ovo é palíndromo\n");
  }

  if(eh_palindromo("ovO")) {
    printf("ovO não é palíndromo\n");
  }

  if(!eh_palindromo("aa")) {
    printf("aa é palíndromo\n");
  }

  if(!eh_palindromo("ivo viu o uiv ovi")) {
    printf("ivo etc é palíndromo\n");
  }
}