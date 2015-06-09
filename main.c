
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "vectorlib.h"
#include "structs.h"


#include "diseno.h"
#include "logica.h"



#include "main.h"
#include "MESA.h"

#include "creador.c"
#include "archivos.c"


//Instituto Tecnologico de Costa Rica
//Introduccion a los graficos por computadora
//Jose Carlos Alvarez Umana
//Leonardo Mendoza
//compile as gcc main.c vectorlib.c logica.c print.c -lm -o main



int main(int argc, char* argv[]);
RGB De_que_color ( Ray Rayo);
int First_Intersection ( Ray Rayo, INTERSECTION *interseccion );
int HayInterseccion(Ray *rayo, ESFERA *esfera, double *distancia);
VECTOR PuntoInterseccion (Ray Rayo, double distancia);
 VECTOR DireccionNormalizada (VECTOR Destino, VECTOR Origen );
#include "esferas.c"
#include "poligonos.c"


 void CreaEsferas();

void cargaBuffer ();
void escribirAvs();

int main(int argc, char* argv[])
        {
        W_HEIGHT = 500;
        W_WIDTH = 500;
        glutInit(&argc, argv);
        BufferInit();
        cargaBuffer();
        escribirAvs();
        init();
    }



void cargaBuffer (void){

        printLabelEncabezado();
        int vres = 500;
        int hres = 500;
        int Xmin =  0 ;
        int Ymin =  0;
        int Xmax =  500;
        int Ymax =  500;
        double Xw = 0;
        double Yw = 0;
        double Zw = 0;
        double Xe =   250;
        double Ye =   250;
        double Ze =  -1500;
        double L;
        double Xd = 0;
        double Yd = 0;
        double Zd = 0;

        int i =0;
        int j =0;

        RGB Color;
        for(i=0; i < hres; i++){
                   //printf (">>>::Cambio de linea #%d :::<< \n", i);
                    for(j=0; j < vres; j++){

                    // Puntos en framebuffer
                    Xw = WindowPointToFramePoint( i,  hres,  Xmax,  Xmin);
                    Yw = WindowPointToFramePoint( j,  vres,  Ymax,  Ymin);
                    Zw = 0.0;


                    // Direccion del rayo normalizada
                    L  = getL (Xw,Yw,Zw,Xe,Ye,Ze);
                    Xd = getXd(Xw, Xe, L);
                    Yd = getYd(Yw, Ye, L);
                    Zd = getZd(Zw, Ze, L);


                    Ray Rayo;
                    //Rayo.direccion.x = Xd;
                    //Rayo.direccion.y = Yd;
                    //Rayo.direccion.z = Zd;
                    VECTOR PuntoVentana = {Xw, Yw, Zw};
                    VECTOR Ojo = {Xe, Ye, Ze};
                    Rayo.direccion = DireccionNormalizada (PuntoVentana,Ojo);
                    Rayo.origen.x = Xe;
                    Rayo.origen.y = Ye;
                    Rayo.origen.z = Ze;

                    // Color del pixel;
                    Color = De_que_color (Rayo);
                    plot ( i,  j,  Color);

                    }
        }
}

RGB De_que_color (Ray Rayo)
{
    RGB color;

    INTERSECTION  interseccion;
    if (First_Intersection(Rayo, &interseccion) == 1){
        return De_que_color_esfera (Rayo, interseccion);
    }
    else if (First_Intersection(Rayo, &interseccion) == 2){
        return De_que_color_poligono(Rayo, interseccion);


    }
    else {

        return BACKGROUD;
    }
}


int First_Intersection (Ray Rayo, INTERSECTION *interseccionEcontrada)
         {

                INTERSECTION  interseccion;
                interseccion.distancia = 0;

                double tmin = 9000;
                double distanciaAnterior = tmin;
                double *distanciaConPrimeraInterseccion = 0;
                int tipoObjeto = 0;

                interseccion = First_Intersection_Poligonos(&distanciaAnterior, Rayo, &tipoObjeto);
                interseccion = First_Intersection_Esferas(&distanciaAnterior, Rayo, &tipoObjeto);




                // Es esfera
                if (tipoObjeto== 1 ){
                    interseccion.puntoInterseccion = PuntoInterseccion (Rayo, interseccion.distancia);
                    *interseccionEcontrada = interseccion;
                    return tipoObjeto;
                }
                // Es poligono
                if (tipoObjeto== 2 ){
                    interseccion.puntoInterseccion = PuntoInterseccion (Rayo, interseccion.distancia);
                    *interseccionEcontrada = interseccion;
                    // Verifica que el punto este dentro del poigono
                    if (dentroPoligono (*interseccionEcontrada)){
                        return tipoObjeto;
                    }
                    else {
                        return 0;
                    }
                }


                else {

                    return 0;
                }
        }

VECTOR PuntoInterseccion (Ray Rayo, double distancia){
   //printf ("Rayo Direc; %f, %f, %f\n", Rayo.direccion.x, Rayo.direccion.y, Rayo.direccion.z);
    //printf ("Rayo Orig; %f, %f, %f\n", Rayo.origen.x, Rayo.origen.y, Rayo.origen.z);
    //printf ("Distancia; %f\n", distancia);
    VECTOR punto = vectorSuma(Rayo.origen, vectorMultiplicacion(Rayo.direccion, distancia));
    //printf ("Punto I: %f, %f, %f \n\n", punto.x, punto.y, punto.z);
    return punto;

}

/// REUBICAR


 VECTOR DireccionNormalizada (VECTOR Destino, VECTOR Origen ){

                        double L =  getL (Destino.x,Destino.y,Destino.z,Origen.x,Origen.y,Origen.z);
                        VECTOR direccion;
                        direccion.x = (double)getXd(Destino.x, Origen.x, L); // TODO: Usar una sola funccion
                        direccion.y = (double)getYd(Destino.y, Origen.y, L);
                        direccion.z = (double)getZd(Destino.z, Origen.z, L);




                        return direccion;
}


