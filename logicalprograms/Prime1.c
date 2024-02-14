#include<stdio.h>

/*int prime()
{
    int i,j,count =0,num;
    printf("Enter the number");
    scanf("%d",&num);
    for(int i =2;i<num;i++)
    {
        if(num%i==0)
         count++;
    }
    if(count ==0)
    printf("This number is the Prime Number %d",num);
    else
    printf("This number is not a Prime Number %d",num);
}*/

int range()
{
	int i,j,count =0,n;
	printf("Enter the Range of Prime");
	scanf("%d",&n);
	for(i =2;i<n;i++)
	{  
		count==0;

		for(j=1;j<i;j++)
		{
		   if(i%j==0)
	             count++;
		}
		if(count ==1)
		printf("The Range of the Prime number%d",i);
	}
}

int main()
{
//	prime();
	range();
}
                   
