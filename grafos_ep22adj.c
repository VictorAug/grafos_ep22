#include "grafos_ep22.h"
#include "grafos_ep22adj.h"
#include "grafos_ep22Q.h"
#include "grafos_ep22PQ.h"

<<<<<<< HEAD
static int *lbl, *ts, cnt;

link NEW(Vertex w, double cst, link next)
{
    link p = malloc(sizeof *p);
    p->w = w;
    p->cst = cst;
    p->next = next;
    return p;
=======
link NEW(Vertex w, double cst, link next){
    link x = malloc(sizeof*x);
    x->w = w;
    x->cst = cst;
    x->next = next;
    return x;
>>>>>>> 0131f0244b52480602700e47025db452474a064e
}

adj_Digraph adj_DIGRAPHInit(int V)
{
    Vertex v;
<<<<<<< HEAD
    adj_Digraph G = malloc(sizeof *G);
=======
    adj_Digraph G = malloc(sizeof*G);
>>>>>>> 0131f0244b52480602700e47025db452474a064e
    G->V = V;
    G->A = 0;
    custo = malloc(V*sizeof(double));
    parent = malloc(V*sizeof(int));
    fr = malloc(V*sizeof(int));
    cst = malloc(V*sizeof(double));
    ts = malloc(V*sizeof(Vertex));
    //vari�veis globais declaradas em grafos_ep22.h
    G->adj = malloc(V*sizeof(link));
    for(v = 0; v < V; v++)
        G->adj[v] = NULL;
    return G;
}

void adj_DIGRAPHInsertA(adj_Digraph G, Vertex v, Vertex w, double cst)
{
    link p;
<<<<<<< HEAD
    if(v == w) return;
    for(p = G->adj[v]; p != NULL; p = p->next){
        if(p->w == w) return;
        G->adj[v] = NEW(p->w, cst, NULL);
        G->A++;
    }
=======
    if(v == w)
        return;
    for(p = G->adj[v]; p != NULL; p = p->next)
        if(p->w == w)
            return;
    G->adj[v] = NEW(w, cst, G->adj[v]);
    G->A++;
>>>>>>> 0131f0244b52480602700e47025db452474a064e
}

void adj_GRAPHInsertE(adj_Digraph G, Vertex v, Vertex w, double cst)
{
	if(v < G->V && w < G->V && v != w)
    {
        adj_DIGRAPHInsertA(G,v,w,cst);
        adj_DIGRAPHInsertA(G,w,v,cst);
        G->A--;
	}
}

/*void adj_DIGRAPHShow(adj_Digraph G)
{
	Vertex v;
	link p;
<<<<<<< HEAD
	printf("\n| V |");
	for(v = 0; v < G->V; v++)
        printf("");
    printf("\n");
	printf("+--+");
	printf("\n");
	for (v = 0; v < G->V; v++)
	{
		printf("|%2d| ->", v);
		for (p = G->adj[v]; p != NULL; p = p->next){
			printf("| %2d |", p->w);
			printf("%3.2lf|",p->cst);
		}
=======
	for (v = 0; v < G->V; v++){
		printf("%d\t", v);
		for (p = G->adj[v]; p != NULL; p = p->next)
            printf("%d -- %2.1f\t", p->w, p->cst);
>>>>>>> 0131f0244b52480602700e47025db452474a064e
		printf("\n");
	}
	printf("\n");
}*/

void adj_DIGRAPHShow(adj_Digraph G)
{
	Vertex v, w, temp = 0;
    link p;
    printf(" V |");
    for(v = 0; v < G->V; v++){
        w = 0;
        for(p = G->adj[v]; p != NULL; p = p->next)
            w++;
        if(temp < w)
            temp = w;
    }
    for(v = 0; v < temp; v++)
        printf("    | W |  cst  |");
    printf("\n---+    +---+-------+");
    for(v = 1; v < temp; v++)
        printf("    +---+-------+");
    for(v = 0; v < G->V; v++)
    {
        printf("\n%2d |",v);
        for(p = G->adj[v]; p != NULL; p = p->next)
        {
            if(p->cst < 0)
                printf(" -> |%2d | %2.2lf |",p->w,p->cst);
            else
                printf(" -> |%2d | %2.2lf  |",p->w,p->cst);
        }
    }
    printf("\n\n");
}

void adj_DAGmin(adj_Digraph G, Vertex s)     //s� para digrafo
{
    Vertex v;
    link p;
    int i;
    //ts = malloc((G->V)*sizeof(int));
    adj_DAGts2(G);
    for(v = 0; v < G->V; v++)
        cst[v] = INFINITO;
    cst[s] = 0;
    for(v = ts[i=0]; i < G->V; v = ts[i++])
        for(p = G->adj[v]; p != NULL; p = p->next)
            if(cst[p->w] > cst[v] + p->cst)
                cst[p->w] = cst[v] + p->cst;
    adj_DIGRAPHShowCST(G);
    adj_DIGRAPHShowTS(G);
}

void adj_DAGts2(adj_Digraph G)
{
    Vertex v;
    cnt = G->V - 1;
    lbl = malloc((G->V)*sizeof(int));
    for(v = 0; v < G->V; v++)
        ts[v] = lbl[v] = -1;
    for(v = 0; v < G->V; v++)
        if(lbl[v] == -1)
            adj_TSdfsR(G, v, lbl);
}

void adj_TSdfsR(adj_Digraph G, Vertex v, int* lbl)
{
    link p;
    lbl[v] = 0;
    for(p = G->adj[v]; p != NULL; p = p->next)
        if(lbl[p->w] == -1)
            adj_TSdfsR(G, p->w, lbl);
    ts[cnt--] = v;
}

void adj_dijkstra(adj_Digraph G, Vertex s)
{
    Vertex v, w;
    link p;
    for(v = 0; v < G->V; v++)
    {
        cst[v] = INFINITO;
        parent[v] = -1;
    }
<<<<<<< HEAD
    Lista *l;
    l = PQInit(G->V);
    data->prior = s;
    data->v = G->V;
    cst[s] = 0;
    parent[s] = s;
    PQInsert(&l, data);
    while(!PQEmpty())
    {
        v = PQDelmin(&l);
=======
    Lista *l = PQInit(G->V);
    Dados *Vertice = malloc(sizeof(Dados));
    Vertice->prior = cst[s] = 0;
    Vertice->v = parent[s] = s;
    PQInsert(&l, Vertice);
    while(!PQEmpty(&l)){
        listar(l);
        printf("%d\n\n", v = PQDelmin(&l));
>>>>>>> 0131f0244b52480602700e47025db452474a064e
        for(p = G->adj[v]; p != NULL; p = p->next)
            if(cst[w=p->w] == INFINITO)
            {
                parent[w] = v;
                Vertice->prior = cst[w] = cst[v] + p->cst;
                Vertice->v = w;
                PQInsert(&l,Vertice);
                listar(l);
            }
            else if(cst[w] > cst[v] + p->cst)
            {
                parent[w] = v;
                cst[w] = cst[v] + p->cst;
                PQDec(&l,cst[w]);
                listar(l);
            }
    }
    adj_DIGRAPHShowCST(G);
    adj_DIGRAPHShowPARENT(G);
}

int adj_BELLMAN_ford(adj_Digraph G, Vertex s)
{
    Vertex v, w; link p; int k = 0;
    for(v = 0; v < G->V; v++)
    {
        cst[v] = maxCST;
        parent[v] = -1;
    }
    QUEUEInit(G->V);
    cst[s] = 0;
    parent[s] = s;
    QUEUEPut(s);
    QUEUEPut(SENTINELA);
    while(!QUEUEEmpty())
    {
        v = QUEUEGet();
        if(v == SENTINELA)
        {
            if(k++ == G->V){
                if(!QUEUEEmpty()) return 0;
                else return 1;
            }
            QUEUEPut(SENTINELA);
        }
        else
        {
            for(p = G->adj[v]; p != NULL; p = p->next)
                if(cst[w=p->w] > cst[v] + p->cst){
                    cst[w] = cst[v] + p->cst;
                    parent[w] = v;
                    QUEUEPut(w);
                }
        }
    }
    return 0;
}

/*void adj_DIGRAPHShowTS(adj_Digraph G)
{
    Vertex w;
    printf("___");
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
    printf("\n__________________________");
    printf("\n\n");
}

void adj_DIGRAPHShowCST(adj_Digraph G)
{
    Vertex w;
    printf("_______");
    for(w = 0; w < G->V; w++)
        printf("____");
    printf("\n\n");
    printf("  i ");
    for(w = 0; w < G->V; w++)
        printf("| %d ",w);
    printf("\n----+---");
    for(w = 1; w < G->V; w++)
        printf("+---");
    printf("\n CST");
    for(w = 0; w < G->V; w++)
        printf("| %2.1f ",cst[w]);
    printf("\n____");
    for(w = 0; w < G->V; w++)
        printf("____");
    printf("\n\n");
}*/

void adj_DIGRAPHShowTS(adj_Digraph G)
{
    Vertex w;
    printf("____");
    for(w = 0; w < G->V; w++)
        printf("________");
    printf("\n\n  i ");
    for(w = 0; w < G->V; w++)
        printf("|   %d   ",w);
    printf("\n----+-------");
    for(w = 1; w < G->V; w++)
        printf("+-------");
    printf("\n TS ");
    for(w = 0; w < G->V; w++)
        printf("|   %d   ",ts[w]);
    printf("\n____");
    for(w = 0; w < G->V; w++)
        printf("________");
    printf("\n\n");
}

void adj_DIGRAPHShowCST(adj_Digraph G)
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
        if(cst[w] < INFINITO/2)
            printf("| %2.2lf\t",cst[w]);
        else
            printf("|   *\t");
    }
    printf("\n");
    for(w = -1; w < G->V; w++)
        printf("________");
    printf("\n\n");
}

void adj_DIGRAPHdel(adj_Digraph G)
{
    free(G);
}

void adj_DIGRAPHShowFRANJA(adj_Digraph G)
{
    Vertex w;
    printf("_______");
    for(w = 0; w < G->V; w++)
        printf("________");
    printf("\n\n     i ");
    for(w = 0; w < G->V; w++)
        printf("|   %d   ",w);
    printf("\n-------+-------");
    for(w = 1; w < G->V; w++)
        printf("+-------");
    printf("\n FRANJA");
    for(w = 0; w < G->V; w++)
        printf("|   %d   ",fr[w]);
    printf("\n_______");
    for(w = 0; w < G->V; w++)
        printf("________");
    printf("\n\n");
}

void adj_DIGRAPHShowPARENT(adj_Digraph G)
{
    Vertex w;
    printf("________");
    for(w = 0; w < G->V; w++)
        printf("________");
    printf("\n\n     i ");
    for(w = 0; w < G->V; w++)
        printf("|   %d\t",w);
    printf("\n-------+--------");
    for(w = 1; w < G->V; w++)
        printf("+-------");
    printf("\n PARENT");
    for(w = 0; w < G->V; w++)
        printf("|   %d\t",parent[w]);
    printf("\n________");
    for(w = 0; w < G->V; w++)
        printf("________");
    printf("\n\n");
}

void adj_DIGRAPHdel(adj_Digraph G)
{
    free(G);
}

/*void adj_DIGRAPHShowPARENT(adj_Digraph G)
{
    Vertex w;
    printf("_______");
    for(w = 0; w < G->V; w++)
        printf("____");
    printf("\n");
    printf("  i ");
    for(w = 0; w < G->V; w++)
        printf("| %d ",w);
    printf("\n-------+---");
    for(w = 1; w < G->V; w++)
        printf("+---");
    printf("\n PARENT");
    for(w = 0; w < G->V; w++)
        printf("| %d ",cst[w]);
    printf("\n_______");
    for(w = 0; w < G->V; w++)
        printf("____");
    printf("\n\n");
}*/

void adj_prim2(adj_Digraph G)
{
    link p; Vertex v, w;Lista *l;Dados *data;
    PQInit(G->V);
    for(v = 0; v < G->V; v++)
        parent[v] = fr[v] = -1;
    v = 0;
    cst[v] = 0;
    fr[v] = v;
    PQInsert(&l,data);
    while(!PQEmpty())
    {
        v = PQDelmin(&l);
        parent[v] = fr[v];
        for(p = G->adj[v]; p != NULL; p = p->next)
        {
            w = p->w;
            if(parent[w] == -1)
            {
                if(fr[w] == -1){
                    cst[w] = p->cst;
                    fr[w] = v;
                    PQInsert(&l,w);
                }
                else if(cst[w] > p->cst){
                    fr[w] = v;
                    cst[w] = p->cst;
                    PQDec(&l,w);
                }
            }
        }
    }
    adj_DIGRAPHShowCST(G);
    adj_DIGRAPHShowPARENT(G);
    adj_DIGRAPHShowFRANJA(G);
}

void adj_Kruskal(adj_Digraph G)
{

}
int DAGtsf(adj_Digraph G){
    int i, in[G->V];
    Vertex v;
    link p;
    for(v=0; v<G->V; v++)
        in[v] = 0;
    for(v=0; v<G->V; v++)
        for(p=G->adj[v]; p!=NULL; p=p->next)
            in[p->w]++;
    QUEUEInit(G->V);
    for(v=0; v<G->V; v++)
        if(in[v] == 0)
            QUEUEPut(v);
    for(i=0; !QUEUEEmpty();i++){
        ts[i] = v = QUEUEGet();
        for(p=G->adj[v]; p!=NULL; p=p->next)
            if(--in[p->w] == 0)
                QUEUEPut(p->w);
    }
    QUEUEFree();
    return i;
}
