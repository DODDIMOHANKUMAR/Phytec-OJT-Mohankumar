#include<stdio.h>

int main()
{
   int *p,n;
   printf("Enter number:\n");
   scanf("%d",&n);
   p=&n;
   printf("address:%p\n",p);
   printf("value:%d\n",*p);
   return 0;
}



