#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

int findmedian(int *,int *,int);

int median(int *,int);

int max(int,int);

int min(int,int);

int * malloc_int(int *,int);

int a_cmp(int,int);

void testcases();

struct test
{
	int input1[20];
	int n1;
	int input2[20];
	int n2;
	int output;
}testDB[10]={{{1,2,3},3,{4,5,6},3,3},
	{{4,5,6},3,{1,2,3},3,3},
	{{1,3,5,7,9,11},6,{2,4,6,8},4,'\0'},
	{{1,1,1},3,{1,1,1},3,1},
	{{11,12,12,13,13,14,14,14,15,15,16},11,{1,2,3,3,3,3,3,3,3,3,3},11,7},
	{{1,2,3,4},4,{5,6,7,8},4,4},
	{{1,3,11},3,{2,6,7},3,4},
	{{1},1,{1,2,3},3,'\0'},
	{{-1,2,3},3,{1,2,3},3,2},
	{{0,1,2},3,{-1,0,1},3,0}};
int max(int a,int b)
{
	return ((a>b)?a:b);
}
 


int min(int a, int b)
{
	return ((a>b)?b:a);
}


int median(int a[],int n)
{
   	if(n%2==0)
		return (a[n/2]+a[n/2-1])/2;
    	else
		return a[n/2];
}

int findmedian(int a[],int b[],int n)
{
	int m1,m2;
	
	if(n==1)
		return ((a[0]+b[0])/2);

	if(n==2)
		return ((max(a[0],b[0])+min(a[1],b[1]))/2);

	if(n>2)
	{
		m1=median(a,n);
		m2=median(b,n);

		if(m1==m2)
			return m1;

		if(m1>m2)
		{
			if(n%2==0)
				return (findmedian(b+n/2-1,a,n-n/2+1));
			else
				return (findmedian(b+n/2,a,n-n/2));
		}

		if(m1<m2)
		{
			if(n%2==0)
				return (findmedian(a+n/2-1,b,n-n/2+1));
			else
				return (findmedian(a+n/2,b,n-n/2));
		}
	}

}

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
	int i,*a,*b,op,check;
	for(i=0;i<10;i++)
	{
		a=malloc_int(testDB[i].input1,testDB[i].n1);
		b=malloc_int(testDB[i].input2,testDB[i].n2);

		if(testDB[i].n1==testDB[i].n2)
		{
			op=findmedian(testDB[i].input1,testDB[i].input2,testDB[i].n1);
			check=a_cmp(testDB[i].output,op);
		}
		else
			check=0;

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








