#include<stdio.h>
#include<string.h>

void main()
{
	int i,l;
	char str[50],c;
	printf("Enter the String Name:\n");
	gets(str);
	l =strlen(str);
	for(i =0;i<l/2;i++)
	{
		c = str[i];
		str[i] = str[l-1-i];
		str[l-1-i] = c;
	}
	
	printf("%s",str);
	
}

