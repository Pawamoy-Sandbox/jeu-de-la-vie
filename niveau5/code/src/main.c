/** \file main.c
 * \brief programme s'exécutant dans une fenêtre graphique (cairo) :  
 * charge les paramètres d'affichage et une grille et débute le jeu
 */

#include <stdio.h>
#include <cairo.h>
#include <cairo-xlib.h>
#include <X11/Xlib.h>
#include "../include/grille.h"
#include "../include/io.h"
#include "../include/jeu.h"

/** 
 * \brief initialisation et début du jeu (mode graphique)
 * \param argc nombre d'arguments shell
 * \param argv tableau des arguments shell
 */
int main (int argc, char *argv[]){
	
	// argument test
	if (argc != 2 ){
		printf("usage : main <fichier grille>\n");
		return 1;
	}
	
	// X11 display
	Display *dpy;
	Window rootwin;
	Window win;
	int scr;
	
	// init the display
	if(!(dpy=XOpenDisplay(NULL))) {
		fprintf(stderr, "ERROR: Could not open display\n");
		exit(1);
	}

	scr=DefaultScreen(dpy);
	rootwin=RootWindow(dpy, scr);

	win=XCreateSimpleWindow(dpy, rootwin, 1, 1, SIZEX, SIZEY+70, 0, 
			BlackPixel(dpy, scr), BlackPixel(dpy, scr));

	XStoreName(dpy, win, "jeu de la vie");
	XSelectInput(dpy, win, ExposureMask|ButtonPressMask|KeyPressMask);
	XMapWindow(dpy, win);
	
	// create cairo surface
	cairo_surface_t *cs; 
	cs=cairo_xlib_surface_create(dpy, win, DefaultVisual(dpy, 0), SIZEX, SIZEY+70);
	
	// init program data
	grille g, gc;
	init_grille_from_file(argv[1],&g);
	alloue_grille (g.nbl, g.nbc, &gc);
	
	// run the event loop
	debut_jeu(&g, &gc, dpy, cs);
	
	// free program data
	libere_grille(&g);
	libere_grille(&gc);

	cairo_surface_destroy(cs); // destroy cairo surface
	XCloseDisplay(dpy); // close the display
	return 0;
}
