# brushless-wiringpi
Control de motor brushlees con wiringPi gpio
 INICIO CONTROLADOR ESC:
 
 1)       
        Pulsos de 2000us  durante 2.5 segundos

        |--------| pulso de 2000us para indicar el pulso mas alto al controlador ESC
         _______                                     3.3v
        |       |                                  |
        |       |                                  |
        |       |__________________________________| 0 V

        |------------------------------------------| 20000 us periodo del controlador ESC

        2500 ms / 20 ms = 125 pulsos;
   
   2)             
        Pulsos de 1000us  durante 2.5 segundos

        |----| pulso de 1000us para indicar el pulso mas bajo al controlador ESC
         ____                             3.3v
        |    |                                      |
        |    |                                      |
        |    |______________________________________| 0 V

        |-------------------------------| 20000 us periodo del controlador ESC

        2500 ms / 20 ms = 125 pulsos;
     
     Velocidad maima 2000 microsegundos (us)
     Velocidad minima 1000 microsegundos (us)
