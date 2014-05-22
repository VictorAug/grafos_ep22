#ifndef GRAFOS_EP22Q_H_INCLUDED
#define GRAFOS_EP22Q_H_INCLUDED
#include "grafos_ep22.h"

void QUEUEInit(int);

int QUEUEEmpty();

void QUEUEPut(Vertex);

Vertex QUEUEGet();

void QUEUEFree();

#endif // GRAFOS_EP22Q_H_INCLUDED
