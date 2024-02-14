#include<stdio.h>


int main()
{
	int res =0,rem = 0,temp,num;
	printf("Enter the number");
	scanf("%d",&num);

	temp = num;
	while(num > 0)
	{

	rem = num % 10;
	res = res + rem*rem*rem;
	num = num/10;
    }
	 if(temp == res){

	printf("This is a Armstrong numbers %d\n",temp);
	 }
	 else
	 {
	   printf("This is not a Armstrong number%d\n",temp);
	 }
	return 0;
}
