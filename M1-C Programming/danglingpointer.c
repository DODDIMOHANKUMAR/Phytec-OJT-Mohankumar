#include<stdio.h>
#include<stdlib.h>


void main()
{
	int *ptr =(int*)malloc(sizeof(int));
	*ptr = 20;
	printf("%d\n",*ptr);
	free(ptr);
       *ptr =NULL;
	printf("%d\n",*ptr);
	
}
