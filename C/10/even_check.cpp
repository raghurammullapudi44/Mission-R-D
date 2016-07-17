#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#pragma warning(disable: 4996)

void testcases();

char *malloc_char(char ip[]);

struct sll * convert_to_list(char *);

struct sll * insert_in_list(int,struct sll *);

int even_odd_check(struct sll *);

int a_cmp(int,int);

struct test
{
	char input[44];
	int even_odd;
}testDB[11]={{"12345678",0},   // '0' for even and '1' for odd
			{"0123456",0},
			{"44445",1},
			{"001234",0},
			{"0012345",1},
			{"123400",0},
			{"0000001",1},
			{"12340056",0},
			{"01111",1},
			{"101011",1},
			{"111111111111111",1}};
			

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

int a_cmp(int a,int b)
{
	if(a==b)
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

int even_odd_check(struct sll * head)
{
	while(head != NULL && head->ptr != NULL)
	{
		if(head->ptr->ptr != NULL)
		{
			head=head->ptr->ptr;
		}
		else
		{
			head=head->ptr;
		}
	}

		if((head->data)%2 == 0)
			return 0;
		else
			return 1;
}

	
void testcases()
{
	int i,check,op,b;
	char *a;

	for(i=0;i<11;i++)
	{
		struct sll *ihead,*ohead,*j;

		a=malloc_char(testDB[i].input);

		op=testDB[i].even_odd;

		b=even_odd_check(convert_to_list(a));

		check=a_cmp(b,op);

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
