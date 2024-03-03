#include "saage.h"
//1 "Intel Core i9\n" 1 "Apple M3 Max\n" 0 1 "AMD Ryzen 9\n" 1 "Intel Core i9\n" 0 0 0 1 "Intel Core i9\n" 1 "Intel Core i9\n" 0 0 0
//1 "arbre\n" 1 "binaire\n" 0 0 1 "ternaire\n" 0 0
//1 "Anémone\n" 1 "Camomille\n" 0 0 1 "Camomille\n" 1 "Dahlia\n" 0 1 "Camomille\n" 1 "Iris\n" 0 0 1 "Jasmin\n" 0 0

int creation_Memo(Memo *p){
    p->code = (char *)calloc( MAX_MOT, sizeof(char));
    if(p->code){
        p->taille_max = MAX_MOT;
        return 1;

    }
    fprintf(stderr ,"il s'est produit une erreur\n");

    free(p->code);
    return 0;
}

Arbre saisir_arbre_binaire(){
    Memo p;
    Arbre A;
    creation_Memo(&p);
    creation_code_adapter_arbre(&p);
    char * mot = strtok(p.code , "*");
    printf("mot : %s\n", mot);
    A = construire_arbre_binaire(mot);
    free(p.code);
    return A;
}


int  Copier_Chiffre(char *mot , Memo * p){
    int copier = 0 , val = 0;

    if(!strstr(mot, "\\n")){


        for(;*mot != '\0';mot++)
        {
            
            copier = (NOEUD_VIDE(*mot))? 1 : (NOEUD_EXIST(*mot))? 2 : (*mot == ' ')? 3 : (*mot == '\n')? 3 : -1;
            

            switch (copier)
            {
                case 1:
                  
                    strcat(p->code , "0");
                    strcat(p->code , "*");
                    val = 1;
                    break;

                case 2:
        
                    strcat(p->code , "1");
                    strcat(p->code , "*");
                    val = 1;
                break;

                case 3:
                break;

                default:
                    return -1;
            }
 
        }

        if(!val)
            return -1;

        return val;
    }
    
    return copier;
      

}

int verification_mot(char * mot){
    if( mot[strlen(mot) - 2] != '\\' && mot[strlen(mot) - 1] != 'n')
        return 0;
    return 1;
}

int creation_code_adapter_arbre(Memo * p){
    char ligne[MAX_MOT] ;
    int  value_copie;
    if(!fgets(ligne , MAX_MOT , stdin)){
        fprintf(stderr , "il y a eu un problème\n");
        return 0;
    }
        
    if(!strstr(ligne , "\"") && !strstr(ligne , "\\n")){
        fprintf(stderr , "le code de cette arbre est incorrecte1\n");
        return 0;
    }

  
    char * mot = strtok(ligne , "\"");
    while (mot)
    {   

        value_copie = Copier_Chiffre(mot , p);
        if(value_copie == -1){
            fprintf(stderr , "le code de cette arbre est incorrecte, je pense que vous avez saisi un mauvais chiffre\n");
            return 0;
        }

        if(!value_copie && !NOEUD_EXIST(p->code[strlen(p->code) - 2]) && !verification_mot(mot)){
            fprintf(stderr , "le code de cette arbre est incorrecte, je pense que vous avez saisi un mauvais chiffre\n");
            return 0;
        }

        if(!value_copie){
            mot[strlen(mot) - 1] = '\0';
            mot[strlen(mot) - 1] = '\0';
            strcat(p->code , mot);
            strcat(p->code , "*");
        }
        

       
    
       mot = strtok(NULL , "\"");
    }
    
    printf("code %s\n", p->code);
    return 1;
}






Arbre construire_arbre_binaire(char * mot){
    mot = strtok(NULL , "*");
    if(mot){
       
        if(NOEUD_VIDE(*mot))
            return NULL;
        
        if(NOEUD_EXIST(*mot))
            mot = strtok(NULL , "*");
    
        

        if(!mot)
            return NULL;
        Arbre a = alloue_Noeud(mot);
    
        if(!a){
            liberer_arbre(&a);
            exit(EXIT_FAILURE);

        }
        a->fg = construire_arbre_binaire(mot);
        a->fd = construire_arbre_binaire(mot);
        
       return a;
   }

    return NULL;
}


void affiche(Arbre A , FILE * out, int nombre_espace ){
    int i ;
    char espace[MAX_MOT] = "    ";
    if(!A){
        return;
    }
    
    for(i = 1 ; i < nombre_espace ; i++){
            strcat(espace , "    ");
    } 
    fprintf(out , "%sValeur : %s\n",espace , A->val);
    
   
    if(A->fg){
        fprintf(out ,"%sGauche :\n" , espace);
        affiche(A->fg , out , nombre_espace + 1); 
    } 
    else if(!A->fg)
        fprintf(out ,"%sGauche : NULL\n" ,espace);

    if(A->fd ){
        fprintf(out ,"%sDroite :\n", espace);
        affiche(A->fd , out  , nombre_espace + 1);
    }
    else if(!A->fd)
        fprintf(out ,"%sDroite : NULL\n",espace);

        

    
}

int test_format(char * nom_de_fichier ){
    if(!FORMAT(nom_de_fichier , ".saage")){
        fprintf(stderr , "le format du fichier est incorrecte\n");
        return 0;
    }
    char format[7] = "egaas.";
    
    for (int i = 0; i < 6; i++)
    {

        if (format[i] != nom_de_fichier[strlen(nom_de_fichier) - i - 1])
            return 0;
        
        
    }
    
    return 1;
}

int serialise(char * nom_de_fichier, Arbre A){
    FILE * out = fopen ( nom_de_fichier , "w") ;

    if (!test_format(nom_de_fichier )){
        fprintf(stderr , "le format du fichier est incorrecte\n");
        return 0;
    }

   

    if(!out){
        fprintf(stderr , "le fichier ne s'est pas ouvert\n");
        return 0;
    }
    if(!A){
        fprintf(stderr , "Arbre n'existe pas \n");
        return 0;

    }

    fprintf(out, "Valeur : %s\n" , A->val);
    fprintf(out , "Gauche : \n");
    int nombre_espace = 1;
    
    affiche(A->fg , out , nombre_espace);
    fprintf(out , "Droite : \n");
    affiche(A->fd , out , nombre_espace);
    return 1;

}



int deserialise(char * nom_de_fichier, Arbre * A){// choisir la séparation en fonction du texte la B.saage ne marche pas 
    int cmpt = 0; 
    char ligne[MAX_MOT] , *direction , *mot;
    int taille_chaine = 0; 
    FILE * out = fopen ( nom_de_fichier , "r") ;

    if(!out){
        printf("le fichier out ne s'est pas ouvert \n");
        return 0;
    }
    Memo p;
    creation_Memo(&p);

    for( ; fgets(ligne , MAX_MOT , out) ; ){
        direction = strtok(ligne , ":\n");
        mot = strtok(NULL , ":\n");
        if(NOEUD_STRING_VIDE(mot)){
            strcat(p.code , "*0");
            strcat(p.code , "*");
        }
        else if (!MOT_VIDE(mot)){
            strcat(p.code , "*1");
            strcat(p.code , "*");
            strcat(p.code , mot);
           
        }
        
        
        

    }

    char * mot2 = strtok(p.code , "*");
    
    *A = construire_arbre_binaire(mot2);
    free(p.code);
    return 1;

}
