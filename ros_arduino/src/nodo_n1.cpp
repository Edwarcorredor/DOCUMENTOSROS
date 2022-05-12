#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Int32.h"

int entrada;

void Callback_n1(const std_msgs::Int32::ConstPtr& dato_recibido)
{
  entrada =dato_recibido->data;
}


int main(int argc, char **argv)
{
  //Se crea el nodo y se le da el nombre
  ros::init(argc, argv, "nodo_n1");

  //Se crean los publisher
  ros::NodeHandle n;
  ros::Publisher pub1_String = n.advertise<std_msgs::String>("from_n1_to_n4", 10);
  //Se crean los subscriber
  ros::Subscriber sub1_Int32 = n.subscribe("from_P_to_n1", 10, Callback_n1);
  //Se define la frecuencia de trabajo del nodo
  ros::Rate loop_rate(10);
  //Variables emuladas
  std_msgs::String salida;
  salida.data = "";

  while (ros::ok())
  {
	if(entrada<11)
		salida.data = "frio";
	else if(entrada<21)
		salida.data = "tibio";
	else
		salida.data = "caliente";

	//Debug
	ROS_INFO("Entrada: [%d]  = [%s]",entrada, salida.data.c_str());
	ROS_INFO("=======================================================");
	//Publicar
	pub1_String.publish(salida);
	//rate
  	ros::spinOnce();
  	loop_rate.sleep();
  
  }
  return 0;
}
