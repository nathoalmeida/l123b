#include <stdio.h>
#include <math.h>

// na hora de compilar, pode ter que incluir -lm pra procurar a biblioteca de matemática

struct 
{
  char nome[10];
  float dt_ativacao;
  float duracao;
} selecionada = {"teste", 5.3, 19.25};

typedef // define um tipo novo
struct 
{
  char nome[10];
  float dt_ativacao;
  float duracao;
} palavra;

typedef struct {
  float x;
  float y;
} ponto;

float distancia(ponto p1, ponto p2) {
  float c1 = p1.x - p2.x;
  float c2 = p1.y - p2.y;
  return sqrt(c1*c1 + c2*c2);
}



int main() {
  
  /* palavra sel = {"oi", 19, 37.5};
  palavra palavras[32];
  selecionada.duracao = 25; */



}

