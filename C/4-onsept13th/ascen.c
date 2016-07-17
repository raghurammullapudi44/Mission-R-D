#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

int a_cmp(int *,int *,int);

int * malloc_int(int *,int);

int * insertion(int,int *,int,int);

struct test
{
	int input1[20];
	int n1;
	int input2[20];
	int n2;
	int output[20];
}testDB[4]={{{1,2},2,{3,4},4,{1,2,3,4}},
	{{1,3,5,7},4,{2,4,6,8,10,12},10,{1,2,3,4,5,6,7,8,10,12}},
	{{2,4,6,8,10,12},6,{1,3,5,7},10,{1,2,3,4,5,6,7,8,10,12}},
	{{30,40,50,60},4,{1,90},6,{1,30,40,50,60,90}}};

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


int * insertion(int n3,int b[],int n1,int n2)
{
	int i=0,j=0,*c,k=0,flag=0,flag1=0;

	c=(int *)malloc(sizeof(int)*n2);
	
	for(i=0;i<n2;i++)
	{   
		if(flag==1)
			c[k++]=b[i-1];

		else
		{
			if(b[i]<=n3 && flag1!=(n2-1))
			{
				c[k++]=b[i];
				flag1++;
			}
				
			else
			{
	    			c[k++]=n3;
				flag=1;
			}
		}
                
	 }

return c;
}

void testcases()
{
	int i,j,*a,*b,*op,check,n3;
	for(i=0;i<4;i++)
	{
		a=malloc_int(testDB[i].input1,testDB[i].n1);
		b=malloc_int(testDB[i].input2,testDB[i].n2);

		n3=testDB[i].n2-testDB[i].n1;
		if(n3<0)
			n3=-n3;

		
		for(j=0;j<testDB[i].n1;j++,n3++)
			b=insertion(a[j],b,testDB[i].n1,n3+1);

		op=malloc_int(testDB[i].output,testDB[i].n2);

		check=a_cmp(b,op,testDB[i].n2);

		if(check==0)
			printf("passed\n");
		else 
			printf("failed\n");
		free(a);
		free(b);
		free(op);
	}

}



int main()
{
	testcases();
	return 0;
}
































	
