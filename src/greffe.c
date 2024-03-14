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
static int ajout_fg(Arbre *A, Arbre gauche){
    if(!*A){
        if(!copie(A ,gauche))
            return 0;
        return 1 ;
    }
    int add = ajout_fg(&((*A)->fg) , gauche);
  
    return add;

}


/* ajoute sous arbre droit de a à tous les noeuds de *g sans fd
on retourne 0 si copie échoue sinon on retourne 1*/

static int ajout_fd(Arbre *A, Arbre droite){

    if(!*A){
        if(!copie(A ,droite ))
            return 0;
        return 1 ;
    }
    int add = ajout_fd(&((*A)->fd) , droite);
        
    return add ;

}

static int Aux_expansion(Arbre * A, Arbre B , Arbre gauche , Arbre droite){
    int cas = 1;

    if(!(*A) || !B)
        return 1;


   int f_g = Aux_expansion(&((*A)->fg), B , gauche , droite);
   int f_d = Aux_expansion(&((*A)->fd), B , gauche , droite);
   
        
    if(MOT_IDENTIQUE((*A)->val, B->val) && (f_g && f_d)){
        *A = NULL;
        if(!copie(A , B)){
            fprintf(stderr ,"il y a une erreur au niveau de la copie\n");
            return -1;
        }
    }
    else if( MOT_IDENTIQUE((*A)->val , B->val) && !(f_d && f_g)){
        Arbre greffon = NULL;
        gauche = ((*A)->fg)? (*A)->fg : NULL;
        droite = ((*A)->fd)? (*A)->fd : NULL;
        
        if(!copie(&greffon , B)){//on copie l'arbre B dans le greffon
            liberer(&greffon);
            fprintf(stderr ,"il y a une erreur au niveau de la copie du greffon et de l'arbre B\n");
            return -1;
        }        
        if(B->fg){/*on traite tous les cas pour le sous-arbre gauche*/
            cas = ajout_fg(&(greffon->fg), gauche);
            cas = (cas)? ajout_fd(&(greffon->fg) , droite) : 0;

            if(!B->fd) 
                cas = (cas)? ajout_fd(&(greffon->fd) , droite) : 0;
            
            if(B->fg->fd)
                cas = (cas)? ajout_fg(&(greffon->fg->fd) , gauche) : 0;
                
            if(B->fg->fg)
                cas = (cas)? ajout_fd(&(greffon->fg->fg) , droite) : 0;
            
            if(!cas){
                liberer(&greffon);
                fprintf(stderr ,"il y a une erreur de l'ajout dans l'arbre B->FG\n");
                return -1;
            }
            

        }
       
        if(B->fd){/*on traite tous les cas pour le sous-arbre droit*/
            cas = ajout_fg(&(greffon->fd) , gauche);
            cas = (cas)? ajout_fd(&(greffon->fd) , droite) : 0;

            if(!B->fg) 
                cas = (cas)? ajout_fg(&(greffon->fg) , droite) : 0;

            if(B->fd->fg)
                cas = (cas)? ajout_fd(&(greffon->fd->fg) , droite) : 0;

            if(B->fd->fd)
                cas = (cas)? ajout_fg(&(greffon->fd->fd) , droite) : 0;

            if(!cas){//si l'un des ajout s'est pas bien effectuer 
                liberer(&greffon);
                fprintf(stderr ,"il y a une erreur de l'ajout dans l'arbre B->FD\n");
                return -1;
            }
        }
        if(!copie(A, greffon)){
            liberer(&greffon);
            fprintf(stderr ,"il y a une erreur au niveau de la copie du greffon et de l'arbre A\n");
            return -1;
        }
        liberer(&greffon);

    }
   
    return 0;

  

}
int expansion(Arbre * a, Arbre b){

   Arbre gauche = NULL , droite = NULL;
   return Aux_expansion(a,  b , gauche , droite);
}



