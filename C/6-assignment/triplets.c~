#include<stdio.h>
#include<stdlib.h>

void testcases();

int * malloc_int(int *,int);

int a_cmp(int *,int *);

int * triplets(int *,int);

struct test
{
	int input[44];
	int n;
	int output[3];
}testDB[10]={{{0,0,1,1,0,2,2,0},8,{2,2,0}},
	{{0,2,3,4,5,6,0,1,0,0,8,2,2,6},14,{4,5,6}},
	{{0,0,3,1,2,3,1,2,3},9,{1,2,3}},
	{{1,1,1},3,{1,1,1}},
	{{3,1,0,0,2,0,0,4,5,0,0,6,0,0,7,8,0,0,9,0,0,0,0,10,0},25,{7,8,0}},
	{{0,2,3,2,2,2,3,1,0,0,6},11,{2,2,3}},
	{{1,0,3,-1,-8,-9,0,4,-9},9,{1,0,3}},
	{{-1,4,3,0,0,3,0,0,3,1,1,1},12,{4,3,0}},
	{{1,2,0,8,8,8,8,8,88,9,9,99},12,{9,9,99}},
	{{0,0,0,},3,{0,0,0}}};

int * malloc_int(int ip[],int n)
{
	int i,*a;
	a=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		a[i]=ip[i];
	return a;
}


int a_cmp(int a[],int b[])
{
	int i,count=0;
	for(i=0;i<3;i++)
		if(a[i]==b[i])
			count++;

	if(count==3)
		return 0;
	else
		return 1;
		
}

int * triplets(int a[],int n)
{
	int i,*b,max=0;
	
	b=(int *)malloc(sizeof(int)*3);

	for(i=0;i<=n-3;i++)
	{
		if(max<=(a[i]+a[i+1]+a[i+2]))
		{
			b[0]=a[i];
			b[1]=a[i+1];
			b[2]=a[i+2];
			
			max=a[i]+a[i+1]+a[i+2];
		}
	}
return b;
}


void testcases()
{
	int i,*a,*b,*op,check;

	for(i=0;i<10;i++)
	{
		a=malloc_int(testDB[i].input,testDB[i].n);

		b=triplets(a,testDB[i].n);

		op=malloc_int(testDB[i].output,3);

		check=a_cmp(b,op);

		if(check==0)
			printf("passed\n");
		else 
			printf("failed\n");
		free(a);
		free(op);
	}

}


int main()
{
	testcases();
	return 0;
}

