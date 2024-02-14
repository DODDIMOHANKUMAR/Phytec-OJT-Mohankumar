#include <stdio.h>
int main()
{
  int c = 0, count = 0;
  char s[1000];
  printf("Input a string\n");
  gets(s);
  while (s[c] != '\0') {
    if (s[c] == 'a' || s[c] == 'e' ||  s[c] == 'i'  || s[c] == 'o' || s[c] == 'u' )
      count++;
    c++;
  }
  printf("Number of vowels in the string: %d", count);
  return 0;
}





