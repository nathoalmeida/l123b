int main() 
{

printf("%d\n", aleatorio(0, 920));

}

int aleatorio(int min, int max)
{
  srand(time(0));
  int r = rand() % (max - min + 1);
  return r + min;
}