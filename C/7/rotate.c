#include<stdio.h>
#include<stdlib.h>

int a_cmp(int *,int,int);

int * malloc_int(int *,int);

struct test
{
	int input[20];
	int n;
	int output;
}testDB[4]={{{7,8,1,3,4,5,6},3,4},
	{{1,2,3,4,5,5},6,5},
	{{1,1,2,3,4,5,5},7,5},
	{{-2,-2,-1,0,1,3,3,4},8,4}};


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

void testcases()
{
	int i,*a,op,check,b;
	for(i=0;i<4;i++)
	{
		a=malloc_int(testDB[i].input,testDB[i].n);

		b=rotate(a,testDB[i].n);

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


