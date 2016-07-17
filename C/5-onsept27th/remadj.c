#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#pragma warning(disable: 4996)

int a_amp(int *,int *);

void remdj(char *);

char * malloc_char(char *);

int equal(char,char);

struct test
{
	char input[40];
	char output[40];
}testDB[11]={{{"rrar"},{"rar"}},
		{{"r  aagh  u"},{"r agh u"}},
		{{"rrr"},{"r"}},
		{{"mmmMullAaPudi"},{"mulAPudi"}},
		{{"surrresHh"},{"suresH"}},
		{{"baBuUUUU"},{"baBu"}},
		{{"    "},{" "}},
		{{"    aAAAaA"},{" a"}},
		{{"b1223  "},{"b123 "}},
		{{"A    U\0    "},{"A U"}},
		{{"\0"},{"\0"}}};

char * malloc_char(char ip[])
{
	int i;
	char *a;
	a=(char *)malloc(sizeof(char)*1);
	for(i=0;ip[i]!='\0';i++)
	{
		a[i]=ip[i];
		a=(char *)realloc(a,sizeof(int)*(i+1));
	}
	a[i]='\0';
	return a;
}



int a_cmp(char a[],char b[])
{
	if(strcmp(a,b)==0)
		return 0;
	else
		return 1;
}



void remadj(char a[])
{
	int i,j=1;
	
	for(i=1;a[i]!='\0';i++)
	{
			
			if(equal(a[i],a[i-1])!=0)
				a[j++]=a[i];
	}
	
	a[j]='\0';

	a=(char *)realloc(a,sizeof(char)*(j+1));
	
}

int equal(char a,char b)
{
	if(a>='A' && a<='Z')
		a=a+32;
	if(b>='A' && b<='Z')
		b=b+32;
	if(a==b)
		return 0;
	else
		return 1;
}

void testcases()
{
	int i,check,j;
	char *a;
	
	for(i=0;i<11;i++)
	{
		a=malloc_char(testDB[i].input);

		if(a[0]!='\0')
			remadj(a);

		check=a_cmp(a,testDB[i].output);

		if(check==0)
			printf("passed\n");
		else 
			printf("failed\n");
		
	}
}

int main()
{
	testcases();
	getch();
	return 0;
}
