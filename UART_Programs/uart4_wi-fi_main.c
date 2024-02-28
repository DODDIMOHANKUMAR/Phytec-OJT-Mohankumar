#include "stm32f4xx.h"

	void UART4_init(void);
	void UART4_write(int c);
	//void delayMs(int);
	char UART4_read(void);

	void delayMs(int n)
		{
			int i;
			for (; n > 0; n--)
				for (i = 0; i < 3195; i++);
		}

		int main(void)
		{
			UART4_init();
			char message[] = "CMD+RESET\r\n";
			int i;
			for (i = 0; message[i] != '\0'; i++){

				UART4_write(message[i]);
			}
			delayMs(1000);
			char messag[] = "CMD+WIFIMODE=1\r\n";
			int j;
			for (j = 0; messag[j] != '\0'; j++) {
				UART4_write(messag[j]);
		}
		delayMs(1000);
		char msg[] = "CMD+CONTOAP=Redmi 9i,9876543210\r\n";
		int k;
		for (k = 0; msg[k] != '\0'; k++) {
			UART4_write(msg[k]);
		}
		delayMs(1000);

		}


	void UART4_init(void)
	{
		RCC->AHB1ENR |= 1;
		RCC->APB1ENR |= 0x80000;
		RCC ->AHB1ENR |=4;
		/* Configure PA0, PA1 for UART4 TX, RX */
		GPIOA->MODER &= ~0x000F;
		GPIOA->MODER |= 0x000A; /* enable alternate function for PA0, PA1 */
		GPIOC->MODER &= ~0X00F00000;
		GPIOC->MODER |= 0x00A00000;
		GPIOA->AFR[0] &= ~0x00FF;
		GPIOA->AFR[0] |= 0x0088; /* alt8 for UART4 */
		GPIOC->AFR[1] &= ~0x0000FF00;
		GPIOC->AFR[1] |= 0x00008800;

		UART4->BRR = 0x01A1; /* 38400 baud @ 16 MHz */
		UART4->CR1 = 0x000C;/* enable Tx, Rx, 8-bit data */
		UART4->CR2 = 0x0000; /* 1 stop bit*/
		UART4->CR3 = 0x0000; /* no flow control */
		UART4->CR1 |= 0x2000; /*enable UART4 */
	}
	/* Write a character to UART4 */

		void UART4_write(int ch) {
		while (!(UART4->SR & 0x0080)) {} // wait until Tx buffer empty
		UART4->DR = (ch & 0xFF);
	}
	/* Read a character from UART4 */
		char UART4_read(void) {
		while (!(UART4->SR & 0x0020)) {} // wait until char arrives
		return UART4->DR;
}
