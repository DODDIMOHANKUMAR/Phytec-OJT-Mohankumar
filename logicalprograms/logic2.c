#include<stdio.h>

int main()
{
	 int n =24;
	for(int c =1;n>0; c++)
	{
		if(n%c == 0)
		{
			printf("%d",n);
			n = n/c;
		}
		return 0;
	}
	  
}
