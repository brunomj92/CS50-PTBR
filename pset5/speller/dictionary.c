// Implements a dictionary's functionality
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

// Number of buckets in hash table
#define N 26

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

unsigned int countw = 0; // Dictionary size

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // hash the word to get hash value
    unsigned int abc = hash(word);
    // Access linked list in that index in the hash table
    for (node *c = table[abc]; c != NULL; c = c->next) // cursor no primeiro node
    {
        // Traverse linked list, looking for the word
        if (strcasecmp(c->word, word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int cat = toupper(word[0]) - 'A';
    return cat;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL; // Initializing hash table properly
    }
    // Open dictionary file
    FILE *dptr = fopen(dictionary, "r");
    if (dptr == NULL) // fopen + check if NULL
    {
        fclose(dptr);
        return false;
    }
    char word[LENGTH+1];
    while (fscanf(dptr, "%s", word) != EOF) // fscanf returns EOF
    {
        node *n = malloc(sizeof(node)); // declare a temp node
        // Create a new node for each word
        if (n == NULL)
        {
            fclose(dptr);
            return false;
        }
        strcpy(n->word, word);
        // Hash word to obtain a hash value
        unsigned int abc = hash(word);
        // Insert node into hash table at that location
        n->next = table[abc];
        // ponteiro table aponta para o node inserido
        table[abc] = n;
        countw++; // Tamanho do dicionario
    }
    fclose(dptr); // Close dictionary file

    // Success
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return countw;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i=0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}
