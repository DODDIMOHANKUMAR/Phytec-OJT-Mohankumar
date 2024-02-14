#include<stdio.h>

int main()
{
	while(1)
	{
		int year;
		printf("Enter the Year");
		scanf("%d",&year);
		if(year%400==0 ||year%4 ==0 &&year%100!=0)
			printf("this is a lep year %d",year);
		else
			printf("this not a lep year %d",year);

	}
		return 0;
}

