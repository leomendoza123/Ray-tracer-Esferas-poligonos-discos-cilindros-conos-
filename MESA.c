/*
* Instituto Tecnologico de Costa Rica
* Escuela de Ingenieria en Computacion
* Computer Graphics
*
* Programa: Mesa Example
* Archivo: mesa_example.c
*/


#include "vectorlib.h"
#include "structs.h"
#include "MESA.h"
#include "main.h"
#include "malloc.h"
#include <time.h>





void plot (int i, int j, RGB color){
	if (i>=0&&i<W_HEIGHT && j>=0&&j< W_WIDTH ){
		BUFFER[i][j].R = color.R;
		BUFFER[i][j].G = color.G ;
		BUFFER[i][j].B = color.B;
	}
}


void BufferInit (){
	int i, j;
	BUFFER = (RGB **)malloc(W_HEIGHT * sizeof(RGB*));
	for (i = 0; i < W_HEIGHT; i++)
	{
		BUFFER[i] = (RGB *)malloc(W_WIDTH * sizeof(RGB));
	}
	for (i = 0; i < W_HEIGHT; i++)
	{

		for (j = 0; j < W_WIDTH; j++){
			BUFFER[i][j].R = 0;
			BUFFER[i][j].G = 0;
			BUFFER[i][j].B = 0;
		}
	}
}


void draw_scene() {

    BufferInit ();
    cargaBuffer();

	int i, j;
	for (i = 0; i < W_HEIGHT; i++)
	{
		for (j = 0; j < W_WIDTH; j++)
		{
			glColor3f (BUFFER[i][j].R,BUFFER[i][j].G,BUFFER[i][j].B);
			glBegin(GL_POINTS);
			glVertex2i(i,j);
			glEnd();
		}
	}
	glFlush();
		//Swap double BUFFERs
	glutSwapBuffers();
}



void init ()
{
//TODO: TRADUCIR

	// Create and name window
	glutInitWindowPosition(10,10);
	glutInitWindowSize(W_HEIGHT, W_WIDTH);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutCreateWindow("RayTracer: Jose y Leo");

	// Set Projection Mode and Volume
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, W_WIDTH , 0.0, W_HEIGHT , -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);

	// Set clear color to black and clear window
	glClearColor (1.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
	glutDisplayFunc(draw_scene);

	// Enter main event loop
	glutMainLoop();
}
