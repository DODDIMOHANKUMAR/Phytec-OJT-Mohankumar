#include<stdio.h>
void main()
{
	int x,y;
	printf("enter num1 and num2\n");
	scanf("%d %d",&x,&y);
	x=x+y;
	y=x-y;
	x=x-y;
	printf("x= %d,y=%d\n",x,y);
}
