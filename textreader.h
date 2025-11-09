#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct chvec chvec_t;

  
  struct chvec {
    /*! donne le nombre d'élements stockés dans le chvec. */
    size_t size;
    /*! max_size est le nombre (actuellement) maximal d'éléments à stocker */
    size_t max_size;
    /*! data est le pointeur vers le tableau dynamique d'éléments (ici des int) à stocker. */
    char ** data;
  };

  extern chvec_t * newvec(void);
