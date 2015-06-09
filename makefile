OBJECTS= main.o logica.c MESA.c print.c vectorlib.c
OUTPUT=mesa
CFLAGS=-I/usr/local/Mesa-3.4/include
#LDLIBS=-lX11 -lglut -lMesaGLU -lMesaGL -lm -lXext -lXmu
LDLIBS=-lX11 -lglut -lGLU -lGL -lm -lXext -lXmu
LDFLAGS=-L/usr/local/Mesa-3.4/lib -L/usr/X11R6/lib
$(OUTPUT): $(OBJECTS)
	cc $(CFLAGS) $(LDFLAGS) -o $(OUTPUT) $(OBJECTS) $(LDLIBS)
$(OBJECTS): main.h diseno.h structs.h creador.c esferas.c poligonos.c
clean:
	rm -f *.o
	rm -f mesa
