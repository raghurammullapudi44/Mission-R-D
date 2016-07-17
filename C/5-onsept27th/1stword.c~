#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int a_amp(char *,char *);

char * firstword(char *);

struct test
{
	char input[20];
	char output[20];
}testDB[10]={{{"mullapudi raghu ram"},{"mullapudi"}},
		{{"anil neerukonda"},{"anil"}},
		{{"1234suresh babu"},{"1234suresh"}},
		{{"raghu"},{"raghu"}},
		{{"ram "},{"ram"}},					
		{{" Raghu"},{"Raghu"}},
		{{"rajasri raghu"},{"rajasri"}},
		{{"Rajasri\0    "},{"Rajasri"}},
		{{"     "},{"\0"}},					
		{{"vv tyv tyvtv"},{"vv"}}};

int a_cmp(char a[],char b[])
{
	if(strcmp(a,b)==0)
		return 0;
	else
		return 1;
}


char * firstword(char a[])
{
	int i=0,j=0;
	char *b=(char *)malloc(sizeof(char)*1);

	while(a[i]!='\0')
	{
		if(a[i]!=32)
		{
			while(a[i]!=32 && a[i]!='\0')
			{
				b[j++]=a[i];
				b=(char *)realloc(b,sizeof(char)*(j+1));
				i++;
			}
			break;
		}
		else
			i++;
	}

	b[j]='\0';
	return b;
}
	
		
void testcases()
{
	int i,check,len1;
	char *a;
	
	for(i=0;i<10;i++)
	{

		a=firstword(testDB[i].input);

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


