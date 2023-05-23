#include <ros.h>
#include <std_msgs/String.h>
#include <geometry_msgs/Twist.h>
#include "math.h"

ros::NodeHandle nh;
void dc_driver(const geometry_msgs::Twist& msg){
float a = msg.linear.x; 
float b = msg.linear.y;
float c = msg.linear.z;

if(a>0 && b==0 && c==0){ //straight
drive(100,100,1,0,1,0);

}

else if(a<0 && b==0 && c==0){ //backward
drive(100,100,0,1,0,1);

}

else if(a==0 && b==0 && c==0){ //stop
drive(0,0,0,0,0,0);
}
else if(a==0 && b==0 && c>0){ //right
drive(100,100,0,0,0,1)   
}
else if(a==0 && b==0 && c<0){ //left
drive(100,100,1,0,0,0)
}
}

ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", dc_driver); 

void setup()

{

pinMode(10, OUTPUT); //ENB
pinMode(8, OUTPUT); //IN 4
pinMode(7, OUTPUT); //IN 3 
pinMode(6, OUTPUT); //IN 2
pinMode(5, OUTPUT); //IN 1
pinMode(9, OUTPUT); //ENA 
pinMode(3, INPUT_PULLUP); //BUTTON

Serial.begin(57600);
nh.initNode();
nh.subscribe(sub);

}

void loop() {

nh.spinOnce();

}


void drive(int Lpwm, int Rpwm ,int in1 ,int in2 ,int in3 ,int in4){

analogWrite(9, Lpwm);
analogWrite(10, Rpwm);
digitalWrite(5, in1);
digitalWrite(6, in2);
digitalWrite(7, in3);
digitalWrite(8, in4);}
