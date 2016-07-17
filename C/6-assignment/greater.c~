#include<stdio.h>
#include<stdlib.h>

int convert(char *);

char * greater(char *,char *);

char * malloc_char(char *);

int a_cmp(char *,char *);

void testcases();

struct test
{
	char input1[20];
	char input2[20];
	char output[20];
}testDB[10]={{{"1234"},{"5678"},{"5678"}},
		{{"0001"},{"1234"},{"1234"}},
		{{"0001"},{"12"},{"12"}},
		{{"1234"},{"9678"},{"9678"}},
		{{"1772"},{"1773"},{"1773"}},
		{{"0001"},{"1"},{"0001"}},
		{{"5678"},{"1234"},{"5678"}},
		{{"5678"},{"12345"},{"12345"}},
		{{"17783"},{"17883"},{"17883"}},
		{{"10000"},{"1"},{"10000"}}};

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

int a_cmp(char a[],char b[])
{
	if(strcmp(a,b)==0)
		return 0;
	else
		return 1;	
}

int convert(char s[])
{
	int i,d=0;

	for(i=0;s[i]!='\0';i++)
		d=(d*10)+s[i]-'0';
return d;
}

char * greater(char a[],char b[])
{
	if(convert(a)>=convert(b))
		return a;
	else
		return b;
}

void testcases()
{
	int i,check,n1,n2,n3,n4,j,k;
	char *a,*b,*op,*c;

	for(i=0;i<10;i++)
	{
		a=malloc_char(testDB[i].input1);
		b=malloc_char(testDB[i].input2);
		
		c=greater(a,b);	

		op=malloc_char(testDB[i].output);

		check=a_cmp(c,op);				
		
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

