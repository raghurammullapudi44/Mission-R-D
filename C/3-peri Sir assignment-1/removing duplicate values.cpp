#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable: 4996)
int * fun(int *,int);
int fun1(int);
int main()
{
	int *a,*b,n,i,count=0;
	printf("enter the array size:");
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	b=(int *)malloc(sizeof(int)*n);
	printf("enter %d numbers into the array:",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	b=fun(a,n);
	i=0;
	while(b[i]!='@')
	{
		i++;
		count++;
	}
	a=(int *)realloc(a,sizeof(int)*count);
	i=0;
	while(b[i]!='@')
	{
		a[i]=b[i];
		i++;
	}
	printf("the resultant array is:");
	for(i=0;i<count;i++)
		printf("%d ",a[i]);
	getch();
	return 0;
	free(a);
}
int * fun(int a[],int n)
{
	int i,j,k=0;
	for (i=0;i<n;i++) 
	{
		j=i+1;
      while(j<n)
	  {
         if(a[j]==a[i])
		  {
            for(k=j;k<n;k++)
			 {
               a[k]=a[k + 1];
            }
            n--;
         } 
		 else
            j++;
      }
   }
   a[k-1]='@';
   	return a;
}

