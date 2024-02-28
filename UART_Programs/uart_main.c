#include"stm32f4xx.h"
#include<stdint.h>

#define GPIOAEN      (1U<<0)
#define PA2MOD       (10U<<4)
#define PA2AF        (7U<<8)
#define APB1EN       (1U<<17)
#define USART2_TX     (1U<<3)
#define USART2EN     (1U<<13)
#define SR_TXE       (1U<<7)


#define SYS_TFEQ     16000000
#define APB1_CLK     SYS_TFEQ

#define UART_BAUDRATE	115200

void uart2_init(void);
void uart2_write(int ch);

static void uart_set_baudrate(USART_TypeDef *USARTx,
		                         uint32_t PeriphClk,

							     uint32_t BaudRate);
static uint16_t compute_uart_bd( uint32_t PeriphClk,

		                         uint32_t BaudRate);

int main()
{

	uart2_init();
	while(1)
	{
		uart2_write('y');


	}
	return 0;
}


void uart2_init(void)
{


		RCC->AHB1ENR |= GPIOAEN;
       GPIOA->MODER  |= PA2MOD;
       GPIOA->AFR[0] |= PA2AF;
        RCC->APB1ENR |= APB1EN;

		uart_set_baudrate(USART2,APB1_CLK,UART_BAUDRATE);

        USART2->CR1 = USART2_TX;
        USART2->CR1 |= USART2EN;

}






static void uart_set_baudrate(USART_TypeDef *USARTx,
		                         uint32_t PeriphClk,
		                         uint32_t BaudRate)
{
	USARTx->BRR =  compute_uart_bd(PeriphClk,BaudRate);
}

static uint16_t compute_uart_bd(uint32_t PeriphClk,
		                        uint32_t BaudRate)
{
	return ((PeriphClk + (BaudRate/2U))/BaudRate);
}






void uart2_write(int ch)
{

	while(!(USART2->SR & SR_TXE)){}

	USART2->DR	=  (ch & 0xFF);
}


