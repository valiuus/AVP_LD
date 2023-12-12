#include "main.h"

void init_tim_gpio(void);
void init_tim(int period);

int main(void)
{
    init_tim_gpio();
    init_tim(1000);

    while (1)
    {
        // Implement fading effect
        for (int duty = 0; duty <= 1000; duty += 10)
        {
            TIM1->CCR3 = duty;
            delay_ms(10); // Adjust the delay for the desired fading speed
        }

        for (int duty = 1000; duty >= 0; duty -= 10)
        {
            TIM1->CCR3 = duty;
            delay_ms(10); // Adjust the delay for the desired fading speed
        }
    }
}

void init_tim_gpio(void)
{
    RCC->AHBENR |= RCC_AHBENR_GPIOEEN;

    // Configure PE13 (TIM1_CH3) as alternate function AF2
    GPIOE->MODER |= GPIO_MODER_MODER13_1;
    GPIOE->MODER &= ~GPIO_MODER_MODER13_0;
    GPIOE->AFR[1] |= (2 << ((13 - 8) * 4)); // Assuming PE13 is in AFR[1]
}

void init_tim(int period)
{
    RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;

    TIM1->CCMR2 |= TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3M_2;
    TIM1->CCMR2 |= TIM_CCMR2_OC3PE;

    TIM1->CR1 |= TIM_CR1_ARPE;
    TIM1->ARR = period;

    TIM1->BDTR |= TIM_BDTR_MOE;
    TIM1->CCER |= TIM_CCER_CC3E;

    TIM1->CR1 |= TIM_CR1_CEN;
}

void delay_ms(int ms)
{
    // Simple delay function, adjust based on your system clock frequency
    for (volatile int i = 0; i < ms * 500; ++i)
    {
        __NOP();
    }
}
