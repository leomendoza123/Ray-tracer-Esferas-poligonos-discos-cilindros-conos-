CONO listaConos[] ={ 
                    {{0,0,0},{0,1,0},0.70,1,{0.7,1,0.7},0.8}
                    };

ESFERA listaEsferas[] ={
                           // {900,{0.2,0.3,0.4}, {250,250,1900},1},
                             //{100,{1,0,0}, {250,250,300},0.8},
                           //{50,{0.8,0.3,0.2}, {150,265,100},0.8},
                           //{25,{0.7,0,0.4}, {300,275,200},0.8},
                           {10,{0.7,1,0.7}, {250,180,200},0.8},

                         };

POLIGONO listaPoligonos[] = {

{{0, 0, 1}, 200,{{270,200,200},{220,200,200}, {220,160, 200},  {270,160, 200}}, 4,{0,0.5,1}, 3},

{{0, 0, 1}, 220,{{390,220,220},{340,220,220}, {340,180, 220},  {90,180, 220}}, 4,{1,0.5,0},2},

};

LUZ listaLuces[] = {
                    {{500, 0,-50}, 1 , -1.2,0.0009,0},
                    };

RGB BACKGROUD = {0.6,0.6,0.6};

double Ka=0.5;
double Ia=0.5;


double KS= 0.5;//coeficiente de reflexión especular
double KN = 10; //Enfoque de mancha especular

/*
ESFERA listaEsferas[] ={
                           {200,{0.8,0.3,0.2}, {100,100,350},1},
                           {100,{0.7,0,0.4}, {200,200,200},1},
                           {50,{0.7,1,0.7}, {250,250,170},1},
                            {25,{0.7,1,0.7}, {275,275,170},1},
                         };

LUZ listaLuces[] = {
                    {{800, 800,200 }, 0.4 , -1.2,0.0009,0},
                    {{0, 500,400 }, 1 , -1.2,0.0009,0},
                    {{500, 500,400 }, 1 , -1.2,0.0009,0},
                    };

RGB BACKGROUD = {0.6,0.6,0.6};

double Ka=0.5;
double Ia=0.5;


double KS= 1;//coeficiente de reflexión especular
double KN = 10; //Enfoque de mancha especular
*/



/*
ESFERA listaEsferas[40] ;


LUZ listaLuces[] = {
                    {{0, 0,-400}, 1 , -1.2,0.0009,0},
                    };

RGB BACKGROUD = {0.6,0.6,0.6};

double Ka=0.0;
double Ia=0.0;


double KS= 20;//coeficiente de reflexión especular
double KN = 100; //Enfoque de mancha especular
*/
