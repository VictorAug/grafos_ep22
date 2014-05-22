#include "grafos_ep22Q.h"
#include <stdio.h>
#include <stdlib.h>
static int *q, i;

void QUEUEInit(int v)
{
    q = malloc(v*sizeof(int));
    i = 0;
}

void QUEUEPut(Vertex v)//vertice 0
{
    q[i] = v;
    i++;
}

Vertex QUEUEGet()//é o elemento da primeira posicao
{
    int j, temp = q[0];
    if(i > 1)
        for(j = 0; j < i-1; j++)
            q[j] = q[j+1];
    i--;
    return temp;
}

int QUEUEEmpty()
{
    return i == 0;
}

void QUEUEFree()
{
    free(q);
}
