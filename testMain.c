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
	AD = adj_DIGRAPHInit(6);
	adj_DIGRAPHInsertA(AD, 0, 2, 7);
	adj_DIGRAPHInsertA(AD, 0, 3, 2);
	adj_DIGRAPHInsertA(AD, 0, 4, 4);
	adj_DIGRAPHInsertA(AD, 1, 2, 0);
	adj_DIGRAPHInsertA(AD, 2, 4, 1);
	adj_DIGRAPHInsertA(AD, 3, 4, 1);
	adj_DIGRAPHInsertA(AD, 3, 5, 3);
	adj_DIGRAPHInsertA(AD, 4, 1, 4);
	adj_DIGRAPHInsertA(AD, 4, 5, 1);
	adj_DIGRAPHInsertA(AD, 5, 1, 2);
	/*DAGtsf(AD);
	adj_DIGRAPHShowTS(AD);
	adj_DAGmin(AD, 0);*/

	adj_dijkstra(AD, 0);

	/*Matriz_DIGRAPHInsertA(MG,0,2,7);
	Matriz_DIGRAPHInsertA(MG,0,3,2);
	Matriz_DIGRAPHInsertA(MG,0,4,4);
	Matriz_DIGRAPHInsertA(MG,2,4,1);
	Matriz_DIGRAPHInsertA(MG,3,4,1);
	Matriz_DIGRAPHInsertA(MG,3,5,3);
	Matriz_DIGRAPHInsertA(MG,1,2,0);
	Matriz_DIGRAPHInsertA(MG,5,1,2);
	Matriz_DIGRAPHInsertA(MG,4,1,4);
	Matriz_DIGRAPHInsertA(MG,4,5,1);
	Matriz_DIGRAPHShow(MG);
	printf("\n");*/
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
	// Lista *l = PQInit(10);
	// Dados *data = malloc(sizeof(Dados));
	// data->v = 0;
	// data->prior = 1;
	// PQInsert(&l, data);
	// 	data->v = 1;
	// data->prior = 3;
	// PQInsert(&l, data);
	// 	data->v = 2;
	// data->prior = 6;
	// PQInsert(&l, data);
	// 	data->v = 3;
	// data->prior = 4;
	// PQInsert(&l, data);
	// listar(l);
	// printf("%d\n", PQDelmin(&l));
	// listar(l);
	// printf("%d\n", PQDelmin(&l));
	// listar(l);
	// printf("%d\n", PQDelmin(&l));
	// listar(l);
	// printf("%d\n", PQDelmin(&l));
	// listar(l);
	system("pause");
}