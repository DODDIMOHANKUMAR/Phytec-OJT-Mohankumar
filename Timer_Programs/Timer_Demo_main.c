#include"stm32f4xx.h"

#define TIM2EN   (1U<<0)
#define CR1_CEN  (1U<<0)
#define SR_UIF   (1U<<0)
#define GPIOAEN   (1U<<0)
#define PIN5      (1U<<5)
#define LED        PIN5

 	 void timer_1hz_init(void);
 	 void timeDelay(void);

 	 int main()
 	 {
 		 RCC->APB1ENR |=GPIOAEN;
 		 GPIOA ->MODER |=(1<<10);

 		 timer_1hz_init();

 		 while(1)
 		 {
 			 timeDelay();
 			 GPIOA->ODR ^= LED;
  }


 }
 void timer_1hz_init(void)
 {
	// RCC->AHB1ENR |= GPIOAEN;
	 RCC->APB1ENR |= TIM2EN;

	  TIM2 ->PSC = 16000-1;
	  TIM2 ->ARR = 2000-1;
	  TIM2 ->CNT =0;
 }
 void timeDelay(void)
 {
	 while(!(TIM2->SR & SR_UIF)){}

	    (TIM2->SR & ~SR_UIF);


 }








