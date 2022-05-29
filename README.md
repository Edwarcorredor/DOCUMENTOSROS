# ROS
## Primer corte
### Instalación de Ubuntu y ROS
Se entrega un video del correcto funcionamiento de ubuntu 16.04, en mi caso usé la maquina virtual virtualbox para instalar UBUNTU, y luego me guie de la pagina oficial de ROS para instalalarlo y realizar su tutorial de turtlesim. 
La carpeta que contiene estos tutoriales se llama:
- begginer_tutorials
### Parcial robot TurtleBot
Se logra mover el robot TurtleBot (irobot color blanco de la USTA) por medio de comandos de teclado, utilizando el PC. Se reestrucura el nodo turtlesim para lograr el movimiento del robot real, y con la ayuda de la carpeta y el package del turtlebot como complementación del proceso. 
La carpeta que contiene el package del Turtlebot se llama:
- rbx1
## Segundo corte
### Creación nodo suscriptor y publicador
Se usa como base la documentación del paso a paso en la pagina oficial de ROS para la creación de nodos suscriptores y publicadores, para esto se crean dos archivos que contendrán los codigos que realizan estas funciones. Se usa lenguaje en python.
La carpeta que contiene los archivos se llama:
- ros_arduino
### Creación nodo suscriptor, suscriptorpublicador y publicador
Se usa como base la documentación del paso a paso en la pagina oficial de ROS para la creación de nodos suscriptores y publicadores, para esto se crean tres archivos que contendrán los codigos que realizan estas funciones. Para la creación del nodo suscriptorpublicador, se usa una combinacion de las funciones de cada uno.Se usa lenguaje en python.
La carpeta que contiene los archivos se llama:
- ros_arduino
### Parcial creación de 8 nodos y comunicación con arduino
Se usan como base los nodos creados anteriormente para duplicarse la estructura, pero con un cambio en el tipo de datos que envian y reciben, ya que se busca enviar entero, flotante y booleanos, la comunicación con arduino la hace el primero nodo que es el que envia los primeros datos hacia los otros nodos. Se usa lenguaje en c++
La carpeta que contiene los archivos se llama:
- ros_arduino
## Tercer corte
### Conexion arduino y ROS
Se corrigen los nodos existentes adjuntando a estos la configuración para el correcto funcionamiento de la conexión.Se usa lenguaje en c++
La carpeta que contiene los archivos se llama:
- ros_arduino
### Comunicación Remmina y SSH
Se instala remmina en las dos maquinas virtuales para usar uso de esta, se configura su red para poder tener una misma red local y luego se obtiene el ip de ambas para asi crear el servidor y el cliente. Para el ssh se instalan primero las librerias y la funciones en ubuntu, luego por medio de un comando de ssh se trata de acceder al servidor, para esto debe ingresar la contraseña del usario del servidor al que se dea acceder.
