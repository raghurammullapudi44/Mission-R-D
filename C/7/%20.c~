#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int a_amp(char *,char *);

void percentile20(char *);

char * malloc_char(char *);

struct test
{
	char input[444];
	char output[444];
}testDB[10]={{{"kony     labs"},{"kony%20%20%20%20%20labs"}},
		{{"      anil  neeeerukonda  institute  "},{"%20%20%20%20%20%20anil%20%20neeeerukonda%20%20institute%20%20"}},
		{{"    t e r r a d a t a    "},{"%20%20%20%20t%20e%20r%20r%20a%20d%20a%20t%20a%20%20%20%20"}},
		{{"    a"},{"%20%20%20%20a"}},
		{{"    gooooo  ooogle     "},{"%20%20%20%20gooooo%20%20ooogle%20%20%20%20%20"}},
		{{" Raghu"},{"%20Raghu"}},
		{{"  rajasri r aghu "},{"%20%20rajasri%20r%20aghu%20"}},
		{{"Rajasri\0    "},{"Rajasri"}},
		{{"     "},{"%20%20%20%20%20"}},
		{{" v vtyv ty vt v"},{"%20v%20vtyv%20ty%20vt%20v"}}};
		
int a_cmp(char a[],char b[])
{
	if(strcmp(a,b)==0)
		return 0;
	else
		return 1;
}

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


void percentile(char *s)
{
	int i,j=0,k=0,len;

	for(len=0;s[len]!='\0';len++);

	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]==32)
		{
			j++;
		}
	}

	j=len+(j*2);

	s=(char *)realloc(s,sizeof(char)*j);

	while(len>=0)
	{
		if(s[len]!=32)
		{
			s[j--]=s[len];	
		}
		else
		{
			s[j--]='0';
			s[j--]='2';
			s[j--]='%';
		}
		len--;
	}
}


void testcases()
{
	int i,check;
	char *a,*op;
	
	for(i=0;i<10;i++)
	{
		a=malloc_char(testDB[i].input);

		percentile(a);

		op=malloc_char(testDB[i].output);

		check=a_cmp(a,op);

		if(check==0)
			printf("passed\n");
		else 
			printf("failed\n");
		free(a);
		free(op);
	}

}

int main()
{
	testcases();
	return 0;
}

