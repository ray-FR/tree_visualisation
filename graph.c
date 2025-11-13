#include "graph.h"

void prepareFile(FILE* f, chvec_t* v){
    fprintf(f, "diagraph G {\n"); 
    addGraph(f, v, v->size, v->size);
    fprintf(f, "}\0");
    

}

void addGraph(FILE* f, chvec_t* v, int ind, int nbrelem){
    
    int ind_mb;
    int ind_mt;
    while (nbrelem >= 1){
        if (nbrelem == 1) fprintf(f, "%s\n", v->data[ind]); return;
        

    }
    
}