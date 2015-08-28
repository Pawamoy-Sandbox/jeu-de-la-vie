/** \file grille.h
 * \brief gestion des grilles (header)
 */

#ifndef __GRILLE_H
#define __GRILLE_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/** \struct grille
 */
typedef struct {
	int nbl; /**< nombre de lignes*/
	int nbc; /**< nombre de colonnes*/
	int** cellules; /**< tableau (de taille nbl) de tableaux (de taille nbc) de cellules*/
} grille;
 
/** 
 * \brief alloue les cellules d'une grille et initialise toutes les cellules à "mortes"
 * \relatesalso grille
 * \param l nombre de lignes
 * \param c nombre de colonnes
 * \param g pointeur vers la grille
 */
void alloue_grille (int l, int c, grille* g);

/** 
 * \brief libère les cellules d'une grille
 * \relatesalso grille
 * \param g pointeur vers la grille
 */
void libere_grille (grille* g);

/** 
 * \brief alloue et initialise les cellules d'une grille à partir d'un fichier
 * \relatesalso grille
 * \param filename nom du fichier
 * \param g pointeur vers la grille
 */
void init_grille_from_file (char * filename, grille* g);

/** 
 * \brief rend vivante la cellule (i,j) de la grille g
 * \param i indice de ligne de la cellule
 * \param j indice de colonne de la cellule
 * \param g grille
 * \pre i < g.nbl
 * \pre j < g.nbc
 */
static inline void set_vivante(int i, int j, grille g){g.cellules[i][j] = 1;}

/** 
 * \brief rend morte la cellule (i,j) de la grille g
 * \param i indice de ligne de la cellule
 * \param j indice de colonne de la cellule
 * \param g grille
 * \pre i < g.nbl
 * \pre j < g.nbc
 */
static inline void set_morte(int i, int j, grille g){g.cellules[i][j] = 0;}

/** 
 * \brief rend non-viable la cellule (i,j) de la grille g
 * \param i indice de ligne de la cellule
 * \param j indice de colonne de la cellule
 * \param g grille
 * \pre i < g.nbl
 * \pre j < g.nbc
 */
static inline void set_nonviable(int i, int j, grille g){g.cellules[i][j] = -1;} 
/** 
 * \brief teste si la cellule (i,j) de la grille g est vivante
 * \param i indice de ligne de la cellule
 * \param j indice de colonne de la cellule
 * \param g grille
 * \return entier (booléen) vaut 1 si la cellule est vivante, 0 sinon
 * \pre i < g.nbl
 * \pre j < g.nbc
 */
static inline int est_vivante(int i, int j, grille g){return g.cellules[i][j] > 0;}

/** 
 * \brief teste si la cellule (i,j) de la grille g est viable
 * \param i indice de ligne de la cellule
 * \param j indice de colonne de la cellule
 * \param g grille
 * \return entier (booléen) vaut 1 si la cellule est viable, 0 sinon
 * \pre i < g.nbl
 * \pre j < g.nbc
 */
static inline int est_viable(int i, int j, grille g){return g.cellules[i][j] >= 0;} 

/** 
 * \brief met à jour la cellule (i,j) : continue à vivre sans viellissement
 * \param i indice de ligne de la cellule
 * \param j indice de colonne de la cellule
 * \param g grille
 * \pre i < g.nbl
 * \pre j < g.nbc
 */
void set_ne_viellit_pas(int i, int j, grille g); 

/** 
 * \brief met à jour la cellule (i,j) : viellit de 1, et meurt si son age dépasse 8
 * \param i indice de ligne de la cellule
 * \param j indice de colonne de la cellule
 * \param g grille
 * \pre i < g.nbl
 * \pre j < g.nbc
 */
void set_viellit(int i, int j, grille g); 

/** 
 * \brief recopie une grille (sans allocation)
 * \relatesalso grille
 * \param gs grille source
 * \param gd grille destination
 * \pre \b gs et \b gd sont allouées et de même taille
 */
void copie_grille (grille gs, grille gd);

/** 
 * \brief indique si deux grilles sont égales ou non (ne prend pas l'âge en compte)
 * \relatesalso grille
 * \param a grille 1
 * \param b grille 2
 * \pre \b a et \b b sont allouées et de même taille
 * \return un entier, 1 si égales, 0 sinon
 */
int grilles_egales(grille a, grille b);

#endif
