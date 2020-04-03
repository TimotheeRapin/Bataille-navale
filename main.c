/*
*************************************************************************
*                                                                       *
*       N° de projet :              Pr01                                *
*       Nom du projet :             Bataille-navale                     *
*       Version :                   0.1                                 *
*       Développer par :            Timothée Rapin                      *
*       Date de création :          04.03.2020                          *
*       Date de mise à jour :       02.04.2020                          *
*       Nouveautés :                Remise à 0 du score                 *
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
//int map = 0;



void fonctionLog (char fonctionLogEcriture[255],int valeur){

    FILE * fp;

    // Log ecriture

    fp = fopen("log.txt", "a");

    if (fp == NULL){
        printf("\n\nErreur fopen\n");
        if (!fp)perror("fopen");
        exit(1);
    }

    if (valeur != -679458374){
        fprintf(fp,"%s\t= %d\n",fonctionLogEcriture,valeur);
    }

    fclose(fp);
}

int fonctionMenu (){
    int choixMenu = 0;
    fonctionLog("choixMenu",choixMenu);    //log

    printf("\n\n\nMENU :");
    printf("\n\n1) Afficher l'aide");
    // printf("\n2) S'authentifier");
    printf("\n3) Choisir une map");
    printf("\n4) Jouer");
    // printf("\n5) Afficher les scores");
    printf("\n6) Quitter");

    printf("\n\n");
    scanf("%d", &choixMenu);
    fonctionLog("choixMenu",choixMenu);    //log

    return choixMenu;
}

// Fonction pour afficher la grille (touché, dans l'eau)
int fonctionGrille(){

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
    lettre++;
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


    return 0;
}

int fonctionMap(int fonctionMapValeur){

    char fonctionTableauMapLigne = 0;
    char fonctionTableauMapCol = 0;
    int type = 0;
    int i = 0;
    int j = 0;

    // remise à 0

    for(i = 0; i < 10; i++){
        for (int j = 0; j < 10; ++j) {
            tableauMap[i][j] = 0;
        }
    }

    FILE * fp;

    switch(fonctionMapValeur) {
        case -1:
            fp = fopen("mapBateauxDisponibles.txt", "r");
            break;
        case 1:
            fp = fopen("map1.txt", "r");
            break;
        case 2:
            fp = fopen("map2.txt", "r");
            break;
        case 3:
            fp = fopen("map3.txt", "r");
            break;
        case 4:
            fp = fopen("map4.txt", "r");
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
                    //tableauMap[fonctionTableauMapLigne][fonctionTableauMapCol] = type;
                    c = fgetc(fp);
                    if (c != EOF){
                        type = c -48;
                        tableauMap[fonctionTableauMapLigne][fonctionTableauMapCol] = type;

                    }
                }
            }
        }
        fclose(fp);

        printf("\n");
        for(int i = 0;i<10;i++){
            for(int j = 0;j<10;j++){
                printf("%d",tableauMap[i][j]);
            }
            printf("\n");
        }


/*
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


    }*/

    return 0;
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
    int grille = 0;
    int grilleMap = 0;
    int mapTemp = 0;
    int coups = 0;
    int touche = 0;
    char ligneChar = 0;
    int map = 0;

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
    fonctionLog("mapTemp\t",mapTemp);    //log
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



    // Titre

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

    //mapTemp = fonctionMap(1);

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


            // bateaux disponibles

            printf("\n\nLes bateaux peuvent etre places verticalement ou horizontalement.");
            printf("\n\nBateaux disponibles :");

            map = -1;
            mapTemp = fonctionMap(map);
            fonctionLog("map\t\t",map);    //log
            // map nbr et type de bateaux


            for(i = 0; i < 10; i++){
                for (int j = 0; j < 10; ++j) {
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


/*
            map = 2;
            fonctionLog("map\t\t",map);    //log
            mapTemp = fonctionMap(map);*/
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
            fonctionLog("map\t\t",map);    //log
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
            fonctionLog("menuMap\t",menuMap);    //log

            // Effacer l'affichage
            system("cls");

            switch(menuMap){

                //  choix de la map
                case 1:
                    printf("\nchoisissez une map entre 1 et 4 (0 pour aleatoire) :");
                    printf("\n\n");
                    scanf("%d",&map);
                    fonctionLog("map\t\t",map);    //log
                    mapTemp = fonctionMap(map);
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

            //  Remise a 0 de la map

            // remise à 0

            for(i = 0; i < 10; i++){
                for (int j = 0; j < 10; ++j) {
                    tableau[i][j] = 0;
                }
            }


            for(ligne = 0; ligne < 10; ligne++){
                fonctionLog("ligne\t",ligne);    //log
                for(col = 0; col < 10; col++){
                    fonctionLog("col\t\t",col);    //log
                    tableau[ligne][col] = 0;
                }
            }

            // map aléatoire

            if(map == 0){
                map = 1 + rand() % 4;
                fonctionLog("map\t\t",map);    //log
                mapTemp = fonctionMap(map);
                fonctionLog("mapTemp\t\t",mapTemp);    //log
            }

            // Effacer l'affichage
            system("cls");

            //  Debut de partie

            printf("\n\nJEU :");
            grille = fonctionGrille();
            touche = 0;
            fonctionLog("touche\t",touche);    //log


            //  Continue tant que tous les bateaux n'ont pas tous ete touches

            while(touche < 17){
                fonctionLog("touche\t",touche);    //log
                grilleMap = fonctionMap(map);

                do {
                    do {

                        ligne = -1;
                        fonctionLog("ligne\t", ligne);    //log
                        //do{
                        printf("\nligne : ");
                        scanf("%c", &ligneChar);
                        fonctionLog("ligneChar", ligneChar);    //log


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

                grille = fonctionGrille();


                fonctionLog("coups\t",coups);    //log
                map = 0;
                fonctionLog("map\t\t",map);    //log
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

    fonctionLog("\n\n",-679458374);
    printf("\n\n");
    return 0;
}