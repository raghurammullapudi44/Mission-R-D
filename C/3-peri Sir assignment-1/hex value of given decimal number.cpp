#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable: 4996)
char * fun(char *,int);
int con(char *);
int main()
{
	char *h,*d;
	int n,l=0,i,ch,d1;
	while(1)
	{
		printf("\nenter the method of choices 1 or 2 and 3 for exit:");
	scanf("%d",&ch);
	if(ch==3)
		exit(0);
	printf("\nenter the size of the decimal number:");
	scanf("%d",&n);
	printf("\nenter the decimal number:");
	d=(char *)malloc(sizeof(char)*n);
	scanf("%s",d);
	switch(ch)
	{
	case 1:d1=con(d);
		   printf("\nhexadecimal number by method 1 is:%X\n",d1); 
		   break;
	case 2:while(d[l]!='\0')
	       l++;
	       h=(char *)malloc(l*sizeof(char));
	       h=fun(d,l);
		   printf("\nhexadecimal number by method 2 is is:\n");
	       for(i=l-1;i>=0;i--)
	       printf("%c",h[i]);
		   break;
	}
	}
	getch();
	return 0;
	free(d);
	free(h);
}
char * fun(char *d,int l)
{
	int d1,i=0,n,temp;
	char *h=(char *)malloc(l*sizeof(char));
	d1=con(d);
	n=d1;
	while(n!=0)
	{
         temp=n%16;
      if( temp<10)
           temp=temp+48;
      else
         temp=temp+55;
      h[i++]=temp;
      n=n/16;
   }
	h[i]='\0';
	return h;
}
	
int con(char *s)
{
	int i,d=0;
	for(i=0;s[i]!='\0';i++)
    d=(d*10)+s[i]-'0';
	return d;
}
