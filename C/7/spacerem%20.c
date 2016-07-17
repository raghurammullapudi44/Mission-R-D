#include<stdio.h>
#include<stdlib.h>

int a_amp(char *,char *);

void percentile(char *);

void  spacerem(char *);

char * malloc_char(char *);

struct test
{
	char input[444];
	char output[444];
}testDB[10]={{{"kony     labs"},{"kony%20labs"}},
		{{"      anil  neeeerukonda  institute  "},{"anil%20neeeerukonda%20institute"}},
		{{"    t e r r a d a t a    "},{"t%20e%20r%20r%20a%20d%20a%20t%20a"}},
		{{"    a"},{"a"}},
		{{"    gooooo  ooogle     "},{"gooooo%20ooogle"}},
		{{" Raghu"},{"Raghu"}},
		{{"  rajasri r aghu "},{"rajasri%20r%20aghu"}},
		{{"Rajasri\0    "},{"Rajasri"}},
		{{"  ama zzzzzzz oooo n    . c o m"},{"ama%20zzzzzzz%20oooo%20n%20.%20c%20o%20m"}},
		{{"     "},{"\0"}}};

int a_cmp(char a[],char b[])
{
	if(strcmp(a,b)==0)
		return 0;
	else
		return 1;
}

char * malloc_char(char ip[])
{
	int i;
	char *a;
	a=(char *)malloc(sizeof(char)*1);
	for(i=0;ip[i]!='\0';i++)
	{
		a=(char *)realloc(a,sizeof(int)*(i+1));
		a[i]=ip[i];
	}
	a[i]='\0';
	return a;
}

void percentile(char *a)
{
	int i,j=0,len;

	for(len=0;a[len]!='\0';len++);

	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]==32)
		{
			j++;
		}
	}

	j=len+(j*2);

	a=(char *)realloc(a,sizeof(char)*j);

	while(len>=0)
	{
		if(a[len]!=32)
		{
			a[j--]=a[len];	
		}
		else
		{
			a[j--]='0';
			a[j--]='2';
			a[j--]='%';
		}
		len--;
	}
}

void spacerem(char a[])
{
	int i,j=1,flag,flag1=0;

	for(i=1;a[i]!='\0';i++)
	{
		if((a[i]!=32) && (a[i-1]==32)  && (flag1==0))
		{
			a[0]=a[i];
			flag1=1;
		}
		else
		{
			if(a[i]!=a[i-1])
			{
				if(a[i]!=32)
				{
					a[j++]=a[i];
					flag1=1;
				}
				else
				{
					if(flag!=i-1)
					{
						a[j++]=a[i];
						flag=i;
						flag1=1;
					}
				}
			}
			else
			{
				if(a[i]!=32 && a[i-1]!=32)
				{
					a[j++]=a[i];
					flag1=1;
				}

			}
				
		}
	}

	if(a[j-1]==32)
	{
		a[j-1]='\0';
		a=(char *)realloc(a,sizeof(char)*(j-1));
	}
	else
	{
		a[j]='\0';
		a=(char *)realloc(a,sizeof(char)*(j));
	}
	if(flag1!=0)
		percentile(a);
}

void testcases()
{
	int i,check,wcount;
	char *a;
	
	for(i=0;i<10;i++)
	{
		a=malloc_char(testDB[i].input);		
	
		spacerem(a);

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


