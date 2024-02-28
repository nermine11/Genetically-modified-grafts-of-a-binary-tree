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



static void ajout_fg(Arbre a, Arbre g){

    if(!a || !g)
        return;
    if(!g->fg)
        copie(&(g->fg), a->fg );
    ajout_fg(a, g->fg);
    ajout_fg(a, g->fd);
}
static void ajout_fd(Arbre a, Arbre g){

    if(!a || !g)
        return;
    if(!g->fd)
        copie(&(g->fd), a->fd );
    ajout_fd(a, g->fg);
    ajout_fd(a, g->fd);
}


static void greffe(Arbre * a, Arbre b){
    ajout_fg(*a, b);
    ajout_fd(*a, b);
    copie(a,b);
}



void expansion(Arbre* a, Arbre b){

    if(!(*a))
        return;
    expansion(&((*a)->fg), b);
    expansion(&((*a)->fd), b);
    if(!(strcmp((*a)->val, b->val))){
        Arbre g = NULL;
        copie(&g, b);
        greffe(a,g);
        
    }


}
