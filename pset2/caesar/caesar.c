#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

string cipher(long keyc);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //argv[1][i] deve ser analisado como numero
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Use: ./caesar key\n");
            return 1;
        }
    }
    // função para transformar em numero
    char *a;
    long numero = strtol(argv[1], &a, 10);
    string ciphertext = cipher(numero);
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}

string cipher(long keyc)
{
    // pega o text com get_string
    string cesar = get_string("plaintext: ");
    for (int i = 0; cesar[i] != '\0'; i++)
    {
        if (isalpha(cesar[i]))
        {
            cesar[i] += keyc%26;
            if (!isalpha(cesar[i]))
            {
                cesar[i] -= 26;
            }
        }
    }
    return cesar;
}
