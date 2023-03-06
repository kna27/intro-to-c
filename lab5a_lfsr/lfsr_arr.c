#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lfsr.h"

struct lfsr
{
    char *seed;
    int tap;
};

LFSR *createLFSR(char *seed, int tap)
{
    LFSR *lfsr = malloc(sizeof(LFSR));
    lfsr->seed = malloc(strlen(seed) + 1);
    strcpy(lfsr->seed, seed);
    lfsr->tap = tap;
    return lfsr;
}

char lfsrHead(LFSR *lfsr)
{
    return lfsr->seed[0];
}

char lfsrTap(LFSR *lfsr)
{
    return lfsr->seed[lfsr->tap];
}

char lfsrStep(LFSR *lfsr)
{
    char head = lfsrHead(lfsr);
    char tap = lfsrTap(lfsr);
    char xor = head ^ tap;
    int i = 0;
    while (lfsr->seed[i] != '\0')
    {
        lfsr->seed[i] = lfsr->seed[i + 1];
        i++;
    }
    lfsr->seed[i - 1] = xor;
    return xor;
}

void lfsrDebugPrint(LFSR *lfsr)
{
    int i = 0;
    while (lfsr->seed[i] != '\0')
    {
        if (i == lfsr->tap)
        {
            printf("+%d: %x (%c)", i, lfsr->seed[i], lfsr->seed[i]);
        }
        else
        {
            printf(" %d: %x (%c)", i, lfsr->seed[i], lfsr->seed[i]);
        }
        i++;
    }
}

char *lfsrToString(LFSR *lfsr)
{
    int i = 0;
    while (lfsr->seed[i] != '\0')
    {
        i++;
    }
    char *str = malloc(i * sizeof(char));
    int j = 0;
    while (lfsr->seed[j] != '\0')
    {
        str[j] = lfsr->seed[j];
        j++;
    }
    return str;
}

void destroyLFSR(LFSR *lfsr)
{
    free(lfsr->seed);
    free(lfsr);
}
