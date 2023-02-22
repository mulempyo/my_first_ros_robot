#!/usr/bin/env python
import roslib; roslib.load_manifest('teleop_twist_listener')
import rospy
import RPi.GPIO as GPIO
import time
import tf.transformations
from geometry_msgs.msg import Twist

def callback(msg):
    a = msg.linear.x
    b = msg.linear.y
    c = msg.linear.z
    # for 1st Motor on ENA
    ENA = 22
    IN1 = 24
    IN2 = 26

    # for 2nd Motor on ENB
    IN3=11
    IN4=13
    ENB=15

    # set pin numbers to the board's
    GPIO.setmode(GPIO.BOARD)
    
    # initialize EnA,ENB,In1,In2,In3,In4
    GPIO.setup(ENA, GPIO.OUT, initial=GPIO.LOW)
    GPIO.setup(IN1, GPIO.OUT, initial=GPIO.LOW)
    GPIO.setup(IN2, GPIO.OUT, initial=GPIO.LOW)
    GPIO.setup(IN3, GPIO.OUT, initial=GPIO.LOW)
    GPIO.setup(IN4, GPIO.OUT, initial=GPIO.LOW)
    GPIO.setup(ENB, GPIO.OUT, initial=GPIO.LOW)

    GPIO.output(ENA, GPIO.HIGH)
    GPIO.output(IN1, GPIO.LOW)
    GPIO.output(IN2, GPIO.LOW)
    GPIO.output(IN3, GPIO.LOW)
    GPIO.output(IN4, GPIO.LOW)
    GPIO.output(ENB, GPIO.HIGH)
    time.sleep(1)

    if a > 0 and b == 0 and c == 0:
       rospy.loginfo("Straight")
       GPIO.output(IN1, GPIO.HIGH)
       GPIO.output(IN2, GPIO.LOW)
       GPIO.output(IN3, GPIO.LOW)
       GPIO.output(IN4, GPIO.HIGH)
       time.sleep(0.5)
    if a < 0 and b == 0 and c == 0:
       rospy.loginfo("Back")
       GPIO.output(IN1, GPIO.LOW)
       GPIO.output(IN2, GPIO.HIGH)
       GPIO.output(IN3, GPIO.HIGH)
       GPIO.output(IN4, GPIO.LOW)
       time.sleep(0.5)
    if a == 0 and b == 0 and c == 0:
       rospy.loginfo("STOP")
       GPIO.output(ENA, GPIO.LOW)
       GPIO.output(IN1, GPIO.LOW)
       GPIO.output(IN2, GPIO.LOW)
       GPIO.output(IN3, GPIO.LOW)
       GPIO.output(IN4, GPIO.LOW)
       GPIO.output(ENB, GPIO.LOW)
       time.sleep(0.5)
    if a == 0 and b == 0 and c > 0:
       rospy.loginfo("RIGHT")
       GPIO.output(IN1, GPIO.LOW)
       GPIO.output(IN2, GPIO.LOW)
       GPIO.output(IN3, GPIO.LOW)
       GPIO.output(IN4, GPIO.HIGH)
       time.sleep(0.5)
    if a == 0 and b == 0 and c < 0:
       rospy.loginfo("LEFT")
       GPIO.output(IN1, GPIO.HIGH)
       GPIO.output(IN2, GPIO.LOW)
       GPIO.output(IN3, GPIO.LOW)
       GPIO.output(IN4, GPIO.LOW)
       time.sleep(0.5)
    

def listener():
    rospy.init_node('teleop_twist_listener')
    rospy.Subscriber("/cmd_vel",Twist,callback)
    rospy.spin()

if __name__=='__main__':
    listener() 

       
