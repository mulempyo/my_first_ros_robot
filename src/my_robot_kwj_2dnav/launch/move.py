#!/usr/bin/env python
import rospy
from geometry_msgs.msg import Twist

def move_robot():
    rospy.init_node('move_robot', anonymous=True)
    vel_pub = rospy.Publisher("/cmd_vel", Twist, queue_size=10)
    
    twist_msg = Twist()
    twist_msg.linear.x = 0.5
    twist_msg.angular.z = 0.1

    vel_pub.publisher(twist_msg)

if __name__=='__main__':
    move_robot()
    
