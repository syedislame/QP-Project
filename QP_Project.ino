#include <NewPing.h>
#include <NewTone.h>


#define echoPin 2 
#define trigPin 3
#define buzzpin 8
#define maxdis 300

long duration; 
int median;
int distance;


NewPing sonar(trigPin, echoPin, maxdis);

void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode (buzzpin, OUTPUT);
  Serial.begin(9600); 

}
void loop() {
  /*digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; 
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");*/
  delay(0);
  unsigned int uS = sonar.ping();
  Serial.print("Ping: ");
  //Serial.print(sonar.convert_cm(uS));
  //Serial.println("cm");
  median = sonar.ping_median(10);
  //Serial.println(times);
  distance= sonar.convert_cm(median);
  Serial.println(distance);
  if (distance<60 && distance>0){
    NewTone(buzzpin, 1000);
    Serial.println("buzzer on");
  }
  if (distance>60){
    noNewTone(buzzpin);
    Serial.println("buzzer off");
  }
  if (distance==0){
    noNewTone(buzzpin);
    Serial.println("buzzer off: 0");
  }
}
