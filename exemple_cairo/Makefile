
CFLAGS = -Wall
IFLAGS = -I /usr/include/cairo/ -I /usr/include/X11/
LFLAGS = -lcairo -lX11

exemple : exemple_cairo.o
	gcc $(CFLAGS) -o $@ $< $(LFLAGS)

exemple_cairo.o : exemple_cairo.c
	gcc $(CFLAGS) -o $@ -c $< $(IFLAGS)

clean :
	rm *.o exemple
