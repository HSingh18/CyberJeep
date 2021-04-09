//Controlling arduino motors using ROS Twist keyboard
//rosrun rosserial_python serial_node.py /dev/ttyUSB0
//rosrun teleop_twist_keyboard teleop_twist_keyboard.py


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

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include <WProgram.h>
#endif
#include <stdlib.h>
#include <ros.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/String.h>
ros::NodeHandle nh;
geometry_msgs::Twist msg;

float move1;
float move2;


void callback(const geometry_msgs::Twist& cmd_vel)
{
  move1 = cmd_vel.linear.x;
  move2 = cmd_vel.angular.z;
  if (move1 > 0 && move2 == 0)
  {
    front();
  }
  else if (move1 > 0 && move2 > 0 )
  {
    left();
  }
  else if (move1 > 0 && move2 < 0 )
  {
    right();
  }
  else if (move1 < 0)
  {
    back();
  }
  else
  {
    die();
  }
}

ros::Subscriber <geometry_msgs::Twist> sub("/cmd_vel", callback);

void setup() {
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

nh.initNode();
nh.subscribe(sub);
}

void loop() {
nh.spinOnce();
delay(1);
}

void front()
{
  TurnOn();
     digitalWrite(RIGHT_FRONT_B, LOW);
  analogWrite(RIGHT_FRONT_PWM, 100);
  digitalWrite(RIGHT_BACK_A, HIGH);
  digitalWrite(RIGHT_BACK_B, LOW);
  analogWrite(RIGHT_BACK_PWM, 100);
  digitalWrite(LEFT_FRONT_A, HIGH);
  digitalWrite(LEFT_FRONT_B, LOW);
  analogWrite(LEFT_FRONT_PWM, 100);
  digitalWrite(LEFT_BACK_A, HIGH);
  digitalWrite(LEFT_BACK_B, LOW);
  analogWrite(LEFT_BACK_PWM, 100);
    delay(100);
    die(); 
    
}
void back()
{
  TurnOn();
    digitalWrite(RIGHT_FRONT_A, LOW);
  digitalWrite(RIGHT_FRONT_B, HIGH);
  analogWrite(RIGHT_FRONT_PWM, 100);
  digitalWrite(RIGHT_BACK_A, LOW);
  digitalWrite(RIGHT_BACK_B, HIGH);
  analogWrite(RIGHT_BACK_PWM, 100);
  digitalWrite(LEFT_FRONT_A, LOW);
  digitalWrite(LEFT_FRONT_B, HIGH);
  analogWrite(LEFT_FRONT_PWM, 100);
  digitalWrite(LEFT_BACK_A, LOW);
  digitalWrite(LEFT_BACK_B, HIGH);
  analogWrite(LEFT_BACK_PWM, 100);
    delay(100);
    die();   
}
void left()
{
  TurnOn();
    digitalWrite(RIGHT_FRONT_A, LOW);
  digitalWrite(RIGHT_FRONT_B, HIGH);
  analogWrite(RIGHT_FRONT_PWM, 100);
  digitalWrite(RIGHT_BACK_A, LOW);
  digitalWrite(RIGHT_BACK_B, HIGH);
  analogWrite(RIGHT_BACK_PWM, 100);
  digitalWrite(LEFT_FRONT_A, HIGH);
  digitalWrite(LEFT_FRONT_B, LOW);
  analogWrite(LEFT_FRONT_PWM, 100);
  digitalWrite(LEFT_BACK_A, HIGH);
  digitalWrite(LEFT_BACK_B, LOW);
  analogWrite(LEFT_BACK_PWM, 100);
  delay(100);
    die(); 

}
void right()
{
  TurnOn();
    digitalWrite(RIGHT_FRONT_A, HIGH);
  digitalWrite(RIGHT_FRONT_B, LOW);
  analogWrite(RIGHT_FRONT_PWM, 100);
  digitalWrite(RIGHT_BACK_A, HIGH);
  digitalWrite(RIGHT_BACK_B, LOW);
  analogWrite(RIGHT_BACK_PWM, 100);
  digitalWrite(LEFT_FRONT_A, LOW);
  digitalWrite(LEFT_FRONT_B, HIGH);
  analogWrite(LEFT_FRONT_PWM, 100);
  digitalWrite(LEFT_BACK_A, LOW);
  digitalWrite(LEFT_BACK_B, HIGH);
  analogWrite(LEFT_BACK_PWM, 100);
  delay(100);
    die(); 
}
void die()
{
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
void TurnOn() {
  //    Serial.println("Turned On");
  digitalWrite(LEFT_STANDBY, HIGH);
  digitalWrite(RIGHT_STANDBY, HIGH);
}
