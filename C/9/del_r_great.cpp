#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#pragma warning(disable: 4996)

void testcases1();

char *malloc_char(char ip[]);

struct sll * convert_to_list(char *);

struct sll * insert_in_list(int,struct sll *);

struct sll * del(struct sll *);

struct sll * del_1(struct sll *);

struct sll * rev_list(struct sll *);

int ll_cmp(struct sll *,struct ll *);

struct test
{
	char input[88];
	char output[88];
}testDB[10]={{{"1,2,3,4,5,6,7,8"},{"8"}},
			{{"2,20,30,4"},{"30,4"}},
			{{"12,15,10,11,5,6,2,3"},{"15,11,6,3"}},
			{{"1,2,3,4,5,6,7,8"},{"8"}},
			{{"4"},{"4"}},
			{{""},{""}},
			{{"1,22,33,44,55,66,77,00"},{"77,00"}},
			{{"10,20,30,40"},{"40"}},
			{{"00,00,00,00"},{"00,00,00,00"}},
			{{"0,1,2,3,6,0"},{"6,0"}}};
			

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
	int i=0,y=0,flag=0;
	struct sll *head=NULL;

	while(a[i]!='\0')
	{
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

struct sll * rev_list(struct sll * head)
{
	struct sll *temp1=NULL,*temp=head;

	while(head!=NULL)
	{
		temp=head;
		head=head->ptr;
		
		if(temp1==NULL)
		{
			temp->ptr=NULL;
			temp1=temp;
		}
		else
		{
			temp->ptr=temp1;
			temp1=temp;
		}
	}

	//for(j=temp1;j!=NULL;j=j->ptr)
			//printf("%d ",j->data);

	return temp1;
}

struct sll * del_1(struct sll * head)
{
	head=rev_list(head);

	struct sll *temp1=NULL,*temp=head,*max=head;

	while(temp!=NULL && temp->ptr!=NULL)
	{
		if(temp->ptr->data < max->data)
		{
			temp1=temp->ptr;
			temp->ptr=temp1->ptr;
			free(temp1);
		}
		else
		{
			temp=temp->ptr;
			max=temp;
		}
	}

	return rev_list(head);
}

struct sll * del(struct sll * head)
{
	struct sll *temp=head,*head1=NULL,*temp1=NULL;

	while(temp!=NULL)
	{
		if(temp->ptr==NULL)
		{
			if(head1==NULL)
			{
				head1=temp;
				//return head1;
			}
			else
			{
				temp1->ptr=temp;
				temp1=temp1->ptr;
				//return head1;
			}
		}
		else if(temp->data>=temp->ptr->data)
		{
			if(head1==NULL)
			{
				head1=temp;
				temp1=head1;
			}
			else
			{
				temp1->ptr=temp;
				temp1=temp1->ptr;
			}
		}
		temp=temp->ptr;
	}
	return head1;
}


	
void testcases()
{
	int i,check,t;
	char *a,*op;

	for(t=0;t<2;t++)
	{
		if(t==0)
			printf("1st algorithm\n");
		else
			printf("2nd algorithm\n");

		for(i=0;i<10;i++)
		{
			struct sll *ihead,*ohead,*j;

			a=malloc_char(testDB[i].input);

			op=malloc_char(testDB[i].output);

			if(t==1)
				ihead=del_1(convert_to_list(a));
			else
				ihead=del(convert_to_list(a));

			ohead=convert_to_list(op);

			//for(j=ihead;j!=NULL;j=j->ptr)
				//printf("%d ",j->data);

			//for(j=ohead;j!=NULL;j=j->ptr)
				//printf("%d ",j->data);

			check=ll_cmp(ihead,ohead);

			if(check==0)
				printf("passed\n");
			else 
				printf("failed\n");
		}
	}
}



int main()
{
	testcases();
	getchar();
	return 0;
}
