#include<stdio.h>
#include<stdlib.h>

int a_amp(char a,char b);

char kthindex(char *,int);

struct test
{
	char input[20];
	int k;
	char output;
}testDB[10]={{{"abcd"},3,'d'},
		{{"ab d"},2,' '},
		{{"\0   "},0,'\0'},
		{{"ab\0 "},2,'\0'},
		{{"abc\0"},-3,'\0'},                           // '\0' implies index is out of bounds of string
		{{" abcd\0"},0,' '},
		{{"      "},3,' '},
		{{"@$ $@"},1,'$'},
		{{"#abcd "},4,'d'},
		{{"a b c d"},10,'\0'}};
 


int a_cmp(char a,char b)
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


char kthindex(char a[],int k)
{
	return a[k];
}


void testcases()
{
	int i,check,len;
	char op,b;
	for(i=0;i<10;i++)
	{
		for(len=0;testDB[i].input[len]!='\0';len++);

		if(testDB[i].k>=len || testDB[i].k<0)
			b='\0';
		else
			b=kthindex(testDB[i].input,testDB[i].k);

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
