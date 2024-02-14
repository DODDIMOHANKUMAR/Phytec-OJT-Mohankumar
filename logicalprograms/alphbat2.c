#include<stdio.h>
#include<string.h>

int main()
{
  
  int i,j,k,n,length;
  char s[] ="mohankumar from sbcs!";
  length =strlen(s);
  printf("Enter the Range if Traingle =");
  scanf("%d",&n);
  for(i =1;i<=n;i++)
  {
	  for(j =i;j<=n;j++)
	  {
		  printf(" ");
	  }
	  for(k =0;k<=i;k++)
	  {
	     printf("%c ",s[k]);
	  }
	  printf("\n");
           
  }
  return 0;
}


