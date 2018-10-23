const int trigPin = 12;
const int echoPin = 11;
String voice;
int
m1 = 2, //Connect LED 1 To Pin #2
m2 = 3, //Connect LED 2 To Pin #3
m4 = 6, //Connect LED 4 To Pin #5
m5 = 7; //Connect LED 5 To Pin #6
//--------------------------Call A Function-------------------------------// 
void f(){
     digitalWrite(m1, HIGH);
     digitalWrite(m5, HIGH);
     digitalWrite(m2, LOW);
     digitalWrite(m4, LOW);
     Serial.println("fcall");
    
}
void b(){
     digitalWrite(m2, HIGH);
     digitalWrite(m4, HIGH);
     digitalWrite(m1, LOW);
     digitalWrite(m5, LOW);
    Serial.println("bcall");
}
void s(){
     digitalWrite(m1, LOW);
     digitalWrite(m2, LOW);
     
     digitalWrite(m4, LOW);
     digitalWrite(m5, LOW);
     Serial.println("scall");
}
void l(){
     digitalWrite(m1, HIGH);
     digitalWrite(m2, LOW);
     
     digitalWrite(m4, LOW);
     digitalWrite(m5, LOW);
     Serial.println("lcall");
}
void r(){
     digitalWrite(m1, HIGH);
     digitalWrite(m2, LOW);
     
     digitalWrite(m4, HIGH);
     digitalWrite(m5, LOW);
     Serial.println("rcall");
}
long duration=0;
int distance=0;
//-----------------------------------------------------------------------// 
void setup() {
  Serial.begin(9600);
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
 
  pinMode(m4, OUTPUT);
  pinMode(m5, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);

}
//-----------------------------------------------------------------------// 
void loop() {
    while (Serial.available()){  
  delay(10); 
  char c = Serial.read(); 
  if (c == '#') {break;} 
  voice += c; 
  } 
  if (voice.length() > 0) {
    Serial.println(voice);
  
    if(voice == "forward") {f();} 
  else if(voice == "backward"){b();} 
 
  //----------Turn On One-By-One----------//
  else if(voice == "left") {l();}
  else if(voice == "right") {r();}
  else if(voice == "stop") {s();}
  
  }
  if(distance<5)
  {
    r();
  }
  digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor


  

//-----------------------------------------------------------------------// 
voice="";

} 
