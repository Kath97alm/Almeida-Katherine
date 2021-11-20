/*
 * CAPÍTULO II: PUERTOS DIGITALES
 * CODIGO DEBER 2.1: Puertos como salida
 * OBJETIVO: Realizar el código necesario para encender 6 leds de forma síncrona, es decir, 
 encender uno por uno. Cada vez que se encienda un led los demás deben estar apagados,
 realizarlo por 3 veces, luego al presionar un switch debe encenderse y apagar los 2 leds del centro hasta presionar nuevamente el switch. 
 Luego al presionar un boton debe encenderse y apagar los 2 leds de los extremos.
 ESTUDIANTE: Katherine Almeida
 */
#define switch 6          //uso de #define para entrada digital del pin 6
#define button 7       //uso de #define para entrada digital del pin 7

const int leds [6]={8,9,10,11,12,13};       //pines de salida 
int i=0;                                    //contador del ciclo for 

void setup() {
  // put your setup code here, to run once:
pinMode(leds [i], OUTPUT);                 //desplazamiento, configuracion de pines como salida 
for (i=1; i <= 3; i++)                     //ciclo para el encendido de leds en secuencia, con repetición tres veces
      {
        digitalWrite(8, HIGH);             //envia 5 voltios al pin 8
        delay(200);                        //se detiene el microcontrolador por 200 ms o 0.2 segundos
        digitalWrite(8, LOW);              //envia 0 voltios al pin 8
        delay(200);

        digitalWrite(9, HIGH);             //envia 5 voltios al pin 9
        delay(200);                        //se detiene el microcontrolador 0.2 segundos entre encendido y apagado
        digitalWrite(9, LOW);              //envia 0 voltios al pin 9
        delay(200);

        digitalWrite(10, HIGH);            //envia 5 voltios al pin 10
        delay(200);                        //se detiene el microcontrolador 0.2 segundos entre encendido y apagado
        digitalWrite(10, LOW);             //envia 0 voltios al pin 10
        delay(200);  

        digitalWrite(11, HIGH);            //envia 5 voltios al pin 11
        delay(200);                        //se detiene el microcontrolador 0.2 segundos entre encendido y apagado
        digitalWrite(11, LOW);             //envia 0 voltios al pin 11
        delay(200);   

        digitalWrite(12, HIGH);            //envia 5 voltios al pin 12
        delay(200);                        //se detiene el microcontrolador 0.2 segundos entre encendido y apagado
        digitalWrite(12, LOW);             //envia 0 voltios al pin 12
        delay(200);  

        digitalWrite(13, HIGH);            //envia 5 voltios al pin 13
        delay(200);                        //se detiene el microcontrolador 0.2 segundos entre encendido y apagado
        digitalWrite(13, LOW);             //envia 0 voltios al pin 13
        
        }
pinMode(button,INPUT);                    //entrada digital para botón pin 7
pinMode(switch,INPUT);                    //entrada digital para switch pin 6
}
void loop() {
  // put your main code here, to run repeatedly:
//Función del pin 6 switch
if (digitalRead (switch)==HIGH)  {        //condición que activa el pin digital de switch en alto
  digitalWrite(10,HIGH);                  //envía 5 voltios al pin 10
  delay(200);                             //tiempo de retardo 0.2 segundos
  digitalWrite(10,LOW);                   //envía 0 voltios al pin 10
  delay(200);                             //se detiene el microcontrolador 0.2 segundos entre encendido y apagado
  digitalWrite(11,HIGH);                  //envía 5 voltios al pin 11
  delay(200);                             //se detiene el microcontrolador 0.2 segundos entre encendido y apagado
  digitalWrite(11,LOW);                   //envía 0 voltios al pin 11
  delay(200);                             //se detiene el microcontrolador 0.2 segundos entre encendido y apagado
//pines 10 y 11 leds centrales 0 voltios
} else {
  digitalWrite(10,LOW);                   //envía 0 voltios al pin 10
  delay(200);                             //se detiene el microcontrolador 0.2 segundos
  digitalWrite(11,LOW);                   //envía 0 voltios al pin 11
}
//Función del pin 7 button
if (digitalRead (button)==LOW)  {        //condición que activa el pin digital botón en abajo
  digitalWrite(8,HIGH);                  //envia 5 voltios al pin 8
  delay(200);                            //se detiene el microcontrolador por 200 ms o 0.2 segundos
  digitalWrite(8,LOW);
  delay(200);
  digitalWrite(13,HIGH);                //envia 5 voltios al pin 13
  delay(200);                           //se detiene el microcontrolador por 200 ms o 0.2 segundos
  digitalWrite(13,LOW);                 //envia 0 voltios al pin 13
  delay(200);                           //se detiene el microcontrolador por 200 ms o 0.2 segundos
//pines de los extremos 0 voltios
} else {
  digitalWrite(8,LOW);                  //envia 0 voltios al pin 8
  delay(200);                           //se detiene el microcontrolador por 200 ms o 0.2 segundos
  digitalWrite(13,LOW);                 //envia 0 voltios al pin 13
  delay(200);                           //se detiene el microcontrolador por 200 ms o 0.2 segundos
}
}
