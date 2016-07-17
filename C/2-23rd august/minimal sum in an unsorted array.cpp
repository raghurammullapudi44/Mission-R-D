#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int * fun(int *,int);
int main()
{
	int *a,i,n,*b;
	printf("enter size:");
	scanf_s("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	b=(int *)malloc(2*sizeof(int));
	printf("enter an unsorted array:");
	for(i=0;i<n;i++)
		scanf_s("%d",&a[i]);
	b=fun(a,n);
	printf("\nminimal sum combination numbers are: %d %d",b[0],b[1]);
	
	_getch();
	return 0;
}
int * fun(int a[],int n)
{
	int i,*d,k=0;
	d=(int *)malloc(2*sizeof(int));
	d[0]=a[0];
    d[1]=a[1];
    for(i=2;i<n;i++)
	{
    if(d[0]>a[i])
	{
    d[0]=a[i];
	k=i;
	}
	}
	for(i=2;i<n;i++)
     if(k!=i && d[1]>a[i])
    d[1]=a[i];
    return d;
}

