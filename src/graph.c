#include "../include/graph.h"

void prepareFile(chvec_t* v, arb_t* a){
    printf("digraph G {\n"); 
    printf("    %d [label=\"%s\"]\n", a->ind, a->name);
    addGraph(v, a, a->ind);
    printf("}\n");
}

void addGraph(chvec_t* v, arb_t* a, int n){
    // dot g.dot -Tpdf -o g.pdf && open g.pdf
    
    if (a == NULL) return;
    if (a->g != NULL) printf("    %d [label=\"%s\"]\n", a->g->ind, a->g->name);

    if (a->d != NULL) printf("    %d [label=\"%s\"]\n", a->d->ind, a->d->name);
    

    if (a->g != NULL) printf("    %d:sw->%d\n", n, a->g->ind);
    
    if (a->d != NULL) printf("    %d:se->%d\n\n", n, a->d->ind);
    

    
    if (a->g != NULL) addGraph(v, a->g, a->g->ind);
    if (a->d != NULL) addGraph(v, a->d, a->d->ind);




    

    
    
}