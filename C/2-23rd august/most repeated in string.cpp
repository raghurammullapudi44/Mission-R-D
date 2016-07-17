#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable: 4996)
char * fun(char *,int);
int main()
{
	char *s1,*s2;
	int n1;
	printf("enter size:");
	scanf("%d",&n1);
	s1=(char *)malloc(sizeof(char)*n1);
	s2=(char *)malloc(sizeof(char)*44);
	fflush(stdin);
	printf("enter string :");
	gets(s1);
	s2=fun(s1,n1);
	printf("%s",s2);
	getch();
	free(s1);
	free(s2);
	return 0;
}
char * fun(char *s1,int n1)
{
	int i,j;
	char *b;
	b=(char *)malloc(sizeof(char)*44);
	
	for(i=0;i<n1;i++)
    {
		
	for(j=i+1;j<n1;j++)
	{
		if(s1[i]==s1[j])
			++b[0]=s1[i];	
	}
	}
	b[1]='\0';
	return b;
}


	