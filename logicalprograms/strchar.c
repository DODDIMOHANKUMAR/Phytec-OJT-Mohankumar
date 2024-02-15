#include<stdio.h>
#include<string.h>

int main()
{
   char str[] ="This is string char";
   char ch[] = "l";
   char *ptr;
   printf("This is Orginal string");
   ptr = strchr(str,ch);
   printf("This is First occurrance of the'%c' is '%s' string'%s'",ch,str,ptr);
   return 0;

  }
