#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int * fun(int *,int,int);
int main()
{
	int *a,n,i,n1;
	printf("enter size:");
	scanf_s("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	printf("enter array:");
	for(i=0;i<n;i++)
		scanf_s("%d",&a[i]);
	printf("insert an number:");
	scanf_s("%d",&n1);
	a=(int *)realloc(a,(n+1)*sizeof(int));
	a=fun(a,n,n1);
	for(i=0;i<(n+1);i++)
		printf("%d ",a[i]);
	_getch();
	return 0;
}
int * fun(int a[],int n,int n1)
{
	int i,*b,flag=0,flag1=0;
	b=(int *)malloc((n+1)*sizeof(int));
	for(i=1;i<n;i++)
	{
		if(a[0]<a[i])
		{
			flag1=1;
			break;
		}
		else
		{
	
			flag1=0;
			break;
		}
	}
	for(i=0;i<(n+1);i++)
	{   
		if(flag==1)
		b[i]=a[i-1];
		else
		{
		if(flag1==1&&a[i]<n1 || flag1==0&&a[i]>n1)
        b[i]=a[i];
		else
		{
	    b[i]=n1;
		flag=1;
		}

		}
	}
	
	return b;
}


	
