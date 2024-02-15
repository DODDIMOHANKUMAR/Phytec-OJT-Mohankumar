#include<stdio.h>
#include<string.h>
void main()
{
	char str[100];
	int temp;
	printf("enter string:\n");
	scanf("%s",str);
	for(int j=0;str[j]!='\0';j++)
	{
		for(int k=j+1;str[k]!='\0';k++)
		{
		if(str[j]>str[k])
		{
			temp=str[j];
			str[j]=str[k];
			str[k]=temp;
		}
	}
	}
	 /*for(int i=0;str[i]!='\0';i++)
	 {
		 printf("%c",str[i]);
	 }*/
	printf("%s\n",str);
}


