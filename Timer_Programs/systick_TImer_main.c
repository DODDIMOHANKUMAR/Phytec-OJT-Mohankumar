#include "stm32f4xx.h"

void systickDelayMs(int delay);


#define SYSTICK_LOAD_VAL			16000
#define	CTRL_ENABLE					(1U<<0)
#define CTRL_CLKSRC					(1U<<2)
#define CTRL_COUNTFLAG				(1U<<16)


int main()
{

			RCC->AHB1ENR |=1;
			GPIOA->MODER |= 1<<10;
				while(1)
				{

					GPIOA ->ODR ^=(1<<5);
					systickDelayMs(1000);
				}
		 return 0;
}




void systickDelayMs(int Delay)
{
	/*Reload with number of clocks per millisecond*/
	SysTick->LOAD	= SYSTICK_LOAD_VAL;

	/*Clear systick current value register */
	SysTick->VAL = 0;

	/*Enable systick and select internal clk src*/
	SysTick->CTRL = CTRL_ENABLE | CTRL_CLKSRC;

	for(int i=0; i<Delay ; i++)
	{

		/*Wait until the COUNTFLAG is set*/

		while((SysTick->CTRL &  CTRL_COUNTFLAG) == 0){}

	}

	SysTick->CTRL = 0;

}
