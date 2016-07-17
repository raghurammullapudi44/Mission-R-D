#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#pragma warning(disable: 4996)

void testcases();

char *malloc_char(char ip[]);

struct sll * convert_to_list(char *);

struct sll * insert_in_list(int,struct sll *);

struct sll * merge_sort(struct sll *,struct sll *);

struct sll * sorted(struct sll *,struct sll*);

int ll_cmp(struct sll *,struct ll *);

struct test
{
	char input[44];
	char output[44];
}testDB[2]={{"14016","01146"},
			{"1122000011","0000111122"}};
			

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

		temp1=head;

		while(temp1->ptr!=NULL)
			temp1=temp1->ptr;

		temp1->ptr=temp;

		//printf("%d ",temp->data);

		return head;
	}
}

struct sll * merge_sort(struct sll * head,struct sll *tail)
{
	if(head==tail || head->ptr==NULL)
		return head;
	else
	{
		struct sll *temp=head,*mid1=head,*mid=head,*head1;
		
		while(mid1!=tail && mid1->ptr!=tail)
		{
			mid=mid->ptr;
			mid1=mid1->ptr->ptr;
		}
		head=merge_sort(head,mid);
		tail=merge_sort(mid->ptr,tail);
		head1=sorted(head,tail);
		return head1;
	}
}

struct sll * sorted(struct sll *head,struct sll *mid1)
{
	struct sll *result;
	if(head==mid1)
		return mid1;
	else if(mid1==NULL)
		return head;
	if(head->data<= mid1->data)
	{
		result=head;
		result->ptr=sorted(head->ptr,mid1);
	}
	else
	{
		result=mid1;
		result->ptr=sorted(head,mid1->ptr);
	}
	return result;
}

	
void testcases()
{
	int i,check;
	char *a,*op;

	for(i=0;i<2;i++)
	{
		struct sll *ihead,*ohead,*j;

		a=malloc_char(testDB[i].input);

		op=malloc_char(testDB[i].output);

		ihead=convert_to_list(a);

		j=ihead;

		while(j->ptr!=NULL)
		{
			j=j->ptr;
		}


		ihead=merge_sort(ihead,j);

		ohead=convert_to_list(op);

		/*for(j=ihead;j!=NULL;j=j->ptr)
			printf("%d ",j->data);

		for(j=ohead;j!=NULL;j=j->ptr)
			printf("%d ",j->data);*/

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
