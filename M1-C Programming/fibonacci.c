#include<stdio.h>


int main()
{
  
 int n1 =0,n2 = 1,n3,num;
 printf("Enter the fiboncci number:");
 scanf("%d",&num);
 printf("\n%d\n%d\n",n1,n2);
 for(int i=2;i<num;++i)
 {
	 n3 = n1+n2;
	// printf("%d",n3);
	 n1 = n2;
	 n2 = n3;

	 printf("%d\n",n3);
 }
 return 0;
}
