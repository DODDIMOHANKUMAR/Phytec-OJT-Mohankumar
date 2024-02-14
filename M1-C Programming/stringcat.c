#include<stdio.h>
#include<string.h>

int main()
{
	char str1[50];
	char str2[50];
	printf("This is A String cat function using three strings Adding\n");
        scanf("%s%s",str1,str2);
	strcat(str1,str2);
	printf("This is A String catenation:%s\n",str1,str2);
	return 0;
}
