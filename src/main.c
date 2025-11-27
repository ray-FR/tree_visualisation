#include "../include/struct.h"
#include "../include/textreader.h"
#include "../include/graph.h"
#include "../include/arb.h"




int main(int argc, char** argv){
    chvec_t* te;
    arb_t* a;
    char buff[1024];
    te = newvec();
    assert(te);
    
    while (fgets(buff, sizeof buff, stdin) != NULL) addnewword(te, buff);
    
    
    assC(&a, te, 0, te->size - 1);
    prepareFile(te, a);
    for(int i = 0; i<te->size; i++){
        free(te->data[i]);
    }
    free(te->data);
    return 0;

}