#ifndef GRAFOS_EP22_H_INCLUDED
#define GRAFOS_EP22_H_INCLUDED
#define Vertex int
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define INFINITO 1000.0
#define SENTINELA G->V
#define maxCST INFINITO
static double cst[1000];
static int fr[1000], parent[1000], ts[1000], dist[1000];

typedef struct Arc{
    Vertex v;
    Vertex w;
    double cst;
}Arc;

#endif // GRAFOS_EP22_H_INCLUDED
