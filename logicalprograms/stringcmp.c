#include<stdio.h>
#include<string.h>

int main()
{
	char str1[] = "hello";
	char str2[] = "Cprogram";
	int result = strcmp(str1,str2);
	if(result == 0)
	{
		printf("This string is Equal\n");
	}

	else if(result < 0)
	{
		printf("str1 is compare to str2 is Graterthan.\n");
	}
	else
	{
		printf("str2 is compare to str1 is Graterthan.\n");
	}
	return 0;
}
