#ifndef GRAFOS_EP22PQ_H_INCLUDED
#define GRAFOS_EP22PQ_H_INCLUDED
#include "grafos_ep22.h"

typedef struct Dados{
	int v;
	int prior;
}Dados;

typedef struct Lista{
    struct Dados *Data;
    int quant;
}Lista;

int PQEmpty();

void listar(Lista*);

Lista *PQInit(Vertex);

void PQBuild(Lista**);

int PQIncrease(Lista**, int, Dados*);

int PQInsert(Lista**, Dados*);

Vertex PQDelmin(Lista**);

void PQDec(Lista**, int);

#endif // GRAFOS_EP22PQ_H_INCLUDED
