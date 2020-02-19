

/**
 * main.c
 */
#include "gpio.h"
#include "regmap.h"
#include "BIT_MODE.h"

int main(void)
{
    u8 flag =0;
    int i =0;
    ConfigureBus();
    GPIOClockSet(PORTF);
    GPIODirModeSet(PORTF,0b00010001, MODE_IN);
    GPIODirModeSet(PORTF,0b00001110, MODE_OUT);
    unsigned char get_dir_test = GPIODirGet(PORTF, 0b00011111);

    GPIOPadSet(PORTF, 0b00011110, Drive_8mA ,PAD_PU);
    unsigned char get_pad_test = GPIOPadDriveStrGet(PORTF, 3);


       GPIOWrite(PORTF,0b00001110, LOW);
       while (1)
       {
       if(GPIORead(PORTF,0b00010000) == (0b00000000))
       {
           if (flag==0)
               {
               GPIOWrite(PORTF,0b0001100, LOW);
               GPIOWrite(PORTF,0b0000010, HIGH);
               flag++;
               }
           else if (flag ==1)
           {
               GPIOWrite(PORTF,0b0001010, LOW);
               GPIOWrite(PORTF,0b0000100, HIGH);
                             flag++;
           }
           else if (flag ==2)
                  {
                      GPIOWrite(PORTF,0b0000110, LOW);
                      GPIOWrite(PORTF,0b0001000, HIGH);
                                    flag=0;
                  }

           for (i =0 ; i< 500000 ; i++);
       }
       }

}
