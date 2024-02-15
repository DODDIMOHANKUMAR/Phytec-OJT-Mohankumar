#include<stdio.h>
#include<stdlib.h>


void  main()
{
       // int a = 10;
	int *ptr =(int*)malloc(sizeof(int));
	*ptr = 70;
	printf("%d\n",*ptr);
}




