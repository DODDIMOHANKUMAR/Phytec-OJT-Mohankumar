#include "stm32f4xx.h"
#define GPIOAEN		    (1U<<0)
#define ADC1EN			(1U<<8)
#define ADC_CH1			(1U<<0)
#define ADC_SEQ_LEN_1	 0x0000
#define CR2_ADON		(1U<<0)
#define CR2_SWSTART		(1U<<30)
#define SR_EOC			(1U<<1)
uint32_t sensor_value;

	void pa1_adc_init(void)
	{

		RCC->AHB1ENR |= 1;
		GPIOA->MODER |=0x0000000C;
		RCC->APB2ENR |= ADC1EN;
		ADC1->SQR3 = ADC_CH1;
		ADC1->SQR1 = 0x0000;
		ADC1->CR2 |= CR2_ADON;
	}
void start_conversion(void)
{
	ADC1->CR2 |= 2;
	ADC1->CR2 |= CR2_SWSTART;
}
uint32_t adc_read(void)
{
	while(!(ADC1->SR & SR_EOC)){}
	return (ADC1->DR);
}
int main(void)
{
	pa1_adc_init();
	start_conversion();
	while(1)
	{
		sensor_value=adc_read();
	}
}
