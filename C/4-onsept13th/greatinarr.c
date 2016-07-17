#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

int a_cmp(int,int);

int * malloc_int(int *,int);

int great(int *,int,int);

struct test
{
	int input[20];
	int n;
	int n1;
	int output;
}testDB[4]={{{1,2,3},3,2,1},
	{{-5,-4,0,8,9,10},6,-4,4},
	{{1,2,2},3,2,0},
	{{0,0,0,4,5,6,7,8,8,8,11},11,0,8}};

int * malloc_int(int ip[],int n)
{
	int i,*a;
	a=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		a[i]=ip[i];
	return a;
}

int a_cmp(int a,int b)
{
	if(a==b)
		return 0;
	else
		return 1;
}


int great(int a[],int n,int n1)
{
	int i=0,count=0;

	while(i<n)
	{
		if(a[i]>n1)
			break;
		i++;
	}

return (n-i);
}

void testcases()
{
	int i,*a,op,check,b;
	for(i=0;i<4;i++)
	{
		a=malloc_int(testDB[i].input,testDB[i].n);

		b=great(a,testDB[i].n,testDB[i].n1);

		check=a_cmp(b,testDB[i].output);
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


