# Gestion des états logiques des sorties digitales de l'EOM

## Introduction

Ce programme, intitulé "Gestion des états logiques des sorties digitales de l'EOM", a été développé par Enzo Sebiane. Il permet de gérer les états logiques des sorties digitales d'une carte Nucleo-L476RG avec microcontrôleur compatible Mbed. L'utilisateur peut choisir entre deux modes de fonctionnement : le Mode Manuel, où l'état logique est défini manuellement, et le Mode Aléatoire, où les états sont générés de manière aléatoire à intervalle régulier.

## Fonctionnalités

- **Mode Manuel :** L'utilisateur peut saisir le nom de l'état pour définir manuellement l'état logique des sorties digitales.
- **Mode Aléatoire :** Les états logiques des sorties sont générés de manière aléatoire à intervalle régulier, défini par l'utilisateur.

## Matériel requis

- Carte Nucleo-L476RG avec microcontrôleur compatible Mbed.
- (Ajoutez ici toute autre carte d'extension ou composant nécessaire)

## Configuration des sorties digitales

Les sorties digitales sont configurées selon un tableau de correspondance entre les noms des états et les configurations des sorties. Voici quelques exemples d'états préconfigurés :

- **LVP :** {1, 0, 1, 0, 1, 0}
- **LHP :** {1, 0, 1, 1, 1, 1}
- **L. +45 :** {1, 0, 1, 0, 0, 0}
- **L.-45 :** {1, 0, 1, 0, 1, 1}
- **RCP :** {1, 1, 0, 1, 0, 1}
- **LCP :** {0, 0, 0, 1, 0, 1}

## Utilisation

1. Au démarrage, le programme affiche un menu permettant à l'utilisateur de choisir entre le Mode Manuel (A) ou le Mode Aléatoire (B).
2. En Mode Manuel, l'utilisateur peut saisir le nom de l'état (LVP, LHP, L. +45, L.-45, RCP, LCP) pour définir manuellement l'état logique des sorties digitales.
3. En Mode Aléatoire, l'utilisateur doit spécifier la période de changement d'état en millisecondes. Les états seront générés de manière aléatoire à intervalle régulier.

## Observations

Les résultats peuvent être observés à l'aide du logiciel Tera Term via la console série.

## Remarques

- La gestion des états logiques est basée sur un tableau de correspondance.
- Le programme utilise la bibliothèque `<chrono>` pour gérer le temps.
- Les résultats sont affichés via la console série.

N'oubliez pas d'ajouter toute information supplémentaire pertinente à votre README et de tenir compte des éventuelles modifications ultérieures dans votre code.
