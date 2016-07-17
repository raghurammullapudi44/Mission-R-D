#include<stdio.h>
#include<stdlib.h>

int a_amp(int a,int b);

int strlength(char *);

struct test
{
	char input[20];
	int output;
}testDB[10]={{{"abcd"},4},
		{{"ab d"},4},
		{{"\0   "},0},
		{{"ab\0 "},2},
		{{"abc\0"},3},                           
		{{" abcd\0"},5},
		{{"     \0 "},5},
		{{"@$ $@"},5},
		{{"#abcd\0"},5},
		{{"a b c d"},7}};
 


int a_cmp(int a,int b)
{
	if(a==b)
		return 0;
	else
		return 1;
}


int strlength(char a[])
{
	int i;	
	
	for(i=0;a[i]!='\0';i++);
	
	return i;
}


void testcases()
{
	int i,check,op,b;
	
	for(i=0;i<10;i++)
	{
		b=strlength(testDB[i].input);
		op=testDB[i].output;
		check=a_cmp(b,op);

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
