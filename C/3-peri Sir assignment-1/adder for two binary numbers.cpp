#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable: 4996)
char * fun(char *,char *,int,int,int);
int cary1(int *);
int main()
{
int i,n1,n2,n;
char *b1,*b2,*sum;
printf("enter the sizes of two arrays in which numbers are stored:");
scanf("%d %d",&n1,&n2);
b1=(char *)malloc(sizeof(char)*n1);
b2=(char *)malloc(sizeof(char)*n2);
printf("enter the binary number of %d size:",n1);
scanf("%s",b1);
printf("enter the binary number of %d size:",n2);
scanf("%s",b2);
if(n1>=n2)
{
	n=n1;
sum=(char *)malloc(n*sizeof(char));
}
else
{
	n=n2;
sum=(char *)malloc(sizeof(char)*n);
}
if(n1>=n2)
sum=fun(b1,b2,n1,n2,n);
else
sum=fun(b2,b1,n2,n1,n);
printf("the resultant binary number:");
printf("%s",sum);
getch();
return 0;
free(b1);
free(b2);
free(sum);
}
char * fun(char *b1,char *b2,int n1,int n2,int n)
{
int i,j,*b3,*b4,*cary;
char *sum;
int *sum1;
b3=(int *)malloc(sizeof(int)*n1);
b4=(int *)malloc(sizeof(int)*n2);
sum1=(int *)malloc(n*sizeof(int));
sum=(char *)malloc(n*sizeof(char));
cary=(int *)malloc((n+1)*sizeof(int));
for(i=0;i<n1;i++)
b3[i]=b1[i]-'0';
for(i=0;i<n2;i++)
b4[i]=b2[i]-'0';
i=n1-1;
j=n2-1;
cary[i]=0;
while(i>=0)
{
if(j>=0)
{
sum1[i]=b3[i]+b4[j]+cary[i];
cary[i-1]=cary1(&sum1[i]);
}
else
{
sum1[i]=b3[i]+cary[i];
cary[i-1]=cary1(&sum1[i]);
}
i--;
j--;
}
for(i=0;i<n;i++)
sum[i]=sum1[i]+'0';
sum[i]='\0';
return sum;
}
int cary1(int *a)
{
	int ret=0;
if(*a==0)
ret=0;
if(*a==1)
ret=1;
if(*a==2)
{
*a=0;
ret=1;
}
if(*a==3)
{
	*a=1;
	ret=1;
}
return ret;
}