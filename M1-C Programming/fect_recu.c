#include<stdio.h>



long  fact(int n)
{
	if(n==0)
	{
		return 1;
	}
	else
	{
		return(n*fact(n-1));
	}
}
void main()
{
   int n;
   long fact;
   printf("Enter the fect number");
   scanf("%d",&n);
   fact = fact(n);
    printf("this is fact number %d is %d\n",n,fact);
    return 0;
   }




