#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable: 4996)
char * fun(char *,int);
int con(char *);
int main()
{
	char *s1,*d;
	int n1;
	printf("enter the size of string:");
	scanf("%d",&n1);
	s1=(char *)malloc(sizeof(char)*n1);
	d=(char *)malloc(sizeof(char)*n1);
	printf("enter the string:");
	scanf("%s",s1);
	d=fun(s1,n1);
	printf("bigger number is:%s",d);
	getch();
	return 0;
}
char * fun(char *s1,int n1)
{
	char *s2,*s3;
	int i,count=0,j=0,k=0;
	s2=(char *)malloc(sizeof(char)*n1);
	s3=(char *)malloc(sizeof(char)*n1);
	for(i=0;i<n1;i++)
		if(s1[i]==',')
			break;
		else
		{
			count++;
			s2[j++]=s1[i];
		}
		s2[j]='\0';
		for(i=(count+1);s1[i]!='\0';i++)
            s3[k++]=s1[i];
		s3[k]='\0';
	if(con(s2)>con(s3))
		return s2;
	else
	    return s3;
}
int con(char *s)
{
	int i,d=0;
	for(i=0;s[i]!='\0';i++)
    d=(d*10)+s[i]-'0';
	return d;
}