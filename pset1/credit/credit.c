#include <math.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdbool.h>

long long get_valid(void);
int z;
bool checksum(const char *number);

int main(void)
{
    long long n = get_valid(); //função de tomada de num cartao
    char number[17];
    sprintf(number, "%llu", n); //toma numero como string
    z = strlen(number);
    if (checksum(number))
    {
        if (z == 15 && number[0] == '3' && number[1] == '4') //Definir cartao
        {
            printf("AMEX\n");
        }
        else if (z == 15 && number[0] == '3' && number[1] == '7')
        {
            printf("AMEX\n");
        }
        else if (z == 16 && number[0] == '5' && number[1] > '0' && number[1] < '6')
        {
            printf("MASTERCARD\n");
        }
        else if (z == 13 && number[0] == '4')
        {
            printf("VISA\n");
        }
        else if (z == 16 && number[0] == '4')
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

long long get_valid(void)
{
    long long card;
    do
    {
        card = get_long_long("Número: ");
    }
    while (card < 0);
    return card;
}

bool checksum(const char *number) {
    int soma = 0;
    bool altern = false;
    // Calcular soma dos digitos usando Luhn
    for (int i = z-1; i >= 0; i--)
    {
        int digit = number[i] - '0';
        if (altern)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit = digit - 9;
            }
        }
        soma += digit;
        altern = !altern;
    }
    // Checar se soma é divisivel por 10
    return (soma % 10 == 0);
}
