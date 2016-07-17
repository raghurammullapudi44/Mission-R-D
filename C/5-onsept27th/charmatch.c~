#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int a_amp(int *,int *);

char * match(char *,char *);

char * malloc_char(char *);

int repeat(char *,char);


struct test
{
	char input1[40];
	char input2[40];
	char output[40];
}testDB[11]={{{"rama"},{"mars"},{"ram"}},
		{{"raaghu"},{"raghu"},{"raghu"}},
		{{"rrr"},{"r"},{"r"}},
		{{"mmmAullAPudh"},{"mulAPudi"},{"mAulPd"}},
		{{"\0"},{"suresH"},{"\0"}},
		{{"babu"},{"baboou"},{"bau"}},
		{{"    "},{"    "},{" "}},
		{{"    aAAAaA"},{" abA"},{" aA"}},
		{{"b1223  "},{"b123 "},{"b123 "}},
		{{"A    U\0    "},{"A U"},{"A U"}},
		{{"\0"},{"\0"},{"\0"}}};

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
	int i,j,k=0;

	char *c=(char *)malloc(sizeof(char)*1);
	
	for(i=0;a[i]!='\0';i++)
	{
		for(j=0;b[j]!='\0';j++)
		{
			if((a[i]==b[j]) && (repeat(c,a[i])!=0))
			{
				
		     			c[k++]=a[i];
					c=(char *)realloc(c,sizeof(char)*k);
					break;
			}
		}
	}
	c[k]='\0';
return c;
}

int repeat(char c[],char b)
{
	int i;
	
	for(i=0;c[i]!='\0';i++)
	{
		if(b==c[i])
			return 0;
	}
return 1;
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
