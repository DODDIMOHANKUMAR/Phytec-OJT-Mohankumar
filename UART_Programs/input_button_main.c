#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"





#define LINE13      (1U<<13)
#define GPIOAEN		(1U<<0)
#define PIN5		 (1U<<5)

#define LED		     PIN5

void PC13_inti();

int main()
{
	RCC ->AHB1ENR |=1;
	GPIOA->MODER   &=0;
	GPIOA ->MODER |=(1<<5);

	PC13_inti();

	while(1)
	{

	}
}
static void EXTI_Callback()
{
	GPIOA ->ODR^=(1<<5);
}
void EXTI15_10_IRQHandler(void)
{
	if(EXTI->PR &(1<<13)!=0){
			EXTI->PR |=(1<<13);
			EXTI_Callback();
	}

}

void PC13_inti(void)
{
	__disable_irq();
	RCC ->AHB1ENR |=(1<<2);
	GPIOC->MODER =0;
	RCC->APB2ENR |=(1<<14);
	SYSCFG->EXTICR[3] |=(1<<5);
	EXTI->IMR |= (1<<13);
	EXTI->RTSR|=(1<<13);
	NVIC_EnableIRQ(EXTI15_10_IRQn);




}

