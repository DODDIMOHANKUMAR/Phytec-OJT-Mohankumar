#include<stdio.h>


int main()
{
	int rows,n = 1;
       //  printf("Enter the fullpyramid:");
	// scanf("%d",&rows);
	 for(int i =1;i<=rows;i++)
	 {
	 for(int j =1;j<=rows-i;j++)
	 {
		 printf(" ");
	 }
		 for(int k =1;k<=i;k++)
		
			 {
				 if(n<=10){
				 printf("%d",n);
				 }
				 //printf("%d",i);
				 
			 }
		 
		 printf("\n");
	 }
		 return 0;

}


