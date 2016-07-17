#include<stdio.h>
#include<malloc.h>

int * indexrem(int *,int,int,int,int);

int main()
{
	int *a,i,n,*b,I,J,n1,t;

	printf("enter the size of the array:");
  	    scanf("%d",&n);

	a=(int *)malloc(sizeof(int)*n);

	printf("enter the values:");
		for(i=1;i<=n;i++)
   			 scanf("%d",&a[i]);

	printf("enter the indexes:");
      		 scanf("%d %d",&I,&J);
	
	if(I>J)
	{
		t=I;
		I=J;
		J=t;
	}


	if( (J>n && I>n) || (J<1 && I<1) )
  		 printf("not possible\n");
	else
	{
                if((J==n && I==1)  || (J>=n && I<1) || (J>=n && I==1))
		{
			printf("empty array\n");
                        return 0;
		}

		if( (J<=n && I>1) || (J<n && I>=1) )
			n1=(n-1)-(J-I);
		else if( (J>n && I>1) )
			n1=I-1;
		else if( (J<n && I<1) )
			n1=n-J;
		else if(I==J)
			n1=n-1;
			
		b=(int *)malloc(sizeof(int)*n1);
			b=indexrem(a,n,I,J,n1);

		free(a);

		a=(int *)realloc(a,sizeof(int)*n1);

		printf("the resultant array is:");
			for(i=1;i<=n1;i++)
			{
  				  a[i]=b[i];
    				  printf("%d ",a[i]);
			}
	}

return 0;
free(a);
free(b);
}

int * indexrem(int a[],int n,int I,int J,int n1)
{
	int i,j=1,*b;

	b=(int *)malloc(sizeof(int)*n1);

	for(i=1;i<=n;i++)
	{
 		if(i<I || i>J)
     			b[j++]=a[i];
	}
return b;
}

