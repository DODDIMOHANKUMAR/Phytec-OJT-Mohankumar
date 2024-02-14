#include<stdio.h>


int main()
{
	int i,j,num;
	int *ptr[5] = {12,23,34,45,67};
	printf("size of ptr =%lu\n",sizeof(ptr));
	for(int i =0;i<num;i++)
	{
		printf("%d",*ptr[i]);
	}
	return 0;
}
	   




