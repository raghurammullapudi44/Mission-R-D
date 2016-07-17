#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#pragma warning(disable: 4996)

void testcases();

char *malloc_char(char ip[]);

struct sll * convert_to_list(char *);

struct sll * insert_in_list(int,struct sll *);

struct sll * del_dup(struct sll *);

struct sll * rev_list(struct sll *);

int ll_cmp(struct sll *,struct ll *);

struct test
{
	char input[88];
	char output[88];
}testDB[10]={{{"11,11,22,23,33,44,4"},{"11,22,23,33,44,4"}},
			{{"44,4,2,2,2,33,31,11"},{"44,4,2,33,31,11"}},
			{{"12,34,56,78"},{"12,34,56,78"}},
			{{"88,88"},{"88"}},
			{{"44,10,4,4"},{"44,10,4"}},
			{{""},{""}},
			{{"1,2,23,3,4,4,5,56,6,77,0,0"},{"1,2,23,3,4,5,56,6,77,0"}},
			{{"1,0,2,0,0,0,4,0"},{"1,0,2,0,4,0"}},
			{{"0,0,0,0,0,0,0,0"},{"0"}},
			{{"0,1,2,2,22,3,6,0"},{"0,1,2,22,3,6,0"}}};
			

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


struct sll * del_dup(struct sll * head)
{
	struct sll *temp=head,*dup=head,*temp1=NULL;

	while(temp!=NULL && temp->ptr!=NULL)
	{
		if(temp->ptr->data==dup->data)
		{
			temp1=temp->ptr;
			temp->ptr=temp1->ptr;
		}
		else
		{
			temp=temp->ptr;
			dup=dup->ptr;
		}
	}
	return head;
}

	
void testcases()
{
	int i,check;
	char *a,*op;

	for(i=0;i<10;i++)
	{
		struct sll *ihead,*ohead,*j;

		a=malloc_char(testDB[i].input);

		op=malloc_char(testDB[i].output);

	
		ihead=del_dup(convert_to_list(a));

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



int main()
{
	testcases();
	getchar();
	return 0;
}
