#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#pragma warning(disable: 4996)

int a_cmp(int);

int anagram(char *,char *);

char * malloc_char(char *);

void parent_anagram(char *);


struct test
{
	char input1[40];
	char input2[40];
}testDB[2]={{{"rrar"},{"rarr"}},
			{{"raghu"},{"ragha"}}};

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



int a_cmp(int a)
{
	if(a==0)
		return 0;
	else
		return 1;
}



int anagram(char a[],char b[])
{
	int *temp1,i,*temp2;

	temp1=(int *)calloc(sizeof(int)*26);
	temp2=(int *)calloc(sizeof(int)*26);

	for(i=0;a[i]!='\0';i++)
	{
		temp1[a[i]]++;
		temp2[a[i]]++;
	}

	for(i=0;a[i]!='\0';i++)
	{
		if(temp1[a[i]]!=temp2[b[i]])
			return 1;
	}
	return 0;
}



void testcases()
{
	int i,check,op;
	char *a,*b;
	
	for(i=0;i<2;i++)
	{
		a=malloc_char(testDB[i].input1);
		b=malloc_char(testDB[i].input2);

		op=anagram(a,b);
		printf("%d",op);

		check=a_cmp(op);

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
