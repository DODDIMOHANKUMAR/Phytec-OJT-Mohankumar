#include<stdio.h>

int main()
{
	 int fect = 1,n,i;
	 printf("Enter the fect number");
	 scanf("%d",&n);
	 
	 for(int i =1;i<=n;i++)
	 {
		 fect = fect*i;
	 }
	 printf("The fectorial %d is %d",n,fect);
	 return 0;
}
