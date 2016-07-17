#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable: 4996)
int * fun(int *,int,int,int);
int main()
{
	int *a,*b,*c,n1,n2,n,i;
	printf("enter the sizes of two arrays:");
	scanf("%d %d",&n1,&n2);
	n=n1+n2;
	a=(int *)malloc(sizeof(int)*n1);
	b=(int *)malloc(sizeof(int)*n2);
	c=(int *)malloc(sizeof(int)*n);
	printf("enter array in ascending order:");
	for(i=0;i<n1;i++)
		scanf("%d",&a[i]);
	printf("enter array in decending order:");
	for(i=0;i<n2;i++)
		scanf("%d",&b[i]);
	for(i=0;i<n1;i++)
		c[i]=a[i];
	for(i=0;i<n2;i++,n1++)
	c=fun(c,b[i],n1+1,n2);
	printf("the resultant third array is:");
	for(i=0;i<n;i++)
		printf("%d ",c[i]);
	getch();
	return 0;
	free(a);
	free(b);
	free(c);
}
int * fun(int a[],int n3,int n1,int n2)
{
	int *c,i,flag=0,n,flag1=0,flag2=0,k=0;
	n=n1+n2;
	c=(int *)malloc(sizeof(int)*n);
	if(a[0]<a[1])
		flag1=1;
	else
		flag1=0;
	for(i=0;i<n1;i++)
	{   
		if(flag==1)
		{
		c[k++]=a[i-1];
		}
		else
		{
		if(flag1==1 && a[i]<n3 && flag2!=(n1-1) )
		{
		c[k++]=a[i];
		flag2++;
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


	
