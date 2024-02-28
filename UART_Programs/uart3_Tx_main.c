#include "stm32f4xx.h"

	void USART3_init(void);
	void USART3_write(int c);
	char USART3_read(void);

	int main()
	{
		char c;
		USART3_init();
		while(1)
		{

			c = USART3_read();
			USART3_write(c);
		}
	}
	void USART3_init(void)
	{
				RCC->AHB1ENR |= 1; /* Enable GPIOA clock */
				RCC->APB1ENR |= 0x40000; /* Enable USART3 clock */
				/* Configure PB10, PB11 for USART3 TX, RX */
				GPIOB->AFR[1] &= ~0x00FF;
				GPIOB->AFR[1] |= 0x7700; /* alt8 for USART3 */
				GPIOB->MODER &= ~0xFF00;
				GPIOB->MODER |= 0x0A00; /* enable alternate function for PB10, PB11 */
				USART3->BRR = 0x0683; /* 9600 baud @ 16 MHz */
				USART3->CR1 = 0x000C;/* enable Tx, Rx, 8-bit data */
				USART3->CR2 = 0x0000; /* 1 stop bit*/
				USART3->CR3 = 0x0000; /* no flow control */
				USART3->CR1 |= 0x2000; /*enable UART4 */
	}

	void USART3_write(int ch)
	{
		while (!(USART3->SR & 0x0080)) {} // wait until Tx buffer empty
		USART3->DR = (ch & 0xFF);
	}
	                                      /* Read a character from UART3 */
		char USART3_read(void)
		{
		while (!(USART3->SR & 0x0020)) {} // wait until char arrives
		return USART3->DR;
}
