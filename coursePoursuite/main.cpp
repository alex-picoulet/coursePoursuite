/*
 Programme : coursePoursuite
 But :  Parcourir la distance saisie sur laquelle les joueurs se sont accordés en début de partie
 Date de dernière modification : 24 octobre 2022
 Auteurs ; A.Picoulet--Sonder  A.Ambroise
*/

#include "game-tools.h"
#include <iostream>
using namespace std;

int main(void)
{
    // VARIABLES
    string joueur1;              // Nom du joueur 1
    string joueur2;              // Nom du joueur 2
    unsigned short int distance; // Distance à parcourir
    unsigned short int tour;     // Le nombre de tours
    string ligneProgression1;    // La ligne de progression du joueur 1
    string ligneProgression2;    // La ligne de progression du joueur 2
    int distanceJoueur1;         // Distance parcouru du joueur 1
    int distanceJoueur2;         // Distance parcouru du joueur 2
    int valeurJoueur1;           // Valeurs des dés du joueur 1
    int valeurJoueur2;           // Valeurs des dés du joueur 2
    unsigned short int de1;      // Valeur du dé1
    unsigned short int de2;      // Valeur du dé2
    string choix;                // Choix des formules
    string direction;            // Direction choisie
    bool choixFormule;           // choix de la formule
    bool choixDirection;         // choix de la direction
    bool tourFini;               // savoir si le tour est terminé
    bool tourAuPluriel;          // savoir si le nombre de tour est superieur a 1 donc afficher le nombre de tours au pluriel
    bool JouerPartie;            // joueur la partie tant qu'aucun des joueurs n'abandonnent ou gagnent
    bool abandonnerJoueur1;      // abandon du joueur1
    bool abandonnerJoueur2;      // abandon du joueur2
    string rejouer;              // rejouer la partie
    int concatenation;           // concatenation des deux dés pour l'une des formules
    string chaine1;              // chaine de caractere correspondant au dé1 pour la concaténer
    string chaine2;              // chaine de caractere correspondant au dé2 pour la concaténer
    string chaine;               // chaine de caractere correspondant au deux dés

    // TRAITEMENTS

    // INITIALISATION
    // premier tour 
    tourAuPluriel = false;

    // affichage de l'interface
    cout << "                        C O U R S E  P O U R S U I T E                         " << endl;
    cout << "*******************************************************************************" << endl;

    // clavier >> saisirJoueur1 >> joueur1
    cout << "Saisisez le nom du joueur 1 : ";
    cin >> joueur1;

    // clavier >> saisirJoueur2 >> joueur2
    cout << "Saisisez le nom du joueur 2 : ";
    cin >> joueur2;

// goto si on veut rejouer la partie avec les memes joueurs
rejouerLaPartie:

    do
    {
        // clavier >> saisirDistance >> distance
        cout << endl
             << "Distance a parcourir (3..100) ? ";
        cin >> distance;

        if (distance > 100 || distance < 3)
        {
            cout << endl
                 << "D I S T A N C E  H O R S  D E S  L I M I T E S" << endl;

            cout << endl
                 << "Distance a parcourir (3..100) ? ";
            cin >> distance;
        }
    } while (distance > 100 || distance < 3);

    tour = 1;

    valeurJoueur1 = 0;
    valeurJoueur2 = 0;

    distanceJoueur1 = 0;
    distanceJoueur2 = 0;

    JouerPartie = true;

    abandonnerJoueur1 = false;
    abandonnerJoueur2 = false;

    // effacer l'ecran
    effacer();

    // JOUER PARTIE
    do
    {

        // Initialisation de la ligne de progression du joueur 1
        ligneProgression1 = ligneProgression1 + "<";
        for (int i = 0; i < distanceJoueur1; i++)
        {
            ligneProgression1 = ligneProgression1 + "=";
        }
        ligneProgression1 = ligneProgression1 + "0";
        for (int i = 0; i <= (distance - distanceJoueur1) - 1; i++)
        {
            ligneProgression1 = ligneProgression1 + "-";
        }
        ligneProgression1 = ligneProgression1 + ">";

        // Initialisation de la ligne de progression du joueur 2
        ligneProgression2 = ligneProgression2 + "<";
        for (int i = 0; i < distanceJoueur2; i++)
        {
            ligneProgression2 = ligneProgression2 + "=";
        }
        ligneProgression2 = ligneProgression2 + "0";
        for (int i = 0; i <= (distance - distanceJoueur2) - 1; i++)
        {
            ligneProgression2 = ligneProgression2 + "-";
        }
        ligneProgression2 = ligneProgression2 + ">";

        tourFini = false;

        // affichage de l'interface

        cout << "                        C O U R S E  P O U R S U I T E                         " << endl;
        cout << "*******************************************************************************" << endl;

        if (distanceJoueur1 > distance)
        {
            cout << endl
                 << "Joueur " << joueur1 << " a parcouru "
                 << "(" << distanceJoueur1 << "/" << distance << ")" << endl;
            cout << "D E P A S S E M E N T  D E  D I S T A N C E " << endl
                 << endl;
        }
        else if (distanceJoueur1 < 0)
        {
            cout << endl
                 << "Joueur " << joueur1 << " a parcouru "
                 << "(" << distanceJoueur1 << "/" << distance << ")" << endl;
            cout << "D I S T A N C E  N E G A T I V E" << endl
                 << endl;
        }
        else
        {
            cout << endl
                 << "Joueur " << joueur1 << " a parcouru "
                 << "(" << distanceJoueur1 << "/" << distance << ")" << endl;
            cout << ligneProgression1 << endl;
        }

        if (distanceJoueur2 > distance)
        {
            cout << endl
                 << "Joueur " << joueur2 << " a parcouru "
                 << "(" << distanceJoueur2 << "/" << distance << ")" << endl;
            cout << "D E P A S S E M E N T  D E  D I S T A N C E " << endl
                 << endl;
        }
        else if (distanceJoueur2 < 0)
        {
            cout << endl
                 << "Joueur " << joueur2 << " a parcouru "
                 << "(" << distanceJoueur2 << "/" << distance << ")" << endl;
            cout << "D I S T A N C E  N E G A T I V E" << endl
                 << endl;
        }
        else
        {
            cout << endl
                 << "Joueur " << joueur2 << " a parcouru "
                 << "(" << distanceJoueur2 << "/" << distance << ")" << endl;
            cout << ligneProgression2 << endl;
        }

        // lancer des dés joueur 1
        de1 = random(1, 6);
        de2 = random(1, 6);

        if (de1 == de2)
        {
            effacer();
            cout << endl
                 << "Tour "
                 << "(" << tour << ") "
                 << "lancer de " << joueur1 << ")"
                 << " (" << de1 << ")"
                 << " et"
                 << " (" << de2 << ")" << endl
                 << endl;
            cout << "(" << joueur1 << ")"
                 << " p a s s e  s o n  t o u r : d o u b l e (" << de1 << ")" << endl
                 << endl;
            goto doubleLancer;
        }

        // afficher tour et le lancer des dés
        cout << "Tour "
             << "(" << tour << ") "
             << "lancer de " << joueur1 << ")"
             << " (" << de1 << ")"
             << " et"
             << " (" << de2 << ")" << endl
             << endl;

        choixFormule = false;

        // clavier >> saisirChoix >> choix
        do
        {
            cout << "Formule : .a(" << de1 << "+" << de2 << ")"
                 << "=" << de1 + de2 << "     .b(" << de1 << "x" << de2 << ")"
                 << "=" << de1 * de2 << "      .c(" << de1 << de2 << ")"
                 << "     .d"
                 << "(" << de2 << de1 << ")"
                 << "      q.abandonner" << endl
                 << "Choix(a, b, c, d, q) : ";
            cin >> choix;

            if (choix == "a")
            {
                choixFormule = true;
                valeurJoueur1 = valeurJoueur1 + (de1 + de2);
            }
            if (choix == "b")
            {
                choixFormule = true;
                valeurJoueur1 = valeurJoueur1 + (de1 * de2);
            }
            if (choix == "c")
            {
                choixFormule = true;
                // Convertir d'abord les deux entiers en chaîne de caractere
                chaine1 = to_string(de1);
                chaine2 = to_string(de2);

                // Concatener les deux chaînes
                chaine = chaine1 + chaine2;

                // Convertir les deux chaînes en entier
                concatenation = stoi(chaine);
                valeurJoueur1 = concatenation;
            }
            if (choix == "d")
            {
                choixFormule = true;
                // Convertir d'abord les deux entiers en chaîne de caractere
                chaine1 = to_string(de1);
                chaine2 = to_string(de2);

                // Concatener les deux chaînes
                chaine = chaine2 + chaine1;

                // Convertir les deux chaînes en entier
                concatenation = stoi(chaine);
                valeurJoueur1 = concatenation;
            }
            if (choix == "q")
            {
                choixFormule = true;
                abandonnerJoueur1 = true;
                goto abandon;
            }
        } while (choixFormule == false);

        choixDirection = false;

        // choix direction
        do
        {
            // clavier >> saisirDirection >> direction
            cout << endl
                 << "Direction : .a.avancer(+" << valeurJoueur1 << ")"
                 << "    b.reculer(-" << valeurJoueur1 << ")"
                 << "    q.abandonner" << endl
                 << "Choix(a, b, q) : ";
            cin >> direction;

            if (direction == "a")
            {
                choixDirection = true;
                valeurJoueur1 = valeurJoueur1;
            }
            if (direction == "b")
            {
                choixDirection = true;
                valeurJoueur1 = valeurJoueur1 - 2 * valeurJoueur1;
            }
            if (direction == "q")
            {
                choixDirection = true;
                abandonnerJoueur2 = false;
            }
        } while (choixDirection == false);
        // ajout de la valeur des dés à la distance
        distanceJoueur1 = distanceJoueur1 + valeurJoueur1;

    // goto de l'abandon du joueur 1
    abandon:

        effacer();

    // goto du lancer double, passe le tour si lancer double
    doubleLancer:

        // reinitialisation des valeurJoueur1 et valeurJoueur2
        valeurJoueur1 = 0;
        valeurJoueur2 = 0;

        // reinitialisation de la ligne progression joueur1 et joueur2
        ligneProgression1 = "";
        ligneProgression2 = "";

        // pareil pour joueur2

        // Initialisation de la ligne de progression du joueur 1
        ligneProgression1 = ligneProgression1 + "<";
        for (int i = 0; i < distanceJoueur1; i++)
        {
            ligneProgression1 = ligneProgression1 + "=";
        }
        ligneProgression1 = ligneProgression1 + "0";
        for (int i = 0; i <= distance - distanceJoueur1; i++)
        {
            ligneProgression1 = ligneProgression1 + "-";
        }
        ligneProgression1 = ligneProgression1 + ">";

        // Initialisation de la ligne de progression du joueur 2
        ligneProgression2 = ligneProgression2 + "<";
        for (int i = 0; i < distanceJoueur2; i++)
        {
            ligneProgression2 = ligneProgression2 + "=";
        }
        ligneProgression2 = ligneProgression2 + "0";
        for (int i = 0; i <= distance - distanceJoueur2; i++)
        {
            ligneProgression2 = ligneProgression2 + "-";
        }
        ligneProgression2 = ligneProgression2 + ">";

        // affichage de l'interface
        cout << "                        C O U R S E  P O U R S U I T E                         " << endl;
        cout << "*******************************************************************************" << endl;

        if (distanceJoueur1 > distance)
        {
            cout << endl
                 << "Joueur " << joueur1 << " a parcouru "
                 << "(" << distanceJoueur1 << "/" << distance << ")" << endl;
            cout << "D E P A S S E M E N T  D E  D I S T A N C E " << endl
                 << endl;
        }
        else if (distanceJoueur1 < 0)
        {
            cout << endl
                 << "Joueur " << joueur1 << " a parcouru "
                 << "(" << distanceJoueur1 << "/" << distance << ")" << endl;
            cout << "D I S T A N C E  N E G A T I V E" << endl
                 << endl;
        }
        else
        {
            cout << endl
                 << "Joueur " << joueur1 << " a parcouru "
                 << "(" << distanceJoueur1 << "/" << distance << ")" << endl;
            cout << ligneProgression1 << endl;
        }

        if (distanceJoueur2 > distance)
        {
            cout << endl
                 << "Joueur " << joueur2 << " a parcouru "
                 << "(" << distanceJoueur2 << "/" << distance << ")" << endl;
            cout << "D E P A S S E M E N T  D E  D I S T A N C E " << endl;
        }
        else if (distanceJoueur2 < 0)
        {
            cout << endl
                 << "Joueur " << joueur2 << " a parcouru "
                 << "(" << distanceJoueur2 << "/" << distance << ")" << endl;
            cout << "D I S T A N C E  N E G A T I V E" << endl;
        }
        else
        {
            cout << endl
                 << "Joueur " << joueur2 << " a parcouru "
                 << "(" << distanceJoueur2 << "/" << distance << ")" << endl;
            cout << ligneProgression2 << endl;
        }

        // lancer des dés joueur 2
        de1 = random(1, 6);
        de2 = random(1, 6);

        if (de1 == de2)
        {
            effacer();
            cout << "Tour "
                 << "(" << tour << ") "
                 << "lancer de " << joueur2 << ")"
                 << " (" << de1 << ")"
                 << " et"
                 << " (" << de2 << ")" << endl
                 << endl;
            cout << "(" << joueur2 << ")"
                 << " p a s s e  s o n  t o u r : d o u b l e (" << de1 << ")" << endl
                 << endl;
            goto doubleLancer2;
        }

        // afficher tour et le lancer des dés
        cout << "Tour "
             << "(" << tour << ") "
             << "lancer de " << joueur2 << ")"
             << " (" << de1 << ")"
             << " et"
             << " (" << de2 << ")" << endl
             << endl;

        choixFormule = false;

        // clavier >> saisirChoix >> choix
        do
        {
            cout << "Formule : .a(" << de1 << "+" << de2 << ")"
                 << "=" << de1 + de2 << "     .b(" << de1 << "x" << de2 << ")"
                 << "=" << de1 * de2 << "      .c(" << de1 << de2 << ")"
                 << "     .d"
                 << "(" << de2 << de1 << ")"
                 << "      q.abandonner" << endl
                 << "Choix(a, b, c, d, q) : ";
            cin >> choix;

            if (choix == "a")
            {
                choixFormule = true;
                valeurJoueur2 = valeurJoueur2 + (de1 + de2);
            }
            if (choix == "b")
            {
                choixFormule = true;
                valeurJoueur2 = valeurJoueur2 + (de1 * de2);
            }
            if (choix == "c")
            {
                choixFormule = true;
                // Convertir d'abord les deux entiers en chaîne de caractere
                chaine1 = to_string(de1);
                chaine2 = to_string(de2);
                // Concatener les deux chaînes
                chaine = chaine1 + chaine2;

                // Convertir les deux chaînes en entier
                concatenation = stoi(chaine);
                valeurJoueur2 = concatenation;
            }
            if (choix == "d")
            {
                choixFormule = true;
                // Convertir d'abord les deux entiers en chaîne de caractere
                chaine1 = to_string(de1);
                chaine2 = to_string(de2);
                // Concatener les deux chaînes
                chaine = chaine2 + chaine1;

                // Convertir les deux chaînes en entier
                concatenation = stoi(chaine);
                valeurJoueur2 = concatenation;
            }
            if (choix == "q")
            {
                choixFormule = true;
                abandonnerJoueur2 = true;
                goto abandon2;
            }
        } while (choixFormule == false);

        choixDirection = false;

        // choix direction
        do
        {
            // clavier >> saisirDirection >> direction
            cout << endl
                 << "Direction : .a.avancer(+" << valeurJoueur2 << ")"
                 << "    b.reculer(-" << valeurJoueur2 << ")"
                 << "    q.abandonner" << endl
                 << "Choix(a, b, q) : ";
            cin >> direction;

            if (direction == "a")
            {
                choixDirection = true;
                valeurJoueur2 = valeurJoueur2;
            }
            if (direction == "b")
            {
                choixDirection = true;
                valeurJoueur2 = valeurJoueur2 - 2 * valeurJoueur2;
            }
            if (direction == "q")
            {
                choixDirection = true;
                abandonnerJoueur2 = true;
            }
        } while (choixDirection == false);
        // ajout de la valeur des dés à la distance
        distanceJoueur2 = distanceJoueur2 + valeurJoueur2;

    // goto de l'abandon du joueur 2
    abandon2:

        effacer();

    // goto du lancer double du joueur 2, passe le tour si lancer double
    doubleLancer2:

        // reinitialisation des valeurJoueur1 et valeurJoueur2
        valeurJoueur1 = 0;
        valeurJoueur2 = 0;

        // reinitialisation des lignes de progressions
        ligneProgression1 = "";
        ligneProgression2 = "";

        if (abandonnerJoueur1 == true and abandonnerJoueur2 == true)
        {
            cout << "double abandon";
            JouerPartie = false;
        }
        else if (abandonnerJoueur1 == true)
        {
            cout << joueur1 << " est une poule mouillee" << endl
                 << endl;
            cout << "### Victoire de (" << joueur2 << ") en (" << tour << ") tour par abandon de (" << joueur1 << ")";
            JouerPartie = false;
        }
        else if (abandonnerJoueur2 == true)
        {
            cout << joueur2 << " est une poule mouillee" << endl
                 << endl;
            cout << "### Victoire de (" << joueur1 << ") en (" << tour << ") tour par abandon de (" << joueur2 << ")";
            JouerPartie = false;
        }

        // verifier si victoirej1 et j2 au pluriel
        if (tourAuPluriel == true)
        {
            if (distanceJoueur1 == distance and distanceJoueur2 == distance)
            {
                effacer();
                cout << "### victoire exaequo de " << joueur1 << " et de" << joueur2 << " en (" << tour << ") tours";
                JouerPartie = false;
            }
        }

        else if (tourAuPluriel == false)
        {
            if (distanceJoueur1 == distance and distanceJoueur2 == distance)
            {
                effacer();
                cout << "### victoire exaequo de " << joueur1 << " et de" << joueur2 << " en (" << tour << ") tours";
                JouerPartie = false;
            }
        }

        // tour terminé
        tourFini = true;

        if (tourAuPluriel == false)
        {
            if (tourFini == true)
            {
                if (distanceJoueur1 == distance)
                {
                    cout << "### Victoire de " << joueur1 << " en (" << tour << ") tour" << endl;
                    JouerPartie = false;
                }
                if (distanceJoueur2 == distance)
                {
                    cout << "### Victoire de " << joueur2 << " en (" << tour << ") tour" << endl;
                    JouerPartie = false;
                }
            }
        }

        if (tourAuPluriel == true)
        {
            if (tourFini == true)
            {
                if (distanceJoueur1 == distance)
                {
                    cout << "### Victoire de " << joueur1 << " en (" << tour << ") tours" << endl;
                    JouerPartie = false;
                }
                if (distanceJoueur2 == distance)
                {
                    cout << "### Victoire de " << joueur2 << " en (" << tour << ") tours" << endl;
                    JouerPartie = false;
                }
            }
        }

        // incrementation de 1 à tour
        tour = tour + 1;

        // nombre de tours superieur a 1 donc au pluriel
        tourAuPluriel = true;

    } while (JouerPartie == true);

    cout << endl
         << endl
         << "Voulez vous rejouez ? " << endl
         << "a.(oui)      b.(non)" << endl
         << "choix(a, b) :";
    cin >> rejouer;

    if (rejouer == "a")
    {
        // retour juste avant de choisir la distance
        goto rejouerLaPartie;
    }

    return 0;
}