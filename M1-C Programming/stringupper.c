#include<stdio.h>
#include<string.h>


int main()
{
	char str[] = "Hello,SBCS!";
	printf("This is orginal string:%s\n",str);
	strupr(str);
	printf("Upper Case string:%s\n",str);
	return 0;
}
