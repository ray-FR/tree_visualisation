#include "../include/graph.h"

void prepareFile(FILE* f, chvec_t* v, arb_t* a){
    fprintf(f, "digraph G {\n"); 
    fprintf(f, "    %d [label=\"%s\"]\n", a->ind, a->name);
    addGraph(f, v, a, a->ind);
    fprintf(f, "}\n");
}

void addGraph(FILE* f, chvec_t* v, arb_t* a, int n){
    // dot g.dot -Tpdf -o g.pdf && open g.pdf
    
    if (a == NULL) return;
    if (a->g != NULL) fprintf(f, "    %d [label=\"%s\"]\n", a->g->ind, a->g->name);

    if (a->d != NULL) fprintf(f, "    %d [label=\"%s\"]\n", a->d->ind, a->d->name);
    

    if (a->g != NULL) fprintf(f, "    %d:sw->%d\n", n, a->g->ind);
    
    if (a->d != NULL) fprintf(f, "    %d:se->%d\n\n", n, a->d->ind);
    

    
    if (a->g != NULL) addGraph(f, v, a->g, a->g->ind);
    if (a->d != NULL) addGraph(f, v, a->d, a->d->ind);




    

    
    
}