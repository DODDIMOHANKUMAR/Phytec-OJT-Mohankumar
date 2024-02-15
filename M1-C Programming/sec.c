#include<stdio.h>

int main()
{
	int s,m,h,rs;
	printf("Enter the number of seconds is taken: ");
	scanf("%d", &s);

	h = s/3600;
	m = (s % 3600) /60;
	rs = s % 60;

	printf("Equivalent time: %d hour ,%d minute, %d reminig sencond\n",h,m,rs);
	
	return 0;
}
