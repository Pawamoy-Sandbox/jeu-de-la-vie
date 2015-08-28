CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -L $(LIB) -ljeu

BIN = ./bin/
LIB = ./lib/
OBJ = ./obj/
INC = ./include/
SRC = ./src/

vpath %.c = ./src/
vpath %.o = ./obj/
vpath %.h = ./include/

main : main.o io.o libjeu.a
	$(CC) $(CFLAGS) -o $(BIN)$@ $(OBJ)main.o $(OBJ)io.o $(LDFLAGS)

io.o : io.c io.h grille.h jeu.h
main.o : main.c grille.h io.h jeu.h
grille.o : grille.c grille.h
jeu.o : jeu.c jeu.h grille.h

%.o : %.c
	$(CC) $(CFLAGS) -o $(OBJ)$@ -c $<

libjeu.a : grille.o jeu.o
	ar -crv $(LIB)$@ $(OBJ)grille.o $(OBJ)jeu.o
	ranlib $(LIB)$@

clean : 
	rm $(OBJ)*.o $(BIN)main $(LIB)libjeu.a

archive : 
	tar -f jeudelavie.tar.gz -cvz $(INC) $(SRC) $(OBJ) $(BIN) $(LIB) makefile Doxyfile
	
run1 :
	$(BIN)main ../../grilles/grille1.txt
run2 :
	$(BIN)main ../../grilles/grille2.txt
run3 :
	$(BIN)main ../../grilles/grille3.txt
run4 :
	$(BIN)main ../../grilles/grille4.txt
run5 :
	$(BIN)main ../../grilles/grille5.txt
run6 :
	$(BIN)main ../../grilles/grille6.txt
run7 :
	$(BIN)main ../../grilles/grille7.txt
run8 :
	$(BIN)main ../../grilles/grille8.txt
run9 :
	$(BIN)main ../../grilles/grille9.txt
