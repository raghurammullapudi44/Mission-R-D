
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

int a_cmp(int *,int *,int);

int * malloc_int(int *,int);

int  sort01(int *,int,int);

void swap(int *,int *);

int * sort_01(int *,int);

struct test
{
	int input[20];
	int n;
	int output[20];
}testDB[10]={{{0,0,1},3,{0,0,1}},
	{{0,0,1,0,0,1},6,{0,0,0,0,1,1}},
	{{1,1,1},3,{1,1,1}},
	{{1,1,1,1,0,1,1,1,0,0,0},11,{0,0,0,0,1,1,1,1,1,1,1}},
        {{1,1,0,0,0},5,{0,0,0,1,1}},
	{{0,0,0,0,0},5,{0,0,0,0,0}},
	{{0},1,{0}},
	{{1},1,{1}},
	{{1,0},2,{0,1}},
	{{0,0,0,0,1,0,0,0,0,0},10,{0,0,0,0,0,0,0,0,0,1}}};

int * malloc_int(int ip[],int n)
{
	int i,*a;
	a=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		a[i]=ip[i];
	return a;
}

int a_cmp(int a[],int b[],int n)
{
	int i,count=0;
	for(i=0;i<n;i++)
	{
		if(a[i]==b[i])
			count++;
	} 
	if(count==n)
		return 0;
	else
		return 1;
}


int  sort01(int a[],int n,int n1)
{
	int i,j;
	
	for(i=0;i<n1;i++)
	{
		if(a[i]==1)
		{
			for(j=n-1;j>i;j--)
			{
				if(a[j]==0)
				{
					swap(&a[i],&a[j]);
					break;
				}
			}
		}
	}
}

int * sort_01(int a[],int n)
{
	int i=0,sum=0;
	while(i<n)
	{
 		sum=sum+a[i];
 		i++;
	}
	for(i=0;i<n;i++)
	{
   		if(i<(n-sum))
     			a[i]=0;
   		else
			a[i]=1;
	}

return a;
}

void swap(int *a,int *b)
{
	int t;
	
	t=*a;
	*a=*b;
	*b=t;
}

void testcases1()
{
	int i,*a,*op,check,k,n;
	for(i=0;i<10;i++)
	{
		a=malloc_int(testDB[i].input,testDB[i].n);

		n=testDB[i].n;
		

		if(n%2==0)
			sort01(a,n,n/2);
		else
			sort01(a,n,(n/2)+1);
		
		op=malloc_int(testDB[i].output,testDB[i].n);


		check=a_cmp(a,op,n);
		if(check==0)
			printf("passed\n");
		else 
			printf("failed\n");
		free(a);
		free(op);
	}

}

void testcases2()
{
	int i,*a,*op,check;
	for(i=0;i<10;i++)
	{
		a=malloc_int(testDB[i].input,testDB[i].n);
		a=sort_01(a,testDB[i].n);
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
	printf("first algorithm\n");
	testcases1();
	printf("second algorithm\n");
	testcases2();
	return 0;
}







