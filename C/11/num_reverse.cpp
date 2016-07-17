#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>

#pragma warning(disable: 4996)

int convert(char *);

int reverse(int);

int a_cmp(int,int);

void testcases();

struct test
{
	int input;
	int output;
}testDB[1]={1234,4321};


int a_cmp(int a,int b)
{
	if(a==b)
		return 0;
	else
		return 1;	
}

int reverse(int a)
{
	static int res=0;
	int b;
	if(a!=0)
	{
		b=a%10;
		res=(res*10)+b;
		a=a/10;
		reverse(a);
	}
	else
		return res;
}

void testcases()
{
	int a,b,op,check,i;

	for(i=0;i<1;i++)
	{
		a=testDB[i].input;

		b=reverse(a);	

		printf("%d",b);

		check=a_cmp(b,testDB[i].output);				
		
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

