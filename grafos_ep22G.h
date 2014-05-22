#ifndef GRAFOS_EP22G_H_INCLUDED
#define GRAFOS_EP22G_H_INCLUDED

typedef struct No
{
    int posto;
    int pai;
}No;

void MakeSet(No*, int);

void Union(No*,int,int);

No *inicializar(int);

No *FindSet(No *, int);

#endif // GRAFOS_EP22G_H_INCLUDED
