#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int fun(char *);
int main()
{
	char *s;
	int x;
	s=(char *)malloc(sizeof(char)*44);
	int i;
	gets_s(s);
	x=fun(s);
	printf("%d",x);
	free(s);
	_getch();
	return 0;
}
int fun(char *s)
{
	int i=0;
	while(*s[i]!='\0')
	{
		i++;
	}
	return i;
}
