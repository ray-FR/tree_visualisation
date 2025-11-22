#include "../include/struct.h"
#include "../include/textreader.h"
#include "../include/graph.h"
#include "../include/arb.h"




int main(int argc, char** argv){
    chvec_t* te;
    FILE* f;
    arb_t* a;
    char buff[1024];
    te = newvec();
    assert(te);
    
    while (fgets(buff, sizeof buff, stdin) != NULL) addnewword(te, buff);
    
    for (int i = 0; i<te->size; i++) printf("%d %s\n", i, te->data[i]);
    
    assC(&a, te, 0, te->size - 1);
    printf("\n");
    f = fopen("stuff/g.dot", "w");
    prepareFile(f, te, a);
    fclose(f);
    for(int i = 0; i<te->size; i++){
        free(te->data[i]);
    }
    free(te->data);
    return 0;

}