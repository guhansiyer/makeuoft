#include <Servo.h>

const int in1 = 5;
const int in2 = 6;
const int in3 = 9;
const int in4 = 10;
const int trigPin = 7;
const int echoPin = 8;
const int redPin = 13; 
const int greenPin = 12; 
const int bluePin = 11; 
Servo s; 
int pos = 0;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  s.attach(3);

  Serial.begin(9600);
}

void loop() {
  // float time;

  // digitalWrite(trigPin, LOW);
  // delayMicroseconds(2);
  // digitalWrite(trigPin, HIGH);
  // delayMicroseconds(10);
  // digitalWrite(trigPin, LOW);

  // time = pulseIn(echoPin, HIGH);



  // float distance = (time*0.0343)/2;

  // Serial.print(distance);
  // Serial.print('\n');

  // if (distance > ){
  //   moveForward();
  // }
  // else stopMove();

  setColor(255, 0, 0); // Red Color
  delay(1000);
  setColor(0, 255, 0); // Green Color
  delay(1000);
  setColor(0, 0, 255); // Blue Color
  delay(1000);
  setColor(255, 255, 0); // White Color
  delay(1000);
  setColor(0, 255, 255); // Purple Color
  delay(1000);
  setColor(255, 0, 255); // White Color
  delay(1000);
  
  moveU();
  moveO();
  moveF();
  moveT();
  moveO();
  setColor(255, 0, 0); // Red Color
  delay(300);
  setColor(255, 0, 0); // Red Color
  delay(300);
  setColor(255, 0, 0); // Red Color
  delay(300);
  moveO();
  setColor(255, 255, 0); // White Color
  delay(300);
  setColor(255, 255, 0); // White Color
  delay(300);
  setColor(255, 255, 0); // White Color
  delay(300);
  moveO();
  setColor(0, 255, 255); // Purple Color
  delay(300);
  setColor(0, 255, 255); // Purple Color
  delay(300);
  setColor(0, 255, 255); // Purple Color
  delay(300);

  
}

void moveBackwards() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void moveForward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void turnRight() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void turnLeft() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void stopMove() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void rightOnSpot() {
  servoUp(50);
  moveForward();
  delay(515);
  turnRight();
  delay(475); // 550 = 90 degrees off paper
  moveBackwards();
  delay(515);



  stopMove();
}

void leftOnSpot() {
  servoUp(50);
  stopMove();
  moveForward();
  delay(515);
  turnLeft();
  delay(475); // 550 = 90 degrees off paper
  moveBackwards();
  delay(515);

  stopMove();
}

void turnAround() {
  servoUp(50);
  turnLeft();
  delay(950); // 550 = 90 degrees off paper

  stopMove();
}

void moveT() {
  moveForward();
  delay(500);
  stopMove();
  rightOnSpot();
  stopMove();
  moveBackwards();
  delay(200);
  stopMove();
  servoDown();
  moveForward();
  delay(500);


  stopMove();
}

void moveO() {
  turnRight();
  delay(2300);

  stopMove();
}

void moveU(){
  moveForward();
  delay(500);
  stopMove();
  delay(100);
  rightOnSpot();
  servoDown();
  moveForward();
  delay(400);
  stopMove();
  delay(100);
  rightOnSpot();
  servoDown();
  moveForward();
  delay(500);
  stopMove();
  // moveForward();
  // delay(500);
  // turnLeft();
  // delay(750);
  // moveForward();
  // delay(500);
  // stopMove();
}

void moveF (){
  servoDown();
  moveForward();
  delay(500);
  stopMove();
  servoUp(60);
  moveBackwards();
  delay(500);
  stopMove();
  rightOnSpot();
  moveForward();
  delay(200);
  stopMove();
  leftOnSpot();
  servoDown();
  moveForward();
  delay(500);
  stopMove();
  servoUp(60);
  stopMove();
  moveBackwards();
  delay(500);
  stopMove();
  rightOnSpot();
  moveBackwards();
  delay(200);
  stopMove();
  servoDown();
  moveForward();
  delay(500);
  stopMove();
}




void servoUp(int degrees){
  for (int i = 90; i >= degrees; --i){
    s.write(i);
    delay(15);
  }
}

void servoDown(){
  int init = s.read();
  for (int i = init; i <= 90; i++){
    s.write(i);
    delay(15);
  }
}


void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}

//void servoDown
