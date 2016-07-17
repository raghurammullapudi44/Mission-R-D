#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#pragma warning(disable: 4996)

void testcases();

char *malloc_char(char ip[]);

struct sll * convert_to_list(char *);

struct sll * insert_in_list(int,struct sll *);

struct sll * swap_kth(struct sll *,int);

int ll_cmp(struct sll *,struct ll *);

struct test
{
	char input[44];
	int pos;
	char output[44];
}testDB[11]={{"123456789",5,"123456789"},
			{"0123456",1,"6123450"},
			{"44445",2,"44445"},
			{"001234",-1,"001234"},
			{"0012345",6,"0412305"},
			{"123400",0,"123400"},
			{"0000001",7,"1000000"},
			{"12340056",5,"12304056"},
			{"01",1,"10"},
			{"1",6,"1"},
			{"",4,""}};
			

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

struct sll * swap_kth(struct sll * head,int pos)
{
	int i=1,len=0;

	struct sll *p=NULL,*q=head,*r=NULL,*s=head,*temp=head,*temp1;
	
	if(pos<1)
		return head;

	while(temp!=NULL)
	{
		len++;
		temp=temp->ptr;
	}

	if(pos>len)
		return head;
	if(pos==(len%2) && (len%2==0))
		return head;
	
	while(i<pos)
	{
		p=q;
		q=q->ptr;
		i++;
	}
	i=1;
	while(i<(len-pos+1))
	{
		r=s;
		s=s->ptr;
		i++;
	}

	if(p!=NULL)
	{
		p->ptr=s;
	}
	if(r!=NULL)
	{
		r->ptr=q;
	}

	temp1=q->ptr;
	q->ptr=s->ptr;
	s->ptr=temp1;

	if(pos==1)
		return s;
	else if(pos==len)
		return q;
	else
		return head;
}

	
void testcases()
{
	int i,check,pos;
	char *a,*op;

	for(i=0;i<11;i++)
	{
		struct sll *ihead,*ohead,*j;

		pos=testDB[i].pos;

		a=malloc_char(testDB[i].input);

		op=malloc_char(testDB[i].output);

		ihead=swap_kth(convert_to_list(a),pos);

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
