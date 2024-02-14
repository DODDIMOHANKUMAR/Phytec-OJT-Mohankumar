#include<stdio.h>
#include<string.h>

int number()
{
	int i,n,reverse =0,r;
	printf("this Reverse numbers");
	scanf("%d",&n);
      
	while(n!=0)
	{
		r =n%10;
		reverse =reverse*10 +r;
		n =n/10;
	}
	printf("This is Reverse Number %d",reverse);
	return 0;
}

int word()
{
           
	int temp,length,i;
	char A[10] ="mohan";
	length =strlen[A];
	for(i =0;i<length;i++)
	{
	temp =A[i];
	A[i] =A[length-i-1];
	A[length-i-1] =temp;
	}

}
printf("This is Reverse %c",A[i]);
return 0;
}


int main()
{
	number();
	word();
}
