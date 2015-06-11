
int HayInterseccionConConos(Ray *rayo,CONO *cono,double *distancia)
{
Ray ray = *rayo;

double a = vectorProductoPunto(rayo->direccion, rayo->direccion);
double coseno2a = cos(cono->alpha) * cos(cono->alpha);
double seno2a = 1 - coseno2a;
VECTOR pa = vectorSuma(cono->centro,cono->upVector);
pa = vectorMultiplicacion(pa, cono->height);
VECTOR va = vectorMultiplicacion(cono->upVector, -1);
VECTOR deltaP = vectorResta(rayo->origen, pa);

return 0;
}
