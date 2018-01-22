#include <stdio.h>
#include <wiringPi.h>
#include<unistd.h>

#define GPIO 12 //gpio 15 orange pi zero

int main()
{

        int speed = 1500; //MINIMO 1000 MAXIMO 2000
        wiringPiSetup();
        pinMode (GPIO, OUTPUT);

        //INICIO CONTROLADOR ESC
        /*
        Pulsos de 2000us  durante 2.5 segundos

        |--------| pulso de 2000us para indicar el pulso mas alto al controlador ESC
         _______                                     3.3v
        |       |                                  |
        |       |                                  |
        |       |__________________________________| 0 V

        |------------------------------------------| 20000 us periodo del controlador ESC

        2500 ms / 20 ms = 125 pulsos;
        */
        for(int i=0;i<125;i++)
        {
                digitalWrite(GPIO, HIGH);
                usleep(2000);//2ms (cambiar por 1000 si tu controlador se inicia al contrario)
                digitalWrite(GPIO, LOW);
                usleep(18000);//18ms
        }
        /*
        Pulsos de 1000us  durante 2.5 segundos

        |----| pulso de 1000us para indicar el pulso mas bajo al controlador ESC
         ____                             3.3v
        |    |                                      |
        |    |                                      |
        |    |______________________________________| 0 V

        |-------------------------------| 20000 us periodo del controlador ESC

        2500 ms / 20 ms = 125 pulsos;
        */

        for(int i=0;i<125;i++)
        {
                digitalWrite(GPIO, HIGH);
                usleep(1000);//1ms (cambiar por 2000 si tu controlador se inicia al contrario)
                digitalWrite(GPIO, LOW);
                usleep(19000);//19ms
        }
        //FIN INICIO CONTROLADOR ESC

        //Inicio Giro del motor
        while(1)
        {
                digitalWrite(GPIO, HIGH);
                usleep(speed);//us
                digitalWrite(GPIO, LOW);
                usleep(20000-speed);//us
        }

  return 0;
}
