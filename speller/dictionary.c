// Implements a dictionary's functionality
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <stdint.h>
#include <ctype.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    int index = hash(word);
    node *cursor = table[index];

    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    free(cursor);
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    int index = 0;
    if (word[0] >= 97)
    {
        index = word[0] - 97;
    }
    else if (word[0] >= 65)
    {
        index = word[0] - 65;
    }
    return index;
}

int wc = 0;
FILE *fp;

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{

    for (int i = 0; i <= 25; i++)
    {
        table[i] = NULL;
    }
    // TODO
    char word[25];

    fp = fopen(dictionary, "r");
    if (fp == NULL)
    {
        return false;
    }
    while (fscanf(fp, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        wc++;
        if (n == NULL)
        {
            return false;
        }

        strcpy(n->word, word);
        int index = hash(word);
        n->next = table[index];
        table[index] = n;


    }

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return wc;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    for (int i = 0; i <= 25; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
        free(cursor);
    }
    fclose(fp);
    return true;
}
