#include<stdio.h>

int main()
{
  int i,j,rows;
  printf("Enter the  Pyramid:");
  scanf("%d",&rows);
  for(int i=1;i<=rows;++i)
  {
	  for(int j =1;j<=i;++j) //half pyramid
         // for(int j =i;j<=rows;++j) //Reverse half pyramid
	  {
            printf("* ");// Printing *
	    printf("%d",i);// Printing of the 1,22,333,4444, Thisi is half Pyaramid shap
	    printf("%d",j);//This is Printing 1,12,123,1234, This is  ''   '' 
	  }
   printf("\n");
  }
  return 0;


}
