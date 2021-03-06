/* 
 * CAPITULO III: MODULOS DE COMUNICACIÓN I2C.
 * CÓDIGO DEBER 3.1:Comunicación I2C configurar 1 maestro y 3 esclavos.  
 * OBJETIVO:Mediante comunicación I2C configurar 1 maestro y 3 esclavos. 
 * Cada esclavo tendrá conectados 4 leds en sus salidas digitales, los cuales deberán encenderse de forma síncrona y ordenada.
 * Los leds del primer esclavo deberán entran en funcionamiento cuando se ingrese 'Cualquier caracter', luego cuando se ingrese otro 
 *'Cualquier caracter 2' entrará en funcionamiento el esclavo 2, y después cuando se ingrese otro 'Cualquier caracter 3' entrará en funcionamiento el esclavo 3.
 * Nombre: Katherine Almeida
 * Fecha: 19/11/2021                      
 */
 ///////////////////////////////***** MASTER***** ////////////////////////////////
 #include <Wire.h>
 char dato;                     //Variable de incremento de dato.

void setup() {
  Wire.begin();                 //Inicia comunicacion i2c
  Serial.begin(9600);
  Serial.println("DEBER 3.1 Katherine Almeida--SE");  //Mensaje de bienvenida Pantalla Virtual
  Serial.println("BIENVENIDO USUARIO");
  Serial.println("Para Activacion de Leds:");
  Serial.println("a=Activacion esclavo uno");    //Caracter uno (a)
  Serial.println("b=Activacion esclavo dos");    //Caracter dos (b)
  Serial.println("c=Activacion esclavo tres");   //Caracter tres (c)
  }

void loop() {
  if(Serial.available()>0){     //Verifica el puerto de comunicación.
    dato=Serial.read();         //Lee o alamecena el dato en la variable
    Serial.println();           //Visualización de caracter
    Wire.beginTransmission(1);  //Empieza la transmision con la id establecisa.
    Wire.write(dato);           //Envia el dato a los esclavos
    Wire.endTransmission();     //Termina la Comunicación.
  }
}