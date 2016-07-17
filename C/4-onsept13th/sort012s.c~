#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

int a_cmp(int *,int *,int);

int * malloc_int(int *,int);

int * sort012(int *,int);

struct test
{
	int input[20];
	int n;
	int output[20];
}testDB[4]={{{2,0,0,1},4,{0,0,1,2}},
	{{0,0,2,0,0,1},6,{0,0,0,0,1,2}},
	{{2,2,1},3,{1,2,2}},
	{{1,1,2,2,2,1,1,1,0,0,0},11,{0,0,0,1,1,1,1,1,2,2,2}}};

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


int * sort012(int a[],int n)
{
	int i=0,count=0,count1=0,*b,s=0,e=n-1;

	b=(int *)malloc(sizeof(int)*n);

	while(i<n)
	{
		switch(a[i])
		{	
			
 			case 0:b[s++]=0;
				break;
			case 2:b[e--]=2;
				break;
		}
		i++;
	}
	
	for(i=s;i<=e;i++)
		b[i]=1;
	
return b;
}

void testcases()
{
	int i,*a,*op,check;
	for(i=0;i<4;i++)
	{
		a=malloc_int(testDB[i].input,testDB[i].n);
		a=sort012(a,testDB[i].n);
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




