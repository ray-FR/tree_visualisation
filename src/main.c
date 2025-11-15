#include "../include/graph.h"

int main(int argc, char** argv){
    chvec_t* te;
    FILE* f;
    char buff[1024];
    te = newvec();
    assert(te);
    
    while (fgets(buff, sizeof buff, stdin) != NULL){
        addnewword(te, buff);
        
        
    }
    f = fopen("stuff/g.dot", "w");
    prepareFile(f, te);
    fclose(f);
    for(int i = 0; i<te->size; i++){
        free(te->data[i]);
    }
    free(te->data);
    return 0;

}