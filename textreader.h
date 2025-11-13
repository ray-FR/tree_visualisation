#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>




  
typedef struct chvec {
    /*! donne le nombre d'élements stockés dans le chvec. */
    size_t size;
    /*! max_size est le nombre (actuellement) maximal d'éléments à stocker */
    size_t max_size;
    /*! data est le pointeur vers le tableau dynamique d'éléments (ici des int) à stocker. */
    char ** data;
} chvec_t;

extern int issep(char txt);

extern chvec_t * newvec(void);

extern void addnewword (chvec_t* vec, char* buff);

extern void chevec_push_back(chvec_t* vec, char* data);