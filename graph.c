#include "graph.h"

void prepareFile(FILE* f, chvec_t* v){
    fprintf(f, "digraph G {\n"); 
    addGraph(f, v, v->size/2, v->size);
    fprintf(f, "}\n");
    
    

}

void addGraph(FILE* f, chvec_t* v, int ind, int nbrelem){
    int ind_mb;
    int ind_mt;
    
    
    if (nbrelem == 1) {
        return;
    } 
    ind_mb = ind / 2;
    if (ind_mb != ind) fprintf(f, "%s -> %s\n", v->data[ind], v->data[ind_mb]);

    ind_mt = ind + (nbrelem - ind) / 2;
    if (ind_mt != ind) fprintf(f, "%s -> %s\n", v->data[ind], v->data[ind_mt]);

    if (ind_mb != ind) addGraph(f, v, ind_mb, nbrelem / 2);
    if (ind_mt != ind) addGraph(f, v, ind_mt, nbrelem - ind_mb);

    
    
}