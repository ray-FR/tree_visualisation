#include "../include/struct.h"
#include "../include/textreader.h"
#include "../include/graph.h"
#include "../include/arb.h"




int main(int argc, char** argv){
    if (argc < 2) {
        printf("Usage: cat path/to/file | ./graph where/to/save+name.dot\n");
        exit(1);
    }
    chvec_t* te;
    FILE* f;
    arb_t* a;
    char buff[1024];
    te = newvec();
    assert(te);
    
    while (fgets(buff, sizeof buff, stdin) != NULL) addnewword(te, buff);
    
    
    assC(&a, te, 0, te->size - 1);
    f = fopen(argv[1], "w");
    prepareFile(f, te, a);
    fclose(f);
    printf("Done! saved to %s\n", argv[1]);
    for(int i = 0; i<te->size; i++){
        free(te->data[i]);
    }
    free(te->data);
    return 0;

}