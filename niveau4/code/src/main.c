/** \file main.c
 * \brief programme s'exécutant dans une console :  
 * charge une grille et débute le jeu
 */

#include <stdio.h>

#include "../include/grille.h"
#include "../include/io.h"
#include "../include/jeu.h"

/** 
 * \brief initialisation et début du jeu
 * \param argc nombre d'arguments shell
 * \param argv tableau des arguments shell
 */
int main (int argc, char ** argv) {
	
	if (argc != 2 )
	{
		printf("usage : main <fichier grille>");
		return 1;
	}

	grille g, gc;
	init_grille_from_file(argv[1],&g);
	alloue_grille (g.nbl, g.nbc, &gc);
	affiche_grille(g);
	
	debut_jeu(&g, &gc);

	libere_grille(&g);
	libere_grille(&gc);
	return 0;
}
