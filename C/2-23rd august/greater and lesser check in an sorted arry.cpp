#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int * fun(int *,int,int);
int main()
{
	int *a,i,n,n1,*b;
	printf("enter size:");
	scanf_s("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	b=(int *)malloc(2*sizeof(int));
	printf("enter an sorted array:");
	for(i=0;i<n;i++)
		scanf_s("%d",&a[i]);
	printf("enter an number to check:");
	scanf_s("%d",&n1);
	b=fun(a,n,n1);
	printf("\ngreater numbers are:%d",b[0]);
	printf("\nlesser numbers are:%d",b[1]);
	_getch();
	return 0;
}
int * fun(int a[],int n,int n1)
{
	int i,count=0,count1=0,*b;
	b=(int *)malloc(2*sizeof(int));
	for(i=0;i<n;i++)
	{
		if(n1<a[i])
			count++;
		if(n1>a[i])
			count1++;
	}
	b[0]=count;
	b[1]=count1;
    return b;
}

