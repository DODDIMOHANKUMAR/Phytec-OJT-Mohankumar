#include <stdio.h>
 

int largest(int arr[], int n)
{
    int i;
    int max = arr[0];
 
    
    for (i = 1; i < n; i++)
    {
        if (arr[i] > max)
           max = arr[i];
    }
 
    return max;
}
int lowest(int arr1[0],int n1)
{
	int i; 
	int min = arr1[0];

	for(int i =0;i<n1;i++)
	{
		if(arr1[i] < min)
		  min = arr1[i];
	}
	return min;

 
}
int main()
{
    int arr[] = {10,30,20,40,60,55 };
    int arr1[] = {12,13,2,5,6,8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
   
    
    printf("Largest in given array is %d", largest(arr, n));
    printf("\n");
    printf("lowest values in Array is %d",lowest(arr1, n1));
    return 0;
}
 



	
