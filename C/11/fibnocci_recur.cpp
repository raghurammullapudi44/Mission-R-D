#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#pragma warning(disable: 4996)

int fib(int);

void series(int);

int main()
{
	int n,i=0;
	printf("enter the number:");
	scanf("%d",&n);
	
	series(n);

	getch();
	return 0;
}

void series(int n)
{
	static int i=0;
	if(i<n)
	{
		printf("%d ",fib(i));
		i++;
		series(n);
	}
}

int fib(int n)
{
	if(n==1 || n==0)
	{
		return 0;
	}
	else if(n==2)
	{
		return 1;
	}
	else
		return (fib(n-1)+fib(n-2));
}