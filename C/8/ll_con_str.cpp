#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#pragma warning(disable: 4996)

void testcases();

char *malloc_char(char ip[]);

char * convert(char *);

char * convert_to_string(struct sll *);

struct sll * insert_in_list(int,struct sll *);

int ll_cmp(char *,char *);

struct test
{
	char input[44];
	char output[44];
}testDB[12]={{"12,34,56,78","12345678"},
			{"01,23,45","012345"},
			{"44,44","4444"},
			{"00,12,34","001234"},
			{"00,12,34","001234"},
			{"12,34,00","123400"},
			{"00,00,00","000000"},
			{"12,34,00,56","12340056"},
			{"11,11","1111"},
			{"10,10,11","101011"},
			{"  ,  ","  ,  "},
			{"\0","\0"}};
			

struct sll
{
	int data;
	struct sll *ptr;
};

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

int ll_cmp(char a[],char b[])
{
	if(strcmp(a,b)==0)
		return 0;
	else
		return 1;
}

char * convert(char a[])
{
	int i=0,y=0,flag=0;
	char *b;
	struct sll *head=NULL;

	while(a[i]!='\0')
	{
		if(a[i]==' ' || a[i]=='\0')
		{
			flag=1;
			break;
		}
		y=0;
		while(a[i]!=',')
		{
			if(a[i]=='\0' )
			{
				i--;
				break;
			}
			else
			{
				y=(y*10)+(a[i]-'0');
				i++;
			}
		}
		head=insert_in_list(y,head);
		i++;
	}
	if(flag==1)
		return a;
	return convert_to_string(head);
}

char * convert_to_string(struct sll * head)
{
	char *b;
	int i=0;
	b=(char *)malloc(sizeof(char)*1);
	struct sll *temp;
	temp=head;
	while(temp)
	{
		b=(char *)realloc(b,sizeof(char)*(i+2));
		b[i++]=((temp->data)/10)+'0';
		b[i++]=((temp->data)%10)+'0';
		temp=temp->ptr;
	}
	b[i]='\0';
	return b;
}

struct sll * insert_in_list(int n,struct sll *head)
{
	if(head==NULL)
	{
		head=(struct sll *)malloc(sizeof(struct sll));
		head->data=n;
		head->ptr=NULL;
		//printf("%d ",head->data);
		return head;
	}
	else
	{
		struct sll *temp,*temp1;
		temp=(struct sll *)malloc(sizeof(struct sll));

		temp->data=n;
		temp->ptr=NULL;

		temp1=head;

		while(temp1->ptr!=NULL)
			temp1=temp1->ptr;

		temp1->ptr=temp;

		//printf("%d ",temp->data);

		return head;
	}
}

	
void testcases()
{
	int i,check;
	char *a,*op;

	for(i=0;i<12;i++)
	{
		a=malloc_char(testDB[i].input);

		op=malloc_char(testDB[i].output);
		
		check=ll_cmp(op,convert(a));

		if(check==0)
			printf("passed\n");
		else 
			printf("failed\n");
	}
}

int main()
{
	testcases();
	getchar();
	return 0;
}
