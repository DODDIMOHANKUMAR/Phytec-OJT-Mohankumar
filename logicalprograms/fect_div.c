#include<stdio.h>
void main()
{
	int num,min,max,sum=0,fact =1;
	printf("Enter fact numbe min and max:\n");
	scanf("%d %d",&min,&max);
	for(int i=min;i<=max;i++)
	{
		for(int j=1;j<=i;j++)
		{
			fact=(fact*j);
		}
		fact=fact/i;
		sum=sum+fact;
	}
	printf("%d\n",sum);
}
