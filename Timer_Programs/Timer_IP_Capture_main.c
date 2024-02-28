#include"stm32f4xx.h"

#define TIM2EN		(1U<<0)
#define TIM3EN		(1U<<1)
#define CR1_CEN		(1U<<0)
#define OC_TOGGLE	((1U<<4) | (1U<<5))
#define CCER_CC1P	(1U<<1)
#define GPIOAEN		(1U<<0)
#define AFR5_TIM	(1U<<20)
#define AFR6_TIM	(1U<<25)
#define CCMR1_TIM   (1U<<0)
//#define CCER_CC1P   (1U<<1)
#define CCER_CC1NP_CC1P   (3U<<1) | (1U<<1)
#define CCER_CC1E    (1U<<0)


uint32_t timestamp;

void tim2_pa5_output_compare(void)
	{

	 /*Enable clock access to GPIOA*/
	 RCC->AHB1ENR |= GPIOAEN;

	/*Set PA5 mode to alternate function*/
	 GPIOA->MODER &=~(1<<10);
	 GPIOA->MODER |=(1<<11);//0x00000400


	/*Set PA5 alternate function type to TIM2_CH1 (AF01)*/
	 GPIOA->AFR[0]|= AFR5_TIM;

	/*Enable clock access to tim2*/
     RCC ->APB1ENR |= TIM2EN;

	/*Set prescaler value*/
	     TIM2 ->PSC =16000-1;      //  16 000 000 / 1 600 = 10 000
	/*Set auto-reload value*/
	     TIM2 ->ARR =1000-1;                      // 10 000 / 10 000 = 1

	/*Set output compare toggle mode ccmr1*/

        TIM2 ->CCMR1=OC_TOGGLE;
	/*Enable tim2 ch1 in compare mode ccer*/
       TIM2 ->CCER = CCER_CC1E;

	/*Clear counter*/
	  TIM2 ->CNT =0;
	/*Enable timer*/
      TIM2->CR1 =CR1_CEN;
}

void tim3_pa6_input_capture(void)
{

	/*Enable clock access to GPIOA*/
	  RCC ->AHB1ENR |=GPIOAEN;
	/*Set PA6 mode to alternate function*/
	  GPIOA->MODER |=0x2000;

	/*Set PA6 alternate function type to TIM3_CH1 (AF02)*/
	  GPIOA->AFR[0]|= AFR6_TIM;


        /*Enable clock access to tim3*/
	  RCC->APB1ENR |= TIM3EN;

	   /*Set Prescaler*/
	   TIM3->PSC = 16000-1; // 16 000 000 /16 000

	/*Set CH1 to input capture ccmr1*/
	   TIM3 ->CCMR1 = CCMR1_TIM;
	/*Set CH1 to capture at rising edge ccer*/
	   //TIM3 ->CCER =CCER_CC1P;
	   /* Both Edges*/
	   TIM3->CCER = CCER_CC1NP_CC1P;
	/*Enable TIM3*/
	   TIM3 ->CR1 =CR1_CEN;
}


int main()
{
	        tim2_pa5_output_compare();
		    tim3_pa6_input_capture();
	while(1)
	{

	    /*Wait until edge is captured*/
		while(!(TIM3->SR & TIM_SR_CC1IF)){}

		/*Read captured value*/
		timestamp =  TIM3->CCR1;


	}
}
