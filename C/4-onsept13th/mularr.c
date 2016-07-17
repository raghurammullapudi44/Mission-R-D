#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

int * mularr(int *,int);

void testcases();

int * malloc_int(int *,int);

int a_cmp(int *,int *,int); 

struct test
{
	int input[20];
	int n;
	int output[20];
}testDB[10]={{{1,2,3},3,{6,3,2}},
	{{0,2,3,4,5,6},6,{720,0,0,0,0,0}},
	{{0,0,3,1,2,3,1,2,3},9,{0,0,0,0,0,0,0,0,0}},
	{{1,1,1},3,{1,1,1}},
	{{3,1,2,4,5,6,7,8,9,10,0},11,{0,0,0,0,0,0,0,0,0,0,3628800}},
	{{0,2,3},3,{6,0,0}},
	{{1,0,3},3,{0,3,0}},
	{{0,0,3},3,{0,0,0}},
	{{1,2,0},3,{0,0,2}},
	{{0,0,0,},3,{0,0,0}}};

int * malloc_int(int ip[],int n)
{
	int i,*a;
	a=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		a[i]=ip[i];
	return a;
}


int a_cmp(int a[],int b[],int  n)
{
	int i,count=0;
	for(i=0;i<n;i++)
		if(a[i]==b[i])
			count++;
	if(count==n)
		return 0;
	else
		return 1;		
}

int * mularr(int a[],int n)
{
	int *b,count=0,i,j,k,mul=1,flag=0;

	b=(int *)malloc(sizeof(int)*n);

	for(i=0;i<n;i++)
	{
		if(a[i]==0)
		{
			count++;
			if(count==1)
				j=i;
		}
	}


	if(count>1)
	{
		for(i=0;i<n;i++)
			b[i]=0;
		return b;
	}

	if(count==1)
	{
		k=0;
		while(k<n)
		{
			flag=0;
			if(k!=j)
			{
				flag++;
				mul=mul*a[k];
			}
			if(flag!=0)
				b[k]=0;
			k++;
		}	
		b[j]=mul;
	return b;
	}

	if(count==0)
	{
		for(i=0;i<n;i++)
			mul=mul*a[i];
		for(i=0;i<n;i++)
			b[i]=mul/a[i];	
	return b;
	}
}

void testcases()
{
	int i,*a,*op,check;
	for(i=0;i<10;i++)
	{
		a=malloc_int(testDB[i].input,testDB[i].n);
		a=mularr(a,testDB[i].n);
		op=malloc_int(testDB[i].output,testDB[i].n);
		check=a_cmp(a,op,testDB[i].n);
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



