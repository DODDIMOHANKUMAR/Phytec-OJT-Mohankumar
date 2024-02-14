#include<stdio.h>

int main()
{
	int i,n,r,temp,sum =0;
	printf("The Enter the Number =");
	scanf("%d",&n);
        temp =n;
	while(n >0)
	{
          r =n%10;
	  sum =(sum*10)+r;
	  n =n/10;
	}
	if(temp ==sum)
	{
		printf("This is Palindramo number");
	}
	   else 
	   {
		printf("Does't Palindramo number");
           }
	
	return 0;
}

