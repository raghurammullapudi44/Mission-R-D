#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int a_amp(int *,int *);

char * match(char *,char *);

char * malloc_char(char *);


struct test
{
	char input1[40];
	char input2[40];
	char output[40];
}testDB[11]={{{"rrar"},{"rlar"},{"rar"}},
		{{"raaghu"},{"raghu"},{"ra"}},
		{{"rrr"},{"r"},{"r"}},
		{{"mmmAullAPud"},{"mulAPudi"},{"mA"}},
		{{"\0"},{"suresH"},{"\0"}},
		{{"babu"},{"baboou"},{"bab"}},
		{{"    "},{"    "},{"    "}},
		{{"    aAAAaA"},{" a"},{" "}},
		{{"b1223  "},{"b123 "},{"b12"}},
		{{"A    U\0    "},{"A U"},{"A "}},
		{{"\0"},{"a"},{"\0"}}};

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


char * match(char *a,char *b)
{
	int i,j=0;
	char *c;

	c=(char *)malloc(sizeof(char)*1);

	for(i=0;a[i]!='\0' || b[i]!='\0';i++)
	{
		if(a[i]==b[i])
		{
			c[j++]=a[i];
			c=(char *)realloc(c,sizeof(char)*j);
		}
	}

	c[j]='\0';

	return c;
}



void testcases()
{
	int i,check,j;
	char *a,*b,*c;
	
	for(i=0;i<11;i++)
	{
		a=malloc_char(testDB[i].input1);
		b=malloc_char(testDB[i].input2);

		if((a[0]=='\0' && b[0]!='\0') || (a[0]!='\0' && b[0]=='\0'))
		{
			c=(char *)malloc(sizeof(char)*1);
			c[0]='\0';
		}

		if(a[0]!='\0' && b[0]!='\0')
			c=match(a,b);

		check=a_cmp(c,testDB[i].output);

		if(check==0)
			printf("passed\n");
		else 
			printf("failed\n");

		free(c);
		
	}
}

int main()
{
	testcases();
	return 0;
}
