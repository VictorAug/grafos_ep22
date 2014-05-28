#include <stdio.h>
#include <stdlib.h>
#include "grafos_ep22m.h"
#include "grafos_ep22adj.h"
#include "grafos_ep22PQ.h"

double cost[10];

int main()
{
	int m1,m2,m3,v,w,x1 = 0,d1 = 0,d2 = 0,x2 = 0;
		
	adj_Digraph AG, AD;
	m_Digraph MG, MD;
	AD = adj_DIGRAPHInit(7);
	adj_GRAPHInsertE(AD, 0, 2, 5);
	adj_GRAPHInsertE(AD, 0, 3, 8);
	adj_GRAPHInsertE(AD, 2, 3, 10);
	adj_GRAPHInsertE(AD, 2, 1, 16);
	adj_GRAPHInsertE(AD, 2, 4, 3);
	adj_GRAPHInsertE(AD, 3, 4, 2);
	adj_GRAPHInsertE(AD, 1, 4, 30);
	adj_GRAPHInsertE(AD, 3, 5, 18);
	adj_GRAPHInsertE(AD, 1, 6, 26);
	adj_GRAPHInsertE(AD, 4, 6, 14);
	adj_GRAPHInsertE(AD, 4, 5, 12);
	adj_GRAPHInsertE(AD, 5, 6, 4);
	printf("\n\nPrim - Lista\n\n");
	adj_prim2(AD);
	/*printf("\n\nDAGmin\n\n");
	DAGtsf(AD);
	adj_DAGmin(AD, 0);
	printf("\n\nDijkstra\n\n");
	adj_dijkstra(AD, 0);
	printf("\n\nBellmanFord\n\n");
	adj_BELLMAN_ford(AD, 0);
	adj_DIGRAPHShowCST(AD);
	adj_DIGRAPHShowPARENT(AD);*/
	printf("----------------------------------------------------------\n");
	MG = Matriz_DIGRAPHInit(7);
	Matriz_GRAPHInsertE(MG, 0, 2, 5);
	Matriz_GRAPHInsertE(MG, 0, 3, 8);
	Matriz_GRAPHInsertE(MG, 2, 3, 10);
	Matriz_GRAPHInsertE(MG, 2, 1, 16);
	Matriz_GRAPHInsertE(MG, 2, 4, 3);
	Matriz_GRAPHInsertE(MG, 3, 4, 2);
	Matriz_GRAPHInsertE(MG, 1, 4, 30);
	Matriz_GRAPHInsertE(MG, 3, 5, 18);
	Matriz_GRAPHInsertE(MG, 1, 6, 26);
	Matriz_GRAPHInsertE(MG, 4, 6, 14);
	Matriz_GRAPHInsertE(MG, 4, 5, 12);
	Matriz_GRAPHInsertE(MG, 5, 6, 4);
	printf("\n\nPrim - Matriz\n\n");
	Matriz_prim1(MG);
	/*printf("\n\nDijkstra\n\n");
	Matriz_dijkstra(MG, 0);
	printf("\n\nFloyd\n\n");
	Matriz_FLOYD_WARSHALL(MG);
	printf("\n\nBellmanFord1\n\n");
	Matriz_BELLMAN_ford1(MG, 0);
	printf("\n\nBellmanFord2\n\n");
	Matriz_BELLMAN_ford2(MG, 0);
	Matriz_DIGRAPHShowCST(MG);
	Matriz_DIGRAPHShow(MG);
	adj_DIGRAPHShow(AD);*/
	//adj_dijkstra(AD, 0);
	//MG = Matriz_DIGRAPHInit(5);
	/*Matriz_DIGRAPHInsertA(MG,0,2,7);
	Matriz_DIGRAPHInsertA(MG,0,3,2);
	Matriz_DIGRAPHInsertA(MG,0,4,4);
	Matriz_DIGRAPHInsertA(MG,2,4,1);
	Matriz_DIGRAPHInsertA(MG,3,4,1);
	Matriz_DIGRAPHInsertA(MG,3,5,3);
	Matriz_DIGRAPHInsertA(MG,1,2,0);
	Matriz_DIGRAPHInsertA(MG,5,1,2);
	Matriz_DIGRAPHInsertA(MG,4,1,4);
	// Matriz_DIGRAPHInsertA(MG,4,5,1);*/
	// Matriz_DIGRAPHInsertA(MG, 0, 2, 8);
	// Matriz_DIGRAPHInsertA(MG, 0, 4, -4);
	// Matriz_DIGRAPHInsertA(MG, 0, 1, 3);
	// Matriz_DIGRAPHInsertA(MG, 3, 0, 2);
	// Matriz_DIGRAPHInsertA(MG, 3, 2, -5);
	// Matriz_DIGRAPHInsertA(MG, 1, 4, 7);
	// Matriz_DIGRAPHInsertA(MG, 1, 3, 1);
	// Matriz_DIGRAPHInsertA(MG, 2, 1, 4);
	// Matriz_DIGRAPHInsertA(MG, 4, 3, 6);
	// Matriz_DIGRAPHShow(MG);
	printf("\n");
	//Matriz_dijkstra(MG, 0);
/*	Matriz_GRAPHInsertE(MG,0,2,5);
	Matriz_GRAPHInsertE(MG,2,1,16);
	Matriz_GRAPHInsertE(MG,2,3,10);
	Matriz_GRAPHInsertE(MG,2,4,3);
	Matriz_GRAPHInsertE(MG,0,3,8);
	Matriz_GRAPHInsertE(MG,3,5,18);
	Matriz_GRAPHInsertE(MG,3,4,2);
	Matriz_GRAPHInsertE(MG,1,4,30);
	Matriz_GRAPHInsertE(MG,5,4,12);
	Matriz_GRAPHInsertE(MG,6,4,14);
	Matriz_GRAPHInsertE(MG,1,6,26);
	Matriz_GRAPHInsertE(MG,6,5,4);
	Matriz_DIGRAPHShow(MG);
	printf("\n");
	Matriz_prim1(MG);*/
	//Matriz_dijkstra(MG, 1);
	//Matriz_dijkstra(MG, 2);
	//Matriz_dijkstra(MG, 3);
	//Matriz_FLOYD_WARSHALL(MG);
	system("pause");
}