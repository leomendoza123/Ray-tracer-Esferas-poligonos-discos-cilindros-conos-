#include <math.h>
#include "logica.h"
//Instituto Tecnologico de Costa Rica
//Introduccion a los graficos por computadora
//Jose Carlos Alvarez Umana
//Leonardo Mendoza

 double WindowPointToFramePoint(double xp, double hres, double xmax, double xmin){
    double xResult;
	xResult = (double) ((double)xp + (double)1/2) * (((double) xmax - xmin)/ (double) hres  ) + xmin;
	return xResult;
	}


double getL( double xw,  double yw,  double zw,  double xe,  double ye,  double ze){
	double lResult;
	lResult = sqrt((pow((xw - xe),2)) + (pow((yw-ye),2)) + (pow((zw-ze),2)));
	return lResult;
	}



// TODO optimizar a una funcion
double getXd( double xw,  double xe,  double l){
	 double XdResult;
	XdResult = ( (double)xw - xe) / ( (double) l);
	return XdResult;
	}

double getYd( double yw,  double ye,  double l){
	double YdResult;
	YdResult = ( (double) yw - ye) / ( double) l;
	return YdResult;
	}

double getZd( double zw,  double ze,  double l){
	double ZdResult;
	ZdResult = ( (double) zw - ze) / ( double) l;
	return ZdResult;
	}
