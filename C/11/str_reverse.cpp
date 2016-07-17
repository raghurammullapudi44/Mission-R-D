#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#pragma warning(disable: 4996)


void reverse(char *,int,int);

int a_cmp(char *,char *);

void testcases();

char * malloc_char(char *);

struct test
{
	char input[40];
	char output[40];
}testDB[2]={{"1234","4321"},
{"abcd","dcba"}};



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
		a[i]=ip[i];
		a=(char *)realloc(a,sizeof(int)*(i+1));
	}
	a[i]='\0';
	return a;
}


void reverse(char a[],int i,int len)
{
	char temp;

	if(i<len)
	{
		temp=a[i];
		a[i]=a[len];
		a[len]=temp;
		i++;
		len--;
		reverse(a,i,len);
	}
}

void testcases()
{
	int check,i,len;
	char *a;

	for(i=0;i<2;i++)
	{
		a=malloc_char(testDB[i].input);

		for(len=0;a[len]!='\0';len++);

		reverse(a,0,len-1);	

		printf("%s",a);

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
	getchar();
	return 0;
}

