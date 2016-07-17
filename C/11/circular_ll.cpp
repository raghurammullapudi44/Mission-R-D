#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#pragma warning(disable: 4996)

void testcases();

char *malloc_char(char ip[]);

struct sll * convert_to_list(char *);

struct sll * insert_in_list(int,struct sll *);

struct sll * ins_in_pos_list(struct sll *,int);

int ll_cmp(struct sll *,struct ll *);

struct test
{
	char input[44];
	int pos;
	char output[44];
}testDB[3]={{"1234",3,"12334"},
{"1345",0,"01345"},
{"1345",6,"13456"}};
			
			

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

		if(head->ptr==NULL)
			head->ptr=temp;
		else
		{
			temp1=head;

			while(temp1->ptr!=NULL)
				temp1=temp1->ptr;

			temp1->ptr=temp;

		//printf("%d ",temp->data);
		}

			return head;
	}
}

struct sll * ins_in_pos_list(struct sll * head,int pos)
{
	struct sll *temp=head,*temp1=head,*temp2=NULL,*temp3=NULL;
	int i,flag=0;

	temp2=(struct sll *)malloc(sizeof(struct sll));
		temp2->data=pos;
		temp2->ptr=NULL;

	if(head->ptr==NULL)
	{
		if(head->data<pos)
		{
			temp2->ptr=head;
			head=temp2;
		}
		else
		{
			head->ptr=temp2;
			temp2->ptr=head;
		}
	}

	else
	{
		while(temp1->ptr!=NULL)
			temp1=temp1->ptr;
		temp1->ptr=head;

		while(temp->ptr!=head && temp->data<=pos)
		{
			temp3=temp;
			temp=temp->ptr;
		}
		temp3->ptr=temp2;
		temp2->ptr=temp;
	}
	return head;
}

	
void testcases()
{
	int i,check,pos;
	char *a,*op;

	for(i=0;i<1;i++)
	{
		struct sll *ihead,*ohead,*j;

		pos=testDB[i].pos;

		a=malloc_char(testDB[i].input);

		op=malloc_char(testDB[i].output);

		ihead=ins_in_pos_list(convert_to_list(a),pos);

		ohead=convert_to_list(op);

		//for(j=ohead;j!=NULL;j=j->ptr)
			//printf("%d ",j->data);

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
