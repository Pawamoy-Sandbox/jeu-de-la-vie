/** \file io.h
 * \brief entrees / sorties (header)
 */

#ifndef __IO_H
#define __IO_H

#include <stdio.h>
#include "grille.h"
#include "jeu.h"

/** 
 * \brief affichage d'un trait horizontal
 * \param c nombre de colonnes
 */
void affiche_trait (int c);

/** 
 * \brief affichage d'une ligne de la grille
 * \param c nombre de colonnes
 * \param ligne ligne dans une grille (pointeur)
 */
void affiche_ligne (int c, int* ligne);

/** 
 * \brief affichage d'une grille
 * \relatesalso grille
 * \param g grille à afficher
 */
void affiche_grille (grille g);

/** 
 * \brief effacement d'une grille
 * \relatesalso grille
 * \param g grille à effacer
 */
void efface_grille (grille g);

/** 
 * \brief débute une partie
 * \param g grille du jeu
 * \param gc grille tampon (nécessaire pourla fonction \c evolue)
 */
void debut_jeu(grille *g, grille *gc);

#endif
