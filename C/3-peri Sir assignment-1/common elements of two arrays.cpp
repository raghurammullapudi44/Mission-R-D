// using character arraysssssssssssssssssssssssssssssss


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable: 4996)
int * fun(int *,int *,int,int);
int main()
{
	int n1,n2,n,i;
	int *a,*b,*c;
	printf("enter the sizes of array 1 & array 2:");
	scanf("%d %d",&n1,&n2);
	a=(int *)malloc(sizeof(int)*n1);
	b=(int *)malloc(sizeof(int)*n2);
	if(n1>=n2)
	{
		n=n1;
		c=(int *)malloc(sizeof(int)*n);
	}
	else
	{
		n=n2;
		c=(int *)malloc(sizeof(int)*n);
	}
	printf("enter  array 1:");
for(i=0;i<n1;i++)
scanf("%d",&a[i]);
    printf("enter  array 2:");
for(i=0;i<n2;i++)
scanf("%d",&b[i]);
	c=fun(a,b,n1,n2);
	if(c[0]=='@')
		printf("no common elements");
	else
	    {
	    	for(i=0;c[i]!='@';i++)
	    	printf("%d ",c[i]);
	    }
	getch();
	return 0;
	free(a);
	free(b);
	free(c);
}
int * fun(int *a,int *b,int n1,int n2)
{
	int i,j,k=0,l,flag;
	int *c;
	if(n1>=n2)
		c=(int *)malloc(sizeof(int)*n1);
	else
		c=(int *)malloc(sizeof(int)*n2);
	for(i=0;i<n1;i++)
	{
		flag=0;
		for(j=0;j<n2;j++)
			if(a[i]==b[j])
				if(k==0)
				c[k++]=a[i];
				else
				{
				for(l=0;l<k;l++)
			    if(a[i]==c[l])
					flag++;
			    if(flag==0)
					c[k++]=a[i];
				}
	}
	c[k]='@';
	return c;
}
