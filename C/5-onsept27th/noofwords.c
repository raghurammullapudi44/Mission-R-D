#include<stdio.h>
#include<stdlib.h>

int a_amp(int,int);

int  no_ofwords(char *);

struct test
{
	char input[40];
	int output;
}testDB[10]={{{"kony labs"},2},
		{{"anil neerukonda institute"},3},
		{{"    t e r r a d a t a    "},9},
		{{"    "},0},
		{{"google "},1},
		{{" Raghu"},1},
		{{"  rajasri r aghu "},3},
		{{"Rajasri\0    "},1},
		{{"     "},0},
		{{" v vtyv ty vt v"},5}};

int a_cmp(int a,int b)
{
	if(a==b)
		return 0;
	else
		return 1;
}

int no_ofwords(char a[])
{
	int i=0,wordcount=0,j=0;
	char words[44][44];

	while(a[i]!='\0')
	{
		if(a[i]!=32)
		{
			while(a[i]!=32 && a[i]!='\0')
			{
				words[wordcount][j++]=a[i];
				i++;
			}			
			printf("%s ",words[wordcount]);
			j=0;
			wordcount++;
		}
		else
			i++;
	}
	
	return wordcount;
}

void testcases()
{
	int i,check,wcount;
	
	for(i=0;i<10;i++)
	{

		wcount=no_ofwords(testDB[i].input);

		check=a_cmp(wcount,testDB[i].output);

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


