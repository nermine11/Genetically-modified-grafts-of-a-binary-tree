#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "greffe.h"
#include "arbres_binares.h"






static greffe(Arbre n, Arbre g){
    if(!n || !g)
        return;
    if(!(n->fg) && !(n->fd))
        return;
    if(!(g->fg)) // && n->fd?
        copie(&(g->fg), n->fd);
    if(!(g->fd))
        copie(&(g->fd), n->fd);
    greffe(n, g->fg);
    greffe(n, g->fd);
} 

static void expansion_aux(Arbre *n, Arbre b){
    copie(&g, b);
    greffe(*n, g);
    *n = g;
}