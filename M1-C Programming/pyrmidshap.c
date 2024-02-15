#include<stdio.h>

int main()
{
  int i,j,rows;
  printf("Enter the  rows:");
  scanf("%d",&rows);
 
  for(int i=1;i<=rows;++i)
  {
	  for(int j=1;j<=i;j++) //half pyramid
        {
	
		
            //printf("%d",i);
	    printf("%d",j); 
	  
	
	}
	 printf("\n");
  }
  
   return 0;
}





