#include<stdio.h>
#include<string.h>

void stringdata()

{
	int i;
	char A[30] = "This is A Cprogramming";
	char B[20] = "Hello SBCS";
	printf("string A = %s\n",A);
	printf("string B =%s\n",B);
	//A = B;
	for(int i=0;A[i] ='\0';i++)
	{
		A[i] = B[i];
	}
	B[i] ='\0';


}
int main()
{
	stringdata();
	return 0;
}

