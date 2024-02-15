#include<stdio.h>
void main()
{
	int rows,colum;
	printf("enter rows  and colums\n");
	scanf("%d %d",&rows,&colum);
	for(int i=1;i<=rows;i++)
	{
		for(int j=1;j<=colum;j++)
		{
			if((i==1)||(i==rows)||(j==1)||(j==rows))
			{
				printf("*");
			}
			else if ((i<=j)||(j!=rows))
			{
		            printf(" ");
			}

		}
		printf("\n");
	}

}

