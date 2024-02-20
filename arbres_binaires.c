Arbre cree_A_1(void){
    char ligne[MAX_MOT] , *mot;
    int noeud;
    const char separateur[3] = "\n ";
    char code[] = "1 arbre\n 1 binaire\n 0 0 1 ternaire\n 0 0\0"; 
    mot = strtok(code , separateur); 
    return construire_arbre_binaire(mot , separateur);
}

Arbre cree_A_2(void){
    char ligne[MAX_MOT] , *mot;
    int noeud;
    const char separateur[3] = "\n ";
    char code[] = "1 Anémone\n 1 Camomille\n 0 0 1 Camomille\n 1 Dahlia\n 0 1 Camomille\n 1 Iris\n 0 0 1 Jasmin\n 0 0\0"; 
    mot = strtok(code , separateur); 
    return construire_arbre_binaire(mot , separateur);
}



Arbre cree_A_3(void){
    char ligne[MAX_MOT] , *mot;
    int noeud;
    const char separateur[3] = "\n ";
    char code[] = "1 IntelCorei9\n 1 AppleM3Max\n 0 1 AMDRyzen9\n 1 IntelCorei9\n 0 0 0 1 IntelCorei9\n 1 IntelCorei9\n 0 0 0\0"; 
    mot = strtok(code , separateur); 
    return construire_arbre_binaire(mot , separateur);
}
//main
