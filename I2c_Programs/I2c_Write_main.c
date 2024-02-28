#include "stm32f4xx.h"
#define SLAVE_ADDR 0x68 /* 1101 000. DS1337 */


	void delayMs(int n);
	void I2C1_init(void);
	int I2C1_byteWrite(char saddr, char maddr, char data);

	int main(void)
	{
		I2C1_init();
		I2C1_byteWrite(SLAVE_ADDR, 0x0E, 0);

		while(1)
		{

		}
	}
void I2C1_init(void)
{
	RCC->AHB1ENR |= 2; /* Enable GPIOB clock */
    RCC ->APB1ENR |=0x00200000;/* Enable I2C1 clock */
	GPIOB->MODER &=0;/* configure PB8, PB9 pins for I2C1 */
    GPIOB ->MODER|=0x000A0000;
     /* PB8, PB9 I2C1 SCL, SDA */
	GPIOB->AFR[1] &=0;
	 /* PB8, PB9 use alternate function */
	GPIOB->AFR[1]|=0x00000044;
     /* output open-drain */
	GPIOB->OTYPER|=0x00000300;
	 /* with pull-ups */
    GPIOB->PUPDR|=0x00050000;

	/* this funtion writes a byte of data to the memory location maddr of*/


     /* software reset I2C1 */
    I2C1->CR1&=(1<<15);
    /* out of reset */
    I2C1->CR1|=(1<<15);
	/* peripheral clock is 16 MHz */
    I2C1->CR1|=(1<<4);
    /* standard mode, 100kHz clock */
    I2C1->CCR|=80;
	/* maximum rise time */
    I2C1->TRISE|=17;
	/* enable I2C1 module */
    I2C1->CR1|=0x00000001;

}
/* a device with I2C slave device address saddr.
* For simplicity, no error checking or error report is done. */
int I2C1_byteWrite(char saddar,char maddar,char data)
{
	      volatile int temp;
		 /* wait until bus not busy */
	      while(I2C1->SR2 & 2);
		 /* generate start */
	    I2C1 ->CR1|=(1<<8);
		 /* wait until start flag is set */
	     while(!(I2C1->SR2 & 1));

		 /* transmit slave address */
          I2C1 ->DR =saddar<<1;
		/* wait until addr flag is set */
          temp =I2C1 ->SR2;

		 /* clear addr flag */
          while(!(I2C1->SR1 & 0x80));
          I2C1 ->DR|=maddar;

		 /* wait until data register empty */
          while(!(I2C1->SR1 |0x80));
        	  I2C1 ->DR |=data;
          while(!(I2C1->SR1 & 4));
          I2C1 ->CR1 |=0x200;


          return 0;
	}

