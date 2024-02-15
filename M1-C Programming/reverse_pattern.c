#include<stdio.h>

int main()
{
	int n;
	printf("Enter the number rows pattern");
	scanf("%d",&n);
	foir(int i =1;i<=n;i++)
	{
	  for(int s =1;s<=n-i;s++)
           { 
		 printf(" ");
	   }	 
		  for(int j =1;j<=i*2-1;j++)
		  {
			  printf("*");
		  }
	  
	  
          printf("\n");
	  
	}
	return 0;
}
       


