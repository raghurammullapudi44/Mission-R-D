#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int a_amp(int *,int *);

void repcount(char *);

char * malloc_char(char *);

int insertcount(char *,int,int);

struct test
{
	char input[40];
	char output[40];
}testDB[11]={{{"rrar"},{"r2ar"}},
		{{"raaaaaaaaaaghu"},{"ra10ghu"}},
		{{"rrr"},{"r3"}},
		{{"mmmullaapudi"},{"m3ul2a2pudi"}},
		{{"surrreshh"},{"sur3esh2"}},
		{{"babuuuuu"},{"babu5"}},
		{{"abc"},{"abc"}},
		{{"aaaaaaaaaaaaaaa"},{"a15"}},
		{{"b"},{"b"}},
		{{"au\0    "},{"au"}},
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



void repcount(char a[])
{
	int i,j=1,count=1,flag=0;

	if(a[1]!='\0')
	{
		for(i=1;a[i]!='\0';i++)
		{		

			flag=0;

			if(a[i]!=a[i-1])
			{
				if(count>1)
				{
					j=insertcount(a,count,j);
					a[j++]=a[i];
				}
				else
					a[j++]=a[i];

				count=1;

				flag=1;
			}
			else
				count++;
		}
	
		if(flag==0)
			j=insertcount(a,count,j);
	
		a[j]='\0';

		a=(char *)realloc(a,sizeof(char)*(j+1));
	}
}

int insertcount(char a[],int count,int j)
{
	if(count<=9)
		a[j++]=count+'0';
	else
	{
		a[j++]=(count/10)+'0';
		a[j++]=(count%10)+'0';
	}
return j;
}

void testcases()
{
	int i,check,j;
	char *a;
	
	for(i=0;i<11;i++)
	{
		a=malloc_char(testDB[i].input);

		if(a[0]!='\0')
			repcount(a);

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
