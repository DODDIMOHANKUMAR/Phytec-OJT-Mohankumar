#include<stdio.h>

int main()

{
	int rem = 0,result=0,base=1,num;

	printf("Enter the Binary  Number to Decimal  number :");
	scanf("%d",&num);
	while(num > 0)
	{
		rem = num%16;
		result = result + rem *base;
		base = base*2;
		num = num/16;
	}

 	printf("find out Decimal  Code %d\n",result);
        return 0;
}




