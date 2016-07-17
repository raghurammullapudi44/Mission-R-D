#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

int * adder(int *,int *,int,int);

int * adder1(int *,int *,int,int);

int * adder2(int *,int *,int,int);

int * neg(int *,int,int);

int nonzerocount(int *,int);

int flaw(int *,int *,int n1);

int * malloc_int(int *,int);

int a_cmp(int *,int *,int);

void testcases();

struct test
{
	int input1[20];
	int n1;
	int input2[20];
	int n2;
	int output[20];
}testDB[10]={{{1,2,3,4},4,{5,6,7,8},4,{6,9,1,2}},
		{{0,0,0,1},4,{1,2,3,4},4,{1,2,3,5}},
		{{0,0,0,1},4,{1,2},2,{1,3}},
		{{-1,2,3,4},4,{-9,6,7,8},4,{-10,9,1,2}},
		{{1,7,7,2},4,{-1,7,7,3},4,{0,0,0,-1}},
		{{0,0,0,-1},4,{-1,2},2,{-1,3}},
		{{5,6,7,8},4,{-1,2,3,4},4,{4,4,4,4}},
		{{-5,6,7,8},4,{1,2,3,4},4,{-4,4,4,4}},
		{{-1,7,7,8,3},5,{1,7,8,8,3},5,{0,0,1,0,0}},
		{{-1,0,0,0,0},5,{1},1,{0,-9,9,9,9}}};

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

int * adder(int a[],int b[],int n1,int n2)
{
	int *c,i,flag1=0,flag2=0,count;

	c=(int *)malloc(sizeof(int)*n1);

	for(i=0;i<n1;i++)
	{
		if(a[0]<0)
		{
			a[0]=-a[0];
			flag1++;
		}
	}
	for(i=0;i<n2;i++)
	{
		if(b[0]<0)
		{
			b[0]=-b[0];
			flag2++;
		}
	}

	if(flag1==flag2)
	{
		c=adder1(a,b,n1,n2);
		if(flag1==1)
			c=neg(c,n1,flag1);	
	return c;
	}

        if(flag1==0 && flag2==1)
	{
		if(a[0]>b[0])
			c=adder2(a,b,n1,n2);
		else
		{
			if(n1==n2)
			{

				if(a[0]<b[0])
				{
					c=adder2(b,a,n2,n1);
					c=neg(c,n1,flag2);
				}
				else
				{
					count=flaw(a,b,n1);
					if(count==0)
						c=adder2(a,b,n1,n2);
					else
					{
						c=adder2(b,a,n2,n1);
						c=neg(c,n1,flag2);
					}
				}
				
			}
			else
				c=adder2(a,b,n1,n2);
		}
	return c;
	}

	
	if(flag1==1 && flag2==0)
	{
		if(a[0]>b[0])
		{
			c=adder2(a,b,n1,n2);
			c=neg(c,n1,flag1);
		}
		else
		{
			
			if(n1==n2)
			{

				if(a[0]<b[0])
					c=adder2(b,a,n2,n1);
				else
				{
					count=flaw(a,b,n1);
					if(count==0)
					{
						c=adder2(a,b,n1,n2);
						c=neg(c,n1,flag1);
					}
					else
						c=adder2(b,a,n2,n1);
				}
				
			}
			else
			{
				c=adder2(a,b,n1,n2);
				c=neg(c,n1,flag1);
			}
				
		}
	return c;
	}
}

// adder for both positive or negative

int * adder1(int a[],int b[],int n1,int n2)
{
	int i=n1-1,j=n2-1,sum=0,cary=0,k=n1-1,*c;

	c=(int *)malloc(sizeof(int)*n1);

	while(i>=0)
	{
		if(cary==0)
		{
			if(j<0)
				sum=a[i];
			else
				sum=a[i]+b[j];
		}
		else
		{
			if(j<0)
				sum=a[i]+cary;
			else
				sum=a[i]+b[j]+cary;
		}

		if(sum>9)
		{

			if(n1==n2)
			{
				if(j==0)
					c[k--]=sum;
			}
			if(i==0 && j<0)
				c[k--]=sum;
			
			else
			{
				cary=sum/10;
				c[k--]=sum%10;

			}	
		}
		else
		{
			c[k--]=sum;
			cary=0;
		}
	
		i--;
		j--;
	}
	return c;
}


// for one positive and another negative

int * adder2(int a[],int b[],int n1,int n2)
{
	int i=n1-1,j=n2-1,*c,borrow=0,k=n1-1;

	c=(int *)malloc(sizeof(int)*n1);

	while(i>=0)
	{
		if(j<0)
		{
			if(borrow==0)
					c[k--]=a[i];
			else
			{
				if((a[i]-1)<0)
					c[k--]=9;
				else
				{
					c[k--]=a[i]-1;
					borrow=0;
				}
			}
		}
		else
		{
			if(borrow==0)
			{
				if(a[i]>=b[j])
				{
					c[k--]=a[i]-b[j];
					borrow=0;
				}
			
				else
				{
					c[k--]=a[i]+(10-b[j]);
					borrow++;
				}
			}
			else
			{
				if((a[i]-1)>=b[j])
				{
					c[k--]=a[i]-1-b[j];
					borrow=0;
				}
				else
				{
					c[k--]=10-b[j]+a[i]-1;
					borrow++;
				}
			}
		}
		i--;
		j--;
	}
	return c;
}

int * neg(int e[],int n1,int flag1)
{
	int i;	
	for(i=0;i<n1;i++)
	{
		if(flag1==1 && e[i]!=0)
		{
			e[i]=-e[i];
			break;
		}
	}
return e;
}

int nonzerocount(int a[],int n1)
{
	int i,count=0;
	
	for(i=0;i<n1;i++)
	{
		if(a[i]==0)
			count++;
		else
			break;
	}
return count;
}


int flaw(int a[],int b[],int n1)
{
	int i,count=0;
	for(i=0;i<n1-1;i++)
	{
		if(a[i]==b[i])
		{
			if(a[i+1]<=b[i+1])
				count=1;
			else
			{
				count=0;
				break;
			}
		}
		else
			break;
	}
return count;
}

void testcases()
{
	int i,*a,*b,*op,check,*c,n1,n2,n3,n4,*d,*e,j,count=0,k;

	for(i=0;i<10;i++)
	{
		a=malloc_int(testDB[i].input1,testDB[i].n1);
		b=malloc_int(testDB[i].input2,testDB[i].n2);

		n1=testDB[i].n1;
		n2=testDB[i].n2;


		n3=nonzerocount(testDB[i].input1,testDB[i].n1);
		n4=nonzerocount(testDB[i].input2,testDB[i].n2);


		d=(int *)malloc(sizeof(int)*(testDB[i].n1-n3));
		e=(int *)malloc(sizeof(int)*(testDB[i].n2-n4));

		

		if(n1==n3)
			for(k=0;k<n1;k++)
				d[k]=a[k];
		else
			for(k=n3,j=0;k<n1;k++)
				d[j++]=a[k];

		if(n2==n4)
			for(k=0;k<n2;k++)
				e[k]=b[k];
		else
			for(k=n4,j=0;k<n2;k++)
				e[j++]=b[k];

		if((n1-n3)>=(n2-n4))
		{
			c=(int *)malloc(sizeof(int)*(n1-n3));
			c=adder(d,e,n1-n3,n2-n4);

			op=malloc_int(testDB[i].output,testDB[i].n1-n3);
			check=a_cmp(c,op,testDB[i].n1-n3);
		}
		else
		{
			c=(int *)malloc(sizeof(int)*(n2-n4));
			c=adder(e,d,n2-n4,n1-n3);
			
			op=malloc_int(testDB[i].output,testDB[i].n2-n4);
			check=a_cmp(c,op,testDB[i].n2-n4);
		}
		
                
		
		if(check==0)
			printf("passed\n");
		else 
			printf("failed\n");
	}

}


int main()
{
	testcases();
	return 0;
}




















	
