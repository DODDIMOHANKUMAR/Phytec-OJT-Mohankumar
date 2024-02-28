#include"stm32f4xx.h"

void usart2_init(void);
void usart2_write(int ch);
char usart2_read(void);

int main(void)
{
	char c;
	usart2_init();
	while (1) {
	c = usart2_read();
	usart2_write(c);
	}

}


void usart2_init(void)
{
	RCC->AHB1ENR |= 1;
	RCC->APB1ENR |= 0x00020000;
	GPIOA->MODER &= ~0x000000F0;
	GPIOA->MODER |= 0x000000A0;
	GPIOA->AFR[0] &= ~0x0000FF00;
	GPIOA->AFR[0] |= 0x00007700 ; /* alt8 for UART4 */
	USART2->BRR = 0x0683; /* 9600 baud @ 16 MHz */
	USART2->CR1 = 0x000C;/* enable Tx, Rx, 8-bit data */
	USART2->CR2 = 0x0000; /* 1 stop bit*/
	USART2->CR3 = 0x0000; /* no flow control */
	USART2->CR1 |= 0x2000; /*enable UART4 */

}



void usart2_write(int ch) {
while (!(USART2->SR & 0x0080)) {} // wait until Tx buffer empty
USART2->DR = (ch & 0xFF);
}
/* Read a character from UART4 */
char usart2_read(void) {
while (!(USART2->SR & 0x0020)) {} // wait until char arrives
return USART2->DR;
}


