#ifndef GRAPH_H
#define GRAPH_H


#include "struct.h"


extern void prepareFile(FILE* f, chvec_t* v, arb_t* a);
extern void addGraph(FILE* f, chvec_t* v, arb_t* a, int n);

#endif