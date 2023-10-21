#include <stdio.h>

int aleatorio(int min, int max)
{
  int r = rand() % (max - min + 1);
  return r + min;
};

int main() {

srand(time(0));

char c;

c = aleatorio('a', 'z');

printf("%c\n", c);

}