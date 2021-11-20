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
 //////////// ESCLAVO UNO /////////
 #include <Wire.h>;           // Libreria I2C
 char dato;                   // variable de almacenamiento de dato
 const int led1=8;            // led1 en pin8
 const int led2=9;            // led2 en pin9
 const int led3=10;           // led3 en pin10
 const int led4=11;           // led4 en pin11

void setup() {
  Wire.begin(1);              // id esclavo
  Wire.onReceive(receiveEvent1);
  Serial.begin(9600);
  pinMode(led1,OUTPUT);       // El pin8 - salida 
  pinMode(led2,OUTPUT);       // El pin9 - salida 
  pinMode(led3,OUTPUT);       // El pin10 - salida 
  pinMode(led4,OUTPUT);       // El pin11 - salida 
}

void loop() { 
}

void receiveEvent1(int bytes){
  while(Wire.available()){           //Mientras haya numero de byts disponibles.
    dato=Wire.read();
    while(dato=='a')                  //Ciclo mientras 'a' se enciende los leds del primer esclavo.
    {
      digitalWrite(led1,HIGH);       //Led 1 encendido
      delay(9000);                   //Tiempo
      digitalWrite(led1,LOW);        //Led 1 apagado
      delay(9000);                   //Tiempo 
      digitalWrite(led2,HIGH);       //Led 2 encendido
      delay(9000);                   //Tiempo
      digitalWrite(led2,LOW);        //Led 2 apagado
      delay(9000);                   //Tiempo 
      digitalWrite(led3,HIGH);       //Led 3 encendido
      delay(9000);                   //Tiempo
      digitalWrite(led3,LOW);        //Led 3 apagado
      delay(9000);                   //Tiempo 
      digitalWrite(led4,HIGH);       //Led 4 encendido
      delay(9000);                   //Tiempo 
      digitalWrite(led4,LOW);        //Led 4 apagado
      delay(9000);                   //Tiempo 
      dato=(' ');                    //Condición: cualquier otro cracter para el ciclo.
  }
}
}
