#include <SoftwareSerial.h>

//Declarando variables
const int led_red = 4;
const int led_green = 2;
const int led_orange = 3;
const int buzzer = 8;
const int RXpin = 10;
const int TXpin = 11;
char buffer[10];

//Instanciando objeto serie para el blueTooth
SoftwareSerial bluetooth(RXpin, TXpin);

void setup()
{
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(led_red, OUTPUT);
  pinMode(led_green, OUTPUT);
  pinMode(led_orange, OUTPUT);
} 

void loop()
{
  //Calculando distancia d = velocidad del sonido * tiempo obtenido desde el sensor
  int distance = 0.01723 * readUltrasonicDistance(5, 6); 
  //Importante que el delay este sincronizado con el timer de la aplicacion
 
  if(distance <= 60){
    //Encender led rojo
    digitalWrite(led_red, HIGH);
    digitalWrite(led_green, LOW);
    digitalWrite(led_orange, LOW);
    //Damos formato al valor que enviaremos mediante blueTooth
    //Formato valor_distancia:valor_led(segun a la distancia que se encuentre el objeto)
    sprintf(buffer, "%d:%d", distance, led_red);
    tone(buzzer, 400, 200);

  }else if(distance > 60 and distance < 130){
    //Encender led naranja
    digitalWrite(led_red, LOW);
    digitalWrite(led_green, LOW);
    digitalWrite(led_orange, HIGH);
    //Damos formato al valor que enviaremos mediante blueTooth
    sprintf(buffer, "%d:%d", distance, led_orange);
    //Hacer sonar el buzzer
    tone(buzzer, 400, 200);
    delay(500);
    
  }else if(distance >= 130 and distance <= 200){
    //Encender led verde
    digitalWrite(led_red, LOW);
    digitalWrite(led_green, HIGH);
    digitalWrite(led_orange, LOW);
    //Damos formato al valor que enviaremos mediante blueTooth
    sprintf(buffer, "%d:%d", distance, led_green);
    //Hacer sonar el buzzer
    tone(buzzer, 400, 200);
    delay(1000);
    
  }else{
    digitalWrite(led_red, LOW);
    digitalWrite(led_green, LOW);
    digitalWrite(led_orange, LOW);
  }

  //Enviar valor mediante blueTooth
  bluetooth.print(buffer);
  
  delay(700);
}


long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}
