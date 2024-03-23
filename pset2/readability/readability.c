#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

float averageLettersPer100Words(string sentence);
float averageSentencesPer100Words(string text);

int main(void)
{
    // inserir texto
    string texto = get_string("Text: ");
    // contar letras por palavra (valor médio por 100 p)
    float L = averageLettersPer100Words(texto);
    // contar sentenças para 100 palavras
    float S = averageSentencesPer100Words(texto);
    // classificar saída "Grade X"
    float n = 0.0588 * L - 0.296 * S - 15.8;
    if (n >= 1 && n <= 15.5)
    {
        printf("Grade %.0f\n", round(n));
    }
    else
    {
        if (n < 1)
        {
            printf("Before Grade 1\n");
        }
        else if (n > 15.5)
        {
            printf("Grade 16+\n");
        }
    }
}

float averageLettersPer100Words(string sentence)
{
    int totalLetters = 0;
    int totalWords = 1;

    for (int i = 0; sentence[i] != '\0'; i++)
    {
        if (isalpha(sentence[i]))
        {
            totalLetters++;
        }
        else if (isspace(sentence[i]))
        {
            totalWords++;
        }
    }

    // Calculate the average number of letters per 100 words
    float average = (float)totalLetters / totalWords * 100;

    return average;
}

float averageSentencesPer100Words(string text)
{
    int totalSentences = 0;
    int totalWords = 1;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isspace(text[i]))
        {
            // If a space character is encountered, count it
            totalWords++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?') //|| text[i] == ';')
        {
            // If a sentence-ending punctuation is encountered, count it as the end of a sentence
            totalSentences++;
        }
    }

    // Calculate the average number of sentences per 100 words
    float avg = (float)totalSentences / totalWords * 100;

    return avg;
}
