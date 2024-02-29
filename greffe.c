#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "greffe.h"


//O(n * len), n : nombre de noeuds dans source, len : longeur de s
// we traverse each node exactly once so it is proportional to n
// for each node we may need to allocate memory
int copie(Arbre * dest, Arbre source){
    if (!source){   
        *dest = NULL;
        return 1;
    }
    if(!(*dest)){
        *dest = alloue_noeud(source->val);
        if (!(*dest)){
            fprintf(stderr, "erreur allocation *dest dans copie()");
            return 0;
        }
    }
    else {
        if (strlen(source->val) > strlen((*dest)->val)){
            char *temp = (char *)realloc((*dest)->val, (strlen(source->val) + 1) * sizeof(char));
            if (!temp) {
                fprintf(stderr, "Error reallocating memory for val in copie\n");
                return 0;
            }
            (*dest)->val = temp;
        }
        strcpy((*dest)->val, source->val);
    }
    if (source->fg){
        if(!copie(&((*dest)->fg), source->fg)){
            fprintf(stderr, "erreur dans copie()");
            return 0;
        }
    }
    if (source->fd){
        if(!copie(&((*dest)->fd), source->fd)){
            fprintf(stderr, "erruer dans copie()");
            return 0;
        }
    }
    return 1;
}





int ajout_fg(Arbre *g, Arbre a){

    if(!a || !(*g))
        return 0 ;
    if(!((*g)->fg) && a->fg){
        if(copie(&((*g)->fg), a->fg ));
            return 1;
        return 0;
    }

    ajout_fg(&((*g)->fg),a);
    ajout_fg(&((*g)->fd),a);
    return 1;
}



int ajout_fd(Arbre *g, Arbre a){

     if(!a || !(*g))
        return 0 ;
    if(!((*g)->fd) && a->fd){
        if(copie(&((*g)->fd), a->fd ))
            return 1;
        return 0;
    }

    ajout_fd(&((*g)->fd), a);
    ajout_fd(&((*g)->fg), a);
    return 1;

}



int greffe(Arbre * a, Arbre b){

    if(!(ajout_fg(&b, *a)))
        return 0;
    if(!(ajout_fd(&b, *a)))
        return 0;
    if(!(copie(a,b)))
        return 0;
    return 1;
}


int expansion(Arbre* a, Arbre b){

    if(!(*a))
        return 0;
    expansion(&((*a)->fg), b);
    expansion(&((*a)->fd), b);
    if(!(strcmp((*a)->val, b->val))){
        Arbre g = NULL;
        if (!(copie(&g, b)))
            return 0;  
        if(!(greffe(a,g)))
            return 0;
        return 1;
    }
    return 1;

}


