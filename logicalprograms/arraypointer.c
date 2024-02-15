#include<stdio.h>

int main()
{
	int var1 = 10;
	int var2 = 20;

	int* ptr_array[2] = {&var1,&var2};
	for(int i =0;i<2;i++)
	{
		printf("value of var is %d\tAddress : %p\n",i + 1,*ptr_array[i], ptr_array[i]);
	}
	return 0;
}
