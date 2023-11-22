// AULA ALOCAÇÃO DE MEMÓRIA

// Tempo de vida da variável
// Escopo (visibilidade) da variável: região de memória
// Alocação de memória ESTÁTICA (dura o tempo de execução do programa) ou DINÂMICA (varia conforme o uso das funções - variáveis locais)

#include <stdlib.h>

// malloc(int) o int é quantos bytes preciso -> retorna um *
// malloc( sizeof()) diz quantos bytes a estrutura ocupa
// free() funções de alocação manual de memória

// quando usar malloc, precisa testar se o valor retornado é NULL, pois indica que deu erro