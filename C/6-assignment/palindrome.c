#include<stdio.h>
#include<stdlib.h>

char * malloc_char(char *);

int a_amp(char **,char **);

void realloc_char(char **,int);

void stringcopy(char *,char *);

int palindrome(char *,int);

char ** words(char *);

void testcases();

struct test
{
	char input[44];
	char output[44][44];
}testDB[10]={{{"my soap is liril"},{"liril"}},
		{{"my name is nitin"},{"nitin"}},
		{{"nitin usesu liril soap"},{"nitin","usesu","liril"}},
		{{"RAGHU m u l l a p u d i"},{"NULL"}},
		{{"Stack cats"},{"NULL"}},					
		{{"bob is an american civic"},{"bob","civic"}},
		{{"liril andna dd"},{"liril","andna"}},
		{{"madam has only one eye with radar"},{"madam","eye","radar"}},
		{{"dddd dd ddd"},{"dddd","ddd"}},					
		{{"VVVv good racecar"},{"racecar"}}};

char * malloc_char(char ip[])
{
	int i;
	char *a;
	a=(char *)malloc(sizeof(char)*1);
	for(i=0;ip[i]!='\0';i++)
	{
		a=(char *)realloc(a,sizeof(char)*(i+1));
		a[i]=ip[i];
	}
	a[i]='\0';
	return a;
}

int a_cmp(char *a,char *b)
{
	if(strcmp(a,b)==0)
		return 0;
	else
		return 1;
}

void realloc_char(char **c,int k)
{
	int i;
	c=(char **)realloc(c,sizeof(char *)*k);
	c[k]=(char *)malloc(sizeof(char)*44);
}

void stringcopy(char a[],char b[])
{
	int i;
	for(i=0;b[i]!='\0';i++)
	{
		a[i]=b[i];
	}
	a[i]='\0';
}

int palindrome(char a[],int n)
{
	int i,j=0;
	
	char *b;

	if(n>=3)
	{
		b=(char *)malloc(sizeof(char)*n);		

		for(i=n-1;i>=0;i--)
		{
			b[j++]=a[i];
		}
		b[j]='\0';

		if(strcmp(a,b)==0)
			return 1;
		else
			return 0;
	}
	else
		return 0;
}


char ** words(char a[])
{
	int i=0,j=0,k=0;

	char **c,*b=(char *)malloc(sizeof(char)*1);

	c=(char **)malloc(sizeof(char *)*1);
	c[0]=(char *)malloc(sizeof(char)*44);

	i=0;
	k=0;

	while(a[i]!='\0')
	{
		if(a[i]!=32)
		{
			j=0;
			while(a[i]!=32 && a[i]!='\0')
			{
				b[j++]=a[i];
				b=(char *)realloc(b,sizeof(char)*(j));
				i++;
			}
			b[j]='\0';

			if(palindrome(b,j)==1)
			{
				stringcopy(c[k],b);
				k++;
				realloc_char(c,k);
			}
		}
		else
			i++;
	}

	if(k==0)
		stringcopy(c[0],"NULL");
	else
		stringcopy(c[k],"NULL");
	
	return c;
}


void testcases()
{
	int i,j,k,check;
	char *a,**op;
	
	for(i=0;i<10;i++)
	{
		check=4;

		a=malloc_char(testDB[i].input);

		op=words(a);

		for(k=0;a_cmp(op[k],"NULL")!=0;k++);

		if(k!=0)
		{
			check=0;			

			for(j=0;j<k;j++)
			{

				if(a_cmp(op[j],testDB[i].output[j])==0)
					check++;
			}
		}
		else
		{
			if(a_cmp(op[0],testDB[i].output[0])==0)
				check=0;
		}


		if(check==k)
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


