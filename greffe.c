#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "greffe.h"
#include "arbres_binares.h"





// greffe de n sur g
// renvoie 0 en cas d'erreur sinon 1
static int greffe(Arbre *n, Arbre b){
    Arbre g;
    if (!(copie(&g, b))){
        fprintf(stderr, "erreur dans copie dans greffe()");
        return 0;
    }
    if(!(*n) || !g){
        fprintf(stderr, "n ou g sont vides dans greffe()");
        return 0;
    }
    if(!((*n)->fg) && !((*n)->fd)){
        *n = g;
        return 1;
    }
    if(!(g->fg) && (*n)->fg){
        if(!(copie(&(g->fg), (*n)->fg))){
            fprintf(stderr, "erreur dans copie dans greffe");
            return 0;
        }
        return 1;
    }
    if(!(g->fd) && (*n)->fd){ 
        if(!(copie(&(g->fd), (*n)->fd))){
            fprintf(stderr, "erreur dans copie dans greffe");
            return 0;
        }
        return 1;
    }
    return greffe(n, g->fg);
    return greffe(n, g->fd);
    *n = g;
    return 1;
} 

int expansion(Arbre * a, Arbre b){



}



