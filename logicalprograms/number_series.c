#include<stdio.h>
void main()
{
	int range;
	printf("enter range\n");
	scanf("%d",&range);
	int count=1;
	while(count<=range)
	{
		if(count%2!=0)

			printf("%d ",count);
		else if(count==2)
			printf("%d ",count);
		else 
			printf("%d ",count+4);
			count++;
	
	}
}
