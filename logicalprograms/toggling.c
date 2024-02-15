#include<stdio.h>

unsigned int toggleBit (unsigned int num,int position)
{
	unsigned int bitmask = 1 << position;

	return num ^ bitmask;
}

int main()  {
	unsigned int number, position;

	printf("Enter the number and Position:");
	scanf("%u%d",&number,&position);
      

	if (position < 0 || position >31){
		printf("Invalid Bit position please Enter a Value Between 0 and 31.\n");
		return 1;
	}


	unsigned int result = toggleBit(number, position);
	printf("Number After toggling bit %d:%u\n",position, result);
	return 0;
}






