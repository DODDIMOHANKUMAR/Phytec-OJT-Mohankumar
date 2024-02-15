#include<stdio.h>
void main()
{
	int mat[2][2];

	int mat1[2][2];
	printf("enter mat1\n");
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			mat1[j][i]=mat[i][j];
		}
	}
	printf("\n");
	 for(int i=0;i<2;i++)
        {
                for(int j=0;j<2;j++)
                {
                       printf("%d ",mat1[i][j]);
                }
		printf("\n");

        }

}
