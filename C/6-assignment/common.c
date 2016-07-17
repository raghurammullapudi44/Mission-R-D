#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * malloc_char(char *);

int a_amp(char **,char **);

void realloc_char(char **,int);

void stringcopy(char *,char *);

char ** commonwords(char *,char *);

char ** words(char *);

void testcases();

struct test
{
	char input1[88];
	char input2[88];
	char output[88][88];
}testDB[10]={{{"rama raghu mullapudi ram"},{"raghu mullapudi ram"},{"raghu","mullapudi","ram"}},
		{{"kony labs"},{"chemistry labs"},{"labs"}},
		{{"	google terra data"},{"terradata"},{"NULL"}},
		{{"microsoft is my aim   so i w i ll"},{"i will"},{"i"}},
		{{"coding is my passion"},{"coding is an easy task"},{"coding","is"}},
		{{"\0"},{"empty"},{"NULL"}},
		{{"i will be placed in microsoft"},{"for sure"},{"NULL"}},
		{{"coding is taught by peri sir"},{"and we are assisted by our almuni"},{"by"}},
		{{"i am raghu ram"},{"mullapudi i s my surnamae"},{"i"}},
		{{" gooooooooooooo ooooooooooo ggggggg lllllllllll eeeeee"},{"g o o g l e"},{"NULL"}}};

char * malloc_char(char ip[])
{
	int i;
	char *a;
	a=(char *)malloc(sizeof(char)*1);
	for(i=0;ip[i]!='\0';i++)
	{
		a=(char *)realloc(a,sizeof(char)*(i+1));
		a[i]=ip[i];
	}
	a[i]='\0';
	return a;
}

int a_cmp(char *a,char *b)
{
	if(strcmp(a,b)==0)
		return 0;
	else
		return 1;
}

void realloc_char(char **c,int k)
{
	c=(char **)realloc(c,sizeof(char *)*k);
	c[k]=(char *)malloc(sizeof(char)*44);
}

void stringcopy(char a[],char b[])
{
	int i;
	for(i=0;b[i]!='\0';i++)
	{
		a[i]=b[i];
	}
	a[i]='\0';
}

char ** words(char a[])
{
	int i=0,j=0,k=0;

	char **b;

	b=(char **)malloc(sizeof(char *)*44);
	for(k=0;k<44;k++)
		b[k]=(char *)malloc(sizeof(char)*44);


	while(a[i]!='\0')
	{
		if(a[i]!=32)
		{
			k=0;
			while(a[i]!=32 && a[i]!='\0')
			{
				b[j][k++]=a[i];
				i++;
			}
			b[j][k++]='\0';
			j++;
			//realloc_char(b,j);
		}
		else
			i++;
	}

	if(j==0)
		stringcopy(b[0],"NULL");
	else
		stringcopy(b[j],"NULL");
	
return b;
}

char ** commonwords(char *a,char *b)
{
	char **c,**d,**e;
	int i,j,len1,len2,k=0,flag,l;

	e=(char **)malloc(sizeof(char *)*44);
	for(k=0;k<44;k++)
		e[k]=(char *)malloc(sizeof(char)*44);

	c=words(a);
	d=words(b);

	for(len1=0;a_cmp(c[len1],"NULL")!=0;len1++);

	for(len2=0;a_cmp(d[len2],"NULL")!=0;len2++);

	k=0;

	for(i=0;i<len1;i++)
	{
		flag=0;
		for(j=0;j<len2;j++)
		{
			if(a_cmp(c[i],d[j])==0)
			{
				if(k==0)
				{
					stringcopy(e[k],c[i]);
					k++;
				}
				else
				{
					for(l=0;l<k;l++)
					{
			   			 if(a_cmp(c[i],e[l])==0)
						 {			
							flag++;
							break;
						 }
					}
			   		 if(flag==0)
					 {
						stringcopy(e[k],c[i]);
						k++;
					}
				}
			}
		}
	}   

	for(i=0;i<k;i++)
	{
		stringcopy(c[i],e[i]);
	}
		stringcopy(c[k],"NULL");
return c;
}



void testcases()
{
	int i,j,k,check;
	char *a,*b,**op;
	
	for(i=0;i<10;i++)
	{
		check=4;

		a=malloc_char(testDB[i].input1);
		b=malloc_char(testDB[i].input2);
		

		op=commonwords(a,b);

		for(k=0;a_cmp(op[k],"NULL")!=0;k++);

		if(k!=0)
		{
			check=0;			

			for(j=0;j<k;j++)
			{

				if(a_cmp(op[j],testDB[i].output[j])==0)
					check++;
			}
		}
		else
		{
			if(a_cmp(op[0],testDB[i].output[0])==0)
				check=0;
		}


		if(check==k)
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


