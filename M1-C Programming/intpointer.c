#include<stdio.h>

int main()
{
int a =10;
int *ptr;

ptr = &a;

printf("value of a = %d\n",a);
printf("value stored at ptr = %d\n",*ptr);
printf("Address of a = %x\n",&a);
printf("ptr points to the address = %x\n",ptr);
printf("Address of ptr = %x\n",&ptr);

return 0;

}
