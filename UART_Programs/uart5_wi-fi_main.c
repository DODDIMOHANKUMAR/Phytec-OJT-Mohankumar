#include"stm32f4xx.h"

	void uart5_init(void);
	void UART5_write(int ch);
	char uart5_read(void);

	void delayMs(int n)
	{
		int i;
		for (; n > 0; n--)
			for (i = 0; i < 3195; i++);
	}

	int main(void)
	{
		uart5_init();
		char message[] = "CMD+RESET\r\n";
		int i;
		for (i = 0; message[i] != '\0'; i++){

			UART5_write(message[i]);
		}
		delayMs(1000);
		char messag[] = "CMD+WIFIMODE=1\r\n";
		int j;
		for (j = 0; messag[j] != '\0'; j++) {
			UART5_write(messag[j]);
	}
	delayMs(1000);
	char msg[] = "CMD+CONTOAP=iQOO Neo6,123456788\r\n";
	int k;
	for (k = 0; msg[k] != '\0'; k++) {
		UART5_write(msg[k]);
	}
	delayMs(1000);

	}

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
	GPIOC->AFR[1] |= 0x00080000;
	GPIOD->AFR[0] &=0;
	GPIOD ->AFR[0] |=0x00000800;
	UART5->BRR = 0x01A1;
	UART5->CR1 = 0x000C;
	UART5->CR2 = 0x0000;
	UART5->CR3 = 0x0000;
	UART5->CR1 |= 0x2000;

}



	void UART5_write(int ch)
		{
		while (!(UART5->SR & 0x0080)) {}
		UART5->DR = (ch & 0xFF);
	}

	char uart5_read(void)
		{
		while (!(UART5->SR & 0x0020)) {}
		return UART5->DR;
	}


