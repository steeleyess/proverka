// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "dictionary.h"

// Represents number of children for each node in a trie
#define N 27
unsigned int KILKIST = 0;
unsigned int hashznach = 0;
char NOVII[LENGTH+1];


// Represents a node in a trie
typedef struct node
{
    bool is_word;
    struct node *children[N];
}
node;
// Represents a trie
node *root;

unsigned int hash(const char word)
{
    if(word=='\'')
    {
        return 26;
    }
    int bukva = tolower(word);
    return (bukva-97);
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Initialize trie
    if(root == NULL)
    {
        root = malloc(sizeof(node));
        if (root == NULL)
        {
            return false;
        }
        root->is_word = false;
        for (int i = 0; i < N; i++)
        {
            root->children[i] = NULL;
        }
    }
    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];

    // Insert words into trie
    while (fscanf(file, "%s", word) != EOF)
    {
        // TODO
        strcpy(NOVII, word);
        for (int i=0;i<(LENGTH+1);i++)
        {
            NOVII[i] = tolower(NOVII[i]);
        }
        node *root1 = root;
        for(int i=0, n=strlen(NOVII);i<n;i++)
        {
            hashznach = hash(NOVII[i]);
            if (root1->children[hashznach]==NULL)
            {
                root1->children[hashznach] = malloc(sizeof(node));
                if(root1->children[hashznach]==NULL)
                {
                    unload();
                    return false;
                }
                for (int j = 0; j < N; j++)
                {
                    root1->children[hashznach]->children[j] = NULL;
                }
                root1->children[hashznach]->is_word = false;
                root1 = root1->children[hashznach];
                if(i==n-1)
                {
                    KILKIST++;
                    root1->is_word = true;
                }
            }
            else
            {
                root1=root1->children[hashznach];
                if(i==n-1)
                {
                    KILKIST++;
                    root1->is_word = true;
                }
            }
        }

    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return KILKIST;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    node *root1 = root;
    for(int i = 0, n=strlen(word);i<n;i++)
    {
        hashznach = hash(word[i]);
        if(root1->children[hashznach]==NULL)
        {
            return false;
        }
        else
        {
            root1 = root1->children[hashznach];
            if(i==n-1 && root1->is_word == true)
            {
                return true;
            }
        }
    }
    return false;
}

// Unloads dictionary from memory, returning true if successful else false
void recurs(node *lol);
bool unload(void)
{
    // TODO
    recurs(root);
    /*node *root1 = root;
    for(int i = 0; i<N;i++)
    {
        if(root1->children[i]!=NULL)
        {
            node *root2 = root1->children[i];
            unload();
        }

    }
    free(root1);*/
    return true;
}

void recurs(node *lol)
{
    for(int i = 0;i<N;i++)
    {
        if(lol->children[i]!=NULL)
        {
            recurs(lol->children[i]);
        }
    }
    free(lol);
}
