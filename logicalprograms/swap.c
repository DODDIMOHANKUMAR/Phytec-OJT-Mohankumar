#include<stdio.h>

int main()
{
	int a =10,b =20;
	printf("Before Swap the two number's a=%d and b= %d\n",a,b);
	
	a =a +b;
	b =a -b;
	a =a-b;

	printf("/n After Swap the numbers a=%d and b=%d",a,b);
	return 0;
}
