#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable: 4996)
int fun(char *);
int main()
{
	char *s1;
	int n,sum;
	printf("enter size:");
	scanf("%d",&n);
	s1=(char *)malloc(n*sizeof(char));
	fflush(stdin);
	gets(s1);
	sum=fun(s1);
	printf("%d",sum);
	getch();
	return 0;
}
int fun(char *s1)
{
	int sum=0,i;
	for(i=0;s1[i]!='\0';i++)
		sum=sum+s1[i];
	return sum;
}