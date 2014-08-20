//
//  SampleStructureSprite.c
//  SpaceInvader
//
//  Created by Antony Canut on 21/07/14.
//  Copyright (c) 2014 Antony Canut. All rights reserved.
//

#include <stdio.h>

// Ceci est un simple sample de la structure d'un sprite
// Chaque contenu et contenant sera expliqué

// Si je pouvais avoir la totalité de ce que l'on avait a la piscine, je pourrais
// faire un exemple avec le sprite du vaisseau en exemple dès ce mardi

// La structure position va permetre a chaque sprite d'avoir une position du sprite sur l'écran
struct Position {
    int X;
    int Y;
};

// Ceci va permettre de savoir si un sprite est toujours "en vie", un sprite mort ne doit pas être affiché
int IsAlive;

// Ceci va permettre de connaitre la vitesse de déplacement d'un sprite.
// Un vaisseau ennemi mineur pourra se déplacer de 3px à l'avance par exemple
// et le boss de 6
// Faire varier cette valeur pour le joueur pour augmenter sa vitesse
int Speed;

// Va contenir le modele du sprite de tir
// Je ne suis pas certains de passer par ici encore
// [EN RESERVE]
struct Bullet{
    
};

// L'initialisation des variables se fait ici, la position, sa vitesse...
void Init(Coordonnees position);

// Cette partie permet de charger les données d'un sprite (image par exemple, ou bien l'image de ses tirs)
void LoadContent();

// Cette partie va permettre de libérer la mémoire lors de la destruction d'un sprite ou la fermeture du jeu
void UnLoadContent();

// Cette partie va pouvoir permettre de "d'afficher" le sprite
// En mettant les sprites dans une boucle de type
// sprite->Draw();
// Ceux-ci s'afficheront dans le bon ordre
void Draw();

// Cette partie contient TOUTE la logique d'un sprite, son déplacement, pourquoi, comment
// Mais elle contient une exception expliqué juste en dessous (pour le joueur)
void Update();

// C'est cette partie qui va gérer la logique lié aux inputs du joueurs (Déplacements, tirs)
// Vous vous doutez bien qu'on en a absolument rien a foutre de remplir cette fonction chez l'ennemi
void UpdateInput();

// Ici sera géré la génération des tirs
// Chaque tir est un sprite avec sa propre logique, il récupere la position du sprite en cours pour démarer (dans son Init(x = 0, y = 0))
void Shot();

// Ici est gérer la mort du sprite, son animation est faite ici
void Dead();

// En conclusion, toute les méthodes sont indispensable.
// Malheureusement ou plutôt heureusement, ce n'est pas fini.
// Il faudra également générer les "BoudingBox" (Qui permettent de définir les HitBox)
// Cette partie pourra être faite lorsque les ennemis et les tirs auront été généré