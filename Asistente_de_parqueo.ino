const int led_red = 4;
const int led_green = 2;
const int led_orange = 3;
const int buzzer = 8;

void setup()
{
  pinMode(led_red, OUTPUT);
  pinMode(led_green, OUTPUT);
  pinMode(led_orange, OUTPUT);
} 

void loop()
{
  long distance = 0.01723 * readUltrasonicDistance(5, 6);
  delay(10);
  
  if(distance > 5 and distance < 100){
    digitalWrite(led_red, HIGH);
    digitalWrite(led_green, LOW);
    digitalWrite(led_orange, LOW);
    tone(buzzer, 400, 200);
  }else if(distance >= 100 and distance < 200){
    digitalWrite(led_red, LOW);
    digitalWrite(led_green, LOW);
    digitalWrite(led_orange, HIGH);
    tone(buzzer, 400, 200);
    delay(500);
  }else if(distance >= 200 and distance < 300){
    digitalWrite(led_red, LOW);
    digitalWrite(led_green, HIGH);
    digitalWrite(led_orange, LOW);
    tone(buzzer, 400, 200);
    delay(1000);
  }else{
    digitalWrite(led_red, LOW);
    digitalWrite(led_green, LOW);
    digitalWrite(led_orange, LOW);
  }
  
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
