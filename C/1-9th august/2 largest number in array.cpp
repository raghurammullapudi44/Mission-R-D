#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int * fun(int *,int);
int main()
{
	int *a,n,i,*b;
	
	scanf_s("%d",&n);
	a=(int *)malloc(n*sizeof(int));
    b=(int *)malloc(2*sizeof(int));
	for(i=0;i<n;i++)
	scanf_s("%d",&a[i]);
	b=fun(a,n);
	
	for(i=0;i<2;i++)
	printf("%d ",b[i]);
	free(a);
	free(b);
	_getch();
	return 0;
}
int * fun(int a[],int n)
{
	int i,*d;

	d=(int *)malloc(2*sizeof(int));

    d[0]=a[0];
    d[1]=a[1];

    for(i=2;i<n;i++)
	{
		if(d[0]<a[i])
			 d[0]=a[i];
	}
	for(i=2;i<n;i++)
	{
		if(d[0]!=a[i]&&d[1]<a[i])
			d[1]=a[n-i];
	}
return d;
}




