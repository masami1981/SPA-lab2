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
    dict->word = NULL;
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
    wp->count =1;
    tmp = dict;
    while(1)
    {
        if(tmp->next == NULL)
        {
            tmp->next = wp;
            return;
        }
        else if(strcmp(tmp->next->word, str) == 0)
        {
            (tmp->next->count)++;
            free(wp->word);
            free(wp);
            return;
        }
        else if(strcmp(tmp->next->word, str) > 0)
        {
            wp->next = tmp->next;
            tmp->next = wp;
            return;
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
    for( tmp=dict ; tmp->next != NULL ; tmp = tmp->next)
        printf("%dx %s\n", tmp->next->count, tmp->next->word);
}

// briše cijeli rjecnik
void destroy(Dictionary dict)
{
    Dictionary tmp, tmp2;
    tmp=dict;
    while(1)
    {
        if (tmp->next->next != NULL)
        {
            tmp2 = tmp->next->next;
            free(tmp->next->word);
            free(tmp->next);
            tmp->next=tmp2;
        }
        else
        {
            free(tmp->next->word);
            free(tmp->next);
            tmp->next=NULL;
            free (dict);
            dict = NULL;
            break;
        }
    }
}

Dictionary filterDictionary(Dictionary indict, int (*filter)(Word *w))
{
    Dictionary tmp, tmp2;
    tmp = indict;
        while(1)
        {
            if (tmp->next != NULL && (*filter)(tmp->next))
            {
                tmp = tmp->next;
                continue;
            }
            else if (tmp->next != NULL)
            {

                if (tmp->next->next != NULL)
                {
                    tmp2 = tmp->next->next;
                    free(tmp->next->word);
                    free(tmp->next);
                    tmp->next=tmp2;
                    continue;
                }
                else
                {
                    free(tmp->next);
                    tmp->next = NULL;
                    break;
                }
            }
            else break;
        }
        return indict;
}

int filter(Word *w)
{
    if((strlen(w->word) > 3) && (w->count>4) && (w->count<11))
        return 1;
    else return 0;
}

