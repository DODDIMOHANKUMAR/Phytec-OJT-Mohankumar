#include"stm32f4xx.h"

int main()
{
	RCC ->AHB1ENR =1;
	GPIOA->MODER |=1<<10;

	while(1)
	{
		GPIOA ->ODR |=(1<5);
		  Delaytime(500);
		 GPIOA ->ODR |= ~(1<5);
		 Delaytime (500);

	}

	void Dalytime(int n)
	{
		for(int i=0;i<n*3195;i++);
	}
}
