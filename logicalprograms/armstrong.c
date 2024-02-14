#include<stdio.h>

int main()
{
	int i,sum =0,r,temp,n;
	printf("Enter the number =");
	scanf("%d",&n);
	temp = n;

	while(n>0)
	{
		r =n%10;
		sum =sum+(r*r*r*r); //logic
		n =n/10;
	}
	if(temp==sum)
	
	  printf("this is Armstrong number");
          else 
		  printf("this is not a Armstrong number");
	  return 0;
}
