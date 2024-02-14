#include<stdio.h>
#include<malloc.h>


int main()
{
int *ptr=NULL;
int size,max;
printf("Enter size\n");
scanf("%d",&size);//20
ptr=(int *)malloc(size*sizeof(int));
char *p1=(char *)malloc(size*sizeof(char));

while(ptr>0)
{
	printf("Enter %d numbers",size);
	for(int i=0;i<size;i++)
		scanf("%d",ptr+i);
	int max=*ptr;
	for(int i=1;i<size;i++)
	{
		if(*(ptr+i) > max){
			max=*(ptr+i);
	}

}         printf("Max Value = %d\n",max);

	else
	{
	printf("alloaction failure\n");
	}
   return 0;
}
        



