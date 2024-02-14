#include<stdio.h>

int main()
{
	static int  i = 7;
	 while(i ==7)
	 {
		 i = i*2;
		 i--;
	 }
	 printf("%d",i);
	 return 0;
}

