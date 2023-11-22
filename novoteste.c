#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool tem_acento(int tam, char v[tam]);

int main() 
{
char vetor[5] = {"olô"};
char outro_vetor[5] = {"meu"} ;

if (tem_acento(5, vetor)) {
  printf("%s tem acento\n", vetor);
}
if (!tem_acento(5, outro_vetor)) {
  printf("%s não tem acento\n", outro_vetor);
}
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