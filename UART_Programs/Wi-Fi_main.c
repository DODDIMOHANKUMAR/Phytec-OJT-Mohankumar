#include"stm32f4xx.h"

	void usart6_init(void);
	void USART6_write(int ch);
	char usart6_read(void);

	void delayMs(int n)
	{
		int i;
		for (; n > 0; n--)
			for (i = 0; i < 3195; i++);
	}

	int main(void)
	{
		usart6_init();
		char message[] = "CMD+RESET\r\n";
		int i;
		for (i = 0; message[i] != '\0'; i++){

			USART6_write(message[i]);
		}
		delayMs(1000);
		char messag[] = "CMD+WIFIMODE=1\r\n";
		int j;
		for (j = 0; messag[j] != '\0'; j++) {
			USART6_write(messag[j]);
	}
	delayMs(1000);
	char msg[] = "CMD+CONTOAP=Redmi 9i,9876543210\r\n";
	int k;
	for (k = 0; msg[k] != '\0'; k++) {
		USART6_write(msg[k]);
	}
	delayMs(1000);

	}


void usart6_init(void)
{
			RCC->AHB1ENR |= 4;
			RCC->APB2ENR |= 0x00000020;
			GPIOC->MODER &= ~0x0000F000;
			GPIOC->MODER |= 0x0000A000;
			GPIOC->AFR[0] &= ~0xFF000000;
			GPIOC->AFR[0] |= 0x88000000; /* alt8 for UART6 */
			USART6->BRR = 0x01A1; /* 38400 baud @ 16 MHz */
			USART6->CR1 = 0x000C;/* enable Tx, Rx, 8-bit data */
			USART6->CR2 = 0x0000; /* 1 stop bit*/
			USART6->CR3 = 0x0000; /* no flow control */
			USART6->CR1 |= 0x2000; /*enable UART1 */


}



	void USART6_write(int ch)
	{
		while (!(USART6->SR & 0x0080)){} // wait until Tx buffer empty
		USART6->DR = (ch & 0xFF);
	}

	char usart6_read(void)
	{
				while (!(USART6->SR & 0x0020)){} // wait until char arrives
				return USART6->DR;
	}

