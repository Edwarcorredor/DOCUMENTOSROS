
#include "ros/ros.h"

#include "std_msgs/Int32.h"
#include "std_msgs/Float64.h"
#include "std_msgs/Bool.h"
#include <sstream>


int main(int argc, char **argv)
{
  //Se crea el nodo y se le da el nombre
  ros::init(argc, argv, "nodo_P");

  //Se crean los publisher
  ros::NodeHandle n;
  ros::Publisher pub1_Int32 =   n.advertise<std_msgs::Int32>("from_P_to_n1", 10);
  ros::Publisher pub2_Float64 = n.advertise<std_msgs::Float64>("from_P_to_n2", 10);
  ros::Publisher pub3_Bool =    n.advertise<std_msgs::Bool>("from_P_to_n3", 10);

  //Se define la frecuencia de trabajo
  ros::Rate loop_rate(30);

  //Variables emuladas
  std_msgs::Int32 sensor1;
  sensor1.data = 0;
  std_msgs::Float64 sensor2;
  sensor2.data = 0.0;
  std_msgs::Bool sensor3;
  sensor3.data = false;

  int count_bool = 0;
  while (ros::ok())
  {

    //Justificante mientras conectamos el arduino
    sensor1.data++;
    if(sensor1.data > 30)
    {
	sensor1.data = 0;
    }
    
    sensor2.data = sensor2.data + 20.0;
    if(sensor2.data > 1500.0)
    {
	sensor2.data = 0;
    }

    count_bool++;
    if(count_bool > 90)
    {
	count_bool = 0;
    }
    
    if(count_bool < 45)
    {
	sensor3.data = true;
    }
    else
    {
	sensor3.data = false;
    }
    
    //Debug
    ROS_INFO("Sensor#1_Int32: [%d]", sensor1.data);
    ROS_INFO("Sensor#2_Float64:  [%f]  ", sensor2.data);
    ROS_INFO("Sensor#3_Bool:  [%d]", sensor3.data);
    ROS_INFO("=======================================================");  

    //Publicando los sensores
    pub1_Int32.publish(sensor1);
    pub2_Float64.publish(sensor2);
    pub3_Bool.publish(sensor3);
    ros::spinOnce();
    loop_rate.sleep();

  }


  return 0;
}

