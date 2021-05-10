//Universidad del Valle de Guatemala
//Depto. de ingenieria Mecatronica y Electronica
//Digital 2
//Prof. Kurt Kellner
//Diego Mencos
//Carne 18300


//Bibliotecas
#include<stdint.h>
#include<stdbool.h>
#include"inc/hw_memmap.h"
#include"inc/tm4c123gh6pm.h"
#include"driverlib/sysctl.h"
#include"driverlib/gpio.h"

int status=1;
int status2=1;

int main(void) {
    //Establecer reloj del microcontrolador
    SysCtlClockSet(SYSCTL_XTAL_16MHZ|SYSCTL_SYSDIV_5);
    //Habilitar periférico GPIO F
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    //Habilitar pines de salida y entrada
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_0|GPIO_PIN_4);
    //Configurar tipo de entrada
    GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_0|GPIO_PIN_4, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);

    while(true){
        //Lee el pin de entrada
     //   status = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0);
        status2 = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4);


        //Si el botón está presionado enciende el LED y si no, lo apaga.
        if (status==0){
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 2);
            SysCtlDelay(1000000);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 10);
            SysCtlDelay(1000000);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 8);
            SysCtlDelay(8000000);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0);
            SysCtlDelay(8000000);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 8);
            SysCtlDelay(8000000);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0);
            SysCtlDelay(8000000);

        }

        else if (status2==0){

            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 8);
            SysCtlDelay(10000000);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0);
            SysCtlDelay(10000000);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 8);
            SysCtlDelay(8000000);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0);
            SysCtlDelay(8000000);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 10);
            SysCtlDelay(8000000);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 2);
            SysCtlDelay(8000000);

        }

        else{
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0);
        }
    }
}
