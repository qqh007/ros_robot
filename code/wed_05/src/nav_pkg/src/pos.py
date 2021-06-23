#!/usr/bin/env python
import rospy

from tf_conversions import transformations
from math import pi
import tf
from std_srvs.srv import Trigger


class Robot:
    def __init__(self):
        self.tf_listener = tf.TransformListener()
        try:
            self.tf_listener.waitForTransform(
                '/map', '/base_link', rospy.Time(), rospy.Duration(1.0))
        except (tf.Exception, tf.ConnectivityException, tf.LookupException):
            return

    def get_pos(self):
        try:
            (trans, rot) = self.tf_listener.lookupTransform(
                '/map', '/base_link', rospy.Time(0))
        except (tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
            if(tf.LookupException):
                rospy.loginfo("11111111")
            elif tf.ConnectivityException:
                rospy.loginfo("22222")
            else:
                rospy.loginfo("333333")
            return None
        euler = transformations.euler_from_quaternion(rot)
        # print euler[2] / pi * 180

        x = trans[0]
        y = trans[1]
        th = euler[2] / pi * 180
        return str(x)+" "+str(y)+" "+str(th)


def callback(req):
    rospy.loginfo("ask rec!!!")
    return TriggerResponse(robot.get_pos())


if __name__ == "__main__":
    rospy.init_node('get_pos_demo', anonymous=True)
    # r = rospy.Rate(100)
    # r.sleep()
    rospy.loginfo("pos_demo init")
    rospy.Service('pos_data', Trigger, callback)
    rospy.spin()
