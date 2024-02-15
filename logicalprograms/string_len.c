#include<stdio.h>
#include<string.h>


int  stringlen(const char * str)

{
    int size  = 0;
    while (str(size)! ='\0'){
	    size ++;
  }
}
int main()
{
    const char*string = "Hello SBCS";
    int size = stringlen(string);
    printf("length of String :%d\n",size);
    return 0;
}
