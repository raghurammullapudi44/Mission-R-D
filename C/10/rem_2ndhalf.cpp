#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#pragma warning(disable: 4996)

void testcases();

char *malloc_char(char ip[]);

struct sll * convert_to_list(char *);

struct sll * insert_in_list(int,struct sll *);

struct sll * rem_2ndhalf(struct sll *);

int ll_cmp(struct sll *,struct ll *);


struct test
{
	char input[44];
	char output[22];
}testDB[10]={{"12345678","1234"},
			{"0123456","012"},
			{"11111111","1111"},
			{"22225678","2222"},
			{"222245678","2222"},
			{"0001","00"},
			{"876542222","8765"},
			{"87652222","8765"},
			{"87654321","8765"},
			{"",""}};

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

int ll_cmp(struct sll *ihead,struct sll *ohead)
{
	int count=0,count1=0;
	struct sll *temp=ihead;

	while(temp)
	{
		count++;
		temp=temp->ptr;
	}

	while(ihead)
	{
		if(ihead->data==ohead->data)
			count1++;
		ihead=ihead->ptr;
		ohead=ohead->ptr;
	}
	if(count==count1)
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

struct sll * rem_2ndhalf(struct sll * head)
{
	if(head==NULL)
		return NULL;
	else
	{
		struct sll *temp=head,*slow=head,*fast=head;

		while(fast->ptr->ptr!=NULL && fast->ptr->ptr->ptr!=NULL)
		{
			slow=slow->ptr;
			fast=fast->ptr->ptr;
		}
		slow->ptr=NULL;
		return head;
	}
}

struct sll * insert_in_list(int n,struct sll *head)
{
	if(head==NULL)
	{
		head=(struct sll *)malloc(sizeof(struct sll));
		head->data=n;
		head->ptr=NULL;
		return head;
		//printf("%d ",head->data);
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

		return head;

		// printf("%d ",temp->data);
	}
}

	
void testcases()
{
	int i,check,median;
	char *a,*op;

	for(i=0;i<10;i++)
	{
		struct sll *ihead=NULL,*ohead=NULL;

		a=malloc_char(testDB[i].input);

		ihead=rem_2ndhalf(convert_to_list(a));

		op=malloc_char(testDB[i].output);

		ohead=convert_to_list(op);
		
		check=ll_cmp(ihead,ohead);

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
