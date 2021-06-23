#include<ros/ros.h>
#include<sound_play/SoundRequest.h>
#include<std_msgs/String.h>
static ros::Publisher tts_pub;
void warnCallback(const std_msgs::String::ConstPtr& msg){
	if (strcmp(msg->data.c_str(),"fire")==0){
		int n=0;
		while(n<3)
		{
		ros::Rate r(0.5);
		sound_play::SoundRequest sp;
		sp.sound = sound_play::SoundRequest::SAY;
		sp.command = sound_play::SoundRequest::PLAY_ONCE;
		sp.volume = 0.0;
		sp.arg = "fire";
		tts_pub.publish(sp);
		ros::spinOnce();
		r.sleep();
		n++;
		}
	}
	else if(strcmp(msg->data.c_str(),"invasion")==0){
		ROS_WARN("invasion receive");
		int n=0;
		while(n<3)
		{
		ros::Rate r(0.4);
		sound_play::SoundRequest sp;
		sp.sound = sound_play::SoundRequest::SAY;
		sp.command = sound_play::SoundRequest::PLAY_ONCE;
		sp.volume = 0.0;
		sp.arg = "invasion";
		tts_pub.publish(sp);
		ros::spinOnce();
		r.sleep();
		n++;
		}
	}
	else 
		ROS_WARN("error alarm:%s",msg->data.c_str());
}

int main(int argc, char** argv){
	ros::init(argc, argv, "alarm_node");
	ROS_INFO("alarm node start");
	ros::NodeHandle n;
	tts_pub = n.advertise<sound_play::SoundRequest>("/robotsound", 20);	
	ros::Subscriber warn_sub=n.subscribe("alarm",2,warnCallback);
	ros::spin();
	return 0;
}