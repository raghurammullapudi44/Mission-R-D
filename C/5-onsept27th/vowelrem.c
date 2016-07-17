#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int a_amp(int *,int *);

void  vowelrem(char *);

char * malloc_char(char *);

struct test
{
	char input[20];
	char output[20];
}testDB[11]={{{"mullApudi"},{"mllpd"}},
		{{"raghu"},{"rgh"}},
		{{"ram"},{"rm"}},
		{{"mullaPudi raghu ram"},{"mllPd rgh rm"}},
		{{"suresh"},{"srsh"}},
		{{"baBu"},{"bB"}},
		{{"    "},{"    "}},
		{{"    a"},{"    "}},
		{{"b    "},{"b    "}},
		{{"AeIoU\0    "},{"\0"}},
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



void  vowelrem(char a[])
{
	int i,j=0;
	
	for(i=0;a[i]!='\0';i++)
	{
			if(a[i]!='a' && a[i]!='e' && a[i]!='i' && a[i]!='o' && a[i]!='u' && a[i]!='A' && a[i]!='E' && a[i]!='I' && a[i]!='O' && a[i]!='U')
				a[j++]=a[i];
			
	}
	
	a[j]='\0';

	a=(char *)realloc(a,sizeof(char)*(j+1));
	
}

void testcases()
{
	int i,check,j,len;
	char *a;
	
	for(i=0;i<11;i++)
	{
		a=malloc_char(testDB[i].input);
		
		if(a[0]!='\0')
			vowelrem(a);

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
	return 0;
}
