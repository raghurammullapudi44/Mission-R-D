#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable: 4996)
char * fun(char *,char *,int);
int main()
{
	char *s1,*s2,*s3;
	int n1,n2;
	printf("enter sizes:");
	scanf("%d%d",&n1,&n2);
	s1=(char *)malloc(sizeof(char)*n1);
	s2=(char *)malloc(sizeof(char)*n2);
	s3=(char *)malloc(sizeof(char)*44);
	fflush(stdin);
	printf("enter string1:");
	gets(s1);
	printf("enter string2:");
	fflush(stdin);
	gets(s2);
	s3=fun(s1,s2,n1);
	fflush(stdin);
	if(s3[0]=='\0')
    printf("no mathes");
	else
	printf("%s",s3);
	getch();
	return 0;
}
char * fun(char *s1,char *s2,int n1)
{
	int i,j,k=0;
	char *b;
	b=(char *)malloc(sizeof(char)*44);
	for(i=0;i<n1;i++)
	{
		j=i;
			if(s1[i]==s2[j])
			{
				b[k++]=s1[i];
				b[k++]=':';
				b[k++]=i+'0';
				b[k++]=' ';
			}
			
		
	}
	b[k]='\0';
	return b;
}




