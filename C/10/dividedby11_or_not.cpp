#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#pragma warning(disable: 4996)

void testcases();

char *malloc_char(char ip[]);

struct sll * convert_to_list(char *);

struct sll * insert_in_list(int,struct sll *);

int divideby11_or_not(struct sll *);

int a_cmp(int,int);

struct test
{
	char input[44];
	int even_odd;
}testDB[11]={{"121",0},   // '0' for divisible and '1' for not divisible
			{"4323",0},
			{"4444",0},
			{"000000000004323",0},
			{"0012375",0},
			{"123400",1},
			{"000000101",1},
			{"12340056",1},
			{"01111",0},
			{"101011",1},
			{"111111111111111",1}};
			

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

int a_cmp(int a,int b)
{
	if(a==b)
		return 0;
	else
		return  1;
}

struct sll * convert_to_list(char a[])
{
	int i=0;
	struct sll *head=NULL;
	
	while(a[i]!='\0')
	{
		head=insert_in_list(a[i]-'0',head);
		i++;
	}
	return head;
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

int divideby11_or_not(struct sll * head)
{
	int count=0,even_sum=0,odd_sum=0;
	
	while(head != NULL)
	{
		if(count%2 == 0)
		{
			even_sum += head->data;
		}
		else
		{
			odd_sum +=head->data;
		}
		head=head->ptr;
		count++;
	}

	if(even_sum == odd_sum)
		return 0;
	else
		return 1;
}

	
void testcases()
{
	int i,check,op,b;
	char *a;

	for(i=0;i<11;i++)
	{
		struct sll *ihead,*ohead,*j;

		a=malloc_char(testDB[i].input);

		op=testDB[i].even_odd;

		b=divideby11_or_not(convert_to_list(a));

		check=a_cmp(b,op);

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
