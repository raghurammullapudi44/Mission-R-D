#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int * fun(int *,int);
int main()
{
	int *a,n,*b,i;
	printf("enter size:");
	scanf_s("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	b=(int *)malloc(n*sizeof(int));
	printf("enter an two position misplaced array only:");
	for(i=0;i<n;i++)
		scanf_s("%d",&a[i]);
	b=fun(a,n);
	printf("final array:");
	for(i=0;i<n;i++)
		printf("%d ",b[i]);
	_getch();
	return 0;
}
int * fun(int a[],int n)
{
	int i,j,flag=0,flag1=0,*b,count=0,count1=0,flag2=0,t;
	b=(int *)malloc(n*sizeof(int));
	for(i=1;i<n;i++)
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
	
	for(i=0;i<n;i++)
		b[i]=a[i];
	for(i=0;i<n;i++)
	for(j=i+1;j<n;j++)
	if(flag1==1&&a[i]>a[j]  || flag1==0&&a[i]<a[j])
	{
			if(flag2==0)
			{
			count=i;
			count1=j;
			flag2++;
			}
			else
			count1=j;
	}
		t=b[count];
		b[count]=b[count1];
		b[count1]=t;
	return b;
}
