            
// program to check whether the two squares intersect or not and if they overlap one on the other completely prints the area of intersection

#include<stdio.h>
#include<conio.h>
#pragma warning(disable: 4996)
typedef struct square
{
	int x1,y1,x2,y2,x3,y3,x4,y4,a;
};
int fun(square,square);
int fun1(square,square);
square s1,s2;
int main()
{
	int x;
	printf("enter the co-ordinates of 1st square && its side length:");
	scanf("%d %d %d",&s1.x1,&s1.y1,&s1.a);
	printf("enter the co-ordinates of 2nd square && its side length:");
	scanf("%d %d %d",&s2.x1,&s2.y1,&s2.a);
	x=fun(s1,s2);
	if(x==0)
		printf("the two squares do not intersect at all");
	else if((x==s1.a) || (x==s2.a))
		printf("area of intersection of two squares is:%d",x);
	else
        printf("the two squares may intersect but they do not overlap completely in to the other");
	getch();
	return 0;
}
int fun(square s1,square s2)
{
	int x;
	s1.x2=s1.x1+s1.a;
	s1.y2=s1.y1+s1.a;

	s2.x2=s2.x1+s2.a;
	s2.y2=s2.y1+s2.a;

	if((s1.x1 < s2.x2) && (s1.x2 > s2.x1) && (s1.y1 < s2.y2) && (s1.y2 > s2.y1))
	{
		x=fun1(s1,s2);
		return x;
	}
	else
		return 0;
}
int fun1(square s1,square s2)
{
	int count=0;
	s1.x3=s1.x1+s1.a;
	s1.y3=s1.y1;
	s1.x4=s1.x1;
	s1.y4=s1.y1+s1.a;
	
	s2.x3=s2.x1+s2.a;
	s2.y3=s2.y1;
	s2.x4=s2.x1;
	s2.y4=s2.y1+s2.a;

	if((s1.x3 > s2.x3) && (s1.y3 < s2.y3) && (s1.x4 < s2.x4) && (s1.y4 > s2.y4) && (s1.a > s2.a))
	{
		count++;
		return s2.a;
	}

	if((s1.x3 < s2.x3) && (s1.y3 > s2.y3) && (s1.x4 > s2.x4) && (s1.y4 < s2.y4) && (s1.a < s2.a))
	{
		count++;
		return s1.a;
	}
	if(count==0)
		return -1;
}

	
