#include "ros/ros.h"
#include "std_msgs/String.h"


std_msgs::String entrada;

void Callback_n5(const std_msgs::String::ConstPtr& dato_recibido)
{
  entrada.data =dato_recibido->data;
}


int main(int argc, char **argv)
{
  //Se crea el nodo y se le da el nombre
  ros::init(argc, argv, "nodo_n5");

  //Se crean los publisher
  ros::NodeHandle n;
  ros::Publisher pub1_String = n.advertise<std_msgs::String>("from_n5_to_S", 10);
  //Se crean los subscriber
  ros::Subscriber sub1_String = n.subscribe("from_n2_to_n5", 10, Callback_n5);
  //Se define la frecuencia de trabajo del nodo
  ros::Rate loop_rate(10);
  //Variables emuladas
  std_msgs::String salida;
  salida.data = "";
  entrada.data = "";

  while (ros::ok())
  {
	if(entrada.data == "lento")
		salida.data = "slow";
	else if(entrada.data == "normal")
		salida.data = "normal";
	else
		salida.data = "fast";

	//Debug
	ROS_INFO("Entrada: [%s]  = [%s]",entrada.data.c_str(), salida.data.c_str());
	ROS_INFO("=======================================================");
	//Publicar
	pub1_String.publish(salida);
	//rate
  	ros::spinOnce();
  	loop_rate.sleep();
  
  }
  return 0;
}
