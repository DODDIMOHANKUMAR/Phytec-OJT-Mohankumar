#include<stdio.h>

int main()
{
	int i,num,fact =1;
	printf("Enter the number fact=");
	scanf("%d",&num);
	for(int i =1;i<=num;i++)
	{
		fact =fact*i;
	}
	printf("This is fact%d number%d",num,fact);
        return 0;
}	
