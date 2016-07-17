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
}testDB[10]={{"12345678",3,"12334356378"}};
			/*{"0123456",1,"101112131415161"},
			{"44445",2,"4242424252"},
			{"001234",6,"0012364"},
			{"0012345",6,"00123645"},
			{"123400",0,"123400"},
			{"0000001",7,"00000071"},
			{"12340056",10,"12340056"},
			{"01111",1,"1011111111"},
			{"101011222222",4,"1014011422242224"}};*/
			

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
		temp->ptr=head;

		return head;
	}
}

struct sll * ins_in_pos_list(struct sll * head,int pos)
{
	struct sll *temp=NULL,*temp1,*temp2,*temp3=head;
	int i,flag=0;
	if(pos==0)
		return head;
	
	while(temp3!=NULL)
	{
		temp=temp3;
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
			temp2=(struct sll *)malloc(sizeof(struct sll));
			temp2->data=pos;
			temp2->ptr=NULL;
			if(pos==1 && temp==head)
			{
				temp2->ptr=head;
				head=temp2;
				temp3=head->ptr;
			}
			else
			{
				temp1=temp->ptr;
				temp->ptr=temp2;
				temp2->ptr=temp1;
				temp3=temp1;
			}
		}	
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

		ihead=ins_in_pos_list(convert_to_list(a),pos);

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
