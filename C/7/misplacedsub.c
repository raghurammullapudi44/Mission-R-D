#include<stdio.h>
#include<stdlib.h>

void swap(int *,int *);

void misplacedsubarray(int *,int);

void testcases();

int * malloc_int(int *,int);

int a_cmp(int *,int *,int); 

struct test
{
	int input[44];
	int n;
	int output[44];
}testDB[10]={{{1,2,3,4,5,10,9,8,7,6,11,12,13},13,{1,2,3,4,5,6,7,8,9,10,11,12,13}},
		{{0,2,4,3,5,6},6,{0,2,3,4,5,6}},
		{{88,77,46,44,1,0},6,{0,1,44,46,77,88}},
		{{3,2,1,4,5,6,7,8,9,10,11},11,{1,2,3,4,5,6,7,8,9,10,11}},
		{{1,1,1},3,{1,1,1}},	
		{{0,2,3,44,444,444},6,{0,2,3,44,444,444}},
		{{1,2,3,888,88,8},6,{1,2,3,8,88,888}},
		{{0,0,3,3,4,4,5,4,6,7},10,{0,0,3,3,4,4,4,5,6,7}},
		{{0,0,0,0,1,1,1,2,2,2,6,5,4,4,4},15,{0,0,0,0,1,1,1,2,2,2,4,4,4,5,6}},
		{{0,0,0,1,0,0,0,0},8,{0,0,0,0,0,0,0,1}}};


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

void misplacedsubarray(int a[],int n)
{
	int i,j,x,xi,yi,flag=0,flag1=0;

	for(i=1;i<n;i++)
	{
		if(a[i]<a[i-1])
		{
			x=a[i-1];
			xi=i-1;
			for(j=i+1;j<n;j++)
			{
				if(a[j]>=x)
				{
					yi=j-1;
					flag=1;
					break;
				}
			}
			flag1=1;
			break;
		}
	}
	if(flag==0)
		yi=n-1;
	if(flag1==1)
	{
		while((xi!=yi) && (xi<yi))
		{
			swap(&a[xi],&a[yi]);
			xi++;
			yi--;
		}
	}
}

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void testcases()
{
	int i,*a,*op,check,n;

	for(i=0;i<10;i++)
	{
		n=testDB[i].n;

		a=malloc_int(testDB[i].input,n);

		misplacedsubarray(a,n);

		op=malloc_int(testDB[i].output,n);

		check=a_cmp(a,op,n);

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

