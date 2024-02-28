#include"stm32f4xx.h"

void uart5_init(void)
{
	RCC->AHB1ENR |= 4;
	RCC->AHB1ENR |=8;
	RCC->APB1ENR |= 0x00100000;
    GPIOC->MODER &= 0;
	GPIOC->MODER |= 0x02000000;
	GPIOD->MODER &=0;
	GPIOD->MODER |=0x00000020;
	GPIOC->AFR[1] &=0;
	GPIOC->AFR[1] |= 0x00080000; /* alt8 for UART4 */
	GPIOD->AFR[0] &=0;
	GPIOD ->AFR[0] |=0x00000800;
	UART5->BRR = 0x0683; /* 9600 baud @ 16 MHz */
	UART5->CR1 = 0x000C;/* enable Tx, Rx, 8-bit data */
	UART5->CR2 = 0x0000; /* 1 stop bit*/
	UART5->CR3 = 0x0000; /* no flow control */
	UART5->CR1 |= 0x2000; /*enable UART4 */

}



void uart5_write(int ch)
	{
	while (!(UART5->SR & 0x0080)) {} // wait until Tx buffer empty
	UART5->DR = (ch & 0xFF);
	}
/* Read a character from UART4 */
char uart5_read(void)
	{
	while (!(UART5->SR & 0x0020)) {} // wait until char arrives
	return UART5->DR;
	}


int main(void)
{
	char c;
	uart5_init();
	while (1)
	{
		c = uart5_read();
		uart5_write(c);
	}

}
