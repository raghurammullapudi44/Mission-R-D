#include<stdio.h>
#include<conio.h>
int fun(int *);
int main()
{
	int n,x;
		scanf_s("%d",&n);
	x=fun(&n);
	printf("%d",x);
    _getch();
	return 0;
}
int fun(int *n)
{
	int i=0,x=0,y=0,count=0,count1=0,n1;
	n1=*n;
	while(n1!=0)
	{
		n1/=10;
		count++;
	}
	
 if(*n!=0 && *n>0)
 {
	 while(*n!=0)
	 {
		 y=*n%10;
		 *n/=10;
		 x=x+y;
	 }
 }
 else
 {
	  while(*n!=0)
	 {
		 
		 y=*n%10;
		 *n/=10;
		 count1++;
		 if(count1<count)
		 x=x+y;
		 else
         x=-(x-y);
	 }
 }
 return x;
}
