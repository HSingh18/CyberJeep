// pins for low power mode
#define LEFT_STANDBY 11
#define RIGHT_STANDBY 24
// pins for right side motors
#define RIGHT_FRONT_PWM 3
#define RIGHT_FRONT_A 26
#define RIGHT_FRONT_B 27
#define RIGHT_BACK_PWM 2
#define RIGHT_BACK_A 22
#define RIGHT_BACK_B 23
// pins for left side motors
#define LEFT_FRONT_PWM 5
#define LEFT_FRONT_A 12
#define LEFT_FRONT_B 13
#define LEFT_BACK_PWM 4
#define LEFT_BACK_A 8
#define LEFT_BACK_B 9
// pins for joystick control
#define YAxis A0
#define XAxis A1
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
// code to move to robot forward at Speed for Duration
void Forward(int Speed, int Duration){
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
  delay(Duration*1000); 
}
// code to move to robot backward at Speed for Duration
void Backward(int Speed, int Duration){
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
  delay(Duration*1000); 
}
// code to move to robot left at Speed for Duration
void Left(int Speed, int Duration){
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
  delay(Duration*1000); 
}
// code to move to robot right at Speed for Duration
void Right(int Speed, int Duration){
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
  delay(Duration*1000); 
}
// code to stop the robot
void Stop(){
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
  digitalWrite(LEFT_STANDBY,LOW);
  digitalWrite(RIGHT_STANDBY,LOW);
}
// code for robot to exit low power mode
void TurnOn(){
  digitalWrite(LEFT_STANDBY,HIGH);
  digitalWrite(RIGHT_STANDBY,HIGH);
}
// MAIN CODE
void loop(){
  int numXAxis = analogRead(XAxis);
  int numYAxis = analogRead(YAxis);
  Serial.print("YAxis = ");
  Serial.println(numYAxis);
  Serial.print("XAxis = ");
  Serial.println(numXAxis);
  if(numYAxis < 700 && numYAxis > 300){
    TurnOff();
  }
  if(numYAxis > 700){
    Serial.println("Backward");
    TurnOn();
    Backward(100,2);
  }
  if(numYAxis < 300){
    Serial.println("Forward");
    TurnOn();
    Forward(100,3);
  }
  if(numXAxis < 700 && numXAxis > 300){
    TurnOff();
  }
  if(numXAxis > 700){
    Serial.println("Left");
    TurnOn();
    Left(100,4);
  }
  if(numXAxis < 300){
    Serial.println("Right");
    TurnOn();
    Right(100,4);
  }
  delay(500);
}
