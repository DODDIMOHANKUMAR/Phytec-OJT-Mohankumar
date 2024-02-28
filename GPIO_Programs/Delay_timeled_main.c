#include "stm32f4xx.h"
#include "led.h"
#define GPIO_EN (1<<0)
#define PA5_MOD (1<<10)



int main()
{
		RCC->AHB1ENR |=GPIO_EN;
		GPIOA->MODER |=PA5_MOD;
			while(1)
			{
					led_on();
					timedelay(1000);
					led_off();
					timedelay(1000);
			}
	 return 0;

}

