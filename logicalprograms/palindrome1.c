#include<stdio.h>

int main()
{
	int i,r,num,temp,sum =0;
	printf("Enter the number =");
	scanf("%d",&num);
	temp =num;

	while(num>0)
	{
	  r =num%10;
	  sum =(sum*10) +r;
	  num =num/10;
	}
	if(temp==sum)
	
		printf("this is Palindrome number");
		else 
	
		printf("This is not a Palindrome number");
		return 0;
	
}
