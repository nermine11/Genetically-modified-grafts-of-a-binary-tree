#include "arbres_binaire.h"

void ecrireDebut(FILE *f){
    fprintf(f, "digraph arbre {\n");
    fprintf(f, "\tnode[ shape = record , height = .1 ]\n");
    fprintf(f, "\tedge[ tailclip = false , arrowtail = dot , dir = both ];\n");
}


void ecrireArbre(FILE *f, Arbre a){
    if (a){
        fprintf(f,"\tn%p [label=\"<gauche> | <valeur> %s | <droit>\"];\n", a, a->s);
    if (a->fg)
        fprintf(f, "\tn%p:gauche:c -> n%p:valeur;\n", a, a->fg);
    if (a->fd)
        fprintf(f, "\tn%p:droit:c -> n%p:valeur;\n", a, a->fd);

    ecrireArbre(f, a->fg);
    ecrireArbre(f, a->fd);
    }
}


void ecrireFin(FILE *f){
    fprintf(f, "}\n");
}



void dessine_arbre(FILE *out, Arbre a){
    fprintf(stderr , "avant ecrire debut\n");
    ecrireDebut(out);
    fprintf(stderr , "après ecrire debut\n");

    ecrireArbre(out, a);
    ecrireFin(out);
}

int main(){
    FILE * out = fopen("Arbre.dot" , "a");
    FILE *f = fopen("/home/lore/Bureau/projet/Fichiers_saage_de_tests/A_2.saage" , "r");
    Arbre a;
    if(f )a = cree_A_3();
    if(!f) printf("le fichier ne s'est pas ouvert \n");
   

    if(out){
        creePDF ("Arbre.dot" , "Arbre.pdf" , a);
        system ( " evince  Arbre.pdf   & " ) ;
    }
    if(!out) printf("le fichier out ne s'est pas ouvert \n");
   
}//main
