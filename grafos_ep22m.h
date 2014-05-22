#ifndef GRAFOS_EP22M_H_INCLUDED
#define GRAFOS_EP22M_H_INCLUDED
#include "grafos_ep22.h"
#include "grafos_ep22PQ.h"

struct m_digraph{
    int V;
    int A;
    double **adj;
};
typedef struct m_digraph *m_Digraph;

double **MATRIXDouble(int, int, double);

m_Digraph Matriz_DIGRAPHInit(int);

void Matriz_DIGRAPHShow(m_Digraph);

void Matriz_GRAPHInsertE(m_Digraph, Vertex, Vertex, double);

void Matriz_DIGRAPHInsertA(m_Digraph, Vertex, Vertex, double);

void Matriz_BELLMAN_ford2(m_Digraph, Vertex);

void Matriz_FLOYD_WARSHALL(m_Digraph);

void Matriz_DIGRAPHShowTS(m_Digraph);

void Matriz_DIGRAPHShowDIST(m_Digraph);

void Matriz_DIGRAPHShowPARENT(m_Digraph);

void Matriz_DIGRAPHShowCST(m_Digraph);

void Matriz_DIGRAPHdel(m_Digraph);

void Matriz_prim1(m_Digraph);

void Matriz_dijkstra(m_Digraph, Vertex);

#endif // GRAFOS_EP22M_H_INCLUDED
