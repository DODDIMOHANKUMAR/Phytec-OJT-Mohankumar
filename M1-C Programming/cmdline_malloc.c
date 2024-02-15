#include<stdio.h>
#include<stdlib.h>


int main(int argc,int *argv)
{
   int n ;
   printf("Number of cmd line Arguments:%d\n",argc);
   printf("%p\n",argv[1]);
   char *p = (char *)malloc(10);

    printf("stack  %p\n",&p);
    printf("heap %p\n",p);

   for(int i =0;i<n;i++)
   {

        printf("argv[%d]%s\n",i,argv[i]);
   }
	  

	  
   }

