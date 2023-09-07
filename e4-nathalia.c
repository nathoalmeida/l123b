// l123b - e4
// exercício 4 - conversões de sistema
// nathália oliveira de almeida
// 2023-09-06

#include <stdio.h>

// função para imprimir os dígitos
void imprime_digito(int digito);

// função para converter os dígitos em hexadecimal
void converter_hexadecimal(int valor);

// função para converter os dígitos em binário
void converter_binario(int valor);

// função para converter os dígitos em octal
void converter_octal(int valor);

// função para converter os dígitos em decimal
void converter_decimal(int valor);

// função que seleciona qual conversao será feita
void selecionar_valor(int valor, int sis);

void imprime_digito(int digito)
{
if (digito <= 9)
{
putchar(digito + '0');
}
else
{
putchar(digito - 10 + 'A');
}

}

void converter_hexadecimal(int valor)
{

    int d1 = valor / 16;
    int d2 = valor % 16;

    imprime_digito(d1);
    imprime_digito(d2);
}

void converter_binario(int valor)
{

    int d1 = (valor / 2) / 2 / 2 / 2 / 2 / 2 / 2 % 2;
    int d2 = (valor / 2) / 2 / 2 / 2 / 2 / 2 % 2;
    int d3 = (valor / 2) / 2 / 2 / 2 / 2 % 2;
    int d4 = (valor / 2) / 2 / 2 / 2 % 2;
    int d5 = (valor / 2) / 2 / 2 % 2;
    int d6 = (valor / 2) / 2 % 2;
    int d7 = (valor / 2) % 2;
    int d8 = valor % 2;

    imprime_digito(d1);
    imprime_digito(d2);
    imprime_digito(d3);
    imprime_digito(d4);
    imprime_digito(d5);
    imprime_digito(d6);
    imprime_digito(d7);
    imprime_digito(d8);
}

void converter_octal(int valor)
{

    int d1, d2, d3;


    d1 = valor / 8 / 8;
    d2 = valor / 8;
    d3 = valor % 8;
  

    imprime_digito(d1);
    imprime_digito(d2);
    imprime_digito(d3);
}

void converter_decimal(int valor)
{
    int d1, d2, d3;

    d1 = valor / 100;
    d2 = (valor - d1 * 100) / 10;
    d3 = (valor - d1 * 100 - d2 * 10);
    

    imprime_digito(d1);
    imprime_digito(d2);
    imprime_digito(d3);
}

void selecionar_valor(int valor, int sis)
{

    if (sis == 'h')
    {
        converter_hexadecimal(valor);
    }
    else if (sis == 'b')
    {
        converter_binario(valor);
    }
    else if (sis == 'd')
    {
        converter_decimal(valor);
    }
    else if (sis == 'o')
    {
        converter_octal(valor);
    }
}

int main()
{

    int numero;

    scanf("%d", &numero);

    if (numero < 0)
    {
        printf("Muito pequeno");
    }
    else if (numero > 255)
    {
        printf("Muito grande");
    }
    else
    {

        printf("Em binario   octal   decimal   hexa\n");
        printf("  ");
        selecionar_valor(numero, 'b');
        printf("     ");
        selecionar_valor(numero, 'o');
        printf("       ");
        selecionar_valor(numero, 'd');
        printf("     ");
        selecionar_valor(numero, 'h');
    }

    return 0;
}
