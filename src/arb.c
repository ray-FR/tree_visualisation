#include "../include/arb.h"


arb_t* allC(char* v, int ind, arb_t* fg, arb_t* fd){
    arb_t* r = malloc (sizeof *r);
    assert(r);
    r->name = v;
    r->ind = ind;
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

void assC(arb_t **a, chvec_t *v, int start, int end)
{
    if (start > end) return;

    int mid = (start + end) / 2;

    // create this node
    *a = allC(v->data[mid], mid, NULL, NULL);

    // lower middle on the left
    assC(&(*a)->g, v, start, mid - 1);

    // upper middle on the right
    assC(&(*a)->d, v, mid + 1, end);
}
