#include "grafos_ep22m.h"
#include "grafos_ep22Q.h"
double **custo, **ccst;

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
    Vertex v, w;
    custo = G->adj;
    for(v = 0; v < G->V; v++)
    {
        cst[v] = INFINITO;
        parent[v] = -1;
    }
    QUEUEInit(G->V);
    cst[s] = 0;
    parent[s] = s;
    QUEUEPut(s);
    while(!QUEUEEmpty())
    {
        v = QUEUEGet();
    }
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
                if(G->adj[v][w] != INFINITO)
                    d = cst[v] + G->adj[v][w];
                else d = cst[v];
                if(d < INFINITO)
                    if(cst[w] > d && d < INFINITO-1)
                        cst[w] = d;
                d = 0;
            }
    Matriz_DIGRAPHShowCST(G);
}

void Matriz_FLOYD_WARCHALL(m_Digraph G)
{
    Vertex v, s, t, k; double d;
    for(s = 0; s < G->V; s++)
        for(v = 0; v < G->V; v++)
            ccst[s][t] = G->adj[s][t];
    for(k = 1; k < G->V; k++)
        for(s = 0; s < G->V; s++)
            for(t = 0; t < G->V; t++){
                d = ccst[s][k-1] + ccst[k-1][t];
                if(ccst[s][t] > d)
                    ccst[s][t] = d;
            }
//    Matriz_DIGRAPHShowCusto(G, custo);
}

void Matriz_DIGRAPHShow(m_Digraph G)
{
	Vertex v, w;
	printf("\t");
	for(v = 0; v < G->V; v++)
        printf("|  %3.2d \t",v);
    printf("\n--------+-------");
    for(v = 0; v < G->V-1; v++)
        printf("+-------");
	for(v = 0; v < G->V; v++){
		printf("\n    %3.2d\t", v);
		for(w = 0; w < G->V; w++){
			if(G->adj[v][w] != INFINITO)
				printf("| %3.2lf\t",G->adj[v][w]);
			else printf("|   *\t");
		}
	}
	printf("\n");
}

void Matriz_DIGRAPHShowCST(m_Digraph G)
{
    Vertex w;
    printf("____");
    for(w = 1; w < G->V; w++)
        printf("______");
    printf("\n\n  i ");
    for(w = 0; w < G->V; w++)
        printf("|   %d\t",w);
    printf("\n----+------");
    for(w = 1; w < G->V; w++)
        printf("+------");
    printf("\n CST");
    if(cst[0] != INFINITO)
        printf("| %3.2lf\t",cst[0]);
    else
        printf("|  *\t");
    for(w = 1; w < G->V; w++){
        if(cst[w] == INFINITO)
            printf("|  *\t");
        else
            printf("| %3.2lf\t",cst[w]);
    }
    printf("\n____");
    for(w = 1; w < G->V; w++)
        printf("______");
    printf("\n\n");
}

void Matriz_DIGRAPHShowDIST(m_Digraph G)
{
    Vertex w;
    printf("__________________________\n");
    printf("  i ");
    for(w = 0; w < G->V; w++)
        printf("| %d ",w);
    printf("\n----+---");
    for(w = 1; w < G->V; w++)
        printf("+---");
    printf("\nDIST");
    for(w = 0; w < G->V; w++)
        printf("| %d ",dist[w]);
    printf("\n__________________________");
    printf("\n\n");
}

void Matriz_DIGRAPHShowPARENT(m_Digraph G)
{
    Vertex w;
    printf("_______");
    for(w = 0; w < G->V; w++)
        printf("____");
    printf("\n\n  i ");
    for(w = 0; w < G->V; w++)
        printf("| %d ",w);
    printf("\n------+---");
    for(w = 1; w < G->V; w++)
        printf("+---");
    printf("\nPARENT");
    for(w = 0; w < G->V; w++)
        printf("| %d ",parent[w]);
    printf("\n_______");
    for(w = 0; w < G->V; w++)
        printf("____");
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
            if(parent[w] == -1 && minCST)
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
}


