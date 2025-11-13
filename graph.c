#include "graph.h"

void prepareFile(FILE* f, chvec_t* v){
    fprintf(f, "diagraph G {\n"); 
    addGraph(f, v);
    fprintf(f, "}\0");
    

}