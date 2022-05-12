#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Int32.h"
#include "std_msgs/Float64.h"
#include "std_msgs/Bool.h"

#include <sstream>

std_msgs::String entrada1;
std_msgs::String entrada2;
std_msgs::String entrada3;
  //Funciones callbacks para tomar los diferentes datos que llegan de diferentes nodos
void Callback_a(const std_msgs::String::ConstPtr& dato_recibido1)
{
  entrada1.data = dato_recibido1->data;
}

void Callback_b(const std_msgs::String::ConstPtr& dato_recibido2)
{
  entrada2.data = dato_recibido2->data;
}

void Callback_c(const std_msgs::String::ConstPtr& dato_recibido3)
{
  entrada3.data = dato_recibido3->data;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "nodo_L");

  ros::NodeHandle n;

  //subscriber a los 3 nodos
  ros::Subscriber sub1_String = n.subscribe("from_n4_to_S", 10, Callback_a);
  ros::Subscriber sub2_String = n.subscribe("from_n5_to_S", 10, Callback_b);
  ros::Subscriber sub3_String = n.subscribe("from_n6_to_S", 10, Callback_c);

  //Se define la frecuencia
  ros::Rate loop_rate(0.5);

  //variables de salida
  std_msgs::String salida1;
  std_msgs::String salida2;
  std_msgs::String salida3;
  salida1.data = "";
  salida2.data = "";
  salida3.data = "";

  while (ros::ok())
  {

  //entrada1 es el sensor de temperatura
  if (entrada1.data == "cold")
  {
   salida1.data = "frio";
  }
  else if (entrada1.data == "warm")
  {
   salida1.data = "tibio";
  }
  else
  {
   salida1.data = "caliente";
  }

  //entrada2 es el sensor de velocidad (tacometro)
  if (entrada2.data == "slow")
  {
   salida2.data = "lento";
  }
  else if (entrada2.data == "normal")
  {
   salida2.data = "normal";
  }
  else
  {
   salida2.data = "rapido";
  }

  //entrada3 es el estado
  if (entrada3.data == "off")
  {
   salida3.data = "apagado";
  }
  else 
  {
   salida3.data = "encendido";
  }
  
    //Debug para imprimir cada variable
    std::stringstream ss1;
    ss1 <<  "Tempereture: [" <<salida1<< "]";
    std_msgs::String msg1;
    msg1.data = ss1.str();
    ROS_INFO("%s",msg1.data.c_str());

    std::stringstream ss2;
    ss2 <<  "Speed: [" <<salida2<< "]";
    std_msgs::String msg2;
    msg2.data = ss2.str();
    ROS_INFO("%s",msg2.data.c_str());

    std::stringstream ss3;
    ss3 <<  "State: [" <<salida3<< "]";
    std_msgs::String msg3;
    msg3.data = ss3.str();
    ROS_INFO("%s",msg3.data.c_str());
    ROS_INFO("=======================================================");
    //Rate
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}
