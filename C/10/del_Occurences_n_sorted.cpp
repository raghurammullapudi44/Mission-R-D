#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#pragma warning(disable: 4996)

void testcases();

char *malloc_char(char ip[]);

struct sll * convert_to_list(char *);

struct sll * insert_in_list(int,struct sll *);

struct sll * del_occurences_sorted(struct sll *,int);

int ll_cmp(struct sll *,struct ll *);

struct test
{
	char input[44];
	int n;
	char output[44];
}testDB[11]={{"-3,1,2,3,3,3,3,3,4,5,6,7,8",-3,"1,2,3,3,3,3,3,4,5,6,7,8"},
			{"0,0,0,1,2,3,4,5,6",0,"1,2,3,4,5,6"},
			{"-6,-6,-6,-4,-4,4,4,5",-4,"-6,-6,-6,4,4,5"},
			{"0,0,1,2,3,6,6,6,6,6,6,7,7,7,7,44",6,"0,0,1,2,3,7,7,7,7,44"},
			{"-3,3,-2,-2,-1,-1,0,0,12,34,50",6,"-3,3,-2,-2,-1,-1,0,0,12,34,50"},
			{"0,0,1,2,3,4",0,"1,2,3,4"},
			{"0,0,0,0,0,0,1",1,"0,0,0,0,0,0"},
			{"10,12,34,5,6",0,"10,12,34,5,6"},
			{"0,1,1,1,1",1,"0"},
			{"4",4,""},
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
	int i=0,y=0,flag=0;
	struct sll *head=NULL;

	while(a[i]!='\0')
	{
		y=0;
		flag=0;
		while(a[i]!=',')
		{
			if(a[i]=='\0' )
			{
				i--;
				break;
			}
			else
			{
				if(a[i]=='-' && flag==0)
				{
					flag=1;
					i++;
				}
				y=(y*10)+(a[i]-'0');
				i++;
			}
		}
		if(flag==1)
			head=insert_in_list(-y,head);
		else
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

struct sll * del_occurences_sorted(struct sll * head,int n)
{
	int flag=0;

	if(head==NULL || (n<head->data))
		return head;
	else
	{
		struct sll *temp=head,*temp1=NULL;
		while(temp)
		{
			if(temp==head)
			{
				if(head->data==n)
				{
					while(temp!=NULL && (temp->data==n))
					{
						head=head->ptr;
						temp=head;
						flag=1;
					}
				}
			}
			else
			{
				while(temp!=NULL && (temp->data==n))
				{
					temp=temp->ptr;
					flag=1;
				}
				temp1->ptr=temp;
				if(temp==NULL)
				break;
			}
			if(flag==1)
				break;
			temp1=temp;
			temp=temp->ptr;
		}
		return head;
	}
}

	
void testcases()
{
	int i,check,n;
	char *a,*op;

	for(i=0;i<11;i++)
	{
		struct sll *ihead,*ohead,*j;

		n=testDB[i].n;

		a=malloc_char(testDB[i].input);

		op=malloc_char(testDB[i].output);

		ihead=del_occurences_sorted(convert_to_list(a),n);

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


