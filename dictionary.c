#include "dictionary.h"
#include <malloc.h>
#include <stdlib.h>
#include <string.h>


// kreaira novi rjecnik
Dictionary create()
{
    Dictionary dict;
    dict = (Dictionary) malloc(sizeof(Word));
    dict->count = 0;
    dict->word = strdup("");
    dict->next = NULL;
    return dict;
}

// dodaje rijec ili uvecava broj pojavljivanja rijeci u rjecniku
// rijeci se dodaju u abecednom redu
void add(Dictionary dict, char *str)
{
    Dictionary wp, tmp;

    wp =(Dictionary) malloc(sizeof(Word));
    wp->word = strdup(str);
    wp->next = NULL;
    tmp = dict;
    while(1)
    {
        if(tmp->next == NULL)
        {
            tmp->next = wp;
            (tmp->next->count)++;
            break;
        }
        else if(strcmp(tmp->next->word, str) == 0)
        {
            (tmp->next->count)++;
            break;
        }
        else if(strcmp(tmp->next->word, str) > 0)
        {
            wp->next = tmp->next;
            tmp->next = wp;
            (tmp->next->count)++;
            break;
        }
        else
        {
            tmp = tmp->next;
            continue;
        }
    }
}

// ispisuje sve rijeci i broj pojavljivanja svake rijeci
void print(Dictionary dict)
{
    Dictionary tmp;
    for( tmp=dict ; tmp != NULL ; tmp = tmp->next)
        printf("%dx %s\n", tmp->count, tmp->word);
}

// briše cijeli rjecnik
void destroy(Dictionary dict)
{
    Dictionary tmp;
    tmp=dict;
    if(tmp == NULL)
    {
        free(tmp);
    }
    else
    {
        tmp = tmp->next;
        destroy(tmp);
    }

}

