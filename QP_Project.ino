#define echoPin 2 
#define trigPin 3
#define buzzpin 8

long duration; 
int distance; 

void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode (buzzpin, OUTPUT);
  Serial.begin(9600); 
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; 
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  if (distance<60){
    tone (buzzpin, 1000);
  }
  if (distance>60){
    noTone(buzzpin);
  }
}
