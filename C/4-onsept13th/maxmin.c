#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

int a_cmp(int *,int,int);

int * malloc_int(int *,int);

int * maxmin(int *,int);

struct test
{
	int input[20];
	int n;
	int output1;
	int output2;
}testDB[4]={{{-2,0,4,6,8,9},6,9,-2},
	{{1,2,3,4,5,5,},6,5,1},
	{{1,1,2,3,4,5,5},7,5,1},
	{{-2,-2,-1,0,1,3,3,4},8,4,-2}};


int * malloc_int(int ip[],int n)
{
	int i,*a;
	a=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		a[i]=ip[i];
	return a;
}

int a_cmp(int a[],int b,int c)
{
	if(a[0]==b && a[1]==c)
		return 0;
	else
		return 1;
}

int * maxmin(int a[],int n)
{
	int i,*b;

	b=(int *)malloc(sizeof(int)*2);

	b[0]=a[0];
	b[1]=a[0];

	for(i=1;i<n;i++)
	{
  		if(b[0]<a[i])
    			 b[0]=a[i];
  		if(b[1]>a[i])
   			 b[1]=a[i];
	}
return b;
}

void testcases()
{
	int i,*a,op,check,*b;
	for(i=0;i<4;i++)
	{
		a=malloc_int(testDB[i].input,testDB[i].n);

		b=maxmin(a,testDB[i].n);

		check=a_cmp(b,testDB[i].output1,testDB[i].output2);
		if(check==0)
			printf("passed\n");
		else 
			printf("failed\n");
		free(a);
		free(b);
	}

}


int main()
{
	testcases();
	return 0;
}


