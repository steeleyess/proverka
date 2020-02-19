// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents number of buckets in a hash table
#define N 26
unsigned int KILKIST = 0;
char NOVII[LENGTH+1];

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Represents a hash table
node *hashtable[N];

// Hashes word to a number between 0 and 25, inclusive, based on its first letter функція повертає число від 0 до 25
unsigned int hash(const char *word)
{
    int bukva = tolower(word[0]);
    return (bukva-97);
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Initialize hash table
    for (int i = 0; i < N; i++)
    {
        hashtable[i] = NULL;
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

    // Insert words into hash table цикл зчитує рядки з файла - в рядок word, яле в файлі повинно бути по одному слову на рядок в нижньому реєстрі
    while (fscanf(file, "%s", word) != EOF)
    {
        // TODO виділяю память для змінної типу node
        node *newnode = malloc(sizeof(node));
        // перевіра чи виділилась память, якщо ні, то виходим з програми і видаляємо виділену память в програмі за допомогою (unload)
        if(newnode == NULL)
        {
            unload();
            return false;
        }
        // копіює слово з файла в змінну newnode
        strcpy(newnode->word, word);
        // присвоюю вказівник next - NULL
        newnode->next = NULL;
        // визиваю функцію хеш, для того, щоб визначити в яку комірку масиву потрібно вставить елемент
        unsigned int persha = hash(word);
        // якщо вказівник в масиві hashtable ні на що не вказує, тоді він буде вказувать на цей елемент
        if(hashtable[persha])
        {
            //newnode->next = hashtable[persha];
            //hashtable[persha] = newnode;
            for(node *ptr = hashtable[persha];ptr!=NULL;ptr=ptr->next)
            {
                if(!ptr->next)
                {
                    ptr->next = newnode;
                    break;
                }
            }
        }
        //інакше спочатку елемент буде вказувати туди, куди вказував hashtable[persha], а потім hashtable[persha] буде вказувать на цей елемент
        else
        {
            hashtable[persha]=newnode;
        }
        KILKIST++;



    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded кількість слів в словнику
unsigned int size(void)
{
    // TODO
    return KILKIST;
}

// Returns true if word is in dictionary else false повертає тру, якщо слово є в словнику
bool check(const char *word)
{
    // TODO зміна в слові всіх великих літер на малі
    //int n=strlen(word);
    strcpy(NOVII, word);
    for (int i=0;i<LENGTH+1;i++)
    {
        NOVII[i] = tolower(NOVII[i]);
    }

    // визначити з якої комірки масива хештебл будемо перевіряти слова
    unsigned int persha1 = hash(word);
    // створюємо вказівник на комірку масиву
    node *cursor = hashtable[persha1];
    // перевіряємо слово з кожним словом звязного списку
    while(cursor!=NULL)
    {
        //printf("ryadok yakii porivnuem: %s\n", NOVII);
        //printf("slovo s slovnika:       %s\n", cursor->word);
        if(strcmp(NOVII, cursor->word)==0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Unloads dictionary from memory, returning true if successful else false очищає память
bool unload(void)
{
    // TODO
    for(int i=0;i<N;i++)
    {
        node *pokaznik = hashtable[i];
        while(pokaznik!=NULL)
        {
            node *temp = pokaznik;
            pokaznik = pokaznik->next;
            free(temp);
        }
    }
    return true;
}

