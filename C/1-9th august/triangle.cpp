#include<stdio.h>
#include<conio.h>
#include<math.h>
float sqrt(float);
float pow(float,float);
int fun(float,float,float);
	int main()
{
	int x1,y1,x2,y2,x3,y3,x;
	float a,b,c;
	scanf_s("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
	a=pow((x2-x1),2.0)+pow(( y2-y1),2.0);
	b=pow((x3-x1),2.0)+pow((y3-y1),2.0);
	c=pow((x2-x3),2.0)+pow((y2-y3),2.0);
	a=sqrt(a);
	b=sqrt(b);
	c=sqrt(c);
	x=fun(a,b,c);
	
	if(x==0)
		printf("\nnot valid co ordinates");
    if(x==1)
		printf("equvi lateral");
	if(x==2)
		printf("\n scalene");
	if(x==3)
		 printf("\nright angle");

	if(x==4)
		printf("\nmay be another form of triangle");
	_getch();
	return 0;
	}
	int fun(float a,float b,float c)
	{
		int ret;
		if(a>b+c && b>a+c && c>a+b)
			ret=0;
		else if(a==b && b==c && c==a)
			ret=1;
		else if(pow(a,2)==(pow(b,2)+pow(c,2)) || pow(b,2)==(pow(a,2)+pow(c,2)) || pow(c,2)==(pow(b,2)+pow(a,2)))
		ret=3;
		else if(a!=b && a!=c &&b!=c)
			ret=2;
		
		else
			ret=4;
		if(ret<4)
			return ret;
		else
			return 4;
	}



