# Asistente de parqueo

#### Proyecto sobre circuitos digitales

El presente trabajo se refiere al tema de circuitos lógicos combinacionales y secuenciales, los cuales permiten el desarrollo de circuitos para automatizar o ejecutar tareas cotidianas como es el caso de parquear o estacionar un vehículo.


#### Materiales

+ Led rojo
+ Led naranja
+ Led verde
+ Tres resistencias de 330Ω
+ Placa Arduino uno
+ Board
+ buzzer
+ Cables tipo macho-hembra
+ Cables tipo macho-macho
+ Sensor ultrasónico
+ Modulo bluetooth
+ http://appinventor.mit.edu
+ https://www.tinkercad.com


#### Funcionamiento

En la placa Arduino se encuentra conectado el sensor ultrasónico el cual, permite calcular el tiempo que se tarda una onda en viajar por el espacio hasta chocar contra una superficie y volver al sensor, con este tiempo podemos emplear la ecuación ***`d = v * t`*** para conocer la distancia. 

Se determinaron rangos en función de la distancia según los cuales se activan los leds, indicando representativamente la distancia: *rojo* peligro, *naranja* alerta y *verde* cuando no hay ningún riesgo; además, el buzzer emite un sonido de mayor frecuencia y constancia según el rango de proximidad.

##### *V2. Datos via bluetooth*
En este proyecto existe una rama llamada bluetooth, la cual contiene una versión del código que permite enviar datos a una aplicación en nuestro dispositivo móvil a través de una conexión bluetooth.

Link de código y descarga de la aplicación: [gallery.appinventor/asistente_de_parqueo](https://gallery.appinventor.mit.edu/?galleryid=8fbd4fa0-dd8a-47ed-8a82-9ee8a695f822)


