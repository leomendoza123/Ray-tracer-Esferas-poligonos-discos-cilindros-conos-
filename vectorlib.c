#include <stdio.h>
#include <math.h>
#include "vectorlib.h"
#include "print.h"

//Instituto Tecnologico de Costa Rica
//Introduccion a los graficos por computadora
//Jose Carlos Alvarez Umana
//Leonardo Mendoza
//Esta biblioteca esta diseñada para vectores de 3 elementos


double vectorProductoPunto(VECTOR a, VECTOR b){
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
	}

VECTOR vectorNegado(VECTOR a){
    VECTOR x = { (a.x * -1) , (a.y * -1) , (a.z * -1) };
    return x;
	}


VECTOR vectorResta(VECTOR a, VECTOR b){
    VECTOR x = {a.x - b.x, a.y - b.y, a.z - b.z};
    return x;
 }

 VECTOR vectorSuma(VECTOR a, VECTOR b){
    VECTOR x = {a.x + b.x, a.y + b.y, a.z + b.z};
    return x;
 }

  VECTOR vectorMultiplicacion(VECTOR a, double k){
    VECTOR x = {a.x *k, a.y *k, a.z *k};
    return x;
 }
