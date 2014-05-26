#include "grafos_ep22.h"
#include "grafos_ep22adj.h"
#include "grafos_ep22Q.h"
#include "grafos_ep22PQ.h"

link NEW(Vertex w, double cst, link next){
    link x = malloc(sizeof(link));
    x->w = w;
    x->cst = cst;
    x->next = next;
    printf("news finished\n");
    return x;
}

adj_Digraph adj_DIGRAPHInit(int V){
    Vertex v;
    adj_Digraph G = malloc(sizeof(adj_Digraph));
    G->V = V;
    G->A = 0;
    G->adj = malloc(V*sizeof(link));
    for(v = 0; v < V; v++)
        G->adj[v] = NULL;
    return G;
}

void adj_DIGRAPHInsertA(adj_Digraph G, Vertex v, Vertex w, double cst){
    link p;
    if(v == w) return;
    for(p = G->adj[v]; p != NULL; p = p->next)
        if(p->w == w) return;
    printf("1\n");
    G->adj[v] = NEW(p->w, cst, G->adj[v]);
    printf("2\n");
    G->A++;
}

int adj_GRAPHInsertE(adj_Digraph G, Vertex v, Vertex w, double cst){
	if(G->V > v && G->V > w && v != w){
		adj_DIGRAPHInsertA(G,w,v,cst);
		adj_DIGRAPHInsertA(G,v,w,cst);
		return 1;
	}
	else return 0;
}

void adj_DIGRAPHShow(adj_Digraph G){
	Vertex v;
	link p;
	for (v = 0; v < G->V; v++){
		printf("|%2d| ", v);
		for (p = G->adj[v]; p != NULL; p = p->next){
			printf("->| %2d |", p->w);
			printf("%3.2lf|");
		}
		printf("\n");
	}
}

void adj_DAGmin(adj_Digraph G, Vertex s){//só para digrafo
    Vertex v;
    link p;
    int i;
    for(v = 0; v < G->V; v++)
        cst[v] = INFINITO;
    adj_DIGRAPHShowCST(G);
    cst[s] = 0;
    adj_DIGRAPHShowCST(G);
    for(v = ts[i=0]; i < G->V; v = ts[i++])
        for(p = G->adj[v]; p != NULL; p = p->next)
            if(cst[p->w] > cst[v] + p->cst)
                cst[p->w] = cst[v] + p->cst;
    adj_DIGRAPHShowCST(G);
}

void adj_dijkstra(adj_Digraph G, Vertex s){
    Vertex v, w;
    Dados *data = malloc(sizeof(Dados));
    link p;
    for(v = 0; v < G->V; v++){
        cst[v] = INFINITO;
        parent[v] = -1;
    }
    Lista *l;
    l = PQInit(G->V);
    data->prior = s;
    data->v = G->V;
    cst[s] = 0;
    parent[s] = s;
    PQInsert(&l, data);
    while(!PQEmpty(&l)){
        v = PQDelmin(&l);
        for(p = G->adj[v]; p != NULL; p = p->next)
            if(cst[w=p->w] == INFINITO){
                parent[w] = v;
                cst[w] = cst[v] + p->cst;
                PQInsert(&l,data);
            }
            else if(cst[w] > cst[v] + p->cst){
                parent[w] = v;
                cst[w] = cst[v] + p->cst;
                PQDec(&l,w);
            }
    }
    listar(l);
}

int adj_BELLMAN_ford(adj_Digraph G, Vertex s){
    Vertex v, w; link p; int k = 0;
    for(v = 0; v < G->V; v++){
        cst[v] = maxCST;
        parent[v] = -1;
    }
    QUEUEInit(G->V);
    cst[s] = 0;
    parent[s] = s;
    QUEUEPut(s);
    QUEUEPut(SENTINELA);
    while(!QUEUEEmpty()){
        v = QUEUEGet();
        if(v == SENTINELA){
            if(k++ == G->V){
                if(!QUEUEEmpty()) return 0;
                else return 1;
            }
            QUEUEPut(SENTINELA);
        }
        else{
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

void adj_DIGRAPHShowTS(adj_Digraph G){
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

void adj_DIGRAPHShowCST(adj_Digraph G){
    Vertex w;
    printf("_______");
    for(w = 0; w < G->V; w++)
        printf("____");
    printf("\n");
    printf("  i ");
    for(w = 0; w < G->V; w++)
        printf("| %d ",w);
    printf("\n----+---");
    for(w = 1; w < G->V; w++)
        printf("+---");
    printf("\n CST");
    for(w = 0; w < G->V; w++)
        printf("| %d ",cst[w]);
    printf("\n____");
    for(w = 0; w < G->V; w++)
        printf("____");
    printf("\n\n");
}

void adj_DIGRAPHdel(adj_Digraph G){
    free(G);
}

void adj_DIGRAPHShowPARENT(adj_Digraph G){
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
}

void adj_prim2(adj_Digraph G){
    link p; Vertex v, w;Lista *l;Dados *data;
    PQInit(G->V);
    for(v = 0; v < G->V; v++)
        parent[v] = fr[v] = -1;
    v = 0;
    cst[v] = 0;
    fr[v] = v;
    PQInsert(&l,data);
    while(!PQEmpty(&l)){
        v = PQDelmin(&l);
        parent[v] = fr[v];
        for(p = G->adj[v]; p != NULL; p = p->next){
            w = p->w;
            if(parent[w] == -1){
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
}

void adj_Kruskal(adj_Digraph G){

}
