#include "main.h"

int main(void)
{
    #define BIT21 0B1000000000000000000000

    RCC -> AHBENR |= 1 << 21;
    RCC -> AHBENR |= RCC_AHBENR_GPIOAEN;

    GPIOE -> MODER |= GPIO_MODER_MODER8_0;
   // GPIOE -> MODER &= ~GPIO_MODER_MODER8_1;
    GPIOE -> MODER |= GPIO_MODER_MODER9_0;
   // GPIOE -> MODER &= ~GPIO_MODER_MODER9_1;
    GPIOE -> MODER |= GPIO_MODER_MODER10_0;
   // GPIOE -> MODER &= ~GPIO_MODER_MODER10_1;
    GPIOE -> MODER |= GPIO_MODER_MODER11_0;
   // GPIOE -> MODER &= ~GPIO_MODER_MODER11_1;
    GPIOE -> MODER |= GPIO_MODER_MODER12_0;
   // GPIOE -> MODER &= ~GPIO_MODER_MODER12_1;
    GPIOE -> MODER |= GPIO_MODER_MODER13_0;
   // GPIOE -> MODER &= ~GPIO_MODER_MODER13_1;
    GPIOE -> MODER |= GPIO_MODER_MODER14_0;
   // GPIOE -> MODER &= ~GPIO_MODER_MODER14_1;
    GPIOE -> MODER |= GPIO_MODER_MODER15_0;
   // GPIOE -> MODER &= ~GPIO_MODER_MODER15_1;





    GPIOA -> MODER &= ~GPIO_MODER_MODER0_0;
    GPIOA -> MODER &= ~GPIO_MODER_MODER0_1;
    while(1)
    {
        // Read the state of the button
        if(GPIOA->IDR & GPIO_IDR_0)
        {
            // Button is not pressed, turn off the LED
        	GPIOE -> BSRR |= 0xFF << 8;
             // Reset the bit to turn off LED
        }
        else
        {
        	GPIOE -> BSRR |= 0xFF << (8 + 16);// Button is pressed, turn on the LED
             // Set the bit to turn on LED
        }
    }
}
