#include<stdio.h>

int main()
{
  int i,j,rows;
  printf("Enter the  Pyramid:");
  scanf("%d",&rows);
  for(int i=1;i<=rows;++i)
  {
	 for(int j =rows-i+1;j>0;++j) //half pyramid
         // for(int j =i;j<=rows;++j) //Reverse half pyramid
	  {
            printf("%C",'A'+(j-1));// Printing *
	  
	  }
   printf("\n");
  }
  return 0;


}




