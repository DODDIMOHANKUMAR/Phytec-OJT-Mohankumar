#include<stdio.h>


int main()
{
	int i,j,temp,n;

	int arr[] = {1,5,6,7,8,2,3,9};
	for(int i = 0;i<7;i++)
	{
		for(int j =0;j<i+1;j++)
		{
			if(arr[i]<arr[j])
			{
			   temp = arr[i];
			   arr[i] = arr[j];
			   arr[j] = temp;
			}
		}
	}
	for(int i =0;i<1;i++)
	{
	printf("%d",arr[6]);

	}	
          return 0;
}


		

