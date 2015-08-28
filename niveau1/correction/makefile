CFLAGS = -Wall -g

main : main.o grille.o io.o jeu.o
	gcc $(CFLAGS) -o main main.o grille.o io.o jeu.o

grille.o : grille.c grille.h
	gcc $(CFLAGS) -c grille.c

io.o : io.c io.h grille.h jeu.h
	gcc $(CFLAGS) -c io.c

jeu.o : jeu.c jeu.h grille.h
	gcc $(CFLAGS) -c jeu.c

main.o : main.c grille.h io.h jeu.h
	gcc $(CFLAGS) -c main.c

clean : 
	rm *.o main

archive : 
	tar -f jeudelavie.tar.gz -cvz *.c *.h makefile Doxyfile
