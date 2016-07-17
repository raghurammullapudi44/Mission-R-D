#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#pragma warning(disable: 4996)

void testcases();

char *malloc_char(char ip[]);

struct sll * convert_to_list(char *);

struct sll * insert_in_list(int,struct sll *);

struct sll * tra_m_del_n(struct sll *,int,int);

int ll_cmp(struct sll *,struct ll *);

struct test
{
	char input[44];
	int m;
	int n;
	char output[44];
}testDB[10]={{"1234567",2,2,"1256"},
			{"0123456",1,2,"036"},
			{"44445",0,2,"44445"},
			{"001234",1,10,"0"},
			{"0012345",6,0,"0012345"},
			{"123400",5,1,"12340"},
			{"0000001",1,7,"0"},
			{"12340056",5,5,"12340"},
			{"01",1,1,"0"},
			{"1",6,0,"1"}};

			

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

struct sll * tra_m_del_n(struct sll * head,int m,int n)
{
	int countm,countn,flag;

	if(m==0 || n==0)
		return head;
	else
	{
		struct sll *mnode=head,*nnode;

		while(mnode->ptr!=NULL && mnode!=NULL)
		{
			flag=0;
			countm=1;
			countn=0;

			while(countm!=m)
			{
				if(mnode->ptr==NULL)
				{
					break;
				}
				mnode=mnode->ptr;
				countm++;
			}

			if(mnode->ptr==NULL)
				break;

			nnode=mnode;

			while(countn!=n)
			{
				if(nnode->ptr==NULL)
				{
					break;
				}
				nnode=nnode->ptr;
				countn++;
			}

			if(nnode->ptr==NULL)
			{
				mnode->ptr=NULL;
				break;
			}

			mnode->ptr=nnode->ptr;
			mnode=mnode->ptr;
		}
		return head;
	}
}

	
void testcases()
{
	int i,check,m,n;
	char *a,*op;

	for(i=0;i<10;i++)
	{
		struct sll *ihead,*ohead,*j;

		m=testDB[i].m;
		n=testDB[i].n;

		a=malloc_char(testDB[i].input);

		op=malloc_char(testDB[i].output);

		ihead=tra_m_del_n(convert_to_list(a),m,n);

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
