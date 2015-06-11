
typedef struct{
double R;
double G;
double B;

} RGB;



typedef struct PuntoLista {
   double x;
   double y;
   double z;
}Elemento;

typedef struct{
VECTOR centro;
VECTOR upVector;
double alpha;
double height;
RGB color;
double KD;
}CONO;

typedef struct{
    VECTOR normal;
    double D;
    Elemento puntos[10];
    int cantidadPuntos;
    RGB color;
    double KD;
} POLIGONO;

typedef struct{
    int radio;
    RGB color;
    VECTOR punto;
    double KD;
} ESFERA;


typedef struct{
    double distancia;
    ESFERA esfera;
    POLIGONO poligono;
    VECTOR puntoInterseccion;

} INTERSECTION;

typedef struct{
    VECTOR origen;
    double Ip;
    double C1;
    double C2;
    double C3;
} LUZ;


typedef struct {

    VECTOR direccion;
    VECTOR origen;
} Ray;



