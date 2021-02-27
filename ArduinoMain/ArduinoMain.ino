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
// Variables for Ultrasonic Sensors
#define TRIG1 32
#define ECHO1 33
#define TRIG2 34
#define ECHO2 35
#define TRIG3 36
#define ECHO3 37
#define MinDistance 2000

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

  pinMode(TRIG1, OUTPUT);
  pinMode(ECHO1, INPUT);
  pinMode(TRIG2, OUTPUT);
  pinMode(ECHO2, INPUT);
  pinMode(TRIG3, OUTPUT);
  pinMode(ECHO3, INPUT);

  // turning off all motors,
  // setting speed of the motor to 0
  // turning on low power mode
  digitalWrite(LEFT_STANDBY, LOW);
  digitalWrite(LEFT_FRONT_A, LOW);
  digitalWrite(LEFT_FRONT_B, LOW);
  analogWrite(LEFT_FRONT_PWM, 0);
  digitalWrite(LEFT_BACK_A, LOW);
  digitalWrite(LEFT_BACK_B, LOW);
  analogWrite(LEFT_BACK_PWM, 0);
  digitalWrite(RIGHT_STANDBY, LOW);
  digitalWrite(RIGHT_FRONT_A, LOW);
  digitalWrite(RIGHT_FRONT_B, LOW);
  analogWrite(RIGHT_FRONT_PWM, 0);
  digitalWrite(RIGHT_BACK_A, LOW);
  digitalWrite(RIGHT_BACK_B, LOW);
  analogWrite(RIGHT_BACK_PWM, 0);

  digitalWrite(TRIG1, LOW);
  digitalWrite(TRIG2, LOW);
  digitalWrite(TRIG3, LOW);

  OBJAvoidance();

  Serial.begin(9600);
  Serial.println("Starting Test:");
}

// MAIN CODE
void loop() {
  int numXAxis = analogRead(XAxis);
  int numYAxis = analogRead(YAxis);

  if (numYAxis < 700 && numYAxis > 300) {
    Stop();
  }

  if (numXAxis < 700 && numXAxis > 300) {
    Stop();
  }

  while (numYAxis > 700) {
    TurnOn();
    Backward(100);
    numXAxis = analogRead(XAxis);
    numYAxis = analogRead(YAxis);
  }

  while (numYAxis < 300) {
    Forward(100);
    numXAxis = analogRead(XAxis);
    numYAxis = analogRead(YAxis);
    OBJAvoidance();
  }

  while (numXAxis > 700) {
    Left(100);
    numXAxis = analogRead(XAxis);
    numYAxis = analogRead(YAxis);
    OBJAvoidance();
  }

  while (numXAxis < 300) {
    Right(100);
    numXAxis = analogRead(XAxis);
    numYAxis = analogRead(YAxis);
    OBJAvoidance();
  }
  delay(500);
}
// code to get distance from ultrasonic sensors
boolean OBJAvoidance() {
  if (GetDistance1() < MinDistance || GetDistance2() < MinDistance || GetDistance3() < MinDistance) {
    TurnOff();
  }
  else() {
    TurnOn();
  }
}
int GetDistance1() {
  digitalWrite(TRIG1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG1, LOW);
  int Duration1 = pulseIn(ECHO1, HIGH);
  Serial.print("Distance1: "); Serial.println(Duration1);
  return Duration1
}
int GetDistance2() {
  digitalWrite(TRIG2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG2, LOW);
  int Duration2 = pulseIn(ECHO2, HIGH);
  Serial.print("Distance2: "); Serial.println(Duration2);
  return Duration2
}
int GetDistance3() {
  digitalWrite(TRIG3, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG3, LOW);
  int Duration3 = pulseIn(ECHO3, HIGH);
  Serial.print("Distance3: "); Serial.println(Duration3);
  return Duration3
}

// code to move to robot forward at Speed for Duration
void Forward(int Speed) {
  //  Serial.println("Forward");
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
void Backward(int Speed) {
  //  Serial.println("Backward");
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
void Left(int Speed) {
  //  Serial.println("Left");
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
void Right(int Speed) {
  digitalWrite(RIGHT_FRONT_A, HIGH);
  digitalWrite(RIGHT_FRONT_B, LOW);
  analogWrite(RIGHT_FRONT_PWM, Speed);
  digitalWrite(RIGHT_BACK_A, HIGH);
  digitalWrite(RIGHT_BACK_B, LOW);
  analogWrite(RIGHT_BACK_PWM, Speed / 2);
  digitalWrite(LEFT_FRONT_A, LOW);
  digitalWrite(LEFT_FRONT_B, HIGH);
  analogWrite(LEFT_FRONT_PWM, Speed);
  digitalWrite(LEFT_BACK_A, LOW);
  digitalWrite(LEFT_BACK_B, HIGH);
  analogWrite(LEFT_BACK_PWM, Speed);
}
// code to stop the robot
void Stop() {
  //  Serial.println("STOP");
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
void TurnOff() {
  //  Serial.println("Turned Off");
  digitalWrite(LEFT_STANDBY, LOW);
  digitalWrite(RIGHT_STANDBY, LOW);
}
// code for robot to exit low power mode
void TurnOn() {
  //  Serial.println("Turned On");
  digitalWrite(LEFT_STANDBY, HIGH);
  digitalWrite(RIGHT_STANDBY, HIGH);
}
