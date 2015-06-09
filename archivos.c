void escribirAvs(void){
FILE *fp;

int i;
int j;
int x = (int)W_HEIGHT;
int y = (int)W_WIDTH;
int r;
int g;
int b;
char *charR = "";
char *charG = "";
char *charB = "";
fp = fopen("imagen.avs","w");
 if(fp == NULL){
  printf("No se pudo crear el archivo para la imagen");
 }
 else{
  fprintf(fp,"# ImageMagick pixel enumeration: %d,%d,255,rgb\n", y,x);
  for(i=0; i<x; ++i){
   for(j=0; j<y; ++j){
       r = 250*BUFFER[i][j].R;
       g = 250* BUFFER[i][j].G;
       b = 250 *BUFFER[i][j].B;
       charR ="";
       charG ="";
       charB="";
       if(r<=15){charR="0";}
       if(g<=15){charG="0";}
       if(b<=15){charB="0";}
       fprintf(fp,"%d,%d: (%d,%d,%d)  #%s%X%s%X%s%X  rgb(%d,%d,%d)\n",j,i,r,g,b,charR,r,charG,g,charB,b,r,g,b);
       }
  }
fclose(fp);
printf("\n\nlisto imagen.avs");
 }

}
