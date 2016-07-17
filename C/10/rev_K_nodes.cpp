#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#pragma warning(disable: 4996)

void testcases();

char *malloc_char(char ip[]);

struct sll * convert_to_list(char *);

struct sll * insert_in_list(int,struct sll *);

struct sll * reverse_list(struct sll *,int);


int ll_cmp(struct sll *,struct ll *);

struct test
{
	char input[44];
	int n;
	char output[44];
}testDB[10]={{"12345678",3,"32165487"},
			{"0123456",4,"3210654"},
			{"44445",1,"44445"},
			{"001234",2,"002143"},
			{"0012345",5,"3210054"},
			{"123400",6,"004321"},
			{"0000001",5,"0000010"},
			{"12340056",2,"21430065"},
			{"01111",3,"11011"},
			{"101011",4,"010111"}};
			

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

	struct sll *temp=ohead;

	while(temp)
	{
		temp=temp->ptr;
		count++;
	}
	while(ohead)
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

struct sll * reverse_list(struct sll * head,int n)
{
	int i,j=0,flag=0,k=0;

	struct sll *temp=head,*temp1=NULL,*ohead=NULL,*otemp=NULL;

	while(temp)
	{
		i=0;
		while(i<n && temp!=NULL)
		{
			temp=temp->ptr;
			head->ptr=temp1;
			temp1=head;
			head=temp;
			i++;
			k++;
		}
		if(flag==0)
		{
			ohead=temp1;
			flag=1;
		}
		if(j>0)
		{
			otemp=ohead;
			while(otemp->ptr!=NULL)
			{
				otemp=otemp->ptr;
			}
			otemp->ptr=temp1;
			i=0;
			otemp=ohead;
			while(i<k-1)
			{
				otemp=otemp->ptr;
				i++;
			}
			otemp->ptr=NULL;

		}
		j++;
	}
	return ohead;
}

	
void testcases()
{
	int i,check,n;
	char *a,*op;

	for(i=0;i<10;i++)
	{
		struct sll *ihead,*ohead,*j;

		a=malloc_char(testDB[i].input);

		op=malloc_char(testDB[i].output);

		n=testDB[i].n;

		ihead=reverse_list(convert_to_list(a),n);

		ohead=convert_to_list(op);

		for(j=ihead;j!=NULL;j=j->ptr)
			printf("%d ",j->data);

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
