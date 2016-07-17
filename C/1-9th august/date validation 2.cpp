#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

//#pragma warning(disable: 4996)

int con(char *);
int fun(int,int,int);

int main()
{
	int m,d,y,x;
	char *s,*s1,*s2,*s3;
	s=(char *)malloc(sizeof(char)*10);
	s1=(char *)malloc(sizeof(char)*2);
	s2=(char *)malloc(sizeof(char)*2);
	s3=(char *)malloc(sizeof(char)*4);
	//  input should be in format of dd/mm/yyyy
		gets(s);
        strncpy(s1,s+0,2);
        s1[2]='\0';
        strncpy(s2,s+3,2);
		s2[2]='\0';    
		strncpy(s3,s+6,4);
		s3[4]='\0';    
     	d=con(s1);
	    m=con(s2);
	    y=con(s3);
	    x=fun(d,m,y);
	if(x==1)
		printf("valid");
	if(x==0)
		printf("not valid");
	getch();
	return 0;
}
int fun(int d,int m,int y)
{
	int d1;
	switch(m)
{
      case 4:
      case 6:
      case 9:
      case 11:
		      d1=30;
      break;
       case 1:
       case 3:
       case 5:
       case 7:
	   case 8:
       case 10:
       case 12:
		       d1=31;
       break;
       case 2:
		   if((y%4)==0)
              d1=29;
              else
               d1=28;
       break;
}
if(((m==4)||(m==6)||(m==9)||(m==11)&&(d<=d1)))
return 1;
else if(((m==1)||(m==3)||(m==5)||(m==7)||(m==8)||(m==10)||(m==12))&&(d<=d1))
return 1;
else if((m==2)&&(d<=d1))
return 1;
else
return 0;
}
int con(char *s)
{
	int i,d=0;
	for(i=0;s[i]!='\0';i++)
    d=(d*10)+s[i]-'0';
	return d;
}