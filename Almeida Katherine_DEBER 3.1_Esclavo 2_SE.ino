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
 //////////// ESCLAVO DOS /////////
 #include <Wire.h>;           // libreria I2C
 char dato;                    // variable de almacenamiento de dato
 const int led5=8;            // led5 en pin8
 const int led6=9;            // led6 en pin9
 const int led7=10;           // led7 en pin10
 const int led8=11;           // led8 en pin10
  
void setup() {
  Wire.begin(1);              // ide esclavo
  Wire.onReceive(receiveEvent2);
  Serial.begin(9600);
  pinMode(led5,OUTPUT);       // pin8 como salida 
  pinMode(led6,OUTPUT);       // pin9 como salida 
  pinMode(led7,OUTPUT);       // pin10 como salida
  pinMode(led8,OUTPUT);       // pin11 como salida
}

void loop() { 
}

void receiveEvent2(int bytes){
  while(Wire.available()){           //Mientras haya numero de byts disponibles.
    dato=Wire.read();
    while(dato=='b')                 //Ciclo mientras 'b' se enciende los leds del primer esclavo.
    {
      digitalWrite(led5,HIGH);       //Led 5 encendido
      delay(9000);                   //Tiempo
      digitalWrite(led5,LOW);        //Led 5 apagado
      delay(9000);                   //Tiempo 
      digitalWrite(led6,HIGH);       //Led 6 encendido
      delay(9000);                   //Tiempo
      digitalWrite(led6,LOW);        //Led 6 apagado
      delay(9000);                   //Tiempo 
      digitalWrite(led7,HIGH);       //Led 7 encendido
      delay(9000);                   //Tiempo
      digitalWrite(led7,LOW);        //Led 7 apagado
      delay(9000);                   //Tiempo 
      digitalWrite(led8,HIGH);       //Led 8 encendido
      delay(9000);                   //Tiempo 
      digitalWrite(led8,LOW);        //Led 8 apagado
      delay(9000);                   //Tiempo 
      dato=(' ');                    //Condición: cualquier otro cracter para el ciclo.
    }
}
}

