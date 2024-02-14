    #include<stdio.h>    
    #include<stdlib.h>  


int Binary()
{  
    int n,i;
    static int a[10];    
    printf("Enter the number to convert: ");    
    scanf("%d",&n);    
    for(i =0;n>0;i++)
    {
	    a[i] =n%2;
	    n =n/2;
    }
    printf("this is the Decimal number convert =");
     for(i =i-1;i>=0;i--)
    {
	    printf("%d",a[i]);
    }
    return 0;

}

int Decimal()
{
	int num,decimal=0,binary,rem,base =1;
	
	printf("Enter the  NUmber:");
	scanf("%d",&num);
	binary =num;
	
	while(num>0)
	{
		rem =num%10;
		decimal =decimal+rem*base;
		num =num/10;
		base =base*2;
	}
	printf("Enter the Binary number %d",binary);
	printf("This is Decimal number %d",decimal);

	return 0;
}

			
int main()
{
   Binary();
   Decimal();
}

