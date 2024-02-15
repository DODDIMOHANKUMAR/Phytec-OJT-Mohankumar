#include<stdio.h>

int main()
{
	int fact =1,i,n,sum =0;
	printf("Enter the Range if the number :\n");
	scanf("%d",&n);
	for(int i =1 ;i<=n;i++){
		for( int j=1;j<=i;j++);{
	        fact = fact * i;
		}
		sum =sum + fact;
	}
	printf("find out the factorial number %d\n",sum);
	return 0;
}
