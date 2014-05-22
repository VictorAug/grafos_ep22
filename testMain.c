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
	MG = Matriz_DIGRAPHInit(6);
	Matriz_DIGRAPHShow(MG);
	printf("\n");
/*	Matriz_GRAPHInsertE(MG,0,4,4);
	Matriz_GRAPHInsertE(MG,1,5,5);
	Matriz_GRAPHInsertE(MG,2,6,6);
	Matriz_GRAPHInsertE(MG,3,7,9);
	Matriz_GRAPHInsertE(MG,4,8,1);
	Matriz_GRAPHInsertE(MG,5,2,11);
	Matriz_GRAPHInsertE(MG,6,0,3);
	Matriz_GRAPHInsertE(MG,7,1,9);
	Matriz_GRAPHInsertE(MG,8,2,2);
	Matriz_GRAPHInsertE(MG,7,3,12);
	Matriz_GRAPHInsertE(MG,0,4,0);
	Matriz_GRAPHInsertE(MG,7,8,11);
	Matriz_GRAPHInsertE(MG,1,0,3);
	Matriz_GRAPHInsertE(MG,4,1,10);
	Matriz_GRAPHInsertE(MG,7,2,2);
	Matriz_GRAPHInsertE(MG,4,3,12);
	Matriz_GRAPHInsertE(MG,0,4,0);
	Matriz_GRAPHInsertE(MG,1,5,3);
	Matriz_GRAPHInsertE(MG,2,6,1);
	Matriz_GRAPHInsertE(MG,3,7,15);
	Matriz_GRAPHInsertE(MG,3,5,2);*/
	Matriz_GRAPHInsertE(MG,0,1,5);
	Matriz_GRAPHInsertE(MG,0,3,10);
	Matriz_GRAPHInsertE(MG,1,2,3);
	Matriz_GRAPHInsertE(MG,2,3,1);
	Matriz_DIGRAPHShow(MG);
	printf("\n");
	Matriz_dijkstra(MG, 0);
	Matriz_dijkstra(MG, 1);
	Matriz_dijkstra(MG, 2);
	Matriz_dijkstra(MG, 3);
	//Matriz_FLOYD_WARSHALL(MG);
/*	Lista *l = PQInit(10);
	Dados *data = malloc(sizeof(Dados));
	data->v = 5;
	data->prior = 10;
	PQInsert(&l, data);
		data->v = 6;
	data->prior = 5;
	PQInsert(&l, data);
		data->v = 8;
	data->prior = 2;
	PQInsert(&l, data);
		data->v = 1;
	data->prior = 7;
	PQInsert(&l, data);
	listar(l);*/
}