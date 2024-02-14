#include<stdio.h>

/*int modify()
{
	int a =4 ,b =5;
	b =a++ + a--;
	a =++b + b--;
	printf("%d,%d",a,b);
}*/
int opertors()
{
	int x =20,y =10,z =5,f,g;
	f =x>z>y;
	g =z-y>x<=y;
	printf("%d,%d",f,g);
}


int main()
{
	//modify();
	opertors();
}
