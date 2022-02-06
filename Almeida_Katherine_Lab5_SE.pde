/*
                Universidad Tecnica Del Norte
        Facultad de Ingenieria en Ciencias Aplicadas
              Ingenieria en Ciencias Aplicadas

                       Laboratorio 05
                     
Integrantes:Almeida Katherine
            Tandayamo Smith
            Torres Erika


Fecha: 04/02/2022

*/

float datoX_max=0;
float datoY_max=0;
float datoX_min=1000;
float datoY_min=1000;
float ejeX_min;
float ejeY_min;
float ejeX_max;
float ejeY_max;
float absX;
float absY;
int ancho1 = 1000;     //ventana celeste
int alto1 = 1000;
int anchoFig = 0;          //Ancho del gráfico
int altoFig = 0;        //Altura del gráfico
int figX = 200;            //Coordenada X de el cuadro principal de la gráfica
int figY = 50;            //Coordenada Y de el cuadro principal de la gráfica
int j=0;
int fil_m = 120;
int col_m = 5;      //Filas y columnas de la BDD
int divV = 6;
int divH = 6;         //Divisiones horizontales y verticales
int [] x = new int[fil_m];
int [] y = new int[fil_m];

////////



float datoX_max2=0;
float datoY_max2=0;
float datoX_min2=1000;
float datoY_min2=1000;
float ejeX_min2;
float ejeY_min2;
float ejeX_max2;
float ejeY_max2;
float absX2;
float absY2;
int ancho2= 1500;     //ventana celeste
int alto2 = 1500;
int anchoFig2 = 0;          //Ancho del gráfico
int altoFig2= 0;        //Altura del gráfico
int figX2= 200;            //Coordenada X de el cuadro principal de la gráfica
int figY2= 300;            //Coordenada Y de el cuadro principal de la gráfica
int j2=0;
int fil_m2 = 120;
int col_m2 = 5;      //Filas y columnas de la BDD
int divV2 = 6;
int divH2 = 6;         //Divisiones horizontales y verticales
int [] x2 = new int[fil_m];
int [] y2 = new int[fil_m];
PImage fondo2;
PImage utn;


void setup() {

  size (1400,550);
  background(52, 152, 219);//fondo celeste
  fill(0);
  textAlign(CENTER);
  textSize(45);
  //text("APRENDIZAJE DE MÁQUINA",width/2, 50);
  textAlign(LEFT);
  text("REGRESIÓN LINEAL",520,40);
  text("LABORATORIO 05",700, 100);
//  text("SISTEMAS EMBEBIDOS",635, 50);
  textSize(20);
    text("BASE ANTIGUA",220, 40);
  text("BASE NUEVA",220, 295);
  text("Almeida Katherine",5,480);
  text("Tandayamo Smith",5, 510);
  text("Torres Erika",5, 540);
   textSize(25);
  // En el eje X
  text("0",190, 270);
  text("2",360, 270);
  text("4",530, 270);
  text("6",690, 270);
  text("8",860, 270);
  text("10",1018, 270);
  text("12",1185, 270);
  
  
  text("0",190, 520);
  text("20",360, 520);
  text("40",530, 520);
  text("60",690, 520);
  text("80",860, 520);
  text("100",1018, 520);
  text("120",1185, 520);
  
  //En el eje Y
  
  text("2",185, 225);
  text("4",185, 190);
  text("6",185, 155);
  text("8",185, 120);
  text("10",175, 85);
  text("12",175, 55);
  
  text("20",170, 475);
  text("40",170, 440);
  text("60",170, 405);
  text("80",170, 375);
  text("100",160, 340);
  text("120",160, 305);
  
  anchoFig2 = width-400;
  altoFig2 = height-350;
  
  anchoFig = width-400;
  altoFig = height-350;
  
  fondo2=loadImage("logo-citel-1-1024x427.png");
  image(fondo2,1220,30);

 utn=loadImage("descarga_ccexpress.png");
  image(utn,1,0);
}

void draw(){
  fill(192, 192, 192);//color de fondo para cuadricula
  rect(figX, figY, anchoFig, altoFig);
  rect(figX2, figY2, anchoFig2, altoFig2);
  
  //Hallar máximos y mínimos de la BDD
  for (int i=0;i<fil_m;i++){
    if(matriz[i][0]>datoX_max) datoX_max = matriz[i][0];
    if(matriz[i][0]<datoX_min) datoX_min = matriz[i][0];
    if(matriz[i][1]>datoY_max) datoY_max = matriz[i][1];
    if(matriz[i][1]<datoY_min) datoY_min = matriz[i][1];
  }
  
    for (int k=0;k<fil_m2;k++){
    if(matriz2[k][0]>datoX_max2) datoX_max2 = matriz2[k][0];
    if(matriz2[k][0]<datoX_min2) datoX_min2= matriz2[k][0];
    if(matriz2[k][1]>datoY_max2) datoY_max2 = matriz2[k][1];
    if(matriz2[k][1]<datoY_min2) datoY_min2 = matriz2[k][1];
  }

  //Definir los ejes máximos de representación
  ejeX_max = datoX_max*1.25;
  ejeY_max = datoY_max*1.25;
  ejeX_min = datoX_min/1.25;
  ejeY_min=  datoY_min/1.25;
  
  ejeX_max2 = datoX_max2*1.25;
  ejeY_max2 = datoY_max2*1.25;
  ejeX_min2 = datoX_min2/1.25;
  ejeY_min2 = datoY_min2/1.25;
  
  

  for (j=0; j<divV+1; j++) {
    stroke(2);
    
    line(figX, figY+(j*altoFig/divV), width-figX, figY+(j*altoFig/divV));
    line(figX+(j*anchoFig/divH), figY, figX+(j*anchoFig/divH), altoFig+figY);
    fill(1);
    textSize(15);

  }
  
    for (j2=0; j2<divV2+1; j2++) {
    stroke(2);
    line(figX2, figY2+(j2*altoFig2/divV2), width-figX2, figY2+(j2*altoFig2/divV2));
    line(figX2+(j2*anchoFig2/divH2), figY2, figX2+(j2*anchoFig2/divH2), altoFig2+figY2);
    fill(1);
    textSize(15);

  }
  for (j=0; j<fil_m; j++) {
    fill(#FA8072);
    x[j]=int(map(matriz[j][0],ejeX_min,ejeX_max,figX,width-figX));
    y[j]=int(map(matriz[j][1],ejeY_min,ejeY_max,figY+altoFig,figY));
    
    ellipse(x[j],y[j],14,14);
  }
  regresion(fil_m);
  
    for (j2=0; j2<fil_m2; j2++) {
    fill(#961BB1 );
    x[j2]=int(map(matriz2[j2][0],ejeX_min2,ejeX_max2,figX2,width-figX2));
    y[j2]=int(map(matriz2[j2][1],ejeY_min2,ejeY_max2,figY2+altoFig2,figY2));
    stroke(#0D0C0D );
    ellipse(x[j2],y[j2],14,14);
  }
    regresion2(fil_m2);
  
  
}

void regresion(int filas){
int col=0; // variable que se mueve en filas
int fil=0; // variable que se mueve en columnas
float Ex=0; // sumatoria de X
float Ey=0; // sumatoria de Y
float Exy=0; // sumatoria de xy
float Ex2=0; // sumatoria de x^2
float Ex_2=0; // sumatoria de (Ex)^2
long n=filas; // tamaño de datos
float Bo; // ordenada en el origen
float m; // pendiente
float m1; // auxiliar
String dato; // recibe datos por cx serial
float [] nuevaInstancia={6.3,2.3,4.4,1.3,}; // conversión de datos
//4.8,3.4,1.6,0.2,1      Base Antigua
//19.0,60.0,8.0,38,2     Base 1
//28.0,55.0,28.0,18.0,2  Base 2
float respuesta; // responder 

//creación del modelo
 for(;fil<n;fil++){
    Ex=Ex+matriz[fil][0];
    Ey=Ey+matriz[fil][1];
    Exy=Exy+(matriz[fil][0]*matriz[fil][1]);
    Ex2=Ex2+pow(matriz[fil][0],2);     
  }
  Ex_2=pow(Ex,2);
 
  Bo=((Ex2*Ey)-(Ex*Exy))/(n*Ex2-Ex_2);

  m1=(n*Exy)-(Ex*Ey);
  m=(m1)/(n*Ex2-Ex_2);
  respuesta=Bo+m*nuevaInstancia[0]; // genera el pronóstico
  //println(respuesta);
  fill(#00FF00);
  int xi=int(map(nuevaInstancia[0],ejeX_min,ejeX_max,figX,width-figX));
  int yi=int(map(respuesta,ejeY_min,ejeY_max,figY+altoFig,figY));
  
  ellipse(xi,yi,20,20);
  //Grafica de la linea
  int Lx=int(map(ejeX_min,ejeX_min,ejeX_max,figX,width-figX));
  int Ly=int(map(Bo+m*ejeX_min,ejeY_min,ejeY_max,figY+altoFig,figY));
  int Lx_F=int(map(ejeX_max,ejeX_min,ejeX_max,figX,width-figX));
  int Ly_F=int(map(Bo+m*ejeX_max,ejeY_min,ejeY_max,figY+altoFig,figY));
  strokeWeight(2);
  stroke(#00FF00);
  line(Lx,Ly,Lx_F,Ly_F);
}


////////////////////////


void regresion2(int filas2){
int col2=0; // variable que se mueve en filas
int fil2=0; // variable que se mueve en columnas
float Ex2=0; // sumatoria de X
float Ey2=0; // sumatoria de Y
float Exy2=0; // sumatoria de xy
float Ex3=0; // sumatoria de x^2
float Ex_3=0; // sumatoria de (Ex)^2
long n2=filas2; // tamaño de datos
float Bo2; // ordenada en el origen
float m2; // pendiente
float m3; // auxiliar
String dato2; // recibe datos por cx serial
float [] nuevaInstancia2={12.0,89.0,25.0,29.0,}; // conversión de datos
//4.8,3.4,1.6,0.2,1      Base Antigua
//19.0,60.0,8.0,38,2     Base 1
//28.0,55.0,28.0,18.0,2  Base 2
float respuesta2; // responder 

//creación del modelo
 for(;fil2<n2;fil2++){
    Ex2=Ex2+matriz2[fil2][0];
    Ey2=Ey2+matriz2[fil2][1];
    Exy2=Exy2+(matriz2[fil2][0]*matriz2[fil2][1]);
    Ex3=Ex3+pow(matriz2[fil2][0],2);     
  }
  Ex_3=pow(Ex2,2);
 
  Bo2=((Ex3*Ey2)-(Ex2*Exy2))/(n2*Ex3-Ex_3);

  m3=(n2*Exy2)-(Ex2*Ey2);
  m2=(m3)/(n2*Ex3-Ex_3);
  respuesta2=Bo2+m2*nuevaInstancia2[0]; // genera el pronóstico
  //println(respuesta);
  fill(#00FF00);
  int xi2=int(map(nuevaInstancia2[0],ejeX_min2,ejeX_max2,figX2,width-figX2));
  int yi2=int(map(respuesta2,ejeY_min2,ejeY_max2,figY2+altoFig2,figY2));
  
  ellipse(xi2,yi2,20,20);
  //Grafica de la linea
  int Lx2=int(map(ejeX_min2,ejeX_min2,ejeX_max2,figX2,width-figX2));
  int Ly2=int(map(Bo2+m2*ejeX_min2,ejeY_min2,ejeY_max2,figY2+altoFig2,figY2));
  int Lx_F2=int(map(ejeX_max2,ejeX_min2,ejeX_max2,figX2,width-figX2));
  int Ly_F2=int(map(Bo2+m2*ejeX_max2,ejeY_min2,ejeY_max2,figY2+altoFig2,figY2));
  strokeWeight(2);
  stroke(#00FF00);
  line(Lx2,Ly2,Lx_F2,Ly_F2);
}
