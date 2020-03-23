/*
*************************************************************************
*                                                                       *
*       N° de projet :              Pr01                                *
*       Nom du projet :             Bataille-navale                     *
*       Version :                   0.1                                 *
*       Développer par :            Timothée Rapin                      *
*       Date de création :          04.03.2020                          *
*       Date de mise à jour :       18.03.2020                          *
*       Nouveautés :                Sortir du jeu                       *
*                                                                       *
*************************************************************************
*/

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

// tableau

int col = 0;
int ligne = 0;
int tableau[10][10];
int tableauMap[10][10];
int map = 0;



void fonctionLog (char fonctionLogEcriture[255]){

    FILE * fp;

    // Log ecriture

    fp = fopen("log.txt", "a");

    if (fp == NULL){
        printf("Erreur fopen\n");
        if (!fp)perror("fopen");
        exit(1);
    }

    fprintf(fp,"%s",fonctionLogEcriture);

    fclose(fp);
}

int fonctionMenu (){
    int choixMenu = 0;
    fonctionLog("choixMenu = 0\n\n");    //log

    printf("\n\n\nMENU :");
    printf("\n\n1) Afficher l'aide");
    // printf("\n2) S'authentifier");
    printf("\n3) Choisir une map");
    printf("\n4) Jouer");
    // printf("\n5) Afficher les scores");
    printf("\n6) Quitter");

    printf("\n\n");
    scanf("%d", &choixMenu);
    fonctionLog("choixMenu = ?\n\n");    //log

    return choixMenu;
}

// Fonction pour afficher la grille (touché, dans l'eau)
int fonctionGrille(){

    int iFonction = 0;
    int jFonction = 0;
    char lettre = 65;


    // Affichage numéro de collones

    printf("\n\n     ");
    for(iFonction = 1; iFonction <= 10; iFonction++){
        printf("%-6d", iFonction);
    }


    // Affichage bordure haute

    printf("\n  %c", 201);
    for(iFonction = 1; iFonction < 10; iFonction++){
        printf("%c%c%c%c%c%c",205,205,205,205,205,203);
    }
    printf("%c%c%c%c%c%c",205,205,205,205,205,187);


    // Affichage tableau

    for(iFonction = 0; iFonction < 9; iFonction++){
        printf("\n%c ",lettre);
        lettre++;
        for(jFonction = 0; jFonction < 10; jFonction++){
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
            printf("%c%c%c%c%c%c",205,205,205,205,205,206);
        }
        printf("%c%c%c%c%c%c",205,205,205,205,205,185);
    }


    // Affichage dernière ligne

    iFonction = 9;
    printf("\n%c ",lettre);
    lettre++;
    for(jFonction = 0; jFonction < 10; jFonction++){
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
        printf("%c%c%c%c%c%c",205,205,205,205,205,202);
    }
    printf("%c%c%c%c%c%c",205,205,205,205,205,188);


    return 0;
}

int fonctionMap(){


    switch(map){

        // map symboles
        case 1:
            tableau[0][0] = 0;
            tableau[0][1] = 1;
            // tableau[0][2] = 2;
            tableau[0][3] = 3;
            break;

        // map nbr et type de bateaux
        case 2:
            tableau[0][0] = 3;
            tableau[0][1] = 3;
            tableau[0][2] = 3;
            tableau[0][3] = 3;
            tableau[0][4] = 3;

            tableau[2][0] = 3;
            tableau[2][1] = 3;
            tableau[2][2] = 3;
            tableau[2][3] = 3;

            tableau[4][0] = 3;
            tableau[4][1] = 3;
            tableau[4][2] = 3;

            tableau[6][0] = 3;
            tableau[6][1] = 3;
            tableau[6][2] = 3;

            tableau[8][0] = 3;
            tableau[8][1] = 3;
            break;

        // map jeux 1
        case 3:
            tableauMap[1][1] = 1;
            tableauMap[1][2] = 1;
            tableauMap[1][3] = 1;
            tableauMap[1][4] = 1;
            tableauMap[1][5] = 1;

            tableauMap[2][7] = 1;
            tableauMap[3][7] = 1;
            tableauMap[4][7] = 1;
            tableauMap[5][7] = 1;

            tableauMap[4][2] = 1;
            tableauMap[4][3] = 1;
            tableauMap[4][4] = 1;

            tableauMap[5][9] = 1;
            tableauMap[6][9] = 1;
            tableauMap[7][9] = 1;

            tableauMap[9][0] = 1;
            tableauMap[9][1] = 1;
            break;

        // map jeu 2
        case 4:
            tableauMap[5][9] = 1;
            tableauMap[6][9] = 1;
            tableauMap[7][9] = 1;
            tableauMap[8][9] = 1;
            tableauMap[9][9] = 1;

            tableauMap[2][4] = 1;
            tableauMap[2][5] = 1;
            tableauMap[2][6] = 1;
            tableauMap[2][7] = 1;

            tableauMap[1][1] = 1;
            tableauMap[2][1] = 1;
            tableauMap[3][1] = 1;

            tableauMap[6][4] = 1;
            tableauMap[6][5] = 1;
            tableauMap[6][6] = 1;

            tableauMap[6][2] = 1;
            tableauMap[7][2] = 1;
            break;

        // map jeu 3
        case 5:
            tableauMap[3][4] = 1;
            tableauMap[4][4] = 1;
            tableauMap[5][4] = 1;
            tableauMap[6][4] = 1;
            tableauMap[7][4] = 1;

            tableauMap[0][0] = 1;
            tableauMap[0][1] = 1;
            tableauMap[0][2] = 1;
            tableauMap[0][3] = 1;

            tableauMap[5][0] = 1;
            tableauMap[6][0] = 1;
            tableauMap[7][0] = 1;

            tableauMap[5][7] = 1;
            tableauMap[5][8] = 1;
            tableauMap[5][9] = 1;

            tableauMap[8][6] = 1;
            tableauMap[8][7] = 1;
            break;

        // map jeu 4
        case 6:
            tableauMap[4][2] = 1;
            tableauMap[5][2] = 1;
            tableauMap[6][2] = 1;
            tableauMap[7][2] = 1;
            tableauMap[8][2] = 1;

            tableauMap[0][4] = 1;
            tableauMap[0][5] = 1;
            tableauMap[0][6] = 1;
            tableauMap[0][7] = 1;

            tableauMap[6][5] = 1;
            tableauMap[6][6] = 1;
            tableauMap[6][7] = 1;

            tableauMap[9][4] = 1;
            tableauMap[9][5] = 1;
            tableauMap[9][6] = 1;

            tableauMap[9][8] = 1;
            tableauMap[9][9] = 1;
            break;
    }

    return 0;
}

int main() {


    setbuf(stdout,0);

    // plein ecran (source : https://codes-sources.commentcamarche.net/forum/affich-371867-plein-ecran-c-console)
    //HWND hwnd=GetForegroundWindow();
    //ShowWindow(hwnd,SW_MAXIMIZE);


    // Déclarations + initialisations

    int menu = 0;
    int menuMap = 0;
    int i = 0;
    int grille = 0;
    int grilleMap = 0;
    int mapTemp = 0;
    int coups = 0;
    int touche = 0;
    char ligneChar = 0;

    fonctionLog("col = 0\nligne = 0\ntableau[10][10]\ntableauMap[10][10]\nmap = 0\n\n");    //log
    fonctionLog("menu = 0\nmenuMap = 0\ni = 0\ngrille = 0\ngrilleMap = 0\nmapTemp = 0\ncoups = 0\ntouche = 0\nligneChar = 0\n\n");    //log


    srand( (unsigned)time( NULL ) ); // pour que le nbr soit différent à chaque fois


    //  Vider le tableau

    for(ligne = 0; ligne < 10; ligne++){
        for(col = 0; col < 10; col++){
            tableau[ligne][col] = 0;
        }
    }



    // Titre

    printf("\n\n%c", 201);
    for(i = 0; i < 17; i++){
        printf("%c", 205);
    }
    printf("%c", 187);
    printf("\n%c BATAILLE-NAVALE %c", 186, 186);
    printf("\n%c", 200);
    for(i = 0; i < 17; i++){
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


    do {

        // MENU

        menu = fonctionMenu();


        // AIDE

        if (menu == 1) {

            // Effacer l'affichage
            system("cls");

            printf("\n\nAIDE :");
            printf("\n\nQuand une case n'est pas designee, la case reste vide");
            printf("\nQuand c'est dans l'eau, il y a un %c",250);
            // printf("\nQuand un bateau est touche, il y a un x");
            // printf("\nQuand un bateau est coule, il y a un %c%c%c",219,219,219);
            printf("\nQuand un bateau est touche, il y a un %c%c%c",219,219,219);
            printf("\n\nExemple :");


            // map exemple

            for(ligne = 0; ligne < 10; ligne++){
                for(col = 0; col < 10; col++){
                    tableau[ligne][col] = 0;
                }
            }

            map = 1;
            mapTemp = fonctionMap();
            grille = fonctionGrille();

            printf("\n\n\n");
            system("pause");

            // Effacer l'affichage
            system("cls");


            // bateaux disponibles

            printf("\n\nLes bateaux peuvent etre places verticalement ou horizontalement.");
            printf("\n\nBateaux disponibles :");


            // map nbr et type de bateaux

            map = 2;
            mapTemp = fonctionMap();
            grille = fonctionGrille();

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
        }


        // AUTHENTIFICATION (pas encore implemente)

        if (menu == 2) {
            // Effacer l'affichage
            system("cls");

            printf("\n\nAUTHENTIFICATION :");
        }


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

            // Effacer l'affichage
            system("cls");

            switch(menuMap){

                //  choix de la map
                case 1:
                    printf("\nchoisissez une map entre 1 et 4 (0 pour aleatoire) :");
                    printf("\n\n");
                    scanf("%d",&map);
                    map = map + 2;
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

            //  Remise a 0 de la map

            for(ligne = 0; ligne < 10; ligne++){
                for(col = 0; col < 10; col++){
                    tableau[ligne][col] = 0;
                }
            }

            // map aléatoire

            if(map == 0){
                map = 1 + rand() % 4;
                map = map + 2;
            }

            // Effacer l'affichage
            system("cls");

            //  Debut de partie

            printf("\n\nJEU :");
            grille = fonctionGrille();
            touche = 0;


            //  Continue tant que tous les bateaux n'ont pas tous ete touches

            while(touche < 17){
                grilleMap = fonctionMap();

                do{

                    ligne = -1;
                    //do{
                        printf("\nligne : ");
                        scanf("%c",&ligneChar);


                    //}while((ligneChar < 49) || ((ligneChar > 74) && (ligneChar < 97)) || (ligneChar > 106));
/*
                    // 1-9 -> 0-8
                    if((ligneChar >= 49) && (ligneChar <= 57)){
                        ligne = ligneChar - 48;
                    }
                    // 10 -> 9
                    if(ligneChar == 97){
                        ligne = ligneChar - 90;
                    }*/


                    // A-J -> 0-9
                    if((ligneChar >= 65) && (ligneChar <= 74)){
                        ligne = ligneChar - 64;
                    }
                    // a-j -> 0-9
                    if((ligneChar > 96) && (ligneChar < 123)){
                        ligne = ligneChar - 96;
                    }
                    // Sortir du jeu
                    if((ligneChar == 88) || (ligneChar == 120)){
                        ligne = 1;
                        touche = 17;
                    }
                }while((ligne < 1) || (ligne > 10));


                //  Demander la colonne
                do{
                    printf("\ncolonne : ");
                    scanf("%d", &col);
                }while((col < 1) || (col > 10));


                //  Marquer comme touche

                if(tableauMap[ligne-1][col-1] == 1){
                    tableau[ligne-1][col-1] = 3;
                    touche++;
                }
                // Marquer comme dans l'eau
                else{
                    tableau[ligne-1][col-1] = 1;
                }

                // Effacer l'affichage
                system("cls");

                grille = fonctionGrille();

                coups++;
                map = 0;
            }

            printf("\nBRAVO !");
            printf("\nvotre score est de %d coups",coups);

            printf("\n\n\n");
            system("pause");

            // Effacer l'affichage
            system("cls");
        }


        // SCORES   (pas encore implemente)

        if(menu == 5){
            // Effacer l'affichage
            system("cls");

            printf("\n\nSCORES :");
        }


    }while(menu != 6);


    // Fin

    fonctionLog("\n\n");
    printf("\n\n");
    return 0;
}