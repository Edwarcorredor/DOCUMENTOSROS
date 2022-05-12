#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Float64.h"

float entrada;

void Callback_n2(const std_msgs::Float64::ConstPtr& dato_recibido)
{
  entrada =dato_recibido->data;
}


int main(int argc, char **argv)
{
  //Se crea el nodo y se le da el nombre
  ros::init(argc, argv, "nodo_n2");

  //Se crean los publisher
  ros::NodeHandle n;
  ros::Publisher pub1_String = n.advertise<std_msgs::String>("from_n2_to_n5", 10);
  //Se crean los subscriber
  ros::Subscriber sub1_Float64 = n.subscribe("from_P_to_n2", 10, Callback_n2);
  //Se define la frecuencia de trabajo del nodo
  ros::Rate loop_rate(10);
  //Variables emuladas
  std_msgs::String salida;
  salida.data = "";

  while (ros::ok())
  {
	if(entrada<201)
		salida.data = "lento";
	else if(entrada<501)
		salida.data = "normal";
	else
		salida.data = "rapido";

	//Debug
	ROS_INFO("Entrada: [%f]  = [%s]",entrada, salida.data.c_str());
	ROS_INFO("=======================================================");
	//Publicar
	pub1_String.publish(salida);
	//rate
  	ros::spinOnce();
  	loop_rate.sleep();
  
  }
  return 0;
}
