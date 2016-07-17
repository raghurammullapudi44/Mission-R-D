#include<stdio.h>
#include<stdlib.h>

int a_amp(char *,char *);

void spacerem(char *);

char * malloc_char(char *);

struct test
{
	char input[88];
	char output[88];
}testDB[10]={{{"kony     labs"},{"kony labs"}},
		{{"      anil  neeeerukonda  institute  "},{"anil neeeerukonda institute"}},
		{{"    t e r r a d a t a    "},{"t e r r a d a t a"}},
		{{"    a"},{"a"}},
		{{"    gooooo  ooogle     "},{"gooooo ooogle"}},
		{{" Raghu"},{"Raghu"}},
		{{"  rajasri r aghu "},{"rajasri r aghu"}},
		{{"Rajasri\0    "},{"Rajasri"}},
		{{"     "},{"\0"}},
		{{" v vtyv ty vt v"},{"v vtyv ty vt v"}}};

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
}

void testcases()
{
	int i,check,wcount;
	char *a,*op;
	
	for(i=0;i<10;i++)
	{
		a=malloc_char(testDB[i].input);		
	
		spacerem(a);

		op=malloc_char(testDB[i].output);

		check=a_cmp(a,op);

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


