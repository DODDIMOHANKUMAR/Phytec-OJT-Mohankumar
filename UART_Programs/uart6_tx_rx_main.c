#include"stm32f4xx.h"

void usart6_init(void);
void usart6_write(int ch);
char usart6_read(void);


int main(void)
{
	char c;
	usart6_init();
	while (1)
	{
	c = usart6_read();
	usart6_write(c);
	}

}

	void usart6_init(void)
	{
		RCC->AHB1ENR |= 4;
		RCC->APB2ENR |= 0x00000020;
		GPIOC->MODER &= ~0x0000F000;
		GPIOC->MODER |= 0x0000A000;
		GPIOC->AFR[0] &= ~0xFF000000;
		GPIOC->AFR[0] |= 0x88000000; /* alt8 for UART6 */
		USART6->BRR = 0x0683; /* 9600 baud @ 16 MHz */
		USART6->CR1 = 0x000C;/* enable Tx, Rx, 8-bit data */
		USART6->CR2 = 0x0000; /* 1 stop bit*/
		USART6->CR3 = 0x0000; /* no flow control */
		USART6->CR1 |= 0x2000; /*enable UART1 */

}



		void usart6_write(int ch) {
			while (!(USART6->SR & 0x0080)) {} // wait until Tx buffer empty
			USART6->DR = (ch & 0xFF);
		}


/* Read a character from UART4 */
		char usart6_read(void) {
			while (!(USART6->SR & 0x0020)) {} // wait until char arrives
			return USART6->DR;
}







