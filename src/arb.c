#include "../include/arb.h"


arb_t* allC(char* v, arb_t* fg, arb_t* fd){
    arb_t* r = malloc (sizeof *r);
    assert(r);
    r->name = v;
    r->g = fg;
    r->d = fd;
    return r;
}

void priC(arb_t* a){
    // pour afficher un arbre (par un parcours préfixe)
    if(a==NULL){
        printf("V "); // V pour vide
        return;
    }
    printf("%s ",a->name);
    priC(a->g);
    priC(a->d);
}

void libC(arb_t** a){
    if(*a==NULL) return;
    libC(&(**a).g);
    libC(&(**a).d);
    free(*a);
    *a=NULL;
}