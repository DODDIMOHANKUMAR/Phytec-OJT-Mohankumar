#include<stdio.h>

int main()
{
        int i,sum =0,m,n;
        printf("Enter the number =");
        scanf("%d",&n);
        

        while(n>0)
        {
                m =n%10;
                sum =sum+m; //logic
                n =n/10;
        }
         printf("this is sum of digit%d",sum);
          return 0;
}
                                                                                                                                                                                                          
                                                                                                                                                                                                          
                   
