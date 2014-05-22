#include "grafos_ep22PQ.h"
#include <stdio.h>
#include <stdlib.h>
void listar(Lista *l)
{
    int i;
    for (i = 0; i < l->quant; i++)
        printf("%d ----- %d ----- %d\n", l->quant, l->Data[i].v, l->Data[i].prior);
}

void PQDec(Lista **vet, int i)
{
    int l = 2*i, r = (2*i)+1, menor=0;
    if(l <= (*vet)->quant  && (*vet)->Data[l-1].prior < (*vet)->Data[i-1].prior)
        menor = l-1;
    else
        menor = i-1;
    if(r <= (*vet)->quant  && (*vet)->Data[r-1].prior < (*vet)->Data[menor].prior)
        menor = r - 1;
    if(menor != i - 1){
        int buffer = (*vet)->Data[menor].prior;
        (*vet)->Data[menor].prior = (*vet)->Data[i-1].prior;
        (*vet)->Data[i-1].prior = buffer;
        PQDec(&(*vet), menor+1);
    }
}

Vertex PQDelmin(Lista **l)
{
    if((*l)->quant < 1)
        return 0;
    int min = (*l)->Data[0].v;
    (*l)->Data[0].prior = (*l)->Data[--(*l)->quant].prior;
    PQDec(&(*l), 1);
    return min;
}

void PQBuild(Lista **vet)
{
    int i;
    int sizeA = (*vet)->quant;
    for(i = sizeA/2; i > 0; i--)
        PQDec(&(*vet), i);
}

int PQEmpty(Lista **l){
    return (*l)->quant == 0 ? 1 : 0;
}

Lista *PQInit(Vertex size)
{
    Lista *l = malloc(sizeof(Lista));
    l->quant = 0;
    l->Data = malloc(size*sizeof(Dados));
    return l;
}

int PQIncrease(Lista **l, int i, Dados *chave)
{
    if(chave->prior > (*l)->Data[i].prior)
        return 0;
    (*l)->Data[i].prior = chave->prior;
    (*l)->Data[i].v = chave->v;
    while(i > -1 && (*l)->Data[i/2].prior > (*l)->Data[i].prior){
        int buffer = (*l)->Data[i/2].prior;
        (*l)->Data[i/2].prior = (*l)->Data[i].prior;
        (*l)->Data[i].prior = buffer;
        i = i/2;
    }
    return 1;
}

int PQInsert(Lista **l, Dados *chave)
{
    (*l)->Data[(*l)->quant].prior = 32678;
    (*l)->quant++;
    if(PQIncrease(&(*l), (*l)->quant-1, chave))
        return 1;
    else
        return 0;
}
