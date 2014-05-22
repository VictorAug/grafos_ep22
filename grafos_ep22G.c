#include "grafos_ep22G.h"

void MakeSet(No *v, int i)
{
    v[i].pai = i;
    v[i].posto = 0;
}

No *inicializar(int tam)
{
    No *no;
    int i;
    no = malloc(tam*sizeof(No));
    for(i = 0;i < tam; i++)
        MakeSet(no, i);
    return no;
}

void Union(No *conj, int u, int v)
{
    int i = FindSet(conj,u);
    int j = FindSet(conj,v);
    if(conj[i].posto > conj[j].posto)
    {
        conj[j].pai = i;
    }
    else
    {
        conj[j].pai = i;
        if(conj[i].posto == conj[j].posto)
            conj[j].posto++;
    }
}

No *FindSet(No *v, int i)
{
    if(i != v[i].pai)
        v[i].pai = FindSet(v, v[i].pai);
    return v[i].pai;
}
