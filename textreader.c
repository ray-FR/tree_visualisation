#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include "textreader.h"

chvec_t * newvec(void) {
  chvec_t * vec = malloc(1 * sizeof *vec);
  assert(vec);
  vec->size = 0;
  vec->max_size = 1024;
  vec->data = malloc(vec->max_size * sizeof **(vec->data));
  assert(vec->data);
  return vec;
}


int issep(char txt){
    if (isspace(txt) || txt == '!' || txt == '?' || txt == '.' || txt == '-' || txt == ',' || txt == ';' || txt == ':'){
        return 1;
    }
    return 0;}




int main(){
    //char buff[1024];
    chvec_t* t = newvec();
    assert(t);
    //int numvec = 0;
    // while (fgets(buff, sizeof buff, stdin) != NULL){
    //     int i = 0;
    //     int taillem = 1;
    //     int iss = 0;
    //     while(buff[i] != '\n'){
    //         if (!issep(buff[i])){
    //             iss = 0;
    //             taillem++;
    //         }
    //         else{
    //             if (!iss){
    //                 // te = movetonewvec(numvec, te, taillem);
    //                 // strncpy(te[numvec].mot, &(buff[i]), taillem);
    //                 taillem = 0;
    //                 iss = 1;
    //                 numvec++;
    //             }
    //         }
    //         i++;
    //     }    
    //     // for (int i = 0; i<numvec;i++){
    //     //     printf("%d: %s", te[i].t, te[i].mot);
    //     // }
    

    // }


    return 0;

}