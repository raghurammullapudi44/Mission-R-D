#include<stdio.h>
#include<stdlib.h>

int * mulladd(int *,int *,int);

int same(int *,int *,int);

void testcases();

int * malloc_int(int *,int);

int a_cmp(int,int); 

struct test
{
	int input1[44];
	int n1;
	int input2[44];
	int n2;
	int output;					// if they are equal output is 1, if not equal output is 0
}testDB[10]={{{1,2,3,4},4,{4,2,1,3},4,1},
		{{0,2,3,9},4,{9,0,1,0},4,0},
		{{0,0,10,11,12,13},6,{11,0,0,12,13,0},6,0},
		{{0,0,0,0,0},5,{0,0,0,0,1},5,0},
		{{0,22,44,88,99},5,{22,88,44,0,99},5,1},
		{{9,99,101},3,{99,1,101,1,88},5,0},
		{{11,13,14},3,{1},1,0},
		{{9,999,9999},3,{9999,9,999},3,1},
		{{88,888,888},3,{88,8,888},3,0},
		{{4,4,4,4,4,4,4,4},8,{4,4,4,4,4,4,4,44},8,0}};

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

int * mulladd(int a[],int b[],int n)
{
	int i,mull1=1,add1=0,mull2=1,add2=0,*c=(int *)malloc(sizeof(int)*4);
	
	for(i=0;i<n;i++)
	{
		mull1*=a[i];
		add1+=a[i];
		mull2*=b[i];
		add2+=b[i];
	}

	c[0]=mull1;
	c[1]=add1;
	c[2]=mull2;
	c[3]=add2;
	
return c;
}

int same(int a[],int b[],int n)
{
	int *c=(int *)malloc(sizeof(int)*4);

	c=mulladd(a,b,n);

	if((c[0]==c[2]) && (c[1]==c[3]))
		return 1;
	else
		return 0;
}



void testcases()
{
	int i,*a,*b,op,check;

	for(i=0;i<10;i++)
	{
		a=malloc_int(testDB[i].input1,testDB[i].n1);
		b=malloc_int(testDB[i].input2,testDB[i].n2);

		if(testDB[i].n1!=testDB[i].n2)
			op=0;
		else
			op=same(a,b,testDB[i].n1);

		check=a_cmp(op,testDB[i].output);

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

