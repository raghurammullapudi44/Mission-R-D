#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int a_amp(char *,char *);

char * lastword(char *);

struct test
{
	char input[20];
	char output[20];
}testDB[11]={{{"mullapudi raghu ram"},{"ram"}},
		{{"anil neerukonda"},{"neerukonda"}},
		{{"1234suresh babu"},{"babu"}},
		{{"raghu"},{"raghu"}},
		{{"ram "},{"ram"}},
		{{" Raghu"},{"Raghu"}},
		{{"rajasri raghu"},{"raghu"}},
		{{"Rajasri\0    "},{"Rajasri"}},
		{{"     "},{"\0"}},					
		{{"vvtyv tyvtv"},{"tyvtv"}},
		{{"\0"},{"\0"}}};


int a_cmp(char a[],char b[])
{
	if(strcmp(a,b)==0)
		return 0;
	else
		return 1;
}


char * lastword(char a[])
{
	int len,i,j=0,k=0;
	char *b=(char *)malloc(sizeof(char)*1),*c;

	for(len=0;a[len]!='\0';len++);

	i=len-1;

	while(a[i]!='\0')
	{
		if(a[i]!=32)
		{
			while(a[i]!=32 && i>=0)
			{
				b[j++]=a[i]; 
				b=(char *)realloc(b,sizeof(char)*(j+1));
				i--;
			}
			break;
		}
		else
			i--;
	}

	c=(char *)malloc(sizeof(char)*j);

	while(j-1>=0)
		c[k++]=b[--j];
	
	c[k]='\0';
	return c;
}
	
		
void testcases()
{
	int i,check,len1;
	char *a;
	
	for(i=0;i<11;i++)
	{

		a=lastword(testDB[i].input);
	
		check=a_cmp(a,testDB[i].output);

		if(check==0)
			printf("passed\n");
		else 
			printf("failed\n");
		free(a);
	}

}

int main()
{
	testcases();
	return 0;
}


