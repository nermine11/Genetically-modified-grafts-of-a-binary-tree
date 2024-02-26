#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "greffe.h"
#include "arbres_binares.h"


int copie(Arbre * dest, Arbre source){
    if (!source)
        return 1;
    if(!(*dest)){
        *dest = alloue_noeud(source->val);
        if (!(*dest)){
            fprintf(stderr, "erreur allocation *dest dans copie()");
            return 0;
        }
    }
    else
        strcpy((*dest)->val, source->val);
    int cg = copie(&((*dest)->fg), source->fg);
    int cd = copie(&((*dest)->fd), source->fd);
    if (!cg || !cd) {
        fprintf(stderr, "erreur dans copie()");
        return 0;
    }
    return 1;
}

// greffe de n sur g
// renvoie 0 en cas d'erreur sinon 1
static int greffe(Arbre *n, Arbre b){
    Arbre g = NULL;
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
    int gr_g = greffe(n, g->fg);
    int gr_d = greffe(n, g->fd);
    if( !gr_g || !gr_d ) // pas d'erreur dans les greffes
        return 0;
    
    *n = g; 
    return 1;
} 




