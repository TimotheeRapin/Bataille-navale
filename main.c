/*
*************************************************************************
*                                                                       *
*       N° de projet :              Pr01                                *
*       Nom du projet :             Bataille-navale                     *
*       Version :                   0.1                                 *
*       Développer par :            Timothée Rapin                      *
*       Date de création :          04.03.2020                          *
*       Date de mise à jour :       07.03.2020                          *
*       Nouveautés :                map aléatoire                       *
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


int fonctionMenu (){
    int choixMenu = 0;

    printf("\n\n\nMENU :");
    printf("\n\n1) Afficher l'aide");
    // printf("\n2) S'authentifier");
    printf("\n3) Choisir une map");
    printf("\n4) Jouer");
    // printf("\n5) Afficher les scores");
    printf("\n6) Quiter\n");

    scanf("%d", &choixMenu);

    return choixMenu;
}

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

    // remise de la map a 0


    switch(map){

        // map symboles
        case 1:
            tableau[0][0] = 0;
            tableau[0][1] = 1;
            // tableau[0][2] = 2;
            tableau[0][3] = 3;
            break;

            // map bateaux
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
    }

    return 0;
}

int main() {
    setbuf(stdout,0);


    // Déclarations + initialisations

    int menu = 0;
    int menuMap = 0;
    int i = 0;
    int grille = 0;
    int grilleMap = 0;
    int mapTemp = 0;
    int touche = 18;
    int coups = 0;

    srand( (unsigned)time( NULL ) ); // pour que le nbr soit différent à chaque fois

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


    do {

        // MENU

        menu = fonctionMenu();


        // AIDE

        if (menu == 1) {
            printf("\n\nAIDE :");
            printf("\n\nquand une case n'est pas designee la case reste vide");
            printf("\nQuand c'est dans l'eau, il y a un %c",250);
            // printf("\nQuand un bateau est touche, il y a un x");
            // printf("\nQuand un bateau est coule, il y a un %c%c%c",219,219,219);
            printf("\nQuand un bateau est touche, il y a un %c%c%c",219,219,219);
            printf("\nExemple :");


            // map exemple

            for(ligne = 0; ligne < 10; ligne++){
                for(col = 0; col < 10; col++){
                    tableau[ligne][col] = 0;
                }
            }

            map = 1;
            mapTemp = fonctionMap();
            grille = fonctionGrille();

            printf("\n");
            system("pause");

            printf("\n\nLes bateaux peuvent etres place verticalement ou horizontalement");
            printf("\nBateaux disponible :");


            // map aide

            map = 2;
            mapTemp = fonctionMap();
            grille = fonctionGrille();

            printf("\n");
            system("pause");

            printf("\nles bateau ne peuvent pas etre colle l'un contre l'autre (en diagonale non plus)");

            printf("\n");
            system("pause");

            map = 0;
        }


        // AUTHENTIFICATION

        if (menu == 2) {
            printf("\n\nAUTHENTIFICATION :");
        }


        // MAPS

        if (menu == 3){
            printf("\n\nMAPS :");
            printf("\n\n1) Choisir une map");
            // printf("\n2) Creer une map");
            // printf("\n3) Supprimer une map");
            printf("\n");
            scanf("%d",&menuMap);

            switch(menuMap){
                case 1:
                    printf("\nchoisissez une map entre 1 et 3 :\n");
                    scanf("%d",&map);
                    map = map + 2;
                    break;

                case 2:

                    break;

                case 3:

                    break;
            }
        }


        // JEU

        if (menu == 4){
            for(ligne = 0; ligne < 10; ligne++){
                for(col = 0; col < 10; col++){
                    tableau[ligne][col] = 0;
                }
            }

            // map aléatoire

            if(map == 0){
                map = 3 + rand() % 5;
            }


            printf("\n\nJEU :");
            grille = fonctionGrille();
            i = 0;
            while(i < touche){
                grilleMap = fonctionMap();

                do{
                    printf("\nligne :");
                    scanf("%d", &ligne);
                }while((ligne < 1) || (ligne > 10));

                do{
                    printf("\ncolonne :");
                    scanf("%d", &col);
                }while((col < 1) || (col > 10));

                if(tableauMap[ligne-1][col-1] == 1){
                    tableau[ligne-1][col-1] = 3;
                    i++;
                }
                else{
                    tableau[ligne-1][col-1] = 1;
                }
                grille = fonctionGrille();

                coups++;
            }

            printf("\nBRAVO !");
            printf("\nvotre score est de %d coups",coups);

            printf("\n");
            system("pause");
        }


        // SCORES

        if(menu == 5){
            printf("\n\nSCORES :");
        }


    }while(menu != 6);


    // Fin

    printf("\n\n");
    return 0;
}