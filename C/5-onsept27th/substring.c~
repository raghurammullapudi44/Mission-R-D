#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int a_amp(char *,char *);

char * substring(char *,int,int,int);

char * string(int,int,int,int);

char * malloc_char(char *);

struct test
{
	char input[20];
	int I;
	int J;
	char output[20];
}testDB[10]={{{"hyderabad"},0,8,{"hyderabad"}},
		{{"ban glore chennai"},3,9,{" glore "}},
		{{"ban glore chennai"},9,44,{" chennai"}},
		{{"kanpur    "},-1,0,{"k"}},
		{{"madras    chennai"},-11,16,{"madras    chennai"}},
		{{"Mumbai"},-20,20,{"Mumbai"}},
		{{"bom bay "},-4,4,{"bom b"}},
		{{"a    gadu"},1,4,{"    "}},
		{{"\0"},0,8,{"\0"}},						
		{{"viZag    \0"},6,2,{"Zag  "}}};

char * malloc_char(char ip[])
{
	int i;
	char *a;
	a=(char *)malloc(sizeof(char)*1);
	for(i=0;ip[i]!='\0';i++)
	{
		a=(char *)realloc(a,sizeof(int)*(i+1));
		a[i]=ip[i];
	}
	a[i]='\0';
	return a;
}

int a_cmp(char a[],char b[])
{
	if(strcmp(a,b)==0)
		return 0;
	else
		return 1;
}

char * string(int i,int I,int J,int len)
{
	char *a;
		a=malloc_char(testDB[i].input);

		if(I>=0 && J<len)
			return (substring(a,I,J,((J-I)+1)));

		if(I<0 && J<len)
			return (substring(a,0,J,(J+1)));

		if(I>=0 && J>=len)
			return (substring(a,I,len-1,(len-I)));

		if(I<0 && J>=len)
			return (substring(a,0,len-1,(len-1)));
}



char * substring(char a[],int I,int J,int len1)
{
	char *b;
	int i,j=0;
	
	b=(char *)malloc(sizeof(char)*(len1+1));

	for(i=I;i<=J;i++)
		b[j++]=a[i];
	
	b[j]='\0';

	return b;

}

void testcases()
{
	int i,check,len,len1,I,J,t;
	char *a;
	
	for(i=0;i<10;i++)
	{

		I=testDB[i].I;
		J=testDB[i].J;

		if(I>J)
		{
			t=I;
			I=J;
			J=t;
		}

		for(len=0;testDB[i].input[len]!='\0';len++);	

		if((I>=len && J>=len) || (I<0 && J<0))
			a[0]='\0';
		else		
			a=string(i,I,J,len);
			
		check=a_cmp(a,testDB[i].output);


		if(check==0)
			printf("passed\n");
		else 
			printf("failed\n");

	}

}

int main()
{
	testcases();
	return 0;
}


