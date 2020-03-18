#include "ros/ros.h"
#include "ros_custom_msg/demo.h"
#include <iostream>

class ROS_SUB {
	public:
		ROS_SUB();
		void topic_cb( ros_custom_msg::demoConstPtr data );

	private:
		ros::NodeHandle _nh;
		ros::Subscriber _topic_sub;
};

ROS_SUB::ROS_SUB() {
	_topic_sub = _nh.subscribe( "/testo", 0, &ROS_SUB::topic_cb, this );
}

void ROS_SUB::topic_cb( ros_custom_msg::demoConstPtr data ) {
	ROS_INFO( "Listener: %s", data->testo.c_str() );
}


int main( int argc, char** argv ) {
	ros::init(argc,argv,"ros_msg_subscriber");
	ROS_SUB rs;
	ros::spin();
	return 0;
}
