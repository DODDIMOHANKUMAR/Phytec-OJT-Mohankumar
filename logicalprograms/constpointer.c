#include<stdio.h>

int main()
{
	int a = 100;
	int b = 300;

	int const*ptr;
        ptr = &a;
	ptr = &b;

	printf("Find outthe Constant values:%d\n",ptr);
	return 0;
	 
}
