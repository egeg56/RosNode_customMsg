#include "ros/ros.h"
#include "ros_custom_msg/demo.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  ros::init(argc, argv, "ros_msg_publisher");
  ros::NodeHandle nh;
  ros::Publisher topic_pub = nh.advertise<ros_custom_msg::demo>("/testo",10);

	//ros::Rate rate(10);


	while ( ros::ok() ) {

		ros_custom_msg::demo msg;
    cout << "Scrivi: ";
		cin >> msg.testo;
    cout<< "Inviato."<<endl;

		ROS_INFO("%s\n", msg.testo.c_str());
		topic_pub.publish(msg);

//		rate.sleep();
	}
  return 0;
}
