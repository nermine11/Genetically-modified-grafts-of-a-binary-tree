#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "greffe.h"



/*O(n * len), n : nombre de nœuds dans source, len : longueur de s
 Nous traversons chaque nœud exactement une fois, donc c'est proportionnel à n
 Pour chaque nœud, nous pourrions avoir besoin d'allouer de la mémoire 
 On retourne 0 si l’allocation échoue, sinon on retourne 1*/
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
            fprintf(stderr, "erreur dans copie()");
            return 0;
        }
    }
    return 1;
}


/* ajoute sous arbre gauche de a à tous les noeuds de *g sans fg
on retourne 0 si copie échoue sinon on retourne 1
*/
static int ajout_fg(Arbre *g, Arbre a){
    if(!a || !(*g))
        return 1 ;
    if(!((*g)->fg) && a->fg){
        if(!(copie(&((*g)->fg), a->fg)))
            return 0;
        return 1;
    }
    int fg, fd;
    fg = ajout_fg(&((*g)->fg),a);
    fd = ajout_fg(&((*g)->fd),a);
    return fg && fd;

}


/* ajoute sous arbre droit de a à tous les noeuds de *g sans fd
on retourne 0 si copie échoue sinon on retourne 1*/

static int ajout_fd(Arbre *g, Arbre a){

    if(!a || !(*g))
        return 1;
    if(!((*g)->fd) && a->fd){
        if(!(copie(&((*g)->fd), a->fd )))
            return 0;
        return 1;
    }
    int fg,fd;
    fd = ajout_fd(&((*g)->fd),a);
    fg = ajout_fd(&((*g)->fg),a);
    return fg && fd;

}

int expansion(Arbre * a, Arbre b){

    if(!(*a))
        return 1;
    int fg, fd;
    fg = expansion(&((*a)->fg), b);
    fd = expansion(&((*a)->fd), b);
    if( !fg || !fd)
        return 0;
    if(!(strcmp((*a)->val, b->val))){
        Arbre g = NULL;
        if(!(copie(&g, b)))
            return 0;
        if((*a)->fg)
            if(!(ajout_fg(&g, *a)))
                return 0;
        if((*a)->fd)
            if(!(ajout_fd(&g, *a)))
                return 0;

        *a = g;
        return 1;
    }
    return 1;
}
