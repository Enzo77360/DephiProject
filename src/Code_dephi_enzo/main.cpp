/*
 * Titre du programme: Gestion des états logiques des sorties digitales de l'EOM
 * 
 * Description du contenu:
 * Ce programme permet de gérer les états logiques des sorties digitales en fonction
 * des choix de l'utilisateur. Il offre deux modes de fonctionnement :
 * - Mode Manuel : L'utilisateur peut choisir manuellement l'état logique des sorties.
 * - Mode Aléatoire : Les états logiques des sorties sont générés de manière aléatoire.
 * 
 * Liste du matériel utilisé:
 * - Carte Nucleo-L476RG avec microcontrôleur compatible Mbed
 * - (Ajoutez ici toute autre carte d'extension ou composant nécessaire)
 * 
 * Auteur : Enzo Sebiane
 * 
 * Date de création : 29/02/2024
 * 
 * Remarques:
 * - La gestion des états logiques des sorties digitales est basée sur un tableau de correspondance
 *   entre les noms des états et les configurations des sorties.
 * - Le Mode Manuel permet à l'utilisateur de saisir le nom de l'état pour définir manuellement
 *   l'état de sortie.
 * - Le Mode Aléatoire génère de manière aléatoire les états des sorties à intervalle régulier choisi via la variable periode.
 * - Les résultats peuvent être observés à l'aide du logiciel Tera Term via la console série.
 */


#include "mbed.h"
#include <cstdio>
#include <string>
#include <map>
#include <chrono> // Inclure la bibliothèque pour chrono::milliseconds


// Déclaration des sorties digitales
DigitalOut digitalOutD3(D3);
DigitalOut digitalOutD5(D5);
DigitalOut digitalOutD6(D6);
DigitalOut digitalOutD9(D9);
DigitalOut digitalOutD10(D10);
DigitalOut digitalOutD11(D11);

// Tableau des noms d'états correspondant aux sorties digitales
std::map<std::string, std::tuple<int, int, int, int, int, int>> stateMap = {
    {"LVP", {1, 0, 1, 0, 1, 0}},
    {"LHP", {1, 0, 1, 1, 1, 1}},
    {"L. +45", {1, 0, 1, 0, 0, 0}},
    {"L.-45", {1, 0, 1, 0, 1, 1}},
    {"RCP", {1, 1, 0, 1, 0, 1}},
    {"LCP", {0, 0, 0, 1, 0, 1}}
};

// Fonction pour définir l'état logique en fonction du nom de l'état
void setLogicState(const std::string &stateName) {
    auto it = stateMap.find(stateName);
    if (it != stateMap.end()) {
        auto selectedLogicState = it->second;
        // Configuration des sorties en fonction du logic state choisi
        digitalOutD3 = std::get<0>(selectedLogicState);
        digitalOutD5 = std::get<1>(selectedLogicState);
        digitalOutD6 = std::get<2>(selectedLogicState);
        digitalOutD9 = std::get<3>(selectedLogicState);
        digitalOutD10 = std::get<4>(selectedLogicState);
        digitalOutD11 = std::get<5>(selectedLogicState);
        printf("État %s choisi manuellement.\r\n", stateName.c_str());
    } else {
        printf("État non valide.\r\n");
    }
}

// Fonction pour générer un état logique de manière aléatoire
void generateRandomLogicState() {
    // Génération d'un index pseudo-aléatoire pour choisir un état logique
    int randomIndex = rand() % stateMap.size();
    auto it = stateMap.begin();
    std::advance(it, randomIndex);
    auto selectedLogicState = it->second;

    // Configuration des sorties en fonction de l'état logique choisi
    digitalOutD3 = std::get<0>(selectedLogicState);
    digitalOutD5 = std::get<1>(selectedLogicState);
    digitalOutD6 = std::get<2>(selectedLogicState);
    digitalOutD9 = std::get<3>(selectedLogicState);
    digitalOutD10 = std::get<4>(selectedLogicState);
    digitalOutD11 = std::get<5>(selectedLogicState);

    // Affichage du nom de l'état en cours
    printf("Current State : %s\r\n", it->first.c_str());
}

int main() {
    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));

    // Affichage du menu pour choisir le mode au début du programme
    printf("Menu :\n");
    printf("a. Mode Manuel (appuyez sur A)\n");
    printf("b. Mode Random (appuyez sur B)\n");
    printf("Votre choix : ");

    char choix;
    scanf(" %c", &choix);

    // Gestion du choix de l'utilisateur
    switch (choix) {
        case 'a':
            printf("Mode Manuel\n");
            // Mettre ici le code pour le Mode Manuel
            printf("Entrez le nom de l'etat (LVP, LHP, L. +45, L.-45, RCP, LCP) : ");
            char stateName[10];
            scanf("%s", stateName);
            setLogicState(stateName);
            printf("Etat actuel : %s\r\n", stateName);
            break;
        case 'b':
             printf("Mode Random\n");
            // Demander à l'utilisateur la période de changement d'état
            printf("Entrez la periode de changement d'etat (en millisecondes) : \n");
            int periode;
            scanf("%d", &periode);
            // Mettre ici le code pour le Mode Aléatoire
            while (1) {
                generateRandomLogicState();
                ThisThread::sleep_for(std::chrono::milliseconds(periode)); // Attendre la période spécifiée
             }
            break;

    }

    // Boucle principale sans attendre
    while(1) {
        // Permettre aux autres processus de s'exécuter
        ThisThread::sleep_for(100ms);
    }
}
