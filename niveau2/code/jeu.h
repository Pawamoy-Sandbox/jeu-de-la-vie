/** \file jeu.h
 * \brief algorithmes d'evolution du jeu (header)
 */

#ifndef __JEU_H
#define __JEU_H

#include "grille.h"

/** 
 * \brief modulo modifié pour traiter correctement les bords cycliques : 
 * \param i dividende
 * \param m diviseur
 * \return entier = \b i modulo \b m
 * \return particularité pour les bords : modulo(-1,m) renvoie (m-1)
 * \pre \b m > 0
 */
static inline int modulo(int i, int m) {return (i+m)%m;}

/** 
 * \brief compte le nombre de voisins vivants d'une cellule (bords cycliques)
 * \relatesalso grille
 * \param i indice de ligne de la cellule 
 * \param j indice de colonne de la cellule 
 * \param g grille
 * \return entier = nombre de voisins de (\b i,\b j) vivants dans \b g
 */
int compte_voisins_vivants (int i, int j, grille g);

/** 
 * \brief fait évoluer la grille \b g d'un pas de temps
 * \relatesalso grille
 * \param g (pointeur vers) la grille qui évolue
 * \param gc (pointeur vers) la grille tampon 
 * \pre \b g et \b gc sont allouées et de même taille
 */
void evolue (grille *g, grille *gc);

#endif
