/*
*************************************************************************
*                                                                       *
*       N° de projet :              Pr01                                *
*       Nom du projet :             Bataille-navale                     *
*       Version :                   1.0                                 *
*       Développer par :            Timothée Rapin                      *
*       Date de création :          04.03.2020                          *
*       Date de mise à jour :       08.04.2020                          *
*       Nouveautés :                Mise au propre du code              *
*                                                                       *
*************************************************************************
*/

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

// tableau

int tableau[10][10];
int tableauMap[10][10];
char globalPseudo[255] = "Aucun pseudo";



/**
 * Enregistre les logs des variable et leurs valeurs dans un fichier externe
 * @param fonctionLogEcriture
 * @param valeur
 */
void fonctionLog (char fonctionLogEcriture[255],int valeur){

    FILE * fp;

    // Log ecriture

    fp = fopen("../log.txt", "a");

    if (fp == NULL){
        printf("\n\nErreur fopen\n");
        perror("fopen");
        exit(1);
    }

    if (valeur != -679458374){
        fprintf(fp,"%s\t= %d\n",fonctionLogEcriture,valeur);
    }

    fclose(fp);
}

/**
 * Affiche le titre du jeu
 */
void fonctionTitre(){
    int i = 0;

    printf("\n\n%c", 201);
    for(i = 0; i < 17; i++){
        fonctionLog("i\t\t",i);    //log
        printf("%c", 205);
    }
    printf("%c", 187);
    printf("\n%c BATAILLE-NAVALE %c", 186, 186);
    printf("\n%c", 200);
    for(i = 0; i < 17; i++){
        fonctionLog("i\t\t",i);    //log
        printf("%c", 205);
    }
    printf("%c", 188);


    // Affichage bateau (source : http://www.ascii-fr.com/-Bateaux-.html#id1127)
    printf("\n\n\n");
    printf("                       $o\n"
           "                       $                     .........\n"
           "                      $$$      .oo..     'oooo'oooo'ooooooooo....\n"
           "                       $       $$$$$$$\n"
           "                   .ooooooo.   $$!!!!!\n"
           "                 .'.........'. $$!!!!!      o$$oo.   ...oo,oooo,oooo'ooo''\n"
           "    $          .o'  oooooo   '.$$!!!!!      $$!!!!!       'oo''oooo''\n"
           " ..o$ooo...    $                '!!''!.     $$!!!!!\n"
           " $    ..  '''oo$$$$$$$$$$$$$.    '    'oo.  $$!!!!!\n"
           " !.......      '''..$$ $$ $$$   ..        '.$$!!''!\n"
           " !!$$$!!!!!!!!oooo......   '''  $$ $$ :o           'oo.\n"
           " !!$$$!!!$$!$$!!!!!!!!!!oo.....     ' ''  o$$o .      ''oo..\n"
           " !!!$$!!!!!!!!!!!!!!!!!!!!!!!!!!!!ooooo..      'o  oo..    $\n"
           "  '!!$$!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!oooooo..  ''   ,$\n"
           "   '!!$!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!oooo..$$\n"
           "    !!$!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!$'\n"
           "    '$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$!!!!!!!!!!!!!!!!!!,\n"
           ".....$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$.....");

    printf("\n\n\n");
    system("pause");

    // Effacer l'affichage
    system("cls");
}

/**
 * Afficher la grille (touché, dans l'eau)
 */
void fonctionGrille(){

    int iFonction = 0;
    int jFonction = 0;
    char lettre = 65;

    fonctionLog("iFonction",iFonction);    //log
    fonctionLog("jFonction",jFonction);    //log
    fonctionLog("lettre\t",lettre);    //log


    // Affichage numéro de collones

    printf("\n\n     ");
    for(iFonction = 1; iFonction <= 10; iFonction++){
        fonctionLog("iFonction",iFonction);    //log
        printf("%-6d", iFonction);
    }


    // Affichage bordure haute

    printf("\n  %c", 201);
    for(iFonction = 1; iFonction < 10; iFonction++){
        fonctionLog("iFonction",iFonction);    //log
        printf("%c%c%c%c%c%c",205,205,205,205,205,203);
    }
    printf("%c%c%c%c%c%c",205,205,205,205,205,187);


    // Affichage tableau

    for(iFonction = 0; iFonction < 9; iFonction++){
        fonctionLog("iFonction",iFonction);    //log
        printf("\n%c ",lettre);
        lettre++;
        fonctionLog("lettre\t",lettre);    //log
        for(jFonction = 0; jFonction < 10; jFonction++){
            fonctionLog("jFonction",jFonction);    //log
            switch(tableau[iFonction][jFonction]){
                case 0: printf("%c     ",186);
                    break;
                case 1: printf("%c  %c  ",186,250);
                    break;
                case 2: printf("%c  x  ",186);
                    break;
                case 3: printf("%c %c%c%c ",186,219,219,219);
            }
        }
        printf("%c",186);


        // Ligne intermediaire

        printf("\n  %c",204);
        for(jFonction = 1; jFonction < 10; jFonction++){
            fonctionLog("jFonction",jFonction);    //log
            printf("%c%c%c%c%c%c",205,205,205,205,205,206);
        }
        printf("%c%c%c%c%c%c",205,205,205,205,205,185);
    }


    // Affichage dernière ligne

    iFonction = 9;
    fonctionLog("iFonction",iFonction);    //log
    printf("\n%c ",lettre);
    for(jFonction = 0; jFonction < 10; jFonction++){
        fonctionLog("jFonction",jFonction);    //log
        switch(tableau[iFonction][jFonction]){
            case 0: printf("%c     ",186);
                break;
            case 1: printf("%c  %c  ",186,250);
                break;
            case 2: printf("%c  x  ",186);
                break;
            case 3: printf("%c %c%c%c ",186,219,219,219);
        }
    }
    printf("%c",186);


    // dernière bordure

    printf("\n  %c",200);
    for(jFonction = 1; jFonction < 10; jFonction++){
        fonctionLog("jFonction",jFonction);    //log
        printf("%c%c%c%c%c%c",205,205,205,205,205,202);
    }
    printf("%c%c%c%c%c%c",205,205,205,205,205,188);
}

/**
 * Charge les maps choisies (aide et jeu)
 * @param fonctionMapValeur
 */
void fonctionMap(int fonctionMapValeur){

    char fonctionTableauMapLigne = 0;
    char fonctionTableauMapCol = 0;
    int type = 0;


    FILE * fp;

    switch(fonctionMapValeur) {
        case -1:
            fp = fopen("../maps/mapBateauxDisponibles.txt", "r");
            break;
        case 1:
            fp = fopen("../maps/map1.txt", "r");
            break;
        case 2:
            fp = fopen("../maps/map2.txt", "r");
            break;
        case 3:
            fp = fopen("../maps/map3.txt", "r");
            break;
        case 4:
            fp = fopen("../maps/map4.txt", "r");
            break;
        case 5:
            fp = fopen("../maps/map5.txt", "r");
            break;
        case 6:
            fp = fopen("../maps/map6.txt", "r");
            break;
        case 7:
            fp = fopen("../maps/map7.txt", "r");
            break;
        case 8:
            fp = fopen("../maps/map8.txt", "r");
            break;
        case 9:
            fp = fopen("../maps/map9.txt", "r");
            break;
        case 10:
            fp = fopen("../maps/map10.txt", "r");
            break;
        case 11:
            fp = fopen("../maps/map11.txt", "r");
            break;
        case 12:
            fp = fopen("../maps/map12.txt", "r");
            break;
    }

    if (fp == NULL){
        printf("\n\nErreur fopen\n");
        printf("\n\nmap%d introuvable !\n",fonctionMapValeur);
        perror("fopen");
        exit(1);
    }

    char c = '0';


    while ((c != EOF)){
        c = fgetc(fp);
        if (c != EOF){
            fonctionTableauMapLigne = c -65;

            c = fgetc(fp);
            if (c != EOF){
                fonctionTableauMapCol = c -48;
                c = fgetc(fp);
                if (c != EOF){
                    type = c -48;
                    tableauMap[fonctionTableauMapLigne][fonctionTableauMapCol] = type;

                }
            }
        }
    }
    fclose(fp);
}

/**
 * Enregistre les scores dans un fichier externe
 * @param fonctionPseudo
 * @param fonctionScore
 */
void fonctionScoresEcriture(char fonctionPseudo[255], int fonctionScore){

    FILE * fp;

    fp = fopen("../scores.txt", "a");


    if (fp == NULL){
        printf("\n\nErreur fopen\n");
        perror("fopen");
        exit(1);
    }

    fprintf(fp,"%s;%d;",fonctionPseudo,fonctionScore);

    fclose(fp);
}

/**
 * Creer un pseudo pour l'enregistrer dans les scores
 */
void fonctionPseudoCreation(){
    char c[255];
    int i = 0;

    for (i = 0; i < 255; ++i) {
        c[i] = 0;
    }

    // Effacer l'affichage
    system("cls");

    printf("\n\nAUTHENTIFICATION :\n");

    printf("Entrez votre pseudo :\t");

    scanf("%s",&c);
    if(((c > 47) && (c < 58)) || ((c > 64) && (c < 91)) || ((c > 96) && (c < 123))){
        printf("1\t%s",c);
    }
    for(i = 0;i < 10;i++){
        printf("2\t%d\n",c[i]);
    }

    for(i = 0;i < 255;i++){
        globalPseudo[i] = c[i];
    }

}

/**
 * Affiche les scores qui sont dans le fichier externe
 */
void fonctionScoresLecture(){

    char c = 0;
    int nbLettres = 0;

    FILE * fp;

    fp = fopen("../scores.txt", "r");

    // Effacer l'affichage
    system("cls");

    printf("\n\nSCORES :\n\n");


    if (fp == NULL){
        printf("\n\nErreur fopen\n");
        perror("fopen");
        exit(1);
    }

    while(c != EOF){

        nbLettres = 0;

        do{
            c = fgetc(fp);
            nbLettres++;

            if ((c != EOF) && (c != 59)){
                printf("%c",c);
            }
        }while((c != 59) && (c != EOF));

        printf("\t");
        if (nbLettres < 8){
            printf("\t");
        }
        if (nbLettres < 16){
            printf("\t");
        }
        if (nbLettres < 24){
            printf("\t");
        }

        do{
            c = fgetc(fp);

            if ((c != EOF) && (c != 59)){
                printf("%c",c);
            }
        }while((c != 59) && (c != EOF));

        if(c != EOF){
            printf("\tCoups");
        }

        printf("\n");
    }

    printf("\n\n\n");
    system("pause");

    // Effacer l'affichage
    system("cls");



    fclose(fp);
}

/**
 * Affiche l'aide avec les bateaux disponibles
 */
void fonctionAide(){
    int map = 0;
    int i = 0;
    int j = 0;

    // Effacer l'affichage
    system("cls");

    printf("\n\nAIDE :");
    printf("\n\nQuand une case n'est pas designee, la case reste vide");
    printf("\nQuand c'est dans l'eau, il y a un %c",250);
    printf("\nQuand un bateau est touche, il y a un %c%c%c",219,219,219);


    // bateaux disponibles

    printf("\n\nLes bateaux peuvent etre places verticalement ou horizontalement.");
    printf("\n\nBateaux disponibles :");

    map = -1;
    fonctionMap(map);
    fonctionLog("map\t\t",map);    //log
    // map nbr et type de bateaux


    for(i = 0; i < 10; i++){
        for (j = 0; j < 10; ++j) {
            //  Marquer comme touche

            if(tableauMap[i][j] == 1){
                tableau[i][j] = 3;
            }
                // Marquer comme dans l'eau
            else{
                tableau[i][j] = 1;
            }
        }
    }


    fonctionGrille();

    printf("\n\n\n");
    system("pause");

    // Effacer l'affichage
    system("cls");


    // dernier commentaire pour l'aide

    printf("\n\nLes bateaux ne peuvent pas etre colles l'un contre l'autre (en diagonale non plus)");

    printf("\n\n\n");
    system("pause");

    // Effacer l'affichage
    system("cls");

    printf("\nVous pouvez quitter le jeu en mettant x quand la ligne vous est demandee");
    printf("\nIl faudra cependant entrer une colonne entre 1-10 juste apres");

    printf("\n\n\n");
    system("pause");

    // Effacer l'affichage
    system("cls");

    map = 0;
    fonctionLog("map\t\t",map);    //log
}

/**
 * affiche le menu qui redirige vers les différentes fonctions
 * @return
 */
int fonctionMenu (){
    int choixMenu = 0;
    int i = 0;
    int j = 0;
    fonctionLog("choixMenu",choixMenu);    //log

    // remise à 0

    for(i = 0; i < 10; i++){
        for (j = 0; j < 10; ++j) {
            tableauMap[i][j] = 0;
        }
    }

    printf("\n\n\nMENU :");
    printf("\n\n1) Afficher l'aide");
    printf("\n2) S'authentifier");
    printf("\n3) Choisir une map");
    printf("\n4) Jouer");
    printf("\n5) Afficher les scores");
    printf("\n6) Quitter");

    printf("\n\n");
    scanf("%d", &choixMenu);
    fonctionLog("choixMenu",choixMenu);    //log

    switch (choixMenu){
        case 1:
            fonctionAide();
            break;
        case 2:
            fonctionPseudoCreation();
            break;
        case 5:
            fonctionScoresLecture();
            break;
    }

    return choixMenu;
}

int main() {


    setbuf(stdout,0);

    // plein ecran (source : https://codes-sources.commentcamarche.net/forum/affich-371867-plein-ecran-c-console)
    HWND hwnd=GetForegroundWindow();
    ShowWindow(hwnd,SW_MAXIMIZE);


    // Déclarations + initialisations

    int menu = 0;
    int menuMap = 0;
    int i = 0;
    int j = 0;
    int grille = 0;
    int grilleMap = 0;
    int coups = 0;
    int touche = 0;
    char ligneChar = 0;
    int map = 0;
    int col = 0;
    int ligne = 0;

    fonctionLog("col\t\t",col);    //log
    fonctionLog("ligne\t",ligne);    //log
//    fonctionLog("tableau[10][10]",tableau);    //log
//    fonctionLog("tableauMap[10][10]",tableauMap);    //log
    fonctionLog("map\t\t",map);    //log
    fonctionLog("menu\t",menu);    //log
    fonctionLog("menuMap\t",menuMap);    //log
    fonctionLog("i\t\t",i);    //log
    fonctionLog("grille\t",grille);    //log
    fonctionLog("grilleMap",grilleMap);    //log
    fonctionLog("coups\t",coups);    //log
    fonctionLog("touche\t",touche);    //log
    fonctionLog("ligneChar",ligneChar);    //log


    srand( (unsigned)time( NULL ) ); // pour que le nbr soit différent à chaque fois


    //  Vider le tableau

    for(ligne = 0; ligne < 10; ligne++){
        fonctionLog("ligne\t",ligne);    //log
        for(col = 0; col < 10; col++){
            fonctionLog("col\t\t",col);    //log
            tableau[ligne][col] = 0;
        }
    }


fonctionTitre();




    do {

        // Aide pour la premierre fois
        FILE * fp;

        fp = fopen("../log.txt", "r");

        if (fp == NULL){
            fonctionAide();
        }



        // MENU

        menu = fonctionMenu();





        // MAPS

        if (menu == 3){
            // Effacer l'affichage
            system("cls");

            printf("\n\nMAPS :");
            printf("\n\n1) Choisir une map");
            // printf("\n2) Creer une map");
            // printf("\n3) Supprimer une map");
            printf("\n\n");
            scanf("%d",&menuMap);
            fonctionLog("menuMap\t",menuMap);    //log

            // Effacer l'affichage
            system("cls");

            switch(menuMap){

                //  choix de la map
                case 1:
                    printf("\nchoisissez une map entre 1 et 12 (0 pour aleatoire) :");
                    printf("\n\n");
                    scanf("%d",&map);
                    fonctionLog("map\t\t",map);    //log
                    fonctionMap(map);
                    fonctionLog("map\t\t",map);    //log
                    break;

                    //  ajout d'une map
                case 2:

                    break;

                    //  suppression d'une map
                case 3:

                    break;
            }
        }

        // Effacer l'affichage
        system("cls");






        // JEU

        if (menu == 4){

            // remise à 0

            for(i = 0; i < 10; i++){
                for (j = 0; j < 10; ++j) {
                    tableau[i][j] = 0;
                }
            }

            coups = 0;


            // map aléatoire

            if(map == 0){
                map = 1 + rand() % 12;
                fonctionLog("map\t\t",map);    //log
                fonctionMap(map);
            }

            // Effacer l'affichage
            system("cls");

            //  Debut de partie

            printf("\n\nJEU :");
            fonctionGrille();
            touche = 0;
            fonctionLog("touche\t",touche);    //log


            //  Continue tant que tous les bateaux n'ont pas tous ete touches

            while(touche < 17){
                fonctionLog("touche\t",touche);    //log
                fonctionMap(map);

                do {
                    do {

                        ligne = -1;
                        fonctionLog("ligne\t", ligne);    //log

                        printf("\nligne : ");
                        scanf("%c", &ligneChar);
                        fonctionLog("ligneChar", ligneChar);    //log


                        // A-J -> 0-9
                        if ((ligneChar >= 65) && (ligneChar <= 74)) {
                            fonctionLog("ligneChar", ligneChar);    //log
                            ligne = ligneChar - 64;
                            fonctionLog("ligneChar", ligneChar);    //log
                        }
                        // a-j -> 0-9
                        if ((ligneChar > 96) && (ligneChar < 123)) {
                            fonctionLog("ligneChar", ligneChar);    //log
                            ligne = ligneChar - 96;
                            fonctionLog("ligneChar", ligneChar);    //log
                        }
                        // Sortir du jeu
                        if ((ligneChar == 88) || (ligneChar == 120)) {
                            ligne = 1;
                            fonctionLog("ligne\t", ligne);    //log
                            touche = 17;
                            fonctionLog("touche\t", touche);    //log
                        }
                    } while ((ligne < 1) || (ligne > 10));


                    //  Demander la colonne
                    do {
                        printf("\ncolonne : ");
                        scanf("%d", &col);
                        fonctionLog("col\t\t", col);    //log
                    } while ((col < 1) || (col > 10));
                }while (tableau[ligne-1][col-1] != 0);

                //  Marquer comme touche

                if(tableauMap[ligne-1][col-1] == 1){
                    tableau[ligne-1][col-1] = 3;
                    touche++;
                    fonctionLog("touche\t",touche);    //log
                    coups++;
                }
                    // Marquer comme dans l'eau
                else{
                    tableau[ligne-1][col-1] = 1;
                    coups++;
                }

                // Effacer l'affichage
                system("cls");

                fonctionGrille();


                fonctionLog("coups\t",coups);    //log
                map = 0;
                fonctionLog("map\t\t",map);    //log
            }

            printf("\nBRAVO !");
            printf("\nvotre score est de %d coups",coups);
            fonctionScoresEcriture(globalPseudo,coups);

            printf("\n\n\n");
            system("pause");

            // Effacer l'affichage
            system("cls");
        }



    }while(menu != 6);


    // Fin

    fonctionLog("\n\n",-679458374);
    printf("\n\n");
    return 0;
}