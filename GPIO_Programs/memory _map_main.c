#include "stm32f4xx.h"
#include "gpio.h"
#define GPIOA_EN (1U<<0)
#define PA5_MOD (1U<<10)



int main()
{
		RCC->AHB1ENR |=GPIOA_EN;
		GPIOA->MODER |=PA5_MOD;
			while(1)
			{
					led_on();
					timedelay(2000);
					led_off();
					timedelay(2000);
			}
	 return 0;

}

