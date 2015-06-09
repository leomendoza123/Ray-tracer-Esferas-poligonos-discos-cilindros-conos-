void CreaEsferas();
void SetBlockDisposition(double centerX, double centerY, double radius, double sides, double coils, double rotation);

void CreaEsferas() {

    SetBlockDisposition (250, 250, 300, 39, 10, 1);


}
int cantidad =40;

    //
//
// centerX-- X origin of the spiral.
// centerY-- Y origin of the spiral.
// radius--- Distance from origin to outer arm.
// sides---- Number of points or sides along the spiral's arm.
// coils---- Number of coils or full rotations. (Positive numbers spin clockwise, negative numbers spin counter-clockwise)
// rotation- Overall rotation of the spiral. ('0'=no rotation, '1'=360 degrees, '180/360'=180 degrees)
//



/*
void SetBlockDisposition(double centerX, double centerY, double radius, double sides, double coils, double rotation)
{
    //
    // How far to step away from center for each side.
    double awayStep = radius/sides;
    //
    // How far to rotate around center for each side.
    double aroundStep = coils/sides;// 0 to 1 based.
    //
    // Convert aroundStep to radians.
    double aroundRadians = aroundStep * 2 * M_PI;
    //
    // Convert rotation to radians.
    rotation *= 2 * M_PI;
    //
    // For every side, step around and away from center.
    double i;
    for(i=1; i<sides; i++){

        //
        // How far away from center
        double away = i * awayStep;
        //
        // How far around the center.
        double around = i * aroundRadians + rotation;
        //
        // Convert 'around' and 'away' to X and Y.
        double x = centerX + cos(around) * away;
        double y = centerY + sin(around) * away;
        //
        // Now that you know it, do it.
        ESFERA esfera1 ={away/2,{1,0,0}, {x,y,300},0.8};
        listaEsferas[(int)i] = esfera1;

        //DoSome(x,y);
    }
    ESFERA esfera1 ={900,{0.2,0.3,0.4}, {250,250,1900},1};
    listaEsferas[0] = esfera1;
    }
*/
/*
void SetBlockDisposition(double centerX, double centerY, double radius, double sides, double coils, double rotation)
{
    //
    // How far to step away from center for each side.
    double awayStep = radius/sides;
    //
    // How far to rotate around center for each side.
    double aroundStep = coils/sides;// 0 to 1 based.
    //
    // Convert aroundStep to radians.
    double aroundRadians = aroundStep * 2 * M_PI;
    //
    // Convert rotation to radians.
    rotation *= 2 * M_PI;
    //
    // For every side, step around and away from center.
    double i;
    for(i=1; i<sides; i++){

        //
        // How far away from center
        double away = i * awayStep;
        //
        // How far around the center.
        double around = i * aroundRadians + rotation;
        //
        // Convert 'around' and 'away' to X and Y.
        double x = centerX + cos(around) * away;
        double y = centerY + sin(around) * away;
        //
        // Now that you know it, do it.
        ESFERA esfera1 ={40,{ i/40,1-around/250,away/250}, {x,y,200-away},0.8};
        printf ("Arround %f\n", around);
        printf ("Away %f\n", away);
        listaEsferas[(int)i] = esfera1;

        //DoSome(x,y);
    }
    ESFERA esfera1 ={900,{0.2,0.3,0.4}, {250,250,1900},1};
    listaEsferas[0] = esfera1;
    }



    void SetBlockDisposition(double centerX, double centerY, double radius, double sides, double coils, double rotation)
{
    //
    // How far to step away from center for each side.
    double awayStep = radius/sides;
    //
    // How far to rotate around center for each side.
    double aroundStep = coils/sides;// 0 to 1 based.
    //
    // Convert aroundStep to radians.
    double aroundRadians = aroundStep * 2 * M_PI;
    //
    // Convert rotation to radians.
    rotation *= 2 * M_PI;
    //
    // For every side, step around and away from center.
    double i;
    for(i=1; i<sides; i++){

        //
        // How far away from center
        double away = i * awayStep;
        //
        // How far around the center.
        double around = i * aroundRadians + rotation;
        //
        // Convert 'around' and 'away' to X and Y.
        double x = centerX + cos(around) * away;
        double y = centerY + sin(around) * away;
        //
        // Now that you know it, do it.
        ESFERA esfera1 ={i*2,{ 1,1-around/250,i/40}, {x,y,500-away},0.8};
        printf ("Arround %f\n", around);
        printf ("Away %f\n", away);
        listaEsferas[(int)i] = esfera1;

        //DoSome(x,y);
    }
    ESFERA esfera1 ={900,{0.2,0.3,0.4}, {250,250,1900},1};
    listaEsferas[0] = esfera1;
    }
*/

void SetBlockDisposition(double centerX, double centerY, double radius, double sides, double coils, double rotation)
{
    //
    // How far to step away from center for each side.
    double awayStep = radius/sides;
    //
    // How far to rotate around center for each side.
    double aroundStep = coils/sides;// 0 to 1 based.
    //
    // Convert aroundStep to radians.
    double aroundRadians = aroundStep * 2 * M_PI;
    //
    // Convert rotation to radians.
    rotation *= 2 * M_PI;
    //
    // For every side, step around and away from center.
    double i;
    for(i=1; i<sides; i++){

        //
        // How far away from center
        double away = i * awayStep;
        //
        // How far around the center.
        double around = i * aroundRadians + rotation;
        //
        // Convert 'around' and 'away' to X and Y.
        double x = centerX + cos(around) * away;
        double y = centerY + sin(around) * away;
        //
        // Now that you know it, do it.
        ESFERA esfera1 ={(20-around)*3,{ 1,1-around/250,i/40}, {y/1.2,x,600-y},0.8};
        printf ("Arround %f\n", around);
        printf ("Away %f\n", away);
        listaEsferas[(int)i] = esfera1;

        //DoSome(x,y);
    }
    ESFERA esfera1 ={900,{0.2,0.3,0.4}, {250,250,1900},1};
    listaEsferas[0] = esfera1;
    }
