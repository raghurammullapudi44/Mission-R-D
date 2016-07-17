#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#pragma warning(disable: 4996)

void testcases();

char *malloc_char(char ip[]);

struct sll * convert_to_list(char *);

struct sll * insert_in_list(int,struct sll *);

struct sll * del_from_list(struct sll *,int);


int ll_cmp(struct sll *,struct ll *);

struct test
{
	char input[44];
	int pos;
	char output[44];
}testDB[10]={{"12345678",5,"1234678"},
			{"0123456",1,""},
			{"44445",2,"445"},
			{"001234",6,"00123"},
			{"00123456789246",6,"001235678946"},
			{"123400",0,"123400"},
			{"0000001",2,"0001"},
			{"12340056",10,"12340056"},
			{"01111",1,""},
			{"10101123",4,"101112"}};
			

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

struct sll * del_from_list(struct sll * head,int pos)
{
	struct sll *temp=NULL,*temp1,*temp2=head;
	int i,flag=0;
	if(pos==0)
		return head;
	if(pos==1)
	{
		return NULL;
	}
	
	while(temp2!=NULL)
	{
		temp=temp2;
		if(temp->ptr==NULL)
			return head;
		for(i=1;i<pos-1;i++)
		{
			temp=temp->ptr;
			if(temp->ptr==NULL)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
			return head;
		else
		{
			temp1=temp->ptr;
			temp->ptr=temp1->ptr;
		}	temp2=temp->ptr;
	}
	return head;
}

	
void testcases()
{
	int i,check,pos;
	char *a,*op;

	for(i=0;i<10;i++)
	{
		struct sll *ihead,*ohead,*j;

		pos=testDB[i].pos;

		a=malloc_char(testDB[i].input);

		op=malloc_char(testDB[i].output);

		ihead=del_from_list(convert_to_list(a),pos);

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
