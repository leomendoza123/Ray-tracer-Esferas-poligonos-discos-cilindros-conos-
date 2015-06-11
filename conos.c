
int HayInterseccionConConos(Ray *rayo,CONO *cono,double *distancia)
{
Ray ray = *rayo;

double a2 = vectorProductoPunto(rayo->direccion, rayo->direccion);
double coseno2a = cos(cono->alpha) * cos(cono->alpha);
double seno2a = 1 - coseno2a;
VECTOR pa = vectorSuma(cono->centro,cono->upVector);
pa = vectorMultiplicacion(pa, cono->height);
VECTOR va = vectorMultiplicacion(cono->upVector, -1);
VECTOR deltaP = vectorResta(rayo->origen, pa);

double c1 = vectorProductoPunto(rayo->direccion, va);
VECTOR c2 = vectorMultiplicacion(va,c1);
double c3 = vectorProductoPunto(deltaP,va);
VECTOR c4 = vectorMultiplicacion(va,c3);

double a = coseno2a * vectorProductoPunto(rayo->direccion,rayo->direccion) - seno2a * c1 * c1;
double b = 2 * coseno2a  * vectorProductoPunto(vectorResta(rayo->direccion,c2),vectorResta(deltaP,c4)) - 2 * seno2a * (c1 * c3);
double c = coseno2a * vectorProductoPunto(vectorResta(deltaP,c4),vectorResta(deltaP,c4)) - seno2a * (c3 * c3);

double discriminante = b * b - 4 * a * c;
if (discriminante<0){return 0;}
else{
discriminante = sqrt(discriminante);
double t1 = ((-1 * b) + discriminante) / (2 * a);
double t2 = ((-1 * b) - discriminante) / (2 * a);

if (t1<t2){
            *distancia =  t1;
        }
        else{
            *distancia =  t2;
        }
        return 1;
}

}
