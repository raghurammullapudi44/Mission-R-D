#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>


int longneg(int *,int);

int * malloc_int(int *,int);

int a_cmp(int,int);

void testcases();

struct test
{
	int input[20];
	int n;
	int output;
}testDB[10]={{{-1,2,3},3,1},
	{{-1,2,3,4,5,-3},6,1},
	{{-1,-2,-3,-4,5,6,7,8,9},9,4},
	{{-1,-18,-19},3,3},
	{{-3,-30,-30,1,2,-3,-4,-5,-6,-7,-8},11,6},
	{{1,-2,3},3,1},
	{{8,90,100},3,0},
	{{-1,-42,3},3,2},
	{{1,-28,-3},3,2},
	{{1,200,-30},3,1}};

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



int longneg(int a[],int n)
{
	int count=0,i=1,count1=0;

	if(a[0]<0)
	{
		count++;
		count1++;
	}
	while(i<n)
	{

     			if(a[i]<0)
       				count++;
     			else
    			{
      				if(count1<count)
        				count1=count;
     				 count=0;
     			}
	i++;
	}

	if(count1<count)
  		count1=count;

return count1;
}

void testcases()
{
	int i,*a,op,check;
	for(i=0;i<10;i++)
	{
		a=malloc_int(testDB[i].input,testDB[i].n);
		op=longneg(a,testDB[i].n);
		check=a_cmp(testDB[i].output,op);
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
