#include<stdio.h>    
#include<stdlib.h>  


int alpbhat()
{  
    char  ch =65;
    int i,j,k,n;      
    for(i=1;i<=5;i++)    
    {   

        for(j=i;j<=5;j++)    
            	printf(" ");
        for(k=1;k<=i;k++)    
            printf("%c " ,ch++);     
            printf("\n");    
        ch =65;
    }    
return 0;  
}
int number()
{
	int l =1;
	int i,j,k,n;
	for(i =1;i<=5;i++)
	{
		for(j =i;j<=5;j++)
		printf(" ");
		for(k =1;k<=i;k++)
			printf("%d ",l++);
		printf("\n");
		l =1;
	}
	return 0;
}

int fact()
{
	int a =0,b =1,i,j,n,c;

	printf("Enter the your Range =");
	scanf("%d",&n);
	for(i =1;i<=n;i++)
	{
	   a =0;
	   b =1;
           printf("%d\t",b);
	
	for(j =1;j<i;j++)
	{
		
	    c =a+b;
	    printf("%d\t",c);

		a =b;
		b =c;
	} 
	printf("\n");
	}
        return 0;
}

int convert()
{
	int r,n,sum =0;
	printf("Enter the number");
	scanf("%d",&n);

	while(n>0)
	{
		r=n%10;
		sum =sum*10+r;
		n =n/10;
		n =sum;

		while(n>0)
		{
			r =n%10;
		}

		switch(r) 
case1:
		printf("one");
		break;
case2:
		printf("two");
		break;
case3:
		printf("three");
		break;
case4:
		printf("four");
		break;
case5:
		printf("five");
		break;
case6:
		printf("six");
		break;
case7:
		printf("seven");
		break;
case8:
		printf("eight");
		break;
case9:
		printf("nine");
		break;
case10:
		printf("zero");
		break;

defult:
		printf("mm");
		break;

		printf("%c",sum);
	}
	n =n/10;

  return 0;
}


int main()
{
   alpbhat();
   number();
   fact();
   convert();
}
