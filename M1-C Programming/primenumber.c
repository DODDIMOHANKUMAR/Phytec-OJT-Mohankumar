#include<stdio.h>

int main()
{
	int num,i,j,count = 0;
	printf("Enter the Prime number:");
	scanf("%d\n",&num);
	for(int i =2;i<num;i++)
	{
		int count= 0;
	}
	for(int j =1;j<i;j++)
	{
		if(i%j == 0)
		{
		       printf("This number is not a Prime number%d\n",num);
		//	count ++;
		}

	}
	if(count == 0)
	{
		printf("This number is a Prime number%d",num);
	}
}
