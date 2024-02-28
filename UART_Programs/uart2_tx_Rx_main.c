#include"stm32f4xx.h"

void usart2_init(void);
void USART2_write(int ch);
char usart2_read(void);

void delayMs(int n)
	{
		int i;
		for (; n > 0; n--)
			for (i = 0; i < 3195; i++);
	}

	int main(void)
	{
		usart2_init();
		char message[] = "CMD+RESET\r\n";
		int i;
		for (i = 0; message[i] != '\0'; i++){

			USART2_write(message[i]);
		}
		delayMs(1000);
		char messag[] = "CMD+WIFIMODE=1\r\n";
		int j;
		for (j = 0; messag[j] != '\0'; j++) {
			USART2_write(messag[j]);
	}
	delayMs(1000);
	char msg[] = "CMD+CONTOAP=Redmi 9i,9876543210\r\n";
	int k;
	for (k = 0; msg[k] != '\0'; k++) {
		USART2_write(msg[k]);
	}
	delayMs(1000);

	}


void usart2_init(void)
{
	RCC->AHB1ENR |= 1;
	RCC->APB1ENR |= 0x00020000;
	GPIOA->MODER &= ~0x000000F0;
	GPIOA->MODER |= 0x000000A0;
	GPIOA->AFR[0] &= ~0x0000FF00;
	GPIOA->AFR[0] |= 0x00007700 ; /* alt8 for UART2 */
	USART2->BRR = 0x01A1; /* 38400baud @ 16 MHz */
	USART2->CR1 = 0x000C;/* enable Tx, Rx, 8-bit data */
	USART2->CR2 = 0x0000; /* 1 stop bit*/
	USART2->CR3 = 0x0000; /* no flow control */
	USART2->CR1 |= 0x2000; /*enable UART2 */

}



void USART2_write(int ch) {
while (!(USART2->SR & 0x0080)) {} // wait until Tx buffer empty
USART2->DR = (ch & 0xFF);
}
/* Read a character from UART4 */
char usart2_read(void) {
while (!(USART2->SR & 0x0020)) {} // wait until char arrives
return USART2->DR;
}


