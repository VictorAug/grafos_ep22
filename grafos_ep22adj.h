#ifndef GRAFOS_EP22ADJ_H_INCLUDED
#define GRAFOS_EP22ADJ_H_INCLUDED
#include "grafos_ep22.h"

typedef struct node *link;

struct node{
    Vertex w;
    double cst;
    link next;
};

struct adj_digraph{
    int V;
    int A;
    link *adj;
};
typedef struct adj_digraph *adj_Digraph;

link NEW(Vertex, double, link);

adj_Digraph adj_DIGRAPHInit(int);

void adj_GRAPHInsertE(adj_Digraph, Vertex, Vertex, double);

void adj_DIGRAPHInsertA(adj_Digraph, Vertex, Vertex, double);

int adj_BELLMAN_ford(adj_Digraph, Vertex);

void adj_DAGmin(adj_Digraph, Vertex);//só para digrafo

void adj_DAGts2(adj_Digraph);

void adj_TSdfsR(adj_Digraph, Vertex, int*);

void adj_DIGRAPHShowTS(adj_Digraph);

void adj_DIGRAPHShowDIST(adj_Digraph);

void adj_DIGRAPHShowPARENT(adj_Digraph);

void adj_DIGRAPHShowCST(adj_Digraph);

void adj_DIGRAPHdel(adj_Digraph);

void adj_dijkstra(adj_Digraph, Vertex);

void adj_prim2(adj_Digraph);

void adj_Kruskal(adj_Digraph);

#endif // GRAFOS_EP22ADJ_H_INCLUDED
