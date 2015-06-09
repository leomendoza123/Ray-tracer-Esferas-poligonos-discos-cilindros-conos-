



int HayInterseccionConPoligonos(Ray *rayo, POLIGONO *poligono, double *distancia)
    {
    Ray ray = *rayo;




    double denominator = vectorProductoPunto(poligono->normal, ray.direccion);
    double numerador = -vectorProductoPunto(poligono->normal, ray.origen)+ poligono->D;
    if (denominator != 0 ){
            *distancia =  numerador/denominator ;
            INTERSECTION inter;
            inter.distancia = *distancia;
            inter.poligono = *poligono;

        return 1;
    }
    else {
        return 0;
    }



    }


int dentroPoligono(INTERSECTION inter){

    POLIGONO poligono = inter.poligono;

    double U ;
    double V ;
    double I_2DX ;
    double I_2DY ;

    // Aplana el poligono
    if (abs(poligono.normal.x) >= abs(poligono.normal.y)&& abs(poligono.normal.x) >= abs(poligono.normal.z)){

         U = poligono.normal.y;
         V = poligono.normal.z;
         I_2DX = inter.puntoInterseccion.y;
         I_2DY = inter.puntoInterseccion.z;
    }

    else if (abs(poligono.normal.y) >= abs(poligono.normal.x)&& abs(poligono.normal.y) >= abs(poligono.normal.z)){
         U = poligono.normal.x;
         V = poligono.normal.z;
         I_2DX = inter.puntoInterseccion.x;
         I_2DY = inter.puntoInterseccion.z;
    }

    else {
         U = poligono.normal.x;
         V = poligono.normal.y;
         I_2DX = inter.puntoInterseccion.x;
         I_2DY = inter.puntoInterseccion.y;
    }
    //TRASLADO de


    U -= I_2DX;
    V -= I_2DY;





    int ContadorParedes = 0;
    // Poca cada vertice del poligono
    double Vert2_2DY;
    double Vert2_2DX;
     double Vert1_2DX;
      double Vert1_2DY;
      int cantPuntos = inter.poligono.cantidadPuntos;
     int x;
    for (x=0; x < cantPuntos; x++){
        //Ovtengo dos vertices consecutivos que forman un de los lines del poligono
        if (abs(poligono.normal.x) >= abs(poligono.normal.y)&& abs(poligono.normal.x) >= abs(poligono.normal.z)){

             Vert1_2DX = inter.poligono.puntos[x%(cantPuntos-1)].y;
             Vert1_2DY = inter.poligono.puntos[x%(cantPuntos-1)].z;
             Vert2_2DX = inter.poligono.puntos[(x+1)%(cantPuntos-1)].y;
             Vert2_2DY = inter.poligono.puntos[(x+1)%(cantPuntos-1)].z;

        }
        else if (abs(poligono.normal.y) >= abs(poligono.normal.x)&& abs(poligono.normal.y) >= abs(poligono.normal.z)){

             Vert1_2DX = inter.poligono.puntos[x%(cantPuntos-1)].x;
             Vert1_2DY = inter.poligono.puntos[x%(cantPuntos-1)].z;
             Vert2_2DX = inter.poligono.puntos[(x+1)%(cantPuntos-1)].x;
             Vert2_2DY = inter.poligono.puntos[(x+1)%(cantPuntos-1)].z;
        }
        else {
             Vert1_2DX = inter.poligono.puntos[x%(cantPuntos-1)].x;
             Vert1_2DY = inter.poligono.puntos[x%(cantPuntos-1)].y;
             Vert2_2DX = inter.poligono.puntos[(x+1)%(cantPuntos-1)].x;
             Vert2_2DY = inter.poligono.puntos[(x+1)%(cantPuntos-1)].y;
        }


        Vert1_2DX -= I_2DX;
        Vert1_2DY -= I_2DY;
        Vert2_2DX -= I_2DX;
        Vert2_2DY -= I_2DY;
        if (Vert1_2DX>0 && Vert2_2DX>0 && Vert1_2DY<0  && Vert2_2DY>0||
            Vert1_2DX>0 && Vert2_2DX>0 && Vert1_2DY>0  && Vert2_2DY<0){
            ContadorParedes ++;

            }
        else if (Vert1_2DX<0 && Vert2_2DX>0 && Vert1_2DY<0  && Vert2_2DY>0||
                Vert1_2DX>0 && Vert2_2DX<0 && Vert1_2DY>0  && Vert2_2DY<0 ||
                Vert1_2DX>0 && Vert2_2DX<0 && Vert1_2DY<0  && Vert2_2DY>0||
                Vert1_2DX<0 && Vert2_2DX>0 && Vert1_2DY>0  && Vert2_2DY<0){
            ContadorParedes ++;

            }


        //printf ("U= %f, V= %f, U'= %f, V'  %f \n",Vert1_2DX, Vert1_2DY,Vert2_2DX, Vert2_2DY );




    } return ContadorParedes %2;





}



INTERSECTION First_Intersection_Poligonos(double *distanciaAnterior, Ray Rayo, int *tipoObjeto){
                    INTERSECTION  interseccion;
                    int existeInterseccion;
                    int numPoligonos = sizeof(listaPoligonos)/sizeof(listaPoligonos[0]);
                    int x;
                    //printf ("Numero poligonos: %d", numPoligonos);

                    for (x=0; x < numPoligonos; x++){
                        double distancia;
                        POLIGONO Poligono = listaPoligonos[x];
                         //printf ("Poligono: %f", Poligono.D);
                         existeInterseccion = HayInterseccionConPoligonos (&Rayo, &Poligono, &distancia);

                         if (existeInterseccion && distancia<*distanciaAnterior && distancia>0.000001  ){
                            //printf ("DIS %f __ ", distancia);
                            interseccion.distancia = distancia;
                            interseccion.poligono = Poligono;
                            *distanciaAnterior = distancia;
                            *tipoObjeto = 2;
                         }
                    }
                    return interseccion;
                }



RGB De_que_color_poligono (Ray Rayo, INTERSECTION interseccion){

            INTERSECTION CausanteDeSombra;
            int x;
            double spec =0 ;
            double iluminacion = 0 ;
            VECTOR L;
            unsigned int numLuces = sizeof(listaLuces)/sizeof(listaLuces[0]);


            for (x = 0; x< numLuces; x++){
                L = DireccionNormalizada (listaLuces[x].origen, interseccion.puntoInterseccion);
                //printf("x %f, y %f, z %f \n", L.x, L.y, L.z);
                 Ray LineaHaciaLuz = {L, interseccion.puntoInterseccion};

                if (!First_Intersection(LineaHaciaLuz, &CausanteDeSombra )){
                   iluminacion = 1;
                   spec = 0;
                }
                else{


                }

            }

          iluminacion +=  (Ka * Ia);

            if(iluminacion > 1.0){
                    iluminacion = 1.0;
            }

            double B = (double)interseccion.poligono.color.B*iluminacion +spec;
            double G = (double)interseccion.poligono.color.G*iluminacion +spec;
            double R = (double)interseccion.poligono.color.R*iluminacion +spec;
            if (B>1){ B = 1;}   if (G>1){ G = 1;}   if (R>1){ R = 1;}
            RGB color;
            color.B = B;
            color.G = G;
            color.R = R;
            return color;


        }
