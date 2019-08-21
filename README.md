# GreenBox_prototipe  

## Resumen
Este repositorio contiene toda la información del desarrollo del dispositivo GreenBox para la sustentacion del proyecto final 2019-1 de las asignaturas de vision por computador y microcontroladores. Incluye datos tanto del diseño, los materiales, lenguajes utilizados y pasos llevados a cabo para el desarrollo.

## Objetivos
<ul>
  <li>Diseño e implementación de un prototipo funcional que integre la teoria aprendida de vision por computadora y dispositivos microcontroladores que garantice la seguridad de un entorno restringiendo el acceso a personal no autorizado a traves de clasificacion por machine learning.</li>
  <li>Proponer un sistema de clasificación de rostros que tenga la capacidad de clasificar personas a traves de redes neuronales y teoria de machine learning.</li>
  <li>Probar el funcionamiento del modulo camara OV7670 y su gran aplicabilidad en problemas de vision por computadora.</li>
  <li>Mediante el dataset <a href="https://drive.google.com/open?id=1LhIVFvFVUxwYvMBJkzmk05l6yJzYE9Fy"><b>FACE MATCHING DATA SET</b></a> entrenaremos los modelos redes neuronales propuestos y de acuerdo a dichos datos haremos los procesos requeridos de entrenamiento y de testeo.</li>
</ul>

## Materiales
<ul>
  <li>1 modulo camara OV7670</li>
  <li>2 placas arduino uno</li>
  <li>2 resistencias de 10kOhm</li>
  <li>2 resistencias de 4.7kOhm</li>
  <li>2 resistencias de 220Ohm</li>
  <li>1 Pantalla LCD de 16 X 2</li>
  <li>1 modulo I2C-LCD</li>
  <li>1 Sensor de ultrasonido HC-SR04</li>
  <li>1 teclado matricial 4 X 4</li>
  <li>1 modulo bluetooth hc-05</li>
  <li>1 servomotor de 9gr</li>
  <li>Jumpers</li>
  <li>1 placa de prueba</li>
  <li>2 clabes USB-Arduino</li>
</ul>

### <a href="https://naylampmechatronics.com/home/140-modulo-camara-vga-ov7670.html">Camara OV7670</a> 
<p>Este módulo posee un sensor de imagen CMOS VGA OV7670, fabricado por Omnivision, capaz de trabajar a un máximo de 30 fps (cuadros por segundo) a una resolución de 640x480 pixeles (0.3MPx). Es un SoC (sistema en chip) por lo que es capaz de realizar procesamiento de imágenes, como: control de exposición, gamma, balance de blancos, saturación de color, control de tono (hue). Estos parámetros son configurables mediante la interface SCCB (Bus de Control de Cámara Serial). El sensor incluye filtros propios de eliminación de ruido eléctrico, fixed pattern noise (FPN), smearing, blooming, etc.</p>

<h5>Especificaciones:</h5>
<ul>
  <li>Voltaje de Operación: 3.3V DC</li>
  <li>Consumo de energía: 60mW/15fpsVGAYUV</li>
  <li>Corriente Sleep: <20μA</li>
  <li>Transmisión de datos en paralelo (8 bits)</li>
  <li>Interface de control estándar SCCB, compatible con I2C.</li>
  <li>Necesita una frecuencia de 8MHz.</li>
  <li>Lente óptico de 1/6”</li>
  <li>Angluo de visión (FOV): 25º</li>
  <li>Resolución: 640x480 VGA</li>
  <li>Sensibilidad: 1.3V / (Lux-sec)</li>
  <li>Ratio Señal-Ruido (SNR): 46 dB</li>
  <li>Rango Dinámico: 52 dB</li>
  <li>Modo de vista: Progresivo</li>
  <li>Lente de alta calidad F1.8/6mm</li>
  <li>Formatos de Salida: Raw RGB (8 digit), RGB (GRB 4:2:2, RGB 565/555/444), YUV (4:2:2) y YCbCr (4:2:2)</li>
  <li>Máximo refresco de cuadro: 30 fps VGA</li>
  <li>Exposición electrónica: 1 a 510 filas</li>
  <li>Covertura de pixel: 3.6μm x 3.6μm</li>
</ul>

### <a href="https://naylampmechatronics.com/arduino-tarjetas/8-arduino-uno-r3-00008.html?search_query=arduino+uno&results=280">Placa Arduino uno</a>
<p>Arduino es la plataforma de desarrollo de proyectos en electrónica y robótica más utilizada a nivel mundial, esto debido a su facilidad de aprendizaje y uso, abundante documentación y multiples aplicaciones. Arduino Uno R3 es una tarjeta de desarrollo que utiliza el microcontrolador ATmega328P (Atmel), es la version más recomendada para iniciarse en esta plataforma.

Arduino Uno R3 posee 14 entradas/salidas digitales (6 pueden usarse como PWM), 6 entradas analógicas, un resonador cerámico de 16 MHz, conexión USB, conector de alimentación, conector ICSP y un botón de Reset. La tarjeta contiene todo lo necesario para el funcionamiento del microcontrolador; basta conectarlo al puerto USB o alimentarlo con una fuente de voltaje continuo o una batería para empezar a usarlo.</p>

### <a href="https://www.geekfactory.mx/tutoriales/tutoriales-arduino/lcd-16x2-por-i2c-con-arduino/">Pantalla LCD y modulo I2C</a>
<p>La pantalla LCD de 16×2 basada en el controlador HD44780 de Hitachi es un periférico muy común, que se utiliza ampliamente en proyectos con arduino y microcontroladores en general, sin embargo, es bien sabido por todo aquel entusiasta que ha incluido una en sus proyectos, que este tipo de pantalla requiere muchos pines del microcontrolador para ser controlada, debido principalmente a que utiliza un bus paralelo para comunicarse. Afortunadamente existe una solución muy fácil y económica para este problema: un adaptador basado en el PCF8574 que permite conectar la pantalla al arduino usando solamente dos lineas digitales a través del bus I2C. Dichos pines, pueden además ser compartidos por otros periféricos como el RTC o memorias EEPROM. En este artículo te explicamos como utilizar una pantalla LCD 16×2 por I2C con Arduino de manera que puedas aprovechar mejor tus pines de I/O.</p>

### <a href="https://naylampmechatronics.com/sensores-proximidad/10-sensor-ultrasonido-hc-sr04.html">Sensor de ultrasonido HC-SR04</a>
<p>El sensor HC-SR04 es un sensor de distancia de bajo costo que utiliza ultrasonido para determinar la distancia de un objeto en un rango de 2 a 450 cm. Destaca por su pequeño tamaño, bajo consumo energético, buena precisión y excelente precio. El sensor HC-SR04 es el más utilizado dentro de los sensores de tipo ultrasonido, principalmente por la cantidad de información y proyectos disponibles en la web. De igual forma es el más empleado en proyectos de robótica como robots laberinto o sumo, y en proyectos de automatización como sistemas de medición de nivel o distancia.

El sensor HC-SR04 posee dos transductores: un emisor y un receptor piezoeléctricos, además de la electrónica necesaria para su operación. El funcionamiento del sensor es el siguiente: el emisor piezoeléctrico emite 8 pulsos de ultrasonido(40KHz) luego de recibir la orden en el pin TRIG, las ondas de sonido viajan en el aire y rebotan al encontrar un objeto, el sonido de rebote es detectado por el receptor piezoeléctrico, luego el pin ECHO cambia a Alto (5V) por un tiempo igual al que demoró la onda desde que fue emitida hasta que fue detectada, el tiempo del pulso ECO es medido por el microcontrolador y asi se puede calcular la distancia al objeto. El funcionamiento del sensor no se ve afectado por la luz solar o material de color negro (aunque los materiales blandos acusticamente como tela o lana pueden llegar a ser difíciles de detectar).</p>

### <a href="https://naylampmechatronics.com/interfaz-de-usuario/19-teclado-matricial-4x4-tipo-membrana.html">Teclado matricial 4 x 4</a>
<p>El Teclado matricial de botones plásticos formado por 4 filas y 4 columnas para un total de 16 teclas permite agregar una entrada de usuario a tus proyectos. El teclado es de tipo membrana, por lo que entre sus ventajas se encuentra el poco espacio que requiere para ser instalado. Posee una cubierta adhesiva y un cable flexible de conexión. Puede ser conectado a cualquier microcontrolador o tarjetas de desarrollo como Arduino.

El teclado matricial 4x4 está formado por una matriz de pulsadores dispuestos en filas (L1, L2, L3, L4) y columnas (C1, C2, C3, C4), con la intención de reducir el número de pines necesarios para su conexión. Las 16 teclas necesitan sólo 8 pines del microcontrolador en lugar de los 16 pines que se requerirían para la conexión de 16 teclas independientes. Para poder leer que tecla ha sido pulsada se debe de utilizar una técnica de barrido y no solo leer un pin de microcontrolador. 

La conexión del teclado matricial 4x4 con Arduino u otra plataforma de microcontroladores es simple: se necesitan 8 pines digitales en total. Puede trabajar con microcontroladores de 3.3V o 5V sin problema. Es necesario colocar resistencias pull-up entre los pines de las columnas y VCC o activar por software las resistencias Pull-up internas en el Arduino. En cuanto a la programación, la lectura de las teclas se debe realizar mediante un "barrido" de las filas. Si bien es posible realizar este procedimiento dentro del loop principal del programa, es una mejor práctica realizar el barrido utilizando interrupciones por TIMER y asi asegurar la lectura de las teclas en un intervalo conocido y exacto, además de dejar al loop libre para realizar otras operaciones.</p>

### <a href="https://naylampmechatronics.com/inalambrico/43-modulo-bluetooth-hc05.html">Modulo Bluetooth HC-05</a>
<p>El módulo Bluetooth HC-05 nos permite conectar nuestros proyectos con Arduino a un smartphone, celular o PC de forma inalámbrica (Bluetooth), con la facilidad de operación de un puerto serial. La transmisión se realiza totalmente en forma transparente al programador, por lo que se conecta en forma directa a los pines seriales de nuestro microcontrolador preferido (respetando los niveles de voltaje, ya que el módulo se alimenta con 3.3V). Todos los parámetros del módulo se pueden configurar mediante comandos AT. La placa también incluye un regulador de 3.3V, que permite alimentar el módulo con un voltaje entre 3.6V - 6V. Este módulo es el complemento ideal para nuestros proyectos de robótica, domótica y control remoto con Arduino, PIC, Raspberry PI, ESP8266, ESP32, STM32, etc.

La comunicación Bluetooth se da entre dos tipos de dispositivos: un maestro y un esclavo. Si nuestro objetivo es conectar nuestro proyecto a un smartphone android podemos utilizar tanto un módulo HC-06 o un HC-05 configurado como esclavo. El módulo Bluetooth HC-05 viene configurado de fábrica para trabajar como esclavo, es decir, preparado para escuchar peticiones de conexión, pero podemos configurarlo para trabajar con Maestro utilizando comandos AT. Por otra parte si nuestro objetivo es conectar dos proyectos, necesitaremos utilizar un módulo HC-05 configurado como maestro y un HC-06 (esclavo) o un HC-05 configurado como esclavo.

Este modulo cumple con las especificaciones del estándar Bluetooth 2.0 que es perfectamente compatible con celulares o smartphones Android, más no con los Iphone. Para trabajar con Iphone recomendamos utilizar el Módulo Bluetooth 4.0 BLE HM-10, que también es compatible con los celulares Android modernos.</p>

### <a href="https://naylampmechatronics.com/servomotores/21-servo-sg90-15kg.html?search_query=servomotor&results=21">Servomotor 9gr</a>
<p>Servomotor de tamaño pequeño ideal para proyectos de bajo torque y donde se requiera poco peso. Muy usado en aeromodelismo, pequeños brazos robóticos y mini artrópodos. Un servo ideal para aprender a programar en Arduino.

Puede rotar aproximadamente 180 grados (90° en cada dirección). Tiene la facilidad de poder trabajar con diversidad de plataformas de desarrollo como Arduino, PICs, Raspberry Pi, o en general a cualquier microcontrolador.

Para su uso con Arduino, recomendamos conectar el cable naranja al pin 9 o 10 y usar la Librería "Servo" incluida en el IDE de Arduino. Para la posición 0° el pulso es de 0.6ms, para 90° es de 1.5ms y para 180° 2.4ms.

Posee un conector universal tipo "S" que encaja perfectamente en la mayoría de los receptores de radio control incluyendo los Futaba, JR, GWS, Cirrus, Hitec y otros. Los cables en el conector están distribuidos de la siguiente forma: Cafe = Tierra (GND),  Rojo = VCC (5V),  Naranja = Señal de control (PWM).

Puede ser alimentado por USB pero se recomienda alimentar por separado el microcontrolador y los servos, ya que el ruido eléctrico puede dar lugar a errores en la ejecución del programa, o en todo caso agregar un capacitor de 100uF entre 5V y GND.</p>

## Software Utilizado:

### Entorno Google Colab
<p>Para el desarrollo de nuestro clasificador de rostros empleamos el lenguaje multiplataforma Python 3 en la plataforma de google Colab ya que nos permite correr codigos pesados y adquirir de estos los resultados en el menor tiempo posible </p>

### Arduino IDE
<p>Es el open source de la parte logica de Arduino. En otras palabras es el lenguaje originalmente desarrollada en C que nos permite programar nuestras tarjetas para que ejecuten las funciones y metodos que hallamos incorporado.</p>

## Dataset (<a href="https://drive.google.com/open?id=1LhIVFvFVUxwYvMBJkzmk05l6yJzYE9Fy">FACE MATCHING DATA SET</a>)
<p>CyberExtruder Ultimate Face Matching Data Set contiene 10205 de 10000 personas. Las imagenes tiene diferentes poses, iluminacion, expresion, raza y variedad de edad. Tambien contiene impresiones artisticas, ej: pinturas y dibujos. Todas las imagenes tienen 600 x 600 pixeles y se almacenaron en formato jpg con un peso total de 1.65 GB. </p>
  

 

## Estudiantes Involucrados:
<ul>
  <li>Edgar Andres Montenegro Martinez</li>
  <li>Franklin Samuel Sierra Jerez</li>
  <li>Leyston Alexander Onate Lizarazo</li>
</ul>
