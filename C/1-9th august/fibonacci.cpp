#include<stdio.h>
#include<conio.h>
int fun(int);
int main()
{
	int n;
	scanf_s("%d",&n);
	printf("%dth fibonacci number is :%d",n,fun(n));
	_getch();
	return 0;
}
int fun(int n)
{
	if(n==1)
		return 0;
	else if(n==2)
		return 1;
	else
	return (fun(n-1)+fun(n-2));
}