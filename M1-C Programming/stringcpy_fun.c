#include<stdio.h>
#include<string.h>

int main()
{
  char str[100];
  printf("Enter the string copy\n");
  fgets(str,sizeof(str),stdin);
  //fgets(str);
  char dest[100];
  strcpy(dest,str);
  printf("This is A string copy:%s\n",dest);
  return 0;
}
