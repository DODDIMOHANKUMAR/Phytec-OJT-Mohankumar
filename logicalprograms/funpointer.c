#include<stdio.h>

int sum(int,int);
int mul(int,int);
int div(int,int);
int sub(int,int);

void main()
{

	int s,m,d,st;
	
	int (*ptr)(int,int)= &sum;
	s =(*ptr)(30,40);
	int (*ptr1)(int,int)= &mul;
	m =(*ptr1)(10,5);
	int (*ptr2)(int,int)= &div;
	d =(*ptr2)(20,10);
	int (*ptr3)(int,int)= &sub;
        st =(*ptr3)(20,10);
	printf("sum = %d\n",s);
	printf("mul = %d\n",m);
        printf("div = %d\n",d);
        printf("sub = %d\n",st);


}

int sum(int a,int b)
{
	return a+b;

}

int mul(int a,int b)
{
	return a*b;
}
int div(int a,int b)
{
        return a/b;
}
int sub(int a,int b)
{
        return a-b;
}


