#! /usr/bin/env python

import rospy
from std_msgs.msg import UInt16
import numpy as np
import matplotlib.pyplot as plt
import math
import time

#Publisher
def talker():
    rospy.init_node('pub', anonymous=True)
    pub = rospy.Publisher('servo', UInt16, queue_size=10)
    rate = rospy.Rate(1) # 10hz
    while not rospy.is_shutdown():
        for message in range(0,100,10):
            time.sleep(1)
            #message = "hello world"
            rospy.loginfo(message)
            pub.publish(message)
            rate.sleep()


#executable
if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
