#include "grafos_ep22m.h"
#include "grafos_ep22Q.h"
#include "grafos_ep22PQ.h"

double **MATRIXDouble(int r, int c, double val)
{
    int i, j;
    double **m = malloc(r*sizeof(double*));
    for(i = 0; i < r; i++)
        m[i] = malloc(c*sizeof(double));
    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            m[i][j] = val;
    return m;
}

m_Digraph Matriz_DIGRAPHInit(int V)
{
    m_Digraph G = malloc(sizeof(m_Digraph));
    G->V = V;
    G->A = 0;
    custo = malloc(V*sizeof(double));
    parent = malloc(V*sizeof(int));
    fr = malloc(V*sizeof(int));
    cst = malloc(V*sizeof(double));
    ts = malloc(V*sizeof(Vertex));
    G->adj = MATRIXDouble(V,V,INFINITO);
    return G;
}

void Matriz_GRAPHInsertE(m_Digraph G, Vertex v, Vertex w, double cst)
{
	if(v < G->V && w < G->V && v != w)
    {
        Matriz_DIGRAPHInsertA(G,v,w,cst);
        Matriz_DIGRAPHInsertA(G,w,v,cst);
        G->A--;
	}
}

void Matriz_DIGRAPHInsertA(m_Digraph G, Vertex v, Vertex w, double cst)
{
    if(v != w && G->adj[v][w] == INFINITO)
    {
        G->adj[v][w] = cst;
        G->A++;
    }
}

void Matriz_dijkstra(m_Digraph G, Vertex s)
{
    Vertex v;
    int i;
    for(v = 0; v < G->V; v++)
    {
        cst[v] = INFINITO;
        parent[v] = -1;
    }
    Lista *l = PQInit(G->V);
    Dados *Vertice = malloc(sizeof(Dados));
    Vertice->prior = cst[s] = 0;
    Vertice->v = parent[s] = s;
    PQInsert(&l, Vertice);
    while(!PQEmpty(&l))
    {
        v = PQDelmin(&l);
        for(i = 0; i < G->V; i++)
            if(G->adj[v][i] != INFINITO && cst[i] == INFINITO){
                parent[i] = v;
                Vertice->prior = cst[i] = cst[v] + G->adj[v][i];
                Vertice->v = i;
                PQInsert(&l, Vertice);
            }
            else if(cst[i] > cst[v]+G->adj[v][i]){
                parent[i] = v;
                cst[i] = cst[v] + G->adj[v][i];
                PQDec(&l, cst[i]);
            }
    }
    Matriz_DIGRAPHShowCST(G);
    Matriz_DIGRAPHShowPARENT(G);
}

void Matriz_BELLMAN_ford2(m_Digraph G, Vertex s)
{
    Vertex v, w, k;
    double d;
    for(v = 0; v < G->V; v++)
        cst[v] = INFINITO;
    cst[s] = 0;
    for(k = 1; k < G->V; k++)
        for(w = 0; w < G->V; w++)
            for(v = 0; v < G->V; v++){
                d = cst[v] + G->adj[v][w];
                if(cst[w] > d)
                    cst[w] = d;
                d = 0;
            }
    Matriz_DIGRAPHShowCST(G);
}

void Matriz_FLOYD_WARSHALL(m_Digraph G)
{
    Vertex v, s, t, k, i, j; double d; double custo[G->V][G->V];
    for(v = 0; v < G->V; v++)
        for(k = 0; k < G->V; k++)
            if(v == k)
                custo[v][k] = 0;
            else
                custo[v][k] = G->adj[v][k];
    for(k = 0; k < G->V; k++)
        for(i = 0; i < G->V; i++)
            if(i != k && custo[i][k] < INFINITO)
                for(j = 0; j < G->V; j++){
                    d = custo[i][k] + custo[k][j];
                    if(d < custo[i][j])
                        custo[i][j] = d;
            }
    printf("\t");
    for(k = 0; k < G->V; k++)
        printf("|   %2d\t", k);
    printf("\n--------+-------");
    for(k = 1; k < G->V; k++)
        printf("+-------");
    printf("\n");
    for(k = 0; k < G->V; k++){
        printf("    %2d  ", k);
        for(v = 0; v < G->V; v++){
            if(custo[k][v] < INFINITO/2)
                printf("| %2.2lf\t", custo[k][v]);
            else
                printf("|   *\t");
        }
        printf("\n");
    }
}

void Matriz_DIGRAPHShow(m_Digraph G)
{
	Vertex v, w;
	printf("\t");
	for(v = 0; v < G->V; v++)
        printf("|  %2d \t",v);
    printf("\n--------+-------");
    for(v = 0; v < G->V-1; v++)
        printf("+-------");
	for(v = 0; v < G->V; v++){
		printf("\n    %2d\t", v);
		for(w = 0; w < G->V; w++){
			if(G->adj[v][w] != INFINITO)
				printf("| %3.2lf\t",G->adj[v][w]);
			else printf("|   *\t");
		}
	}
	printf("\n");
}

void Matriz_DIGRAPHShowCCST(Vertex V, double **d)
{
	Vertex v, w;
	printf("\t");
	for(v = 0; v < V; v++)
        printf("|  %3.2d \t",v);
    printf("\n--------+-------");
    for(v = 0; v < V-1; v++)
        printf("+-------");
	for(v = 0; v < V; v++){
		printf("\n    %3.2d\t", v);
		for(w = 0; w < V; w++){
			if(d[v][w] != INFINITO)
				printf("| %3.2lf\t",d[v][w]);
			else printf("|   *\t");
		}
	}
	printf("\n");
}

void Matriz_DIGRAPHShowCST(m_Digraph G)
{
    Vertex w;
    for(w = -1; w < G->V; w++)
        printf("________");
    printf("\n\n      i ");
    for(w = 0; w < G->V; w++)
        printf("|  %2d\t",w);
    printf("\n--------+-------");
    for(w = 1; w < G->V; w++)
        printf("+-------");
    printf("\n     CST");
    for(w = 0; w < G->V; w++){
        if(cst[w] != INFINITO)
            printf("| %3.2lf\t",cst[w]);
        else
            printf("|   *\t");
    }
    printf("\n");
    for(w = -1; w < G->V; w++)
        printf("________");
    printf("\n\n");
}

void Matriz_DIGRAPHShowPARENT(m_Digraph G)
{
    Vertex w;
    for(w = -1; w < G->V; w++)
        printf("________");
    printf("\n\n      i ");
    for(w = 0; w < G->V; w++)
        printf("|  %2d\t",w);
    printf("\n--------+-------");
    for(w = 1; w < G->V; w++)
        printf("+-------");
    printf("\n  PARENT");
    for(w = 0; w < G->V; w++)
        printf("|  %2d\t",parent[w]);
    printf("\n");
    for(w = -1; w < G->V; w++)
        printf("________");
    printf("\n\n");
}

void Matriz_DIGRAPHShowTS(m_Digraph G)
{
    Vertex w;
    printf("_______");
    for(w = 0; w < G->V; w++)
        printf("____");
    printf("\n");
    printf("  i ");
    for(w = 0; w < G->V; w++)
        printf("| %d ",w);
    printf("\n---+---");
    for(w = 1; w < G->V; w++)
        printf("+---");
    printf("\n TS");
    for(w = 0; w < G->V; w++)
        printf("| %d ",ts[w]);
    printf("\n_______");
    for(w = 0; w < G->V; w++)
        printf("____");
    printf("\n\n");
}

void Matriz_DIGRAPHdel(m_Digraph G)
{
    free(G);
}

void Matriz_prim1(m_Digraph G)
{
    Vertex v,w;
    fr = malloc(G->V*sizeof(int));
    for (v = 0; v < G->V; v++)
    {
        cst[v] = maxCST;
        parent[v] = -1;
        fr[v] = -1;
    }
    v = 0;
    cst[v] = 0;
    fr[v] = v;
    while(1)
    {
        double minCST = (double)maxCST;
        for(w = 0; w < G->V; w++)
            if(parent[w] == -1 && minCST > cst[w])
                minCST = cst[v=w];
        if(minCST == maxCST) break;
        parent[v] = fr[v];
        for(w = 0; w < G->V; w++)
            if(parent[w] == -1 && cst[w] > G->adj[v][w]){
                cst[w] = G->adj[v][w];
                fr[w] = v;
            }
    }
    Matriz_DIGRAPHShowCST(G);
    Matriz_DIGRAPHShowPARENT(G);
    Matriz_DIGRAPHShowFR(G);
}

void Matriz_DIGRAPHShowFR(m_Digraph G)
{
    Vertex w;
    printf("________");
    for(w = 0; w < G->V; w++)
        printf("________");
    printf("\n\n      i ");
    for(w = 0; w < G->V; w++)
        printf("|   %d\t",w);
    printf("\n--------+-------");
    for(w = 1; w < G->V; w++)
        printf("+-------");
    printf("\n FRANJA ");
    for(w = 0; w < G->V; w++)
        printf("|   %d\t",fr[w]);
    printf("\n________");
    for(w = 0; w < G->V; w++)
        printf("________");
    printf("\n\n");
}
