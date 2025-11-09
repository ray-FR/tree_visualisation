#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
/* 



*/
int issep(char txt){
    if (isspace(txt) || txt == '!' || txt == '?' || txt == '.' || txt == '-' || txt == ',' || txt == ';' || txt == ':'){
        return 1;
    }
    return 0;}

typedef struct vec{
    int t;
    char* mot;
} vec_t;



vec_t* movetonewvec(int n, vec_t* oldv, int taillechar){
    vec_t* newv = malloc((n+1) * sizeof *newv);
    
    
    
    for (int i = 0; i<n; i++){
        newv[i].t = oldv->t;
        newv[i].mot = oldv->mot;
    }
    newv[n].t = taillechar;
    newv[n].mot = malloc(taillechar * sizeof* newv[n].mot);
    assert(newv[n].mot);
    return newv;

}

int main(){
    vec_t* te;
    char buff[1024];
    int taillevec = 0;
    int numvec = 0;
    while (fgets(buff, sizeof buff, stdin) != NULL){
        int i = 0;
        int taillem = 1;
        int iss = 0;
        while(buff[i] != '\n'){
            if (!issep(buff[i])){
                iss = 0;
                taillem++;
            }
            else{
                if (!iss){
                    te = movetonewvec(numvec, te, taillem);
                    strncpy(te[numvec].mot, &(buff[i]), taillem);
                    taillem = 0;
                    iss = 1;
                    numvec++;
                }
            }
            i++;
        }    
        for (int i = 0; i<numvec;i++){
            printf("%d: %s", te[i].t, te[i].mot);
        }
    

    }


    return 0;

}