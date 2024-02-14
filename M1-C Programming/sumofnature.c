#include<stdio.h>

int main()
{
  int i,sum = 0,n;
  printf("Enter the Sum of Natural Numaber");
  scanf("%d",&n);

  for(int i =1;i<=n;i++)
  {
	  sum += i;
  }
  printf("find out the Sum  of Nature number %d\n",sum);
  return 0;
}
