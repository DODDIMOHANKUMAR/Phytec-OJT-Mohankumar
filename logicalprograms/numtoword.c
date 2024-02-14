#include<stdio.h>
#include<string.h>


int main()
{
	int r,n,sum =0;
	printf("Enter the number");
	scanf("%d",&n);

	while(n>0)
	{
		r=n%10;
		//sum =sum*10+r;
	//	n =n/10;
	//	n =sum;
		switch(r)
		{	
case1:
		printf("one");
		break;
case2:
		printf("two");
		break;
case3:
		printf("three");
		break;
case4:
		printf("four");
		break;
case5:
		printf("five");
		break;
case6:
		printf("six");
		break;
case7:
		printf("seven");
		break;
case8:
		printf("eight");
		break;
case9:
		printf("nine");
		break;
case10:
		printf("zero");
		break;

default:
		printf("mm");
		break;

		sum=sum*10+r;
		n =n/10;
		}
		}		
			
  return 0;



}
