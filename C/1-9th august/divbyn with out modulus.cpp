#include<stdio.h>
#include<conio.h>
int fun(int *);
int main()
{
	int n,x;
	scanf_s("%d",&n);
	x=fun(&n);
	if(x==1)
		printf("yes");
	else
		printf("no");
	_getch();
	return 0;
}
int fun(int *n)
{
	while(*n>0)
	
		*n-=11;
	while(*n<0)
		*n+=11;
	if(*n==0)
		return 1;
	else 
		return 0;
}
