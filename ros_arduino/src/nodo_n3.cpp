#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Bool.h"

int entrada;

void Callback_n3(const std_msgs::Bool::ConstPtr& dato_recibido)
{
  entrada =dato_recibido->data;
}


int main(int argc, char **argv)
{
  //Se crea el nodo y se le da el nombre
  ros::init(argc, argv, "nodo_n3");

  //Se crean los publisher
  ros::NodeHandle n;
  ros::Publisher pub1_String = n.advertise<std_msgs::String>("from_n3_to_n6", 10);
  //Se crean los subscriber
  ros::Subscriber sub1_Bool = n.subscribe("from_P_to_n3", 10, Callback_n3);
  //Se define la frecuencia de trabajo del nodo
  ros::Rate loop_rate(10);
  //Variables emuladas
  std_msgs::String salida;
  salida.data = "";

  while (ros::ok())
  {
	if(entrada<1)
		salida.data = "apagado";
	else
		salida.data = "encendido";

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
