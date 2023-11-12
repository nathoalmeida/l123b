// função que coloca as palavras aleatórias na matriz (se tiver acento, ignorar)

// função que dá o tamanho da palavra
int tamanho_palavra(char v[])
{
  int i = 0;
  while(v[i] != '\0') {
    i++;
  }
  return i;
}

void transforma_minusculas(char v[]) // CONSERTAR AS VARIÁVEIS TUDO
{
  int tam = tamanho_palavra(v) + 1;
  for(int i = 0; i < tam; i++) {
    if(v[i] >= 'a' && v[i] <= 'z') {
      v[i] = v[i] - 'a' + 'A';
    } else {
      // não faz nada
    }
  } 
}
// função que transforma as letras maiúsculas em minúsculas





