#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

string cipher(string chave);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }
    //argv[1][i] deve ser analisado como 26 letras
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    //apenas letras
    int repete[26] = {0}; // vetor que conta cada letra de 0 para 1
    char baseM[27];
    //strcpy(baseM, argv[1]);
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Key must contain only alphabetic characters.\n");
            return 1;
        }
        baseM[i] = toupper(argv[1][i]); // função para transformar em maiusc
        if (repete[baseM[i] - 'A'] > 0)
        {
            printf("Key must not contain repeated characters.\n");
            return 1; // Duplicate found
        }
        else
        {
            repete[baseM[i] - 'A']++;
        }
        // If no duplicates were found and all characters are valid, the key is valid
    }

    string ciphertext = cipher(baseM);
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}

string cipher(string chave)
{
    string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int chv[26] = {0};
    //mapear a substituição em número de posições
    for (int i = 0; abc[i] != '\0'; i++)
    {
        chv[i] = chave [i] - abc[i];
    }

    // pega o texto com get_string
    string cifrado = get_string("plaintext: ");
    char origM[strlen(cifrado)];
    for (int i = 0; cifrado[i] != '\0'; i++)
    {
        origM[i] = toupper(cifrado[i]);
        if (isalpha(cifrado[i]))
        {
            for(int j = 0; abc[j] != '\0'; j++)
            {
                if(origM[i] == abc[j])
                {
                    cifrado[i] += chv[j];
                    break;
                }
            }
        }
    }
    return cifrado;
}
