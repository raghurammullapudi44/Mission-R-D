
            //program to find LCM of N numbers

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable: 4996)
int fun(int *,int);
int main()
{
	int *a,n,i,x;
	printf("enter the size of the array:");
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	printf("enter %d numbers:",n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	x=fun(a,n);
	printf("LCM is:%d",x);
	getch();
	return 0;
	free(a);
}
int fun(int a[],int n)
{
	int i,n1,n2=1,j,count;
	
	for(i=0;i<n;i++)
		if(a[i]==0)
		return 0;
	n1=a[0];
	for(i=1;i<n;i++)
			if(a[i]>n1)
				n1=a[i];
	for(i=0;i<n;i++)
		n2=n2*a[i];

	for(i=n1;i<=n2;i++)
	{
	    if(i%n1==0)
		{
		count=0;
		for(j=0;j<n;j++)
		{
			if((i%a[j])==0)
				count++;
		}
		if(count==n)
		return i;
		}
	}
}