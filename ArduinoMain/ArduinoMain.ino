// pins for low power mode
#define RIGHT_STANDBY 3
#define LEFT_STANDBY 6
// pins for right side motors
#define LEFT_BACK_PWM 5
#define LEFT_BACK_A 27
#define LEFT_BACK_B 26
#define LEFT_FRONT_PWM 7
#define LEFT_FRONT_A 28
#define LEFT_FRONT_B 29
// pins for left side motors
#define RIGHT_FRONT_PWM 2
#define RIGHT_FRONT_A 23
#define RIGHT_FRONT_B 22
#define RIGHT_BACK_PWM 4
#define RIGHT_BACK_A 25
#define RIGHT_BACK_B 24
// pins for joystick control
#define YAxis A9
#define XAxis A8
#define Button 50

void setup() {
  // put your setup code here, to run once:
  pinMode(RIGHT_BACK_A, OUTPUT);
  pinMode(RIGHT_BACK_B, OUTPUT);
  pinMode(RIGHT_BACK_PWM, OUTPUT);
  pinMode(RIGHT_FRONT_A, OUTPUT);
  pinMode(RIGHT_FRONT_B, OUTPUT);
  pinMode(RIGHT_FRONT_PWM, OUTPUT);  
  pinMode(RIGHT_STANDBY, OUTPUT);  

  pinMode(LEFT_BACK_A, OUTPUT);
  pinMode(LEFT_BACK_B, OUTPUT);
  pinMode(LEFT_BACK_PWM, OUTPUT);
  pinMode(LEFT_FRONT_A, OUTPUT);
  pinMode(LEFT_FRONT_B, OUTPUT);
  pinMode(LEFT_FRONT_PWM, OUTPUT);  
  pinMode(LEFT_STANDBY, OUTPUT); 

  pinMode(XAxis, INPUT);
  pinMode(YAxis, INPUT);
  pinMode(Button, INPUT);

  // turning off all motors,
  // setting speed of the motor to 0
  // turning on low power mode
  digitalWrite(LEFT_STANDBY,LOW);
  digitalWrite(LEFT_FRONT_A, LOW);
  digitalWrite(LEFT_FRONT_B, LOW);
  analogWrite(LEFT_FRONT_PWM, 0);
  digitalWrite(LEFT_BACK_A, LOW);
  digitalWrite(LEFT_BACK_B, LOW);
  analogWrite(LEFT_BACK_PWM, 0);
  digitalWrite(RIGHT_STANDBY,LOW);
  digitalWrite(RIGHT_FRONT_A, LOW);
  digitalWrite(RIGHT_FRONT_B, LOW);
  analogWrite(RIGHT_FRONT_PWM, 0);
  digitalWrite(RIGHT_BACK_A, LOW);
  digitalWrite(RIGHT_BACK_B, LOW);
  analogWrite(RIGHT_BACK_PWM, 0);

  Serial.begin(9600);
  Serial.println("Starting Test:");
}
// MAIN CODE
int previousMillis = 0;
int previousMillis2 = 0;
void loop(){
  long interval = 2000;
  int numXAxis = analogRead(XAxis);
  int numYAxis = analogRead(YAxis);

  if(numYAxis < 700 && numYAxis > 300){
    TurnOff();
  }
  if(numXAxis < 700 && numXAxis > 300){
    TurnOff();
  }
  while(numYAxis > 700){
    TurnOn();
    Backward(100);
    numXAxis = analogRead(XAxis);
    numYAxis = analogRead(YAxis);
  }
  
  while(numYAxis < 300){
    TurnOn();
    Forward(100);
    numXAxis = analogRead(XAxis);
    numYAxis = analogRead(YAxis);
  }
  
  while(numXAxis > 700){
    TurnOn();
    Left(100);
    numXAxis = analogRead(XAxis);
    numYAxis = analogRead(YAxis);
  }
  
  while(numXAxis < 300){
    TurnOn();
    Right(100);
    numXAxis = analogRead(XAxis);
    numYAxis = analogRead(YAxis);
  } 
}

// code to move to robot forward at Speed for Duration
void Forward(int Speed){
  Serial.println("Forward");
  digitalWrite(RIGHT_FRONT_A, HIGH);
  digitalWrite(RIGHT_FRONT_B, LOW);
  analogWrite(RIGHT_FRONT_PWM, Speed);
  digitalWrite(RIGHT_BACK_A, HIGH);
  digitalWrite(RIGHT_BACK_B, LOW);
  analogWrite(RIGHT_BACK_PWM, Speed);
  digitalWrite(LEFT_FRONT_A, HIGH);
  digitalWrite(LEFT_FRONT_B, LOW);
  analogWrite(LEFT_FRONT_PWM, Speed);
  digitalWrite(LEFT_BACK_A, HIGH);
  digitalWrite(LEFT_BACK_B, LOW);
  analogWrite(LEFT_BACK_PWM, Speed);
}
// code to move to robot backward at Speed for Duration
void Backward(int Speed){
  Serial.println("Backward");
  digitalWrite(RIGHT_FRONT_A, LOW);
  digitalWrite(RIGHT_FRONT_B, HIGH);
  analogWrite(RIGHT_FRONT_PWM, Speed);
  digitalWrite(RIGHT_BACK_A, LOW);
  digitalWrite(RIGHT_BACK_B, HIGH);
  analogWrite(RIGHT_BACK_PWM, Speed);
  digitalWrite(LEFT_FRONT_A, LOW);
  digitalWrite(LEFT_FRONT_B, HIGH);
  analogWrite(LEFT_FRONT_PWM, Speed);
  digitalWrite(LEFT_BACK_A, LOW);
  digitalWrite(LEFT_BACK_B, HIGH);
  analogWrite(LEFT_BACK_PWM, Speed);
}
// code to move to robot left at Speed for Duration
void Left(int Speed){
  Serial.println("Left");
  digitalWrite(RIGHT_FRONT_A, LOW);
  digitalWrite(RIGHT_FRONT_B, HIGH);
  analogWrite(RIGHT_FRONT_PWM, Speed);
  digitalWrite(RIGHT_BACK_A, LOW);
  digitalWrite(RIGHT_BACK_B, HIGH);
  analogWrite(RIGHT_BACK_PWM, Speed);
  digitalWrite(LEFT_FRONT_A, HIGH);
  digitalWrite(LEFT_FRONT_B, LOW);
  analogWrite(LEFT_FRONT_PWM, Speed);
  digitalWrite(LEFT_BACK_A, HIGH);
  digitalWrite(LEFT_BACK_B, LOW);
  analogWrite(LEFT_BACK_PWM, Speed);
}
// code to move to robot right at Speed for Duration
void Right(int Speed){
  digitalWrite(RIGHT_FRONT_A, HIGH);
  digitalWrite(RIGHT_FRONT_B, LOW);
  analogWrite(RIGHT_FRONT_PWM, Speed);
  digitalWrite(RIGHT_BACK_A, HIGH);
  digitalWrite(RIGHT_BACK_B, LOW);
  analogWrite(RIGHT_BACK_PWM, Speed/2);
  digitalWrite(LEFT_FRONT_A, LOW);
  digitalWrite(LEFT_FRONT_B, HIGH);
  analogWrite(LEFT_FRONT_PWM, Speed);
  digitalWrite(LEFT_BACK_A, LOW);
  digitalWrite(LEFT_BACK_B, HIGH);
  analogWrite(LEFT_BACK_PWM, Speed); 
}
// code to stop the robot
void Stop(){
  Serial.println("STOP");
  digitalWrite(RIGHT_FRONT_A, LOW);
  digitalWrite(RIGHT_FRONT_B, LOW);
  analogWrite(RIGHT_FRONT_PWM, 0);
  digitalWrite(RIGHT_BACK_A, LOW);
  digitalWrite(RIGHT_BACK_B, LOW);
  analogWrite(RIGHT_BACK_PWM, 0);
  digitalWrite(LEFT_FRONT_A, LOW);
  digitalWrite(LEFT_FRONT_B, LOW);
  analogWrite(LEFT_FRONT_PWM, 0);
  digitalWrite(LEFT_BACK_A, LOW);
  digitalWrite(LEFT_BACK_B, LOW);
  analogWrite(LEFT_BACK_PWM, 0); 
}
// code for robot to enter low power mode
void TurnOff(){
  Serial.println("Turned Off");
  digitalWrite(LEFT_STANDBY,LOW);
  digitalWrite(RIGHT_STANDBY,LOW);
}
// code for robot to exit low power mode
void TurnOn(){
  Serial.println("Turned On");
  digitalWrite(LEFT_STANDBY,HIGH);
  digitalWrite(RIGHT_STANDBY,HIGH);
}
