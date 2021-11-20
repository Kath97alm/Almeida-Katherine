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
 //////////// ESCLAVO TRES /////////
 #include <Wire.h>;           // libreria I2C
 char dato;                    // variable de almacenamiento de dato
 const int led9=8;            // led9 en pin8
 const int led10=9;            // led10 en pin9
 const int led11=10;           // led11 en pin10
 const int led12=11;           // led12 en pin11
void setup() {
  Wire.begin(1);              // ide esclavo
  Wire.onReceive(receiveEvent3);
  Serial.begin(9600);
  pinMode(led9,OUTPUT);        // pin8 como salida 
  pinMode(led10,OUTPUT);       // pin9 como salida 
  pinMode(led11,OUTPUT);       // pin10 como salida 
  pinMode(led12,OUTPUT);       // pin11 como salida
}

void loop() { 
}

void receiveEvent3(int bytes){
  while(Wire.available()){          //Mientras haya numero de byts disponibles.
    dato=Wire.read();
    while(dato=='c')                //Ciclo mientras 'c' se enciende los leds del primer esclavo.
    {
      digitalWrite(led9,HIGH);       //Led 9 encendido
      delay(9000);                   //Tiempo
      digitalWrite(led9,LOW);        //Led 9 apagado
      delay(9000);                   //Tiempo 
      digitalWrite(led10,HIGH);       //Led 10 encendido
      delay(9000);                   //Tiempo
      digitalWrite(led10,LOW);        //Led 10 apagado
      delay(9000);                   //Tiempo 
      digitalWrite(led11,HIGH);       //Led 11 encendido
      delay(9000);                   //Tiempo
      digitalWrite(led11,LOW);        //Led 11 apagado
      delay(9000);                   //Tiempo 
      digitalWrite(led12,HIGH);       //Led 12 encendido
      delay(9000);                   //Tiempo 
      digitalWrite(led12,LOW);        //Led 12 apagado
      delay(9000);                   //Tiempo 
      dato=(' ');                    //Condición: cualquier otro cracter para el ciclo.
    }
}
}

