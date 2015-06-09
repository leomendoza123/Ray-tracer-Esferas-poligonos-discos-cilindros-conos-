



int HayInterseccionConEferas(Ray *rayo, ESFERA *esfera, double *distancia)
    {
    Ray ray = *rayo;
   // printf (">>>%f,%f,%f<< \n",  ray.direccion.x,  ray.direccion.y,  ray.direccion.z);

    double a = vectorProductoPunto(rayo->direccion, rayo->direccion);
    VECTOR ro_sc = vectorResta(rayo->origen, esfera->punto);
    double b = 2.0 * vectorProductoPunto(rayo->direccion, ro_sc);
    double y = vectorProductoPunto(ro_sc, ro_sc) - (esfera->radio*esfera->radio) ;


    double discriminante = b*b - 4 * a * y;

    double RaizDiscriminante = sqrt(b*b - 4 * a * y);

    if (discriminante >=0 ){
        double t1 = (-b-RaizDiscriminante)/2*a;
        double t2 = (-b+RaizDiscriminante)/2*a;
        if (t1<t2){
            *distancia =  t1;
        }
        else{
            *distancia =  t2;
        }
        return 1;
    }
    else {
        return 0;
    }

    }


INTERSECTION First_Intersection_Esferas(double *distanciaAnterior, Ray Rayo, int *tipoObjeto){
                    INTERSECTION  interseccion;
                    int existeInterseccion;
                    int numEsferas = sizeof(listaEsferas)/sizeof(listaEsferas[0]);
                    int x;

                    for (x=0; x < numEsferas; x++){
                        double distancia;
                        ESFERA Esfera = listaEsferas[x];
                         existeInterseccion = HayInterseccionConEferas (&Rayo, &Esfera, &distancia);

                         if (existeInterseccion && distancia<*distanciaAnterior && distancia>0.000001  ){
                            interseccion.distancia = distancia;
                            interseccion.esfera = Esfera;
                            *distanciaAnterior = distancia;
                            *tipoObjeto = 1;
                         }
                    }
                    return interseccion;
                }





        RGB De_que_color_esfera (Ray Rayo, INTERSECTION interseccion){

            //printf ("%f, %f, %f __ <<\n", interseccion.puntoInterseccion.x, interseccion.puntoInterseccion.y, interseccion.puntoInterseccion.z);

            VECTOR N = DireccionNormalizada(interseccion.puntoInterseccion, interseccion.esfera.punto );

           // printf ("Normal: %f, %f, %f __ \n", N.x, N.y, N.z);

            double iluminacion = 0;
            unsigned int numLuces = sizeof(listaLuces)/sizeof(listaLuces[0]);

            VECTOR L;
            double CosVectores;
            INTERSECTION CausanteDeSombra;
             double spec = 0;

            int x;
            for (x = 0; x< numLuces; x++){
                L = DireccionNormalizada (listaLuces[x].origen, interseccion.puntoInterseccion);
                Ray LineaHaciaLuz = {L, interseccion.puntoInterseccion};

                if (!First_Intersection(LineaHaciaLuz, &CausanteDeSombra )){
                    double F =  (double)1/((double)listaLuces[x].C1+interseccion.distancia*listaLuces[x].C2+(listaLuces[x].C3*interseccion.distancia*interseccion.distancia));
                    if (F>1){
                        F=1;
                    }
                    //REFLEXION DIFUZA
                    CosVectores = vectorProductoPunto(N, L);

                    if (CosVectores<0){
                        CosVectores = 0;
                    }
                    iluminacion += CosVectores * interseccion.esfera.KD * listaLuces[x].Ip * F;

                    //REFLEJO ESPECULAR
                    VECTOR V = vectorNegado(Rayo.direccion);
                    VECTOR R = vectorResta(vectorMultiplicacion(N, CosVectores * 2.0), L) ;
                    double Ri = vectorProductoPunto(V, R);
                    if (!(Ri < 0)) {
                        spec += pow(Ri, KN) * KS * listaLuces[x].Ip * F ;
                    }

                }

            }

            iluminacion +=  (Ka * Ia);

            if(iluminacion > 1.0){
                    iluminacion = 1.0;
            }

            double B = (double)interseccion.esfera.color.B*iluminacion +spec;
            double G = (double)interseccion.esfera.color.G*iluminacion +spec;
            double R = (double)interseccion.esfera.color.R*iluminacion +spec;
            if (B>1){ B = 1;}   if (G>1){ G = 1;}   if (R>1){ R = 1;}
            RGB color;
            color.B = B;
            color.G = G;
            color.R = R;
            return color;
        }
